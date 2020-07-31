#ifndef BASE_SYSTEMS_H
#define BASE_SYSTEMS_H

#include "Ecs/BaseComponents.h"
#include "Ecs/BaseEntity.h"
#include "Data.h"

#include "string"
#include "vector"
#include "memory"

class BaseSystem{
protected:
public:
    BaseSystem(){}
    virtual ~BaseSystem(){}
    virtual void process() = 0;
};
#endif