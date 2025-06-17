#include <iostream>
#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#include "quaternion.h"

typedef obj_r::Quaternion quaternion;

int main(){
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 640, "Object Rotation", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    //glew from here


    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        
        glfwPollEvents();
    }

    glfwTerminate();

    quaternion q1(1, 1, 1, 1);
    quaternion q2(2, 2, 2, 2);

    std::cout << q1.getB();
    std::cout << q2.getB();

    return 0;
}