#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include "Ecs/BaseSystem.h"
#include "Ecs/BaseEntity.h"
#include "Ecs/BaseComponents.h"
#include "Ecs/Entities/CameraEntity.h"
#include "Ecs/Data.h"


class RenderSystem : public BaseSystem{
public:
    void process();
};

#endif