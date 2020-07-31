#include "Ecs/BaseComponents.h"

//TODO return this from transforms so that they can be chained
const std::string BaseTransformComponent::name = "TransformComponent";

void BaseTransformComponent::scale(glm::vec2 scale){
    m_scale = glm::scale(m_scale, glm::vec3(scale, 1));
}

void BaseTransformComponent::scale(float scale){
    this->scale(glm::vec2(scale, scale));
}

void BaseTransformComponent::rotate(float degrees){
    m_rotation = glm::rotate(m_rotation, glm::radians(degrees), glm::vec3(0, 0, 1));
}

void BaseTransformComponent::translateBy(glm::vec2 move_by){
    m_translation = glm::translate(m_translation, glm::vec3(move_by, 1));
    m_position += glm::vec2(move_by);
}

void BaseTransformComponent::translateTo(glm::vec2 move_to){
    translateBy(move_to - m_position);
}