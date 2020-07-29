#include "Ecs/Entities/CameraEntity.h"
#include "Ecs/BaseEcsStructures.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace {
    class : public BaseDataComponent{
    private:
        glm::mat4 V;
        glm::mat4 P;
        glm::vec2 up;
    public:
        init()
    };
}