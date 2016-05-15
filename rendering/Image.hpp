#ifndef RT_IMAGE
#define RT_IMAGE

#include <vector>
#include <cstddef>
#include "../geometry/BasicGeom.hpp"
#include <fstream>
#include <iostream>

using namespace Float;
using std::vector;

class Image {
public:
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
private:
    size_t width;
    size_t height;
    vector <vector <RGB> > body;

public:
    Image(size_t width, size_t height) {
        this->width = width;
        this->height = height;
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

    void write(const char *filename) {
        std::ofstream ofs;

        // need to spec. binary mode for Windows/UNIX users
        ofs.open(filename, std::ios::binary);
        if (ofs.fail())
            std::cout << "Can't open output file";

        ofs << "P6\n" << width << " " << height << "\n255\n";

        // loop over each pixel in the image, clamp and convert to byte format
        for (int y = 0; y < height; ++y) {
            for (size_t x = 0; x < width; ++x) {
                ofs << body[y][x].R << body[y][x].G << body[y][x].B;
            }
        }
        ofs.close();
    }
};

#endif
