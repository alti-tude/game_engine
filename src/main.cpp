#include "iostream"
#include "memory"
#include "vector"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"

#include "Renderer.h"
#include "Window.h"
#include "Shader.h"

#include "Message/Messages.h"
#include "Message/Buffer.h"

#include "Ecs/BaseComponents.h"
#include "Ecs/BaseEntity.h"


int main(){
    std::shared_ptr<Buffer> buffer = Buffer::getInstance();
    buffer->pushMessage(new CarPositionMessage(glm::vec2(1,2)));
    buffer->pushMessage(new CarRandomMessage("random"));
    buffer->pushMessage(new CarPositionMessage(glm::vec2(2,4)));
    buffer->pushMessage(new CarRandomMessage("random2"));
    std::vector<std::shared_ptr<CarRandomMessage> > messages = buffer->getMessages<CarRandomMessage>();
    for(auto msg:messages) std::cout << msg->getMsg() << std::endl;
    // Window window = Window(800, 600, "simulator"); //GLFW INIT
    // Renderer::rendererGlewInit();//GLEW INIT
    // Shader shader = Shader("res/Shaders/vertex_shader.vs", "res/Shaders/fragment_shader.fs");
    // shader.bind();
    // Renderer* renderer = Renderer::getInstance(); 

    // float x = -1;
    // while (!window.closed())
    // {
    //     glClear(GL_COLOR_BUFFER_BIT);

    //     std::vector<Vertex> vec;
    //     Vertex v = {{-1.0f,-1.0f, 0.0f}, {1.0, 0.0f, 0.0f, 1.0f}};
    //     vec.push_back(v);
    //     v = {{1.0f,-1.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 1.0f}};
    //     vec.push_back(v);
    //     v = {{1.0f,1.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 1.0f}};
    //     vec.push_back(v);
    //     v = {{1.0f,1.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 1.0f}};
    //     vec.push_back(v);
    //     v = {{-1.0f,-1.0f, 0.0f}, {1.0, 0.0f, 0.0f, 1.0f}};
    //     vec.push_back(v);
    //     v = {{-1.0f,1.0f, 0.0f}, {0, 0.0f, 0.0f, 1.0f}};
    //     vec.push_back(v);

    //     renderer->startBatch();
    //     renderer->drawVertices(vec);
    //     renderer->endBatch();
    //     renderer->draw();

    //     window.swapBuffers();
    //     window.pollEvents();
    // }
    // shader.unbind();
    // window.terminate();
    return 0;
}