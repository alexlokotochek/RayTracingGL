#ifndef GLIB_LIGHTSOURCE
#define GLIB_LIGHTSOURCE

#include "../Geometry.hpp"

using namespace Geometry;

class LightSource {
public:
    Vector3D position;
    goodFloat energy;
    goodFloat refDistance;
    goodFloat refEnergy;

    goodFloat getIncrease(const Vector3D &point, const Vector3D &normal) const {
        return (pow(refDistance, 2.) / refEnergy)
               * (energy * (normal * (position - point)))
               / (normal.len() * pow((position - point).len(), 3.));

    }
};

#endif
