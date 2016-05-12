//
// Created by Lokotochek on 12.05.16.
//

#include "Painting.h"

void GlutDrawer::initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void GlutDrawer::display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glTranslatef(1.5f, 0.0f, -7.0f);

    /// drawing the figures ////////////////////////////////////////////////////////////////////////////////////////////

    glutSwapBuffers();
}

void GlutDrawer::reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void GlutDrawer::startDraw(int &argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(title);
    glutDisplayFunc(GlutDrawer::display);
    glutReshapeFunc(GlutDrawer::reshape);
    initGL();
    glutMainLoop();
}