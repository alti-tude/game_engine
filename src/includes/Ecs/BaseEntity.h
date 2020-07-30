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

    bool componentExists(std::string component_name);
    bool baseComponentExists(std::string base_component_name);
    std::shared_ptr<void> getComponent(std::string component_name);
    std::shared_ptr<void> getLastComponentByBasename(std::string base_component_name);
    std::vector<std::string>& getComponentNamesByBasename(std::string base_component_name);
    void registerComponent(std::string component_name, BaseComponent *component);
};

#endif