#include "Image.hpp"
#include "scene/Camera.hpp"

// g = glut, f = file

int main(int argc, char **argv) {

    char mode = 'g';


    // spheres
    Camera camera(Vector(-500, 0, 0),
                  Vector(800, 0, 0),
                  Vector(0, 1, 0), // 2 basis for rotate
                  Vector(0, 0, 1) // GLUT: 1, FILE: -1
    );


    // bowl
//        Camera camera(Vector(-300, -300, 300),
//                      Vector(1000, 1000, -1000),
//                      Vector(0, 1, 0), // 2 basis for rotate
//                      Vector(0, 0, 1) // GLUT: 1, FILE: -1
//    );



    char *lampsFile = argv[1];
    char *sceneFile = argv[2];

    if (mode == 'f') {

//        char *outFile = argv[3];
//        Scene *scene = new Scene(lampsFile, sceneFile);
//        Image image = view(camera, scene, 800, 800);
//        image.write(outFile);
//        delete scene;

    } else {
        Scene *scene = new Scene(lampsFile, sceneFile);
        Image image = view(camera, scene, 800, 800);
        image.show(argc, argv);
        delete scene;

    }
    return 0;
}
