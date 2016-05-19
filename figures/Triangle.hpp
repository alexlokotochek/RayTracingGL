#ifndef GLIB_TRIANGLE
#define GLIB_TRIANGLE

#include "Object.hpp"
#include "../Geometry.hpp"
#include <algorithm>
#include <cstdio>

using std::min;
using std::max;

using namespace GoodFloat;
using namespace Geometry;


class Triangle : public Object{
    static const int SIDES = 3;
    Vector3D V[SIDES];
    bool inside(const Vector3D &v) const {
        for (int i = 0; i < SIDES; ++i) {
            if (!collinearIfParralel(
                    (V[(i + 1) % SIDES] - V[i]) % (v - V[i]),
                    (V[(i + 1) % SIDES] - V[i])
                    % (V[(i + 2) % SIDES] - V[i]))) {
                auto x1 = (V[(i + 1) % SIDES] - V[i]) % (v - V[i]);
                auto x2 = (V[(i + 1) % SIDES] - V[i]) % (V[(i + 2) % SIDES] - V[i]);
                int z = 1 + 2;
                return false;
            }
        }
        return true;
    }

    Plane getContainingPlane() const {
        Vector3D dir1 = V[1] - V[0];
        Vector3D dir2 = V[2] - V[0];
        return Plane(V[0], dir1, dir2);
    }
public:
    Triangle() {}

    Triangle(const Vector3D &a, const Vector3D &b, const Vector3D &c) {
        V[0] = a, V[1] = b, V[2] = c;
    }

    static size_t size() {
        return SIDES;
    }

    Vector3D &operator[](size_t i) {
        if (i >= SIDES) {
            throw "triangle only has three sides";
        }
        return V[i];
    }

    Box getBoundingBox() const {
        Box result;
        for (int i = 0; i < 3; ++i) {
            result[i][0] = min(min(V[0][i], V[1][i]), V[2][i]);
            result[i][1] = max(max(V[0][i], V[1][i]), V[2][i]);
        }
        return result;
    }

    goodFloat getBoundingBox(int dim, int side) const {
        if (side == 0) {
            return min(V[0][dim], min(V[1][dim], V[2][dim]));
        } else {
            return max(V[0][dim], max(V[1][dim], V[2][dim]));
        }
    }

    Plane getTangentPlane(const Vector3D &point) const {
        return getContainingPlane();
    }

    Vector3D rayIntersection(const Ray &r) const {
        Plane self = getContainingPlane();
        Vector3D candidate = intersect(r, self);
        if (inside(candidate)) {
            return candidate;
        }
        return NONE;
    }

};

#endif