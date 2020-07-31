#include "Ecs/BaseEntity.h"

void BaseEntity::addComponent(const std::string& component_name, unsigned int idx){
    if (m_component_map.find(component_name) != m_component_map.end())
        throw ComponentNameClashes(
            "Component name (" + component_name + ") already exists for " + this->name + " entity");
    m_component_map[component_name] = idx;
}

bool BaseEntity::componentExists(std::string component_name){
    return m_component_map.find(component_name) != m_component_map.end();
}

unsigned int BaseEntity::getComponentIdx(const std::string& component_name){
    if (m_component_map.find(component_name) == m_component_map.end())
        throw ComponentNameNotFound(
            "Component name (" + component_name + ") not found for " + this->name + " entity");
    return m_component_map[component_name];
}

void BaseEntity::setComponentIdx(const std::string& component_name, unsigned int idx){
    deleteComponent(component_name);
    addComponent(component_name, idx);       
}

void BaseEntity::deleteComponent(const std::string& component_name){
    if (componentExists(component_name))
        m_component_map.erase(component_name);
}

std::vector<std::string> BaseEntity::getComponentNames(){
    std::vector<std::string> names;
    for(auto it:m_component_map) 
        names.push_back(it.first);
    return names;
}  
