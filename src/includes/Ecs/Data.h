#ifndef DATA_H
#define DATA_H

#include "Ecs/BaseComponents.h"
#include "Ecs/BaseEntity.h"

#include "Exceptions.h"

#include "memory"
#include "vector"
#include "map"

class Data{
private:
    std::map<std::string, std::vector<std::shared_ptr<BaseComponent> > > m_component_lists;
    std::vector<std::shared_ptr<BaseEntity> > m_entities;
    std::vector<bool> m_entities_to_delete;
    std::shared_ptr<BaseEntity> m_camera;

    unsigned int m_frame_count;
    static std::shared_ptr<Data> data_instance;
    Data():m_frame_count(0){};
public: 
    static std::shared_ptr<Data> getInstance();

    std::vector<std::shared_ptr<BaseEntity> >& getEntities(){return this->m_entities;}
    std::shared_ptr<BaseEntity> getCamera(){return this->m_camera;}
    template<typename T>
    void addEntity(){
        this->m_entities.push_back(std::shared_ptr<BaseEntity>(new T(this->m_entities.size())));
        this->m_entities_to_delete.push_back(0);
    }
    template<typename T>
    void addCamera(){
        if(m_camera) 
            throw CameraAlreadInitialised("Camera already initialised in Data object");
        addEntity<T>();
        m_camera = m_entities.back();
    }

    template<typename T>
    std::vector<std::shared_ptr<T> > getComponents(){
        std::vector<std::shared_ptr<T> > components;
        for(auto component: m_component_lists[T::name]){
            components.push_back(std::static_pointer_cast<T>(component));
        }
        return components;
    }
    template<typename T>
    unsigned int registerComponent(T* component){
        m_component_lists[T::name].push_back(std::shared_ptr<T>(component));
        return m_component_lists[T::name].size()-1;
    }
    template<typename T> 
    std::shared_ptr<T> getComponent(unsigned int entity_id){
        unsigned int component_id = m_entities[entity_id]->getComponentIdx(T::name);
        return std::static_pointer_cast<T>(m_component_lists[T::name][component_id]);
    }
    //TODO add removeComponent with template
    void deleteComponent(const std::string& name, unsigned int idx);
    void deleteEntity(unsigned int idx);
    void removeEntity(unsigned int idx);
    void garbageCollect();

    unsigned int getFrameCount(){return this->m_frame_count;}
    void tick(){this->m_frame_count++;}
};
#endif