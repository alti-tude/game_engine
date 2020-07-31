#ifndef VERTEX_H
#define VERTEX_H

#include "glm/glm.hpp"

#include "Config.h"

struct Vertex{
    glm::vec2 position;
    glm::vec4 color;

    bool operator==(const Vertex &b) const{
        glm::vec2 delta_position = glm::abs(position-b.position);
        glm::vec4 delta_color = glm::abs(color - b.color);
        return (delta_position.x + delta_position.y) <= Config::epsilon
            && (delta_color.b + delta_color.g + delta_color.b + delta_color.a) <= Config::epsilon;
    }
};

#endif
