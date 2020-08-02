#ifndef KINEMATIC_SYSTEM_H
#define KINEMATIC_SYSTEM_H

#include "Ecs/BaseComponents.h"
#include "Ecs/BaseEntity.h"
#include "Ecs/ISystem.h"
#include "Ecs/Data.h"

class KinematicSystem : public ISystem{
public:
    void process();
};

#endif