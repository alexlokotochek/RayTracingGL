#ifndef GLIB_RT
#define GLIB_RT

#include "../figures/Triangle.hpp"
#include "../figures/Object.hpp"
#include "../figures/Sphere.hpp"
#include "../Image.hpp"
#include "../scene/LightSource.hpp"
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <assert.h>
#include <map>
#include <utility>

using std::vector;

class RTReader {
public:

    Vector3D position;
    Vector3D topLeft;
    Vector3D bottomLeft;
    Vector3D topRight;

    goodFloat refDist, refEnergy;

    vector<Object *> objects;
    std::map<std::string, RGB> materials;
    vector<LightSource> lights;

    typedef std::pair<std::string, RGB> Entry;

    void readRT(const std::string filename) {

        std::ifstream fin(filename, std::ios::in);
        std::string s;

        goodFloat x, y, z;
        int r, g, b;

        while (!fin.eof()) {

            fin >> s;

            if (s == "viewport") {

                fin >> s;
                while (s != "endviewport") {

                    if (s == "origin") {
                        fin >> x >> y >> z;
                        position = Vector3D(x, y, z);
                    }
                    if (s == "topleft") {
                        fin >> x >> y >> z;
                        topLeft = Vector3D(x, y, z);
                    }
                    if (s == "bottomleft") {
                        fin >> x >> y >> z;
                        bottomLeft = Vector3D(x, y, z);
                    }
                    if (s == "topright") {
                        fin >> x >> y >> z;
                        topRight = Vector3D(x, y, z);
                    }

                    fin >> s;

                }

            }

            if (s == "materials") {

                fin >> s;

                while (s != "endmaterials") {

                    Entry entry;
                    entry.first = "-";

                    fin >> s;
                    while (s != "endentry") {
                        if (s == "name") {
                            fin >> entry.first;
                        }
                        if (s == "color") {
                            fin >> r >> g >> b;

                            entry.second.R = (unsigned char)r;
                            entry.second.G = (unsigned char)g;
                            entry.second.B = (unsigned char)b;

                        }
                        fin >> s;
                    }

                    materials.insert(entry);

                    fin >> s;
                }
            }

            if (s == "lights") {
                fin >> s;

                while (s != "endlights") {
                    if (s == "reference") {
                        fin >> s >> refEnergy;
                        fin >> s >> refDist;
                        fin >> s; // endreference
                    }
                    if (s == "point") {
                        LightSource light;
                        light.refDistance = refDist;
                        light.refEnergy = refEnergy;
                        fin >> s >> x >> y >> z;
                        light.position = Vector3D(x, y, z);
                        fin >> s >> light.energy;
                        fin >> s; // endpoint
                        lights.push_back(light);
                    }
                    fin >> s;
                }
            }

            if (s == "geometry") {
                fin >> s;
                while (s != "endgeometry") {

                    if (s == "sphere") {
                        Sphere *sphere = new Sphere();
                        fin >> s >> x >> y >> z;
                        sphere->Center = Vector3D(x, y, z);
                        fin >> s >> (*sphere).Radius;
                        fin >> s >> s; // material id
                        (*sphere).figureColor = materials.find(s)->second;
                        fin >> s; // endsphere
                        objects.push_back(dynamic_cast<Object *>(sphere));
                    }

                    if (s == "triangle") {
                        Triangle *triangle = new Triangle();

                        for (int i = 0; i < 3; ++i) {
                            fin >> s >> (*triangle)[i].x >> (*triangle)[i].y >> (*triangle)[i].z;
                        }

                        fin >> s >> s; // material id
                        (*triangle).figureColor = materials.find(s)->second;
                        objects.push_back(dynamic_cast<Object *>(triangle));
                    }

                    fin >> s;
                }
            }

        }
        fin.close();
    }

};

#endif

