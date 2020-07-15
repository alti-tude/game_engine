#ifndef VERTEX_H
#define VERTEX_H

#include "glm/glm.hpp"

#include "Config.h"

struct Vertex{
    glm::vec3 position;
    glm::vec4 color;

    bool operator==(const Vertex &b) const{
        glm::vec3 delta_position = glm::abs(position-b.position);
        glm::vec4 delta_color = glm::abs(color - b.color);
        return (delta_position.x + delta_position.y + delta_position.z) <= Config::epsilon
            && (delta_color.b + delta_color.g + delta_color.b + delta_color.a) <= Config::epsilon;
    }

    // //required for map and set
    // bool operator<(const Vertex &b) const{
    //     return (position.x-b.position.x) < -Config::epsilon 
    //         || (position.y-b.position.y) < -Config::epsilon
    //         || (position.z-b.position.z) < -Config::epsilon
    //         || (color.r-b.color.r) < -Config::epsilon
    //         || (color.g-b.color.g) < -Config::epsilon
    //         || (color.b-b.color.b) < -Config::epsilon
    //         || (color.a-b.color.a) < -Config::epsilon;
    // }
};

#endif
