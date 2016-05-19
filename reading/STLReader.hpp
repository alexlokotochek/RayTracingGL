#ifndef GLIB_STL
#define GLIB_STL

#include "../figures/Triangle.hpp"
#include "../figures/Object.hpp"
#include "../figures/Sphere.hpp"
#include <cstdio>
#include <cstring>

vector <Object *> readAsciiStl(const std::string filename) {
    vector <Object *> result;
    std::ifstream fin(filename, std::ios::in);
    std::string s;
    while (!fin.eof()) {
        fin >> s;
        if (s == "vertex") {
            Triangle* current = new Triangle();
            for (int i = 0; i < Triangle::size(); ++i) {
                fin >> (*current)[i].x >> (*current)[i].y >> (*current)[i].z;
                if (i + 1 != Triangle::size()) {
                    fin >> s;
                }
            }
            result.push_back(dynamic_cast<Object *>(current));
        } else if (s == "sphere") {
            Sphere *sphere = new Sphere();
            sphere->readMe(fin);

            result.push_back(dynamic_cast<Object *>(sphere));
        }
    }
    fin.close();
    return result;
}

vector <Object *> readBinaryStl(const std::string filename) {
    vector <Object *> result;
    std::ifstream fin(filename,
                      std::ios::binary | std::ios::in);
    char *tmp = new char[100];
    fin.read(tmp, 80);
    unsigned int triangleCount;
    fin.read((char *)&triangleCount, 4);
    float x, y, z; // normal - забьём на неё
    __uint16_t attribute;

    for (int i = 0; i < (int)triangleCount; ++i) {
        Triangle* current = new Triangle();
        fin.read((char *)&x, 4);
        fin.read((char *)&y, 4);
        fin.read((char *)&z, 4);
        for (int j = 0; j < 3; ++j) {
            fin.read((char *)&(*current)[j].x, 4);
            fin.read((char *)&(*current)[j].y, 4);
            fin.read((char *)&(*current)[j].z, 4);
        }
        fin.read((char *)&attribute, 2);
        result.push_back(dynamic_cast<Object *>(current));
    }

    delete tmp;
    fin.close();
    return result;

}

#endif