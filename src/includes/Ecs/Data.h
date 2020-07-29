#ifndef DATA_H
#define DATA_H

#include "Ecs/BaseComponents.h"
#include "Ecs/BaseEntity.h"

#include "Exceptions.h"

#include "Ecs/Entities/CameraEntity.h"

#include "memory"
#include "vector"

class Data{
private:
    std::vector<std::shared_ptr<BaseEntity> > m_entities;
    std::shared_ptr<CameraEntity> m_camera;

    static std::shared_ptr<Data> data_instance;
    Data();
public: 
    static std::shared_ptr<Data> getInstance(){
        if(!data_instance)
            data_instance.reset(new Data());
        return data_instance;
    }
    std::vector<std::shared_ptr<BaseEntity> >& getEntities(){return this->m_entities;}
    std::shared_ptr<CameraEntity> getCamera(){return this->m_camera;}
    void addEntity(BaseEntity* entity) {this->m_entities.push_back(std::shared_ptr<BaseEntity>(entity));}
    void addCamera(CameraEntity* camera) {
        if(m_camera) 
            throw CameraAlreadInitialised("Camera already initialised in Data object");
        m_camera.reset(camera);
        addEntity(camera);
    }
};
std::shared_ptr<Data> Data::data_instance = std::shared_ptr<Data>();
#endif