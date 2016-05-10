//
// Created by Lokotochek on 11.05.16.
//
#include <iostream>
#include <GLUT/glut.h>

#ifndef RAYTRACINGGL_GLUTDRAWER_H
#define RAYTRACINGGL_GLUTDRAWER_H


class GlutDrawer {

private:

<<<<<<< HEAD
    char* title = new char[16];

    void initGL();
    static void display();
    static void reshape(GLsizei width, GLsizei height);
=======
    char* title;

    void initGL();
    void display();
    void reshape(GLsizei width, GLsizei height);
>>>>>>> origin/master

public:

    GlutDrawer() {
<<<<<<< HEAD
        sprintf(title, "RayTracingGL");
    }

    void startDraw(int &argc, char** argv);
=======
        sprintf(title, "3D Shapes");
    }

    void startDraw();
>>>>>>> origin/master

};


#endif //RAYTRACINGGL_GLUTDRAWER_H
