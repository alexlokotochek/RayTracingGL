#include "rendering/Image.hpp"
#include "scene/Camera.hpp"

int main(int argc, char **argv) {

    Camera camera(Vector(-500, 0, 0),
                  Vector(800, 0, 0),
                  Vector(0, 1, 0), // 2 basis for rotate/sjumanie
                  Vector(0, 0, 1) // GLUT: y, FILE: -y
    );

    char *lampsFile = argv[1];
    char *sceneFile = argv[2];
    char *outFile = argv[3];
    Scene *scene = new Scene(lampsFile, sceneFile);
    Image image = view(camera, scene, 800, 800);
//    image.write(outFile);
    image.show(argc, argv);
    delete scene;
    printf("%d\n", steps);
    return 0;
}
