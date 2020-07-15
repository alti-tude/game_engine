#ifndef SHADER_H
#define SHADER_H

#include "GL/glew.h"
#include "glm/glm.hpp"

#include "fstream"
#include "sstream"
#include "string"
#include "vector"

class Shader{
    unsigned int m_shader_program_id;
public:
    Shader(const std::string& vertex_file, const std::string& fragment_file);
    void bind() {glUseProgram(m_shader_program_id);}
    void unbind() {glUseProgram(0);}
};

#endif
