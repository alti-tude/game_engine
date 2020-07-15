#include "iostream"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"

#include "Renderer.h"
#include "Window.h"
#include "Shader.h"

int main(){
    
    Window window = Window(800, 600, "simulator"); //GLFW INIT
    Renderer::rendererGlewInit();//GLEW INIT
    Shader shader = Shader("res/Shaders/vertex_shader.vs", "res/Shaders/fragment_shader.fs");
    shader.bind();
    Renderer renderer = Renderer(); 

    float x = -1;
    while (!window.closed())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        std::vector<Vertex> vec;
        Vertex v = {{-1.0f,-1.0f, 0.0f}, {1.0, 0.0f, 0.0f, 1.0f}};
        vec.push_back(v);
        v = {{1.0f,-1.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 1.0f}};
        vec.push_back(v);
        v = {{1.0f,1.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 1.0f}};
        vec.push_back(v);
        v = {{1.0f,1.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 1.0f}};
        vec.push_back(v);
        v = {{-1.0f,-1.0f, 0.0f}, {1.0, 0.0f, 0.0f, 1.0f}};
        vec.push_back(v);
        v = {{-1.0f,1.0f, 0.0f}, {0, 0.0f, 0.0f, 1.0f}};
        vec.push_back(v);

        renderer.startBatch();
        renderer.drawTraingle(vec);
        renderer.endBatch();
        renderer.draw();

        window.swapBuffers();
        window.pollEvents();
    }
    shader.unbind();
    window.terminate();
    return 0;
}