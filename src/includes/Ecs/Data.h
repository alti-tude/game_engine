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
    Data(){};
public: 
    static std::shared_ptr<Data> getInstance();

    std::vector<std::shared_ptr<BaseEntity> >& getEntities(){return this->m_entities;}
    std::shared_ptr<CameraEntity> getCamera(){return this->m_camera;}
    void addEntity(BaseEntity* entity);
    void addCamera(CameraEntity* camera);
    void garbageCollect();
};
#endif