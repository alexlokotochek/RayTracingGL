#include <iostream>
#include "GlutDrawer.h"

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    GlutDrawer gd;
    gd.startDraw(argc, argv);
}