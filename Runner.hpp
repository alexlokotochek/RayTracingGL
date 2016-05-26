#ifndef GLIB_RUNNER
#define GLIB_RUNNER

#include "Image.hpp"
#include "scene/Camera.hpp"
#include "reading/ConfigReader.hpp"
#include "reading/RTReader.hpp"
#include <string>

class Runner {
public:

    void RT(int argc, char **argv) {

        int width = atoi(argv[2]);
        int height = atoi(argv[3]);
        std::cerr << width << " " << height << std::endl;
        RTReader reader;
        reader.readRT(std::string(argv[1]));

        Camera camera(reader.position,
                      reader.topLeft,
                      reader.bottomLeft,
                      reader.topRight,
                      width,
                      height);

        Scene *scene = new Scene(reader.lights,
                                 reader.objects);

        Image image = view(camera,
                           scene,
                           width,
                           height);
        image.show(argc, argv);
        delete scene;
    }

    void STL(int argc, char **argv) {

        ConfigReader::read(std::string(argv[1]));

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
    }
};

#endif