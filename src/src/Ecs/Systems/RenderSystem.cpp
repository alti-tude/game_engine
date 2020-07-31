#include "Ecs/Systems/RenderSystem.h"

void RenderSystem::process(){
    std::shared_ptr<Data> data = Data::getInstance();
    glm::mat4 PV = 
        data->getComponent<BaseTransformComponent>(data->getCamera()->getId())->getTransformMatrix();
    
    std::vector<std::shared_ptr<BaseRenderComponent> > render_components = 
        data->getComponents<BaseRenderComponent>();

    for(auto render_component: render_components){
        glm::mat4 M = 
            data->getComponent<BaseTransformComponent>(render_component->getParentEntityId())->getTransformMatrix();
        render_component->draw(PV*M);
    }
}