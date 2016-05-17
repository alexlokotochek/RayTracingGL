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
vector <Figure *> readAsciiStl(const char *filename) {
    vector <Figure *> result;
    if (filename == NULL) {
        return result;
    }
    FILE *in = fopen(filename, "r");
    static const int MAX_LINE_LENGTH = 80;
    char s[MAX_LINE_LENGTH];
    while (fscanf(in, "%s", s) == 1) {
        if (strcmp(s, VERTEX) == 0) {
            Triangle* current = new Triangle();
            for (int i = 0; i < Triangle::size(); ++i) {
                if (fscanf(in,
                           "%lf %lf %lf",
                           &(*current)[i].x,
                           &(*current)[i].y,
                           &(*current)[i].z) != Triangle::size()) {
                    throw BAD_FORMAT;
                }
                if (i + 1 != Triangle::size()) {
                    if (fscanf(in, "%s", s) != 1) { //here should be vertex word
                        throw BAD_FORMAT;
                    }
                }
            }
            result.push_back(dynamic_cast<Figure *>(current));
        } else if (strcmp(s, SPHERE) == 0) {
            Sphere *sphere = new Sphere();
            if (!sphere->fscanfSelf(in)) {
                throw BAD_FORMAT;
            }
            result.push_back(dynamic_cast<Figure *>(sphere));
        }
    }
    fclose(in);
    return result;
}

vector <Figure *> readBinaryStl(const char *filename) {
    vector <Figure *> result;
    if (filename == NULL) {
        return result;
    }

    std::ifstream fin(filename, std::ios::binary | std::ios::in);
    char *tmp = new char[100];
    fin.read(tmp, 80);
    unsigned int triangleCount;
    fin.read((char *)&triangleCount, 4);
    float x, y, z; // normal - забьём на неё
    __uint16_t attribute;

//    std::cout << "triangles total: " << triangleCount << std::endl;

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
//        if (i % 1000 == 0) {
//            std::cout << (*current)[0].x << " " << (*current)[0].y << " " << (*current)[0].z << " " << std::endl;
//        }
    }

    std::cout << "result size: " << result.size() << std::endl;

    delete tmp;
    fin.close();
    return result;

}

#endif
