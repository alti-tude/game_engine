#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include "Ecs/BaseComponents.h"

#include "string"
#include "map"
#include "vector"
#include "memory"

class BaseEntity{
protected:
    std::string name;
    std::map<std::string, unsigned int> m_component_map;
    unsigned int id;
public:
    BaseEntity(){}
    BaseEntity(std::string name)
        :name(name){}
    
    void setId(unsigned int id) {this->id = id;}
    unsigned int getId(){return this->id;}
    virtual void init(unsigned int id){}

    void addComponent(const std::string& component_name, unsigned int idx);
    void setComponentIdx(const std::string& component_name, unsigned int idx);
    void deleteComponent(const std::string& component_name);
    bool componentExists(std::string component_name);
    unsigned int getComponentIdx(const std::string& component_name);
    std::vector<std::string> getComponentNames();
};

#endif