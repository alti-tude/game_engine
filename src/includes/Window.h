#ifndef WINDOW_H
#define WINDOW_H

#include "GLFW/glfw3.h"
#include "iostream"
#include "string"

class Window{
private:
    GLFWwindow* window;
    
public:
    Window(size_t height, size_t width, std::string title);

    bool closed() const {return glfwWindowShouldClose(this->window);} 
    void swapBuffers() {glfwSwapBuffers(this->window);}
    void pollEvents() const {glfwPollEvents();}
    void terminate() const {glfwTerminate();}
    GLFWwindow* getWindow() const {return this->window;}
};

#endif