#include "Ecs/BaseComponents.h"

const std::string BaseRenderComponent::name = "RenderComponent";

void BaseRenderComponent::draw(glm::mat4 PVM){
    m_shader.bind();
    m_shader.setMat4("PVM", PVM);
    std::shared_ptr<Renderer> renderer = Renderer::getInstance();
    renderer->drawVertices(m_mesh_data);
}

