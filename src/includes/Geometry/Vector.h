#ifndef VECTOR_H
#define VECTOR_H

#include "glm/glm.hpp"
#include "glm/gtx/rotate_vector.hpp"

#include "Config.h"

struct Vector{
    glm::vec2 vec;
    
    void rotate(float degrees){
        vec = glm::rotate(vec, glm::radians(degrees));
    }

    void normalise(){
        assert(glm::length(vec) > Config::epsilon);
        vec = glm::normalize(vec);
    }

    float getLen(){
        return glm::length(vec);
    }
    
};

#endif