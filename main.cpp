#include "Image.hpp"
#include "scene/Camera.hpp"

// g = glut, f = file
const char drawMode = 'g';
const char readMode = 'a'; // a: ascii stl, b: binary stl

int main(int argc, char **argv) {

//    Camera(
//    const Vector &position,
//    const Vector &topLeft,
//    const Vector &bottomLeft,
//    const Vector &topRight,
//    int height,
//    int width)
    Camera camera(Vector(-200, 0, 0),
                  Vector(-100, -100, 100),
                  Vector(-100, -100, -100), // 2 basis for rotate
                  Vector(-100, 100, 100),
                  800,
                  800);


    char *lampsFile = argv[1];
    char *sceneFile = argv[2];

    if (drawMode == 'f') {

//        char *outFile = argv[3];
//        Scene *scene = new Scene(lampsFile, sceneFile);
//        Image image = view(camera, scene, 800, 800);
//        image.write(outFile);
//        delete scene;

    } else {
        Scene *scene = new Scene(lampsFile, sceneFile, readMode);
        Image image = view(camera, scene, 800, 800);
        image.show(argc, argv);
        delete scene;

    }
    return 0;
}
