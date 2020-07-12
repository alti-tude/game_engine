#include "iostream"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"
#include "Renderer.h"
#include "Window.h"

int main(){
    Window window = Window(800, 600, "simmulator");
    Renderer renderer = Renderer();

    float x = -1;
    while (!window.closed())
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        std::vector<Vertex> vec;
        Vertex v = {{x,-1.0f, 0.0f}};
        vec.push_back(v);
        v = {{x+2,-1.0f, 0.0f}};
        vec.push_back(v);
        v = {{x+1,1.0f, 0.0f}};
        vec.push_back(v);

        renderer.startBatch();
        renderer.drawTraingle(vec);
        renderer.endBatch();
        renderer.draw();

        window.swapBuffers();
        window.pollEvents();
    }

    window.terminate();
    return 0;
}