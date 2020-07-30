#ifndef BOUNDING_BOXES_H
#define BOUNDING_BOXES_H

#include "glm/glm.hpp"

struct BoundingBox{
    glm::vec2 point;
    glm::vec2 size;

    bool collide(const BoundingBox *b){
        if( point.x + size.x < b->point.x || b->point.x + b->size.x < point.x
            || point.y + size.y < b->point.y || b->point.y + b->size.y < point.y
        )
            return false;
        return true;
    }
};
#endif