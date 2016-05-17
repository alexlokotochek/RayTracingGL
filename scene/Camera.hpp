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
    int height;
    int width;
//    Vector direction;
//    Vector xBasis;
//    Vector yBasis;
public:

    const Vector &getPosition() const {
        return position;
    }


    Camera(const Vector &position,
           const Vector &topLeft,
           const Vector &bottomLeft,
           const Vector &topRight,
           int height,
           int width) : position(position),
                        topLeft(topLeft),
                        bottomLeft(bottomLeft),
                        topRight(topRight),
                        height(height),
                        width(width)
    {
        xBasis = (topRight - topLeft) / (float)width;
        yBasis = (bottomLeft - topLeft) / (float)height;
//        std::cerr << topLeft << " " << xBasis << " " << yBasis << std::endl;
    }
//    Camera(const Vector &position,
//           const Vector &direction,
//           const Vector &xBasis,
//           const Vector &yBasis) : position(position),
//                                   direction(direction),
//                                   xBasis(xBasis.normed()),
//                                   yBasis(yBasis.normed()){}
//

    Vector getPixel(float x, float y) const {
//        return position +
//               topLeft +
//               xBasis*x +
//               yBasis*y;
//        if (x == 400 && y == 400) {
//            std::cerr << topLeft << " " << (xBasis*x) << " " << (yBasis*y) << std::endl;
//            std::cerr << "!!! " << topLeft+(xBasis*x)+(yBasis*y) << std::endl;
//        }
        return (topLeft+(xBasis*x)+(yBasis*y));
    }
};

Image view(const Camera &camera,
           const Scene *scene,
           int height,
           int width){

    Image result(width, height);

//    std::pair<int, int> leftmost(0, 0);

    for (int y = 0; y < height; ++y) {

        for (int x = 0; x < width; ++x) {
//
//            if (y == height/2 && x == width/2) {
//                std::cerr << x << " " << y << " " << camera.getPosition() << " | " <<
//                        camera.getPosition() + camera.getPixel(x, y) << std::endl;
//            }

            result(x, y)
                = scene->color(Ray(camera.getPosition(),
                                   camera.getPixel(x, y), START_POINT));

//            auto tmp = result(height / 2 + y, width / 2 + x);
//
//            if (tmp.R != 0 || tmp.G != 0 || tmp.B != 0) {
//                if (x > leftmost.second) {
//                    leftmost = std::make_pair(y, x);
//                }
//            }

        }

    }

    return result;

}

#endif
