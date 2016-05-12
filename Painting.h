//
// Created by Lokotochek on 12.05.16.
//

#ifndef RAYTRACINGGL_PAINTING_H
#define RAYTRACINGGL_PAINTING_H


#include <iostream>
#include <GLUT/glut.h>

#ifndef RAYTRACINGGL_GLUTDRAWER_H
#define RAYTRACINGGL_GLUTDRAWER_H


class GlutDrawer {

private:

    char* title = new char[32];

    void initGL();
    static void display();
    static void reshape(GLsizei width, GLsizei height);

public:

    GlutDrawer() {
        sprintf(title, "RayTracingGL");
    }

    void startDraw(int &argc, char** argv);

};


#endif //RAYTRACINGGL_PAINTING_H
