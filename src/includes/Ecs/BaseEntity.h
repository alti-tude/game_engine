#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include "Ecs/BaseComponents.h"
#include "Ecs/IBaseEntity.h"

#include "string"
#include "map"
#include "vector"
#include "memory"

class BaseEntity : public IBaseEntity{
private:
    std::map<std::string, std::shared_ptr<BaseComponent> > m_component_map;
    std::map<std::string, std::vector<std::string> > m_basename_map;
    std::string m_entity_name;
    bool to_delete;

public:
    BaseEntity() : to_delete(false), m_entity_name("BaseEntity") {}
    BaseEntity(std::string name) : to_delete(false), m_entity_name(name) {}
    virtual ~BaseEntity(){}

    bool componentExists(std::string component_name)
    {
        return m_component_map.find(component_name) != m_component_map.end();
    }
    bool baseComponentExists(std::string base_component_name){
        return m_basename_map.find(base_component_name) != m_basename_map.end();
    }

    std::shared_ptr<void> getComponent(std::string component_name)
    {
        if (m_component_map.find(component_name) == m_component_map.end())
            throw ComponentNameNotFound(
                "Component name (" + component_name + ") not found for " + m_entity_name + " entity");
        return std::static_pointer_cast<void>(m_component_map[component_name]);
    };

    std::shared_ptr<void> getLastComponentByBasename(std::string base_component_name)
    {
        if (m_basename_map.find(base_component_name) == m_basename_map.end())
            throw BaseNameNotFound(
                "Component name (" + base_component_name + ") not found for " + m_entity_name + " entity");
        return std::static_pointer_cast<void>(m_component_map[m_basename_map[base_component_name].back()]);
    };

    std::vector<std::string>& getComponentNamesByBasename(std::string base_component_name)
    {
        if (m_basename_map.find(base_component_name) == m_basename_map.end())
            throw BaseNameNotFound(
                "Component name (" + base_component_name + ") not found for " + m_entity_name + " entity");
        return m_basename_map[base_component_name];
    };

    void registerComponent(std::string component_name, BaseComponent *component)
    {
        if (m_component_map.find(component_name) != m_component_map.end())
            throw ComponentNameClashes(
                "Component name (" + component_name + ") already exists for " + m_entity_name + " entity");
        m_component_map[component_name] = std::shared_ptr<BaseComponent>(component);
        m_basename_map[component->getBaseComponentName()].push_back(component_name);
    }
};

#endif