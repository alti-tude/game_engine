#ifndef REDER_SYSTEM_H
#define REDER_SYSTEM_H

#include "Ecs/BaseSystem.h"
#include "Ecs/BaseEcsStructures.h"
#include "Renderer.h"

class RenderSystem: BaseSystem{
public:
    RenderSystem(): BaseSystem(){}
    void filter(std::vector<BaseEntity*> entities){
        for(auto entity: entities) 
            if(entity->baseComponentExists("BaseRenderComponent"))
                m_filtererd_entities.push_back(entity);
    }

    void process(){
        for(auto entity: m_filtererd_entities){
            std::vector<std::string>& component_names = entity->getComponentNamesByBasename("BaseRenderComponent");
            for(auto component_name: component_names) {
                std::shared_ptr<BaseRenderComponent> component = entity->getComponent<BaseRenderComponent>(component_name);
                component->preDraw();
                component->draw()
            }
        }
    }
};
#endif