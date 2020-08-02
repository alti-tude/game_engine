#ifndef BASE_SYSTEMS_H
#define BASE_SYSTEMS_H

#include "Ecs/BaseComponents.h"
#include "Ecs/BaseEntity.h"
#include "Data.h"

#include "string"
#include "vector"
#include "memory"

class ISystem{
protected:
public:
    virtual ~ISystem(){}
    virtual void process(){};
};
#endif