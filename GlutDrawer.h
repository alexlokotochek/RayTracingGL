//
// Created by Lokotochek on 11.05.16.
//
#include <iostream>
#include <GLUT/glut.h>

#ifndef RAYTRACINGGL_GLUTDRAWER_H
#define RAYTRACINGGL_GLUTDRAWER_H


class GlutDrawer {

private:

    char* title;

    void initGL();
    void display();
    void reshape(GLsizei width, GLsizei height);

public:

    GlutDrawer() {
        sprintf(title, "3D Shapes");
    }

    void startDraw();

};


#endif //RAYTRACINGGL_GLUTDRAWER_H
