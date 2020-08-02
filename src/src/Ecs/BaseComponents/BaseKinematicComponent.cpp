#include "Ecs/BaseComponents.h"
#include "Ecs/Data.h"

const std::string BaseKinematicComponent::name = "BaseKinematicComponent";

void BaseKinematicComponent::processAcceleration(){
    m_velocity += m_acceleration;
}

void BaseKinematicComponent::processVelocity(){
    Data::getInstance()
        ->getComponent<BaseTransformComponent>(this->getParentEntityId())
        ->translateBy(m_velocity);
}

void BaseKinematicComponent::rotateAcceleration(float degrees){
    m_acceleration = glm::rotate(m_acceleration, glm::radians(degrees));
}

void BaseKinematicComponent::rotateVelocity(float degrees){
    m_velocity = glm::rotate(m_velocity, glm::radians(degrees));
}