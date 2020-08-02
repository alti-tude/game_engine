#ifndef CAMERA_ENTITY_H
#define CAMERA_ENTITY_H

#include "Ecs/BaseComponents.h"
#include "Ecs/BaseEntity.h"
#include "Ecs/Data.h"
#include "Config.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/rotate_vector.hpp"

#include "memory"

class CameraEntity: public BaseEntity{
public:
    class TransformComponent : public BaseTransformComponent{
    private:
        glm::vec2 up;
        glm::mat4 P;
    public:
        TransformComponent(unsigned int parent_id);
        void rotate(float degrees);
        glm::mat4 getTransformMatrix();
    };

    CameraEntity(unsigned int id)
        :BaseEntity("CameraEntity")
    {
        this->setId(id);

        unsigned int component_id = Data::getInstance()->registerComponent(new TransformComponent(this->getId()));
        this->addComponent(TransformComponent::name, component_id);
    }
};

#endif