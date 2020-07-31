#ifndef CAR_ENTITY_H
#define CAR_ENTITY_H

#include "Ecs/BaseEntity.h"
#include "Ecs/BaseComponents.h"

class CarEntity : public BaseEntity{
public:
    class DataComponent : public BaseDataComponent{
    public:
        DataComponent(BaseEntity* parent_entity)
            :BaseDataComponent(parent_entity){}
    };

    class RenderComponent: public BaseRenderComponent{
    public:
        RenderComponent(BaseEntity* parent_entity);
    };

    CarEntity()
        :BaseEntity("CarEntity")
    {
        this->registerComponent("DataComponent", new DataComponent(this));
        this->registerComponent("RenderComponent", new RenderComponent(this));
    }
};
#endif