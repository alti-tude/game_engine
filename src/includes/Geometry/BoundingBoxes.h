#ifndef BOUNDING_BOXES_H
#define BOUNDING_BOXES_H

#include "glm/glm.hpp"

struct BoundingBox{
    glm::vec2 point;
    glm::vec2 size;

    bool collide(const BoundingBox& b){
        if( point.x + size.x < b.x || b.x + b.size.x < point.x
            || point.y + size.y < b.y || b.y + b.size.y < point.y
        )
            return false;
        return true;
    }
};
#endif