#ifndef CAR_ENTITY_H
#define CAR_ENTITY_H

#include "Ecs/BaseEntity.h"
#include "Ecs/BaseComponents.h"
#include "Ecs/Data.h"

class CarEntity : public BaseEntity{
public:
    class TransformComponent : public BaseTransformComponent{
    public:
        TransformComponent(unsigned int parent_id)
            :BaseTransformComponent(parent_id){}
    };

    class RenderComponent: public BaseRenderComponent{
    public:
        RenderComponent(unsigned int parent_id);
    };

    CarEntity(unsigned int id)
        :BaseEntity("CarEntity")
    {
        this->setId(id);

        unsigned int component_id = Data::getInstance()->registerComponent(new TransformComponent(this->getId()));
        this->addComponent(BaseTransformComponent::name, component_id);
        component_id = Data::getInstance()->registerComponent(new RenderComponent(this->getId()));
        this->addComponent(BaseRenderComponent::name, component_id);
    }
};
#endif