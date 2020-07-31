#include "Ecs/Entities/CarEntity.h"

CarEntity::RenderComponent::RenderComponent(unsigned int parent_id)
    :BaseRenderComponent(parent_id)
{
    m_shader = Shader();
    m_mesh_data = std::vector<Vertex>({
        { {-100, -100}, {1,0,0,1} },
        { {100, 100}, {1,0,0,1} },
        { {100, -100}, {1,0,0,1} },
        { {-100, -100}, {1,0,0,1} },
        { {-100, 100}, {1,0,0,1} },
        { {100, 100}, {1,0,0,1} },
    });
}

