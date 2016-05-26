#ifndef GLIB_SCENE
#define GLIB_SCENE

#include "LightSource.hpp"
#include "../Geometry.hpp"
#include "../KDTree.hpp"
#include "../reading/LightsReader.hpp"
#include <vector>

class Scene {
    std::vector <LightSource> lights;
    KDTree *container;
public:

    Scene(const std::string lightsFile, const std::string figuresFile, const std::string readMode) {
        lights = readLightSources(lightsFile);
        container = new KDTree(figuresFile, readMode);
    }

    Scene (vector<LightSource> &lights_, vector<Object*> &objects) {
        lights = lights_;
        container = new KDTree(objects);

        std::cerr << "lights_size in Scene(): " << lights.size() << std::endl;

    }



    RGB color(const Ray &cameraRay) const {
        auto camViewPoint = container->rayIntersection(cameraRay);
        if (camViewPoint.first != NONE) {
            float increase = 0;
            for (auto &lamp: lights) {
                auto lampPoint
                    = container->rayIntersection(Ray(lamp.position,
                                                     camViewPoint.first,
                                                     START_POINT));
                if (lampPoint == camViewPoint) {
                    Vector3D normal = camViewPoint.second->figure
                                        ->getTangentPlane(camViewPoint.first).n;
                    if (greaterOrEqual(normal * cameraRay.direction, 0.)) {
                        normal = -normal;
                    }
                    double currentIncrease = fabs(lamp.getIncrease(camViewPoint.first,
                                                                  normal));
                    if (greaterOrEqual(currentIncrease, 0.)) {
                        increase += currentIncrease;
                    } else {

                    }
                }
            }
            return camViewPoint.second->properties.color * increase;
        }
        return RGB(0, 0, 0);
    }
    ~Scene() {
        delete container;
    }
};

#endif