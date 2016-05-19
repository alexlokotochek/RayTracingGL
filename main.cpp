#include "Image.hpp"
#include "scene/Camera.hpp"
#include "reading/ConfigReader.hpp"

int main(int argc, char **argv) {

    std::string config = std::string(argv[1]);

    ConfigReader::read(config);

    Camera camera(ConfigReader::position,
                  ConfigReader::topLeft,
                  ConfigReader::bottomLeft,
                  ConfigReader::topRight,
                  ConfigReader::screenWidth,
                  ConfigReader::screenHeight);

    if (ConfigReader::drawMode == "glut") {

        Scene *scene = new Scene(ConfigReader::lampsFile,
                                 ConfigReader::sceneFile,
                                 ConfigReader::readMode);
        Image image = view(camera,
                           scene,
                           ConfigReader::screenWidth,
                           ConfigReader::screenHeight);
        image.show(argc, argv);
        delete scene;

    } else if (ConfigReader::drawMode == "file"){

        Scene *scene = new Scene(ConfigReader::lampsFile,
                                 ConfigReader::sceneFile,
                                 ConfigReader::readMode);
        Image image = view(camera,
                           scene,
                           ConfigReader::screenWidth,
                           ConfigReader::screenHeight);
        image.write(ConfigReader::outFile);
        delete scene;

    }

    return 0;

}
