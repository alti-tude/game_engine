#ifndef CAMERA_ENTITY_H
#define CAMERA_ENTITY_H

#include "Ecs/BaseComponents.h"
#include "Ecs/BaseEntity.h"

class CameraEntity: public BaseEntity{
private:
    class DataComponent : public BaseDataComponent{
    public:
        DataComponent(BaseEntity* parent_entity)
            : BaseDataComponent(parent_entity)
        {

        }
    };
public:
    CameraEntity()
        :BaseEntity("CameraEntity")
    {
        BaseDataComponent* data_component = new DataComponent(this);
        this->registerComponent("DataComponent", data_component);
    }

};

#endif