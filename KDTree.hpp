#ifndef RT_KD_TREE
#define RT_KD_TREE

#include <algorithm>
#include "BasicGeom.hpp"
#include "scene/Body.hpp"
#include "Image.hpp"
#include <utility>
#include "figures/Figure.hpp"
#include "reading/STLReader.hpp"
#include <vector>

using namespace BasicGeom;

int steps = 0;

class Node {
public:
    BoundingBox bounds;
    Node *left, *right;
    Body *body;
    Node() {
        body = NULL;
        left = right = NULL;
    }
    Node (Body *body) : body(body) {
        bounds = body->figure->getBoundingBox();
        left = right = NULL;
    }
    ~Node() {
        delete body;
        delete left;
        delete right;
    }
};

class KDTree{

    Node *root;

    void recalc(Node *v) {
        if (v->left) {
            v->bounds = (v->bounds | v->left->bounds);
        }
        if (v->right) {
            v->bounds = (v->bounds | v->right->bounds);
        }
    }

    Node *makeTree(vector<Body *>::iterator begin,
                   vector<Body *>::iterator end, int step) {
        if (begin == end) {
            return NULL;
        }
        int n = end - begin;
        auto process = [&step] (const Body * a, const Body *b) {
            return  (a->figure->getBoundingBox(step, 0) <
                     b->figure->getBoundingBox(step, 0));
        };
        nth_element(begin,
                    begin + n / 2,
                    end,
                    process);
        Node *result = new Node(*(begin + n / 2));
        result->left = makeTree(begin,
                                begin + (n / 2),
                                (step + 1) % 3);
        result->right = makeTree(begin + (n / 2) + 1,
                                 end,
                                 (step + 1) % 3);
        recalc(result);
        return result;
    }

    void intersect(Node *v, myFloat &currentTime,
                   const Body * &currentIntersection,
                   const Ray &currentRay) const {
        ++steps;
        if (!v || !(v->bounds.intersects(currentRay))) {
            return;
        }
        Vector current = v->body->figure->rayIntersection(currentRay);
        if (current != NONE) {
            myFloat myTime = (current - currentRay.start)
                              * currentRay.direction;
            if (greater(myTime, 0.) && less(myTime, currentTime)) {
                currentTime = myTime;
                currentIntersection = v->body;
            }
        }
        intersect(v->left,
                  currentTime,
                  currentIntersection,
                  currentRay);
        intersect(v->right,
                  currentTime,
                  currentIntersection,
                  currentRay);
    }

public:

    KDTree(const char *filename, const char &readMode) {
        vector <Figure *> figures;
        if (readMode == 'a') {
            figures = readAsciiStl(filename);
        }
        if (readMode == 'b') {

            std::cout << "binary reading" << std::endl;

            figures = readBinaryStl(filename);
        }
        vector <Body *> bodies(figures.size());
        for (size_t i = 0; i < figures.size(); ++i) {
            bodies[i] = new Body({RGB(120, 100, 90)},
                                 figures[i]);
        }
        root = makeTree(bodies.begin(), bodies.end(), 0);
    }

    std::pair<Vector, const Body *> rayIntersection(const Ray &ray) const {
        myFloat currentTime = 1e15;
        const Body *currentIntersection = NULL;
        intersect(root,
                  currentTime,
                  currentIntersection,
                  ray);
        if (eq(currentTime, 1e15)) {
            return {NONE, NULL};
        } else {
            return {ray.start + ray.direction * currentTime,
                    currentIntersection};
        }
    }

    ~KDTree() {
        delete root;
    }
};

#endif
