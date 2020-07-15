#ifndef SHADER_H
#define SHADER_H

#include "GL/glew.h"
#include "glm/glm.hpp"

#include "fstream"
#include "sstream"
#include "string"

class Shader{
public:
    Shader(const std::string& vertex_file, const std::string& fragment_file);

};

#endif
