#ifndef RT_CAMERA
#define RT_CAMERA

#include "../Image.hpp"
#include "../figures/Figure.hpp"
#include "Scene.hpp"
#include <algorithm>

class Camera {
    Vector position;
    Vector direction;
    Vector xBasis;
    Vector yBasis;
public:

    const Vector& getPosition() const {
        return position;
    }

    Camera(const Vector &position,
           const Vector &direction,
           const Vector &xBasis,
           const Vector &yBasis) : position(position),
                                   direction(direction),
                                   xBasis(xBasis.normed()),
                                   yBasis(yBasis.normed()){
    }

    Vector getPixel(float x, float y) const {
        return position +
               direction +
               xBasis*x +
               yBasis*y;
    }
};

Image view(const Camera &camera,
           const Scene *scene,
           int height,
           int width){

    Image result(width, height);

    std::pair<int, int> leftmost(-height / 2, -width / 2);

    for (int y = -height / 2; y < height / 2; ++y) {

        for (int x = -width / 2; x < width / 2; ++x) {

            result(height / 2 + y, width / 2 + x)
                = scene->color(Ray(camera.getPosition(),
                                   camera.getPixel(x, y)));

            auto tmp = result(height / 2 + y, width / 2 + x);

            if (tmp.R != 0 || tmp.G != 0 || tmp.B != 0) {
                if (x > leftmost.second) {
                    leftmost = std::make_pair(y, x);
                }
            }

        }

    }

    return result;

}



#endif
