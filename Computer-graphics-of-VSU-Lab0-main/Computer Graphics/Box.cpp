#include "Box.h"
#include <GLFW/glfw3.h>

Box::Box(int size, int offsetX, int offsetY) :
    Figure(size, offsetX, offsetY)
{
}

void Box::draw()
{
    int windowWidth, windowHeight;
    glfwGetWindowSize(glfwGetCurrentContext(), &windowWidth, &windowHeight);

    float left = 2.0f * m_offsetX / windowWidth - 1.0f;
    float right = 2.0f * (m_offsetX + m_size) / windowWidth - 1.0f;
    float top = 2.0f * (m_offsetY + m_size) / windowHeight - 1.0f;
    float bottom = 2.0f * m_offsetY / windowHeight - 1.0f;


    glBegin(GL_QUADS);
    glVertex2f(left, bottom);
    glVertex2f(right, bottom);
    glVertex2f(right, top);
    glVertex2f(left, top);
    glEnd();
}

bool Box::isInnerPoint(int x, int y)
{
    return (x >= m_offsetX && x <= m_offsetX + m_size &&
        y >= m_offsetY && y <= m_offsetY + m_size);
}