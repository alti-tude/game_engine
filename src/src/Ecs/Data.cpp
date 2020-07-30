#include "Ecs/Data.h"

void Data::addEntity(BaseEntity* entity) {
    this->m_entities.push_back(std::shared_ptr<BaseEntity>(entity));
}

void Data::addCamera(CameraEntity* camera) {
    if(m_camera) 
        throw CameraAlreadInitialised("Camera already initialised in Data object");
    m_camera.reset(camera);
    addEntity(camera);
}