#include "Image.hpp"
#include "scene/Camera.hpp"

// g = glut, f = file
const char drawMode = 'g';
const char readMode = 'a'; // a: ascii stl, b: binary stl

int main(int argc, char **argv) {

//    // spheres
    Camera camera(Vector(-550, 90, 60),
                  Vector(1000, 0, 0),
                  Vector(0, 1, 0), // 2 basis for rotate
                  Vector(0, 0, 1) // GLUT: 1, FILE: -1
    );


//    default (Vector(-150, -150, 250), Vector(1000, 1000, -1000), Vector(0, 1, 0), 001);
//     bowl
//    Camera camera(Vector(-300, -300, 250),
//                  Vector(2000, 2000, -1250),
//                  Vector(0, 1, 0), // 2 basis for rotate
//                  Vector(0, 0, 1) // GLUT: 1, FILE: -1
//    );
//


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
