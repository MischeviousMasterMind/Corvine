#include <iostream>

#include "root/math/corvinemath.hpp"
#include "GL/glut.h"

using namespace corvine;

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.5f, -0.5f);
        glVertex2f( 0.5f,  0.5f);
        glVertex2f(-0.5f,  0.5f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    std::cout << "Hello World!" << std::endl;
    glutInit(&argc, argv);
    glutCreateWindow("Corvine Test");
    glutInitWindowSize(100, 200);
    glutInitWindowPosition(0, 0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}