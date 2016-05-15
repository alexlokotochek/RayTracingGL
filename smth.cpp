#include "rendering/Image.hpp"
#include "figures/Triangle.hpp"
#include "scene/Camera.hpp"

int main(int argc, char **argv) {
    Camera camera(Vector(-500, 0, 0),
                  Vector(1000, 0, 0),
                  Vector(0, 1, 0),
                  Vector(0, 0, -1)
    );
    char *lampsFile = argv[1];
    char *sceneFile = argv[2];
    char *outFile = argv[3];
    Scene *scene = new Scene(lampsFile, sceneFile);
    Image image = view(camera, scene, 1500, 1500);
    image.write(outFile);
    delete scene;
    printf("%d\n", steps);
    return 0;
}
