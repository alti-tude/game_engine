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
            :BaseTransformComponent(parent_id){
                this->translateBy(glm::vec2(rand()%800-400, rand()%10));
            }
    };

    class RenderComponent: public BaseRenderComponent{
    public:
        RenderComponent(unsigned int parent_id);
    };
    
    class KinematicComponent: public BaseKinematicComponent{
    public:
        KinematicComponent(unsigned int parent_id)
            :BaseKinematicComponent(parent_id){
                this->setVelocity(glm::vec2((rand()%10)/10.0,(rand()%10)/10.0));
                this->setAcceleration(glm::vec2((rand()%10) / 100.0 - 0.05, (rand()%10)/100.0-0.05));
            }
    };

    CarEntity(unsigned int id)
        :BaseEntity("CarEntity")
    {
        this->setId(id);
        
        unsigned int component_id = Data::getInstance()->registerComponent(new TransformComponent(this->getId()));
        this->addComponent(BaseTransformComponent::name, component_id);
        component_id = Data::getInstance()->registerComponent(new RenderComponent(this->getId()));
        this->addComponent(BaseRenderComponent::name, component_id);
        component_id = Data::getInstance()->registerComponent(new KinematicComponent(this->getId()));
        this->addComponent(BaseKinematicComponent::name, component_id);
    }
};
#endif