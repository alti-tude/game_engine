#include "Ecs/Entities/CameraEntity.h"

CameraEntity::TransformComponent::TransformComponent(unsigned int parent_id)
    : BaseTransformComponent(parent_id) 
{
    up = glm::vec2(0,1);
    P = glm::ortho(-(Config::screen_width/2), Config::screen_width/2, -(Config::screen_height/2), Config::screen_height/2, -(Config::cube_depth/2), Config::cube_depth/2);
}

void CameraEntity::TransformComponent::rotate(float degrees){
    this->baseRotate(degrees);
    up = glm::rotate(up, glm::radians(degrees));
}

glm::mat4 CameraEntity::TransformComponent::getTransformMatrix(){
    glm::mat4 V = glm::lookAt(glm::vec3(m_position, 1), glm::vec3(m_position, 0), glm::vec3(up, 0));
    return P*V;
}