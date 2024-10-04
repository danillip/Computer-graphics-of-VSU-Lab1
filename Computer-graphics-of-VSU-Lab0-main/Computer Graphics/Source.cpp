#include <GLFW/glfw3.h>
#include "Box.h"
#include <iostream>

Box box(100, 200, 150); // Создаем квадрат

void renderPrimitives();
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);

int main()
{
    if (!glfwInit()) {
        std::cerr << "Не удалось инициализировать GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Test OpenGL", nullptr, nullptr);
    if (!window) {
        std::cerr << "Не удалось создать окно GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

        renderPrimitives();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void renderPrimitives() {
    box.draw();
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    int windowHeight;
    glfwGetWindowSize(window, nullptr, &windowHeight);
    ypos = windowHeight - ypos; // Инвертируем координаты Y

    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        if (box.isInnerPoint(static_cast<int>(xpos), static_cast<int>(ypos))) {
            box.startDragging(static_cast<int>(xpos), static_cast<int>(ypos));
        }
        else {
            box.moveTo(static_cast<int>(xpos), static_cast<int>(ypos));
        }
    }

    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
        box.stopDragging();
    }
}

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
    int windowHeight;
    glfwGetWindowSize(window, nullptr, &windowHeight);
    ypos = windowHeight - ypos; // Инвертируем координаты Y

    if (box.isDragging()) {
        box.drag(static_cast<int>(xpos), static_cast<int>(ypos));
    }
}