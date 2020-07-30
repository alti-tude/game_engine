#include "Ecs/BaseComponents.h"

void BaseRenderComponent::preDraw(glm::mat4 PV){
    m_shader.bind();
    glm::mat4 M = std::static_pointer_cast<BaseDataComponent>(getParentEntity()->getLastComponentByBasename("BaseDataComponent"))->getModelMatrix();
    m_shader.setMat4("MVP", PV*M);
}

void BaseRenderComponent::draw(){
    Renderer *renderer = Renderer::getInstance();
    renderer->startBatch();
    renderer->drawVertices(m_vertex_data);
    renderer->endBatch();
    renderer->draw();
}

void BaseDataComponent::scale(glm::vec2 scale){
    m_scale = glm::scale(m_scale, glm::vec3(scale, 1));
}

void BaseDataComponent::scale(float scale){
    this->scale(glm::vec2(scale, scale));
}

void BaseDataComponent::rotate(float degrees){
    m_rotation = glm::rotate(m_rotation, glm::radians(degrees), glm::vec3(0, 0, 1));
}

void BaseDataComponent::translateBy(glm::vec2 move_by){
    m_translation = glm::translate(m_translation, glm::vec3(move_by, 1));
    m_position += glm::vec2(move_by);
}

void BaseDataComponent::translateTo(glm::vec2 move_to){
    translateBy(move_to - m_position);
}