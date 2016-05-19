#ifndef GLIB_LIGHTSOURCE
#define GLIB_LIGHTSOURCE

#include "../Geometry.hpp"

using namespace BasicGeom;

class LightSource {
public:
    Vector position;
    myFloat energy;

    myFloat getIncrease(const Vector &point, const Vector &normal) const {
        return energy / pow((position - point).len(), 3.)
               * (normal * (position - point)) / (normal.len());
    }
};

#endif
