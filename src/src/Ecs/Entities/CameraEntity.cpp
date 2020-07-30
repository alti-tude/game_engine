#include "Ecs/Entities/CameraEntity.h"
#include "Ecs/BaseComponents.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class CameraEntity: public BaseEntity{
private:
    class DataComponent : public BaseDataComponent{
    public:
        DataComponent(BaseEntity* parent_entity)
            : BaseDataComponent(parent_entity)
        {
            
        }
    };
public:
    CameraEntity()
        :BaseEntity("CameraEntity")
    {
        DataComponent* data_component = new DataComponent(this);
        this->registerComponent("DataComponent", data_component);
    }

};