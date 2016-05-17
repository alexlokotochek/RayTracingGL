#ifndef RT_FIGURE
#define RT_FIGURE

#include "../BasicGeom.hpp"
#include <algorithm>

using namespace BasicGeom;

using std::min;
using std::max;

struct BoundingBox {

    myFloat boundaries[3][2];

    myFloat* operator[](size_t i) {
        return boundaries[i];
    }

    ~BoundingBox() {}

    const myFloat* operator[](size_t i) const {
        return boundaries[i];
    }

    bool intersects(const Ray &ray) const {

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 2; ++j) {
                myFloat t;
                if (eq(ray.direction[i], 0.)) {
                    if (eq(ray.start[i], boundaries[i][j])) {
                        t = 0;
                    }
                    else {
                        continue;
                    }
                } else {
                    t = (boundaries[i][j] - ray.start[i]) / ray.direction[i];
                }
                if (less(t, 0.)) {
                    continue;
                }
                Vector candidate = ray.start + ray.direction * t;
                bool fail = false;
                for (int k = 1; k < 3; ++k) {
                    if (!(less(boundaries[(i + k) % 3][0],
                               candidate[(i + k) % 3]) &&
                          less(candidate[(i + k) % 3],
                               boundaries[(i + k) % 3][1]))) {
                        fail = true;
                    }
                }
                if (!fail) {
                    return true;
                }
            }
        }
        return false;
    }
};

BoundingBox operator|(const BoundingBox &a, const BoundingBox &b) {
    BoundingBox result;
    for (int i = 0; i < 3; ++i) {
        result[i][0] = min(a[i][0], b[i][0]);
        result[i][1] = max(a[i][1], b[i][1]);
    }
    return result;
}

bool intersects(const myFloat *first, const myFloat *second) {
    return greaterOrEqual(min(first[1], second[1]), max(first[0], second[0]));
}

bool intersects(const BoundingBox &a, const BoundingBox &b) {
    for (int i = 0; i < 3; ++i) {
        if (!intersects(a[i], b[i])) {
            return false;
        }
    }
    return true;
}

//is first inside second
bool isInside(const myFloat *first, const myFloat *second) {
    return lessOrEqual(second[0], first[0]) && lessOrEqual(first[1], second[1]);
}

bool isInside(const BoundingBox &a, const BoundingBox &b) {
    for (int i = 0; i < 3; ++i) {
        if (!isInside(a, b)) {
            return false;
        }
    }
    return true;
}

struct Figure {
    virtual Vector rayIntersection(const Ray &r) const = 0;
    virtual Plane getTangentPlane(const Vector &point) const = 0;
    virtual BoundingBox getBoundingBox() const = 0;
    virtual myFloat getBoundingBox(int dim, int side) const {
        return getBoundingBox()[dim][side];
    }

    virtual ~Figure() {
    }
};

#endif
