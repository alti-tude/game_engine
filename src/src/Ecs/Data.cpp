#include "Ecs/Data.h"

std::shared_ptr<Data> Data::data_instance = std::shared_ptr<Data>();
std::shared_ptr<Data> Data::getInstance(){
    if(!data_instance)
        data_instance.reset(new Data());
    return data_instance;
}

void Data::addEntity(BaseEntity* entity) {
    this->m_entities.push_back(std::shared_ptr<BaseEntity>(entity));
}

void Data::addCamera(CameraEntity* camera) {
    if(m_camera) 
        throw CameraAlreadInitialised("Camera already initialised in Data object");
    m_camera.reset(camera);
    addEntity(camera);
}

void Data::garbageCollect(){
    std::vector<std::shared_ptr<BaseEntity> > alive_entities;
    for(auto entity: m_entities)
        if(!(entity->shouldDelete()))
            alive_entities.push_back(entity);
    m_entities = alive_entities;
}