#ifndef RT_CONTAINER
#define RT_CONTAINER

#include "../geometry/BasicGeom.hpp"
#include "../scene/IBody.hpp"
#include "../rendering/Image.hpp"
#include <utility>

using namespace BasicGeom;

class Container {
public:
    virtual std::pair<Vector, const IBody *> rayIntersection(const Ray &) const = 0;
    virtual ~Container() {
    };
};

#endif
