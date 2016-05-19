#ifndef GEOMETRY
#define GEOMETRY

#include <cmath>

typedef double goodFloat;

namespace GoodFloat {
    const goodFloat EPS = 1e-9;

    inline bool eq(goodFloat a, goodFloat b) {
        return fabsl(a - b) < EPS;
    }

    inline bool less(goodFloat a, goodFloat b) {
        return a + EPS < b;
    }

    inline bool lessOrEqual(goodFloat a, goodFloat b) {
        return a < b + EPS;
    }

    inline bool greater(goodFloat a, goodFloat b) {
        return less(b, a);
    }

    inline bool greaterOrEqual(goodFloat a, goodFloat b) {
        return lessOrEqual(b, a);
    }

    goodFloat sq(goodFloat a) {
        return a * a;
    }
};

using namespace GoodFloat;

namespace Geometry {

    struct Vector3D {
        goodFloat x, y, z;

        Vector3D();

        Vector3D(goodFloat x, goodFloat y, goodFloat z);

        bool operator==(const Vector3D &a) const;

        bool operator!=(const Vector3D &a) const;

        Vector3D operator-(const Vector3D &a) const;

        Vector3D operator+(const Vector3D &a) const;

        goodFloat operator*(const Vector3D &a) const;

        Vector3D operator%(const Vector3D &a) const;

        Vector3D operator-() const;

        Vector3D operator*(const goodFloat &k) const;

        Vector3D operator/(const goodFloat &k) const;

        goodFloat len() const;

        goodFloat len2() const;

        Vector3D normed() const;

        goodFloat operator[](size_t i) const;
    };

    const Vector3D NONE = Vector3D(1e15, 1e15, 1e15);

    Vector3D::Vector3D() { }

    Vector3D::Vector3D(goodFloat x,
                   goodFloat y,
                   goodFloat z) : x(x), y(y), z(z) { }

    bool Vector3D::operator==(const Vector3D &a) const {
        return eq(x, a.x) && eq(y, a.y) && eq(z, a.z);
    }

    bool Vector3D::operator!=(const Vector3D &a) const {
        return !(operator==(a));
    }

    Vector3D Vector3D::operator-(const Vector3D &a) const {
        return Vector3D(x - a.x, y - a.y, z - a.z);
    }

    Vector3D Vector3D::operator+(const Vector3D &a) const {
        return Vector3D(x + a.x, y + a.y, z + a.z);
    }

    goodFloat Vector3D::operator*(const Vector3D &a) const {
        return x * a.x + y * a.y + z * a.z;
    }

    Vector3D Vector3D::operator%(const Vector3D &a) const {
        return Vector3D(y * a.z - z * a.y,
                      z * a.x - x * a.z,
                      x * a.y - y * a.x);
    }

    Vector3D Vector3D::operator-() const {
        return Vector3D(-x, -y, -z);
    }

    Vector3D Vector3D::operator*(const goodFloat &k) const {
        return Vector3D(x * k, y * k, z * k);
    }

    Vector3D Vector3D::operator/(const goodFloat &k) const {
        if (eq(k, 0.)) {
            return NONE;
        }
        return operator*(1. / k);
    }

    goodFloat Vector3D::len() const {
        return sqrt(operator*(*this));
    }

    goodFloat Vector3D::len2() const {
        return operator*(*this);
    }

    Vector3D Vector3D::normed() const {
        return operator/(len());
    }

    goodFloat Vector3D::operator[](size_t i) const {
        if (i == 0) {
            return x;
        }
        if (i == 1) {
            return y;
        }
        return z;
    }

    bool collinearIfParralel(const Vector3D &a, const Vector3D &b) {
        return greaterOrEqual(a * b, 0.);
    }

    enum ERayConstructor {
        START_DIRECTION,
        START_POINT,
    };

    struct Ray {
        Vector3D start;
        Vector3D direction;
        Ray(const Vector3D &v1, const Vector3D &v2,
            ERayConstructor type=START_DIRECTION) {
            switch(type) {
                case START_DIRECTION:
                    start = v1;
                    direction = v2;
                break; case START_POINT:
                    start = v1;
                    direction = v2 - v1;
                break;
            }
            direction = direction / direction.len();
        }
    };

    struct Plane {
        Vector3D n;
        Vector3D start;

        Plane(const Vector3D &start, const Vector3D &a, const Vector3D &b)
            : start(start) {
            n = a % b;
            n = n / n.len();
        }

        Plane(const Vector3D &start, const Vector3D &n) : start(start) {
            this->n = n.normed();
        }

        goodFloat d() const {
            return -start * n;
        }
    };

    goodFloat det(const Vector3D &a, const Vector3D &b, const Vector3D &c) {
        return a.x * (b.y * c.z - b.z * c.y)
               + a.y * (b.z * c.x - b.x * c.z)
               + a.z * (b.x * c.y - b.y * c.x);
    }

    Vector3D intersect(const Ray &ray, const Plane &plane) {
        Vector3D dir = ray.direction.normed();
        goodFloat denominator = dir * plane.n;
        if (eq(denominator, 0.)) {
            return NONE;
        }
        goodFloat t = -(ray.start * plane.n + plane.d()) / denominator;
        if (greaterOrEqual(t, 0.)) {
            return ray.start + dir * t;;
        }
        return NONE;
    }
};

#endif