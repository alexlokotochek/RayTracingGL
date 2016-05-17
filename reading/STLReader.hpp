#ifndef RT_STL_READER
#define RT_STL_READER

#include "../figures/Triangle.hpp"
#include "../figures/Figure.hpp"
#include "../figures/Sphere.hpp"
#include <cstdio>
#include <cstring>

const char *VERTEX = "vertex";
const char *SPHERE = "sphere";
const char *BAD_FORMAT = "bad stl file";
vector <Figure *> readAsciiStl(const std::string filename) {
    vector <Figure *> result;
    std::ifstream fin(filename,
                      std::ios::binary | std::ios::in);
    static const int MAX_LINE_LENGTH = 80;
    char s[MAX_LINE_LENGTH];
    while (!fin.eof()) {
        fin >> s;
        if (strcmp(s, VERTEX) == 0) {
            Triangle* current = new Triangle();
            for (int i = 0; i < Triangle::size(); ++i) {
                fin >> (*current)[i].x >> (*current)[i].y >> (*current)[i].z;
                if (i + 1 != Triangle::size()) {
                    fin >> s;
                }
            }
            result.push_back(dynamic_cast<Figure *>(current));
        } else if (strcmp(s, SPHERE) == 0) {
            Sphere *sphere = new Sphere();
            sphere->fscanfSelf(fin);

            result.push_back(dynamic_cast<Figure *>(sphere));
        }
    }
    fin.close();
    return result;
}

vector <Figure *> readBinaryStl(const std::string filename) {
    vector <Figure *> result;
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
        result.push_back(dynamic_cast<Figure *>(current));
    }

    delete tmp;
    fin.close();
    return result;

}

#endif
