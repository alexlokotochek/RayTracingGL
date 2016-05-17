#ifndef RT_CAMERA
#define RT_CAMERA

#include "../Image.hpp"
#include "../figures/Figure.hpp"
#include "Scene.hpp"
#include <algorithm>


std::ostream &operator<<(std::ostream &out, Vector const &a) {
    out << "{" << a.x << " " << a.y << " " << a.z << "}";
    return out;
}


class Camera {
    Vector position;
    Vector topLeft;
    Vector bottomLeft;
    Vector topRight;
    Vector xBasis;
    Vector yBasis;
    int width;
    int height;

public:

    const Vector &getPosition() const {
        return position;
    }


    Camera(const Vector &position,
           const Vector &topLeft,
           const Vector &bottomLeft,
           const Vector &topRight,
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

    Vector getPixel(float x, float y) const {
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
