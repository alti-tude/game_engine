#ifndef BASE_SYSTEMS_H
#define BASE_SYSTEMS_H

#include "Ecs/BaseEcsStructures.h"

#include "string"
#include "vector"

class BaseSystem{
protected:
    std::vector<BaseEntity*> m_filtererd_entities; 
public:
    virtual ~BaseSystem();
    virtual void filter();
    virtual void process()=0;
};
#endif