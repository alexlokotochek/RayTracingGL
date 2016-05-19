#ifndef GLIB_SPHERE
#define GLIB_SPHERE

#include "Object.hpp"
#include "../Geometry.hpp"
#include <algorithm>
#include <cstdio>

using std::min;

using namespace GoodFloat;
using namespace Geometry;

struct Sphere: public Object {

    Vector3D Center;
    goodFloat Radius;
//    RGB Object::figureColor;

    Sphere() {}

    Sphere(const Vector3D &Center,
           const goodFloat &Radius) : Center(Center),
                                      Radius(Radius) {}

    Plane getTangentPlane(const Vector3D &point) const {
        return Plane(point, point - Center);
    }

    Vector3D rayIntersection(const Ray &r) const {
        Vector3D normalUp = ((Center - r.start) % r.direction);
        goodFloat distance2 = normalUp.len2() / r.direction.len2();
        if (greater(distance2, sq(Radius))) {
            return NONE;
        }
        goodFloat startDistance = sqrt((Center - r.start).len2() - distance2);
        Vector3D normedDirection = r.direction.normed();
        Vector3D projection = r.start + normedDirection * startDistance;
        goodFloat intersecDistance = sqrt(sq(Radius) - distance2);

        Vector3D candidate1 = projection - normedDirection * intersecDistance;
        Vector3D candidate2 = projection + normedDirection * intersecDistance;

        goodFloat t1 = (candidate1 - r.start) * normedDirection;
        goodFloat t2 = (candidate2 - r.start) * normedDirection;
        t1 = (lessOrEqual(t1, 0.) ? 1e18 : t1);
        t2 = (lessOrEqual(t2, 0.) ? 1e18 : t2);
        goodFloat t = min(t1, t2);
        if (eq(t, 1e18)) {
            return NONE;
        }
        return r.start + normedDirection * t;
    }

    void readMe(std::ifstream &fin) {
        int r, g, b;
        fin >>
            Center.x >>
            Center.y >>
            Center.z >>
            Radius >>
            r >>
            g >>
            b;
        std::cerr << std::endl << r << " " << g << " " << b << std::endl;
        figureColor.R = (unsigned char)r;
        figureColor.G = (unsigned char)g;
        figureColor.B = (unsigned char)b;
    }

    Box getBoundingBox() const {
        Box result;
        for (int i = 0; i < 3; ++i) {
            result[i][0] = Center[i] - Radius;
            result[i][1] = Center[i] + Radius;
        }
        return result;
    }

    goodFloat getBoundingBox(int dim, int side) const {
        return Center[dim] + (2 * side - 1) * Radius;
    }
};

#endif