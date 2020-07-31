#include "Window.h"

Window::Window (size_t width, size_t height, std::string title){
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (!glfwInit()) {
        throw GlfwInitException("Glfw failed to initialise");
    }
    
    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!window)
    {
        throw WindowCreationException("Failed to create window");
    }
    glfwMakeContextCurrent(window); 
}


