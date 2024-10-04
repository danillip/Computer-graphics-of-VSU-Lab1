//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//
//using namespace std;
//
//bool isDrawing = false;
//float startX = 0.0f, startY = 0.0f;
//float endX = 0.0f, endY = 0.0f;
//
//float lineColor[3] = { 1.0f, 1.0f, 1.0f };
//float lineColors[][3] = {
//    {1.0f, 1.0f, 0.0f},
//    {0.0f, 0.0f, 1.0f},
//    {1.0f, 0.65f, 0.0f}
//};
//int currentColorIndex = 0;
//
//void renderPrimitives();
//void processInput(GLFWwindow* window);
//void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
//
//int main()
//{
//    if (!glfwInit()) {
//        std::cerr << "Не удалось инициализировать GLFW" << std::endl;
//        return -1;
//    }
//
//    GLFWwindow* window = glfwCreateWindow(800, 600, "Test OpenGL", nullptr, nullptr);
//    if (!window) {
//        std::cerr << "Не удалось создать окно GLFW" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//
//    glfwMakeContextCurrent(window);
//    glfwSetMouseButtonCallback(window, mouseButtonCallback);
//
//    while (!glfwWindowShouldClose(window)) {
//        processInput(window);
//        renderPrimitives();
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glfwDestroyWindow(window);
//    glfwTerminate();
//    return 0;
//}
//
//void renderPrimitives() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
//
//    if (isDrawing) {
//        glColor3f(lineColor[0], lineColor[1], lineColor[2]);
//        glBegin(GL_LINES);
//        glVertex2f(startX, startY);
//        glVertex2f(endX, endY);
//        glEnd();
//    }
//}
//
//void processInput(GLFWwindow* window) {
//    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
//        currentColorIndex = (currentColorIndex + 1) % 3;
//        lineColor[0] = lineColors[currentColorIndex][0];
//        lineColor[1] = lineColors[currentColorIndex][1];
//        lineColor[2] = lineColors[currentColorIndex][2];
//    }
//
//    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
//        currentColorIndex = (currentColorIndex - 1 + 3) % 3;
//        lineColor[0] = lineColors[currentColorIndex][0];
//        lineColor[1] = lineColors[currentColorIndex][1];
//        lineColor[2] = lineColors[currentColorIndex][2];
//    }
//}
//
//void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
//{
//    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
//        double xpos, ypos;
//        glfwGetCursorPos(window, &xpos, &ypos);
//
//        int width, height;
//        glfwGetWindowSize(window, &width, &height);
//        xpos = (xpos / width) * 2.0 - 1.0;
//        ypos = 1.0 - (ypos / height) * 2.0;
//
//        if (!isDrawing) {
//            startX = static_cast<float>(xpos);
//            startY = static_cast<float>(ypos);
//            isDrawing = true;
//        }
//        else {
//            endX = static_cast<float>(xpos);
//            endY = static_cast<float>(ypos);
//            isDrawing = false;
//        }
//    }
//}