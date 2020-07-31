#include "Ecs/Systems/RenderSystem.h"

std::vector<bool> RenderSystem::filter(){
    std::vector<bool> mask;
    for(auto entity: Data::getInstance()->getEntities())
        mask.push_back(entity->baseComponentExists("BaseRenderComponent"));
    return mask;
}

void RenderSystem::process(std::vector<bool> filter_mask){
    std::shared_ptr<Data> data = Data::getInstance();
    std::vector<std::shared_ptr<BaseEntity> >& entities = data->getEntities();
    glm::mat4 PV =
        std::static_pointer_cast<CameraEntity::DataComponent>(data->getCamera()->getComponent("DataComponent"))->getPV();
    for(int i=0;i<entities.size();i++)
        if(filter_mask[i]) {
            std::shared_ptr<BaseRenderComponent> render_component = 
                std::static_pointer_cast<BaseRenderComponent>(entities[i]->getLastComponentByBasename("BaseRenderComponent"));
            render_component->preDraw(PV);
            render_component->draw();
        }
}