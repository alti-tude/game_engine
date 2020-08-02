#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include "Ecs/ISystem.h"
#include "Ecs/BaseEntity.h"
#include "Ecs/BaseComponents.h"
#include "Ecs/Entities/CameraEntity.h"
#include "Ecs/Data.h"


class RenderSystem : public ISystem{
public:
    void process();
};

#endif