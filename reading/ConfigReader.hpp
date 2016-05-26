#ifndef GLIB_CONFIG
#define GLIB_CONFIG

#include <string>
#include "../Geometry.hpp"

namespace ConfigReader {

    std::string drawMode;
    std::string readMode;
    int screenWidth;
    int screenHeight;
    std::string lampsFile;
    std::string sceneFile;
    std::string outFile;
    Vector3D position;
    Vector3D topLeft;
    Vector3D bottomLeft;
    Vector3D topRight;

    void read(std::string filename) {

        std::ifstream fin(filename, std::ios::in);

        std::string input;

        goodFloat x, y, z;

        while (!fin.eof()) {
            fin >> input;
            if (input == "drawMode") {
                fin >> drawMode;
                continue;
            }
            if (input == "readMode") {
                fin >> readMode;
                continue;
            }
            if (input == "screenWidth") {
                fin >> screenWidth;
                continue;
            }
            if (input == "screenHeight") {
                fin >> screenHeight;
                continue;
            }
            if (input == "lampsFile") {
                fin >> lampsFile;
                continue;
            }
            if (input == "sceneFile") {
                fin >> sceneFile;
                continue;
            }
            if (input == "outFile") {
                fin >> outFile;
                continue;
            }
            if (input == "position") {
                fin >> x >> y >> z;
                position = Vector3D(x, y, z);
                continue;
            }
            if (input == "topLeft") {
                fin >> x >> y >> z;
                topLeft = Vector3D(x, y, z);
                continue;
            }
            if (input == "bottomLeft") {
                fin >> x >> y >> z;
                bottomLeft = Vector3D(x, y, z);
                continue;
            }
            if (input == "topRight") {
                fin >> x >> y >> z;
                topRight = Vector3D(x, y, z);
                continue;
            }
        }

    }

};

#endif