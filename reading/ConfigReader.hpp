#ifndef RT_CONFIGREADER
#define RT_CONFIGREADER

#include <string>
#include "../BasicGeom.hpp"

namespace ConfigReader {

    char drawMode;
    char readMode;
    int screenWidth;
    int screenHeight;
    std::string lampsFile;
    std::string sceneFile;
    std::string outFile;
    Vector position;
    Vector topLeft;
    Vector bottomLeft;
    Vector topRight;

    void read(std::string filename) {

        std::ifstream fin(filename, std::ios::in);

        std::string input;

        myFloat x, y, z;

        while (!fin.eof()) {
            fin >> input;
            if (input == "drawMode") {
                fin >> input;
                drawMode = input[0];
            }
            if (input == "readMode") {
                fin >> input;
                readMode = input[0];
            }
            if (input == "screenWidth") {
                fin >> screenWidth;
            }
            if (input == "screenHeight") {
                fin >> screenHeight;
            }
            if (input == "lampsFile") {
                fin >> lampsFile;
            }
            if (input == "sceneFile") {
                fin >> sceneFile;
            }
            if (input == "outFile") {
                fin >> outFile;
            }
            if (input == "position") {
                fin >> x >> y >> z;
                position = Vector(x, y, z);
            }
            if (input == "topLeft") {
                fin >> x >> y >> z;
                topLeft = Vector(x, y, z);
            }
            if (input == "bottomLeft") {
                fin >> x >> y >> z;
                bottomLeft = Vector(x, y, z);
            }
            if (input == "topRight") {
                fin >> x >> y >> z;
                topRight = Vector(x, y, z);
            }
        }

    }

};


#endif //RT_CONFIGREADER
