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
    virtual std::vector<bool> filter() = 0;
    virtual void process(std::vector<bool> filter_mask) = 0;
    void run(){
        std::vector<bool> filter_mask = filter();
        process(filter_mask);
    }
};
#endif