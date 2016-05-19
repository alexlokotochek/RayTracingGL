#ifndef GLIB_IMAGE
#define GLIB_IMAGE

#include <vector>
#include <cstddef>
#include "Geometry.hpp"
#include <fstream>
#include <iostream>
#include <GLUT/glut.h>

using namespace GoodFloat;
using std::vector;

class RGB {
public:
    unsigned char R, G, B;

    RGB() : R(0), G(0), B(0) {};

    RGB(unsigned char r,
        unsigned char g,
        unsigned char b) : R(r), G(g), B(b) {}

    RGB operator*(float increase) const {
        auto cast = [] (float x) {
            return (less(x, 0.) ?
                    0 : (greater(x, 255) ?
                         255 : (unsigned char)x));
        };
        return RGB(cast(R * increase),
                   cast(G * increase),
                   cast(B * increase));
    }

};

size_t width;
size_t height;
vector <vector <RGB> > body;

void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            glColor3f(body[y][x].R / 255.0, body[y][x].G / 255.0, body[y][x].B / 255.0);
            glVertex2d(x, y);
        }
    }
    glEnd();
    glFlush();
}

void Initialize() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, 0, 1);
}

class Image {

public:
    Image(size_t width_, size_t height_) {
        width = width_;
        height = height_;
        body.assign(height, vector<RGB>(width));
    }

    size_t getWidth() const {
        return width;
    }

    size_t getHeight() const {
        return height;
    }

    RGB& operator()(size_t i, size_t j) {
        return body[i][j];
    }

    void write(std::string filename) {
        std::ofstream ofs;

        // need to spec. binary mode for Windows/UNIX users
        ofs.open(filename, std::ios::binary);
        if (ofs.fail())
            std::cout << "Can't open output file";

        ofs << "P6\n" << width << " " << height << "\n255\n";

        // loop over each pixel in the image, clamp and convert to byte format
        for (size_t y = 0; y < height; ++y) {
            for (size_t x = 0; x < width; ++x) {
                ofs << body[y][x].R << body[y][x].G << body[y][x].B;
            }
        }
        ofs.close();
    }

    void show(int argc, char **argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(width, height);
        glutInitWindowPosition(0, 0);
        glutCreateWindow("RayTRCR");
        Initialize();
        glutDisplayFunc(Display);
        glutMainLoop();
    }
};

#endif