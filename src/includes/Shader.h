#ifndef SHADER_H
#define SHADER_H

#include "GL/glew.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "fstream"
#include "sstream"
#include "string"
#include "vector"

class Shader{
private:
    unsigned int m_shader_program_id;
public:
    Shader() :Shader("res/Shaders/defaultVertexShader.vs", "res/Shaders/defaultFragmentShader.fs") {}
    Shader(const std::string& vertex_file, const std::string& fragment_file);

    void bind() {glUseProgram(m_shader_program_id);}
    void unbind() {glUseProgram(0);}
    void setMat4(std::string name, glm::mat4 value);
    void set1f(std::string name, float value);
};

#endif
