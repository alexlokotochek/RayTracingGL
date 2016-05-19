#ifndef GLIB_OBJECT
#define GLIB_OBJECT

#include "../Geometry.hpp"
#include <algorithm>

using namespace Geometry;

using std::min;
using std::max;

class Box {
public:

    goodFloat bounds[3][2];

    goodFloat* operator[](size_t i) {
        return bounds[i];
    }

    ~Box() {}

    const goodFloat* operator[](size_t i) const {
        return bounds[i];
    }

    bool intersects(const Ray &ray) const {

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 2; ++j) {
                goodFloat t;
                if (eq(ray.direction[i], 0.)) {
                    if (eq(ray.start[i], bounds[i][j])) {
                        t = 0;
                    }
                    else {
                        continue;
                    }
                } else {
                    t = (bounds[i][j] - ray.start[i]) / ray.direction[i];
                }
                if (less(t, 0.)) {
                    continue;
                }
                Vector3D candidate = ray.start + ray.direction * t;
                bool fail = false;
                for (int k = 1; k < 3; ++k) {
                    if (!(less(bounds[(i + k) % 3][0],
                               candidate[(i + k) % 3]) &&
                          less(candidate[(i + k) % 3],
                               bounds[(i + k) % 3][1]))) {
                        fail = true;
                    }
                }
                if (!fail) {
                    return true;
                }
            }
        }
        return false;
    }
};

Box operator|(const Box &a, const Box &b) {
    Box result;
    for (int i = 0; i < 3; ++i) {
        result[i][0] = min(a[i][0], b[i][0]);
        result[i][1] = max(a[i][1], b[i][1]);
    }
    return result;
}

bool isInside(const Box &a, const Box &b) {
    for (int i = 0; i < 3; ++i) {
        if (!isInside(a, b)) {
            return false;
        }
    }
    return true;
}

struct Object {

    RGB figureColor = RGB(120, 100, 90);

    virtual Vector3D rayIntersection(const Ray &r) const = 0;
    virtual Plane getTangentPlane(const Vector3D &point) const = 0;
    virtual Box getBoundingBox() const = 0;
    virtual goodFloat getBoundingBox(int dim, int side) const {
        return getBoundingBox()[dim][side];
    }

    virtual ~Object() {}

};

#endif