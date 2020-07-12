#ifndef RENDERER_H
#define RENDERER_H

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"

#include "string"
#include "vector"
#include "iostream"

#define GLEW_STATIC
#define GLCall(x) GLClearError();\
    x;\
    assert(GLLogCall(#x, __FILE__, __LINE__));

static void GLClearError(){
    while(glGetError()!=GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* file, int line){
    while(GLenum error = glGetError()){
        std::cout << "[OpenGL Error] (" << error << ")" << std::endl;
        std::cout << function << ": " << file << ":: " << line << std::endl;
        return false;
    }
    return true; 
}
 
static struct Config{
    unsigned int num_vertices;
    unsigned int vertex_size; 

    Config(){
        num_vertices = 10;
    }
} config;

struct Vertex{
    glm::vec3 position;
    // glm::vec4 color;
};

class Renderer{
private:
    unsigned int m_vao_id;
    unsigned int m_vertex_buffer_id;
    unsigned int m_index_buffer_id; 
    unsigned int m_num_vertices;
    
    std::vector<float> m_vertex_data;
    std::vector<unsigned int> m_index_data;

    void initGL();

public:
    Renderer();
    void draw();
    void endBatch();
    void startBatch();
    void drawTraingle(std::vector<Vertex> vertices); 
};

#endif