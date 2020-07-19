#ifndef BOUNDING_BOXES_H
#define BOUNDING_BOXES_H

#include "glm/glm.hpp"

struct BoundingBox{
    glm::vec2 point;
    glm::vec2 size;

    bool collide(const BoundingBox& b){
        glm::vec2 right = point + size;
        glm::vec2 b_right = b.point + b.size;
        if( right.y > b.point.y && point.y < b_right.y && 

        )
        return true;
    }
};
#endif