#include "Ecs/Systems/KinematicSystem.h"

void KinematicSystem::process(){
    std::vector<std::shared_ptr<BaseKinematicComponent> > components = Data::getInstance()->getComponents<BaseKinematicComponent>();
    for(auto component: components){
        component->processAcceleration();
        component->processVelocity();
    }
}