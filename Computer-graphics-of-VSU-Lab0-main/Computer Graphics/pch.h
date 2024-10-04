#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>


void setupProjection(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);  // Координаты окна
    glMatrixMode(GL_MODELVIEW);
}