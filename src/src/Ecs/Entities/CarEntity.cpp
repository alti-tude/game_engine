#include "Ecs/Entities/CarEntity.h"

CarEntity::RenderComponent::RenderComponent(BaseEntity* parent_entity)
    :BaseRenderComponent(parent_entity)
{
    m_shader = Shader();
    m_vertex_data = std::vector<Vertex>({
        { {-100, -100}, {1,0,0,1} },
        { {100, 100}, {1,0,0,1} },
        { {100, -100}, {1,0,0,1} },
        { {-100, -100}, {1,0,0,1} },
        { {-100, 100}, {1,0,0,1} },
        { {100, 100}, {1,0,0,1} },
    });
}
