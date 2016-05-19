#ifndef GLIB_CAMERA
#define GLIB_CAMERA

#include "../Image.hpp"
#include "../figures/Object.hpp"
#include "Scene.hpp"
#include <algorithm>


std::ostream &operator<<(std::ostream &out, Vector3D const &a) {
    out << "{" << a.x << " " << a.y << " " << a.z << "}";
    return out;
}


class Camera {
    Vector3D position;
    Vector3D topLeft;
    Vector3D bottomLeft;
    Vector3D topRight;
    Vector3D xBasis;
    Vector3D yBasis;
    int width;
    int height;

public:

    const Vector3D &getPosition() const {
        return position;
    }


    Camera(const Vector3D &position,
           const Vector3D &topLeft,
           const Vector3D &bottomLeft,
           const Vector3D &topRight,
           int width,
           int height) : position(position),
                        topLeft(topLeft),
                        bottomLeft(bottomLeft),
                        topRight(topRight),
                        width(width),
                        height(height)
    {
        xBasis = (topRight - topLeft) / (float)width;
        yBasis = (bottomLeft - topLeft) / (float)height;
    }

    Vector3D getPixel(float x, float y) const {
        return (topLeft+(xBasis*x)+(yBasis*y));
    }
};

Image view(const Camera &camera,
           const Scene *scene,
           int width,
           int height){

    Image result(width, height);


    for (int y = 0; y < height; ++y) {

        for (int x = 0; x < width; ++x) {

            result(y, x)
                = scene->color(Ray(camera.getPosition(),
                                   camera.getPixel(x, y), START_POINT));

        }

    }

    return result;

}

#endif