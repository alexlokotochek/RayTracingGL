#ifndef GLIB_LIGHTSOURCE
#define GLIB_LIGHTSOURCE

#include "../Geometry.hpp"

using namespace Geometry;

class LightSource {
public:
    Vector3D position;
    goodFloat energy;

    goodFloat getIncrease(const Vector3D &point, const Vector3D &normal) const {
        return energy / pow((position - point).len(), 3.)
               * (normal * (position - point)) / (normal.len());
    }
};

#endif
