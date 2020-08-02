#include "Ecs/Data.h"

std::shared_ptr<Data> Data::data_instance = std::shared_ptr<Data>();
std::shared_ptr<Data> Data::getInstance(){
    if(!data_instance)
        data_instance.reset(new Data());
    return data_instance;
}

void Data::deleteComponent(const std::string& name, unsigned int idx){
    m_entities[m_component_lists[name][idx]->getParentEntityId()]->deleteComponent(name);
    swap(m_component_lists[name][idx], m_component_lists[name].back());
    m_component_lists[name].pop_back();
    
    //change the parent of the component to point to the new index
    if(idx<m_component_lists[name].size())
        m_entities[m_component_lists[name][idx]->getParentEntityId()]->setComponentIdx(name, idx);
}

void Data::deleteEntity(unsigned int idx){
    for(auto component_name: m_entities[idx]->getComponentNames())
        deleteComponent(component_name, m_entities[idx]->getComponentIdx(component_name));
    
    swap(m_entities[idx], m_entities.back());
    swap(m_entities_to_delete[idx], m_entities_to_delete.back());
    m_entities.pop_back();
    
    //change components of the entity to point to new index
    if(idx<m_entities.size()){
        for(auto component_name: m_entities[idx]->getComponentNames())
            m_component_lists[component_name][m_entities[idx]->getComponentIdx(component_name)]->setParentEntityId(idx);
        m_entities[idx]->setId(idx);
    }
}

void Data::removeEntity(unsigned int idx){
    if (idx>=this->m_entities.size())
        throw InvalidEntityIdx("Index >= num entities");
    this->m_entities_to_delete[idx] = 1;
}

void Data::garbageCollect(){
    for(int i=0;i<m_entities.size();){
        if(m_entities_to_delete[i]) 
            deleteEntity(i);
        else
            i++;
    }
}