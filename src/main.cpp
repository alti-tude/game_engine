#include "iostream"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Renderer.h"
#include "Window.h"
#include "Shader.h"

int main(){

    Window window = Window(800, 600, "simulator"); //GLFW INIT
    Renderer::rendererGlewInit();//GLEW INIT
    Shader shader = Shader("res/Shaders/vertex_shader.vs", "res/Shaders/fragment_shader.fs");
    shader.bind();
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    Renderer renderer = Renderer(); 
    ImGui_ImplGlfw_InitForOpenGL(window.window, true);
    const char* glsl_version = "#version 330";
    ImGui_ImplOpenGL3_Init(glsl_version);

    static float f = 0.0f;
    static int counter = 0;
    while (!window.closed())
    {

        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("color");               // Display some text (you can use a format strings too)

        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
        ImGui::Render();

        std::vector<Vertex> vec;
        Vertex v = {{-1.0f,-1.0f, 0.0f}, {f, 0.0f, 0.0f, 1.0f}};
        vec.push_back(v);
        v = {{1.0f,-1.0f, 0.0f}, {f, 0.0f, 0.0f, 1.0f}};
        vec.push_back(v);
        v = {{1.0f,1.0f, 0.0f}, {f, 0.0f, 0.0f, 1.0f}};
        vec.push_back(v);
        v = {{1.0f,1.0f, 0.0f}, {f, 0.0f, 0.0f, 1.0f}};
        vec.push_back(v);
        v = {{-1.0f,-1.0f, 0.0f}, {f, 0.0f, 0.0f, 1.0f}};
        vec.push_back(v);
        v = {{-1.0f,1.0f, 0.0f}, {f, 0.0f, 0.0f, 1.0f}};
        vec.push_back(v);
        renderer.startBatch();
        renderer.drawTraingle(vec);
        renderer.endBatch();
        renderer.draw();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        window.swapBuffers();
        window.pollEvents();
    }
    shader.unbind();
    window.terminate();
    return 0;
}