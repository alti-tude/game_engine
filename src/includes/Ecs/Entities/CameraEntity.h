#ifndef CAMERA_ENTITY_H
#define CAMERA_ENTITY_H

#include "Ecs/BaseComponents.h"
#include "Ecs/BaseEntity.h"
#include "Config.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


class CameraEntity: public BaseEntity{
public:
    class DataComponent : public BaseDataComponent{
    private:
        glm::vec2 up;
        glm::mat4 P;
    public:
        DataComponent(BaseEntity* parent_entity);
        void rotate(float degrees);
        glm::mat4 getPV();
    };

    CameraEntity()
        :BaseEntity("CameraEntity")
    {
        this->registerComponent("DataComponent", new DataComponent(this));
    }
};

#endif