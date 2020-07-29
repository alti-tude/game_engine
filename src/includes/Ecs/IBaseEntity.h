#ifndef I_BASE_ENTITY_H
#define I_BASE_ENTITY_H

#include "vector"
#include "string"
#include "memory"

class IBaseEntity{
public:
    virtual bool componentExists(std::string component_name) = 0;
    virtual std::shared_ptr<void> getComponent(std::string component_name) = 0;
    
    virtual bool baseComponentExists(std::string base_component_name) = 0;
    virtual std::shared_ptr<void> getLastComponentByBasename(std::string base_component_name) = 0;
    virtual std::vector<std::string>& getComponentNamesByBasename(std::string base_component_name) = 0;
};

#endif