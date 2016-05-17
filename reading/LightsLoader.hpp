#ifndef RT_LIGHT_LOADER
#define RT_LIGHT_LOADER

#include "../scene/LightSource.hpp"
#include <vector>
#include <cstdio>

using std::vector;

const char *BAD_FILE = "Bad lights sources file";

vector<LightSource> readLightSources(const std::string filename) {
    vector <LightSource> result;
    std::ifstream fin(filename,
                      std::ios::binary | std::ios::in);
    int n;
//    if (fscanf(in, "%d", &n) != 1) {
//        throw BAD_FILE;
//    }
    fin >> n;
    for (int i = 0; i < n; ++i) {
        LightSource source;
//        if (fscanf(in, "%lf%lf%lf%lf", &source.position.x, &source.position.y,
//                               &source.position.z, &source.energy) != 4) {
//            throw BAD_FILE;
//        }
        fin >> source.position.x >>
                source.position.y >>
                source.position.z >>
                source.energy;
        result.push_back(source);
    }
    fin.close();
    return result;
}

#endif
