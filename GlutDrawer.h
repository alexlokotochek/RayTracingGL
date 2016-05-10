//
// Created by Lokotochek on 11.05.16.
//
#include <iostream>
#include <GLUT/glut.h>

#ifndef RAYTRACINGGL_GLUTDRAWER_H
#define RAYTRACINGGL_GLUTDRAWER_H


class GlutDrawer {

private:

    char* title = new char[16];

    void initGL();
    static void display();
    static void reshape(GLsizei width, GLsizei height);

public:

    GlutDrawer() {
        sprintf(title, "RayTracingGL");
    }

    void startDraw(int &argc, char** argv);

};


#endif //RAYTRACINGGL_GLUTDRAWER_H
