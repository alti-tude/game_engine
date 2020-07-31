#include "Ecs/BaseComponents.h"

const std::string BaseRenderComponent::name = "RenderComponent";

void BaseRenderComponent::draw(glm::mat4 PVM){
    m_shader.bind();
    m_shader.setMat4("PVM", PVM);
    std::cout << PVM[0][0] << " " << PVM[0][1] << " " << PVM[0][2] << " " << PVM[0][3] << std::endl;
    std::cout << PVM[1][0] << " " << PVM[1][1] << " " << PVM[1][2] << " " << PVM[1][3] << std::endl;
    std::cout << PVM[2][0] << " " << PVM[2][1] << " " << PVM[2][2] << " " << PVM[2][3] << std::endl;
    std::cout << PVM[3][0] << " " << PVM[3][1] << " " << PVM[3][2] << " " << PVM[3][3] << std::endl;
    std::shared_ptr<Renderer> renderer = Renderer::getInstance();
    renderer->drawVertices(m_mesh_data);
}

