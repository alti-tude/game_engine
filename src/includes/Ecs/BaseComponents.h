#ifndef BASE_COMPONENT_H
#define BASE_COMPONENT_H

#include "Geometry/Vertex.h"
#include "Renderer.h"
#include "Shader.h"
#include "Exceptions.h"

#include "Ecs/IBaseEntity.h"

#include "vector"
#include "string"
#include "map"
#include "memory"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


class BaseComponent
{
protected:
    IBaseEntity *m_parent_entity;
    std::string m_base_component_name;

public:
    BaseComponent(){}
    BaseComponent(IBaseEntity *parent_entity, std::string base_component_name)
        : m_parent_entity(parent_entity), m_base_component_name(base_component_name) {}
    virtual ~BaseComponent() {}

    std::string getBaseComponentName() { return this->m_base_component_name; }
    IBaseEntity *getParentEntity() { return this->m_parent_entity; }
    
    BaseComponent* setParentEntity(IBaseEntity* parent_entity) {
        this->m_parent_entity = parent_entity;
        return this;
    }
    BaseComponent* setBaseComponentName(std::string base_component_name) {
        this->m_base_component_name = base_component_name;
        return this;
    }
};

class BaseRenderComponent : public BaseComponent
{
protected:
    std::vector<Vertex> m_vertex_data;
    Shader m_shader;

public:
    BaseRenderComponent(){}
    BaseRenderComponent(IBaseEntity *parent_entity) 
        : BaseComponent(parent_entity, "BaseRenderComponent") {}

    virtual BaseRenderComponent* setVertexData(const std::vector<Vertex>& vertex_data){
        this->m_vertex_data = vertex_data;
        return this;
    }

    virtual void preDraw(glm::mat4 PV);
    void draw();
};

class BaseDataComponent : public BaseComponent
{
protected:
    glm::vec2 m_position;
    glm::mat4 m_rotation;
    glm::mat4 m_scale;
    glm::mat4 m_translation;

public:
    BaseDataComponent(){}
    BaseDataComponent(IBaseEntity *parent_entity) 
        : BaseComponent(parent_entity, "BaseDataComponent"), m_position(glm::vec2(0,0)), m_translation(glm::mat4(1)), m_rotation(glm::mat4(1)), m_scale(glm::mat4(1)) {}

    virtual void scale(glm::vec2 scale);
    virtual void scale(float scale);
    virtual void rotate(float degrees);
    virtual void translateBy(glm::vec2 move_by);
    virtual void translateTo(glm::vec2 move_to);

    glm::vec2 getPosition() { return m_position; }
    glm::mat4 getModelMatrix() { return m_translation * m_rotation * m_scale; }
};

class BaseLogicComponent : public BaseComponent
{
public:
    BaseLogicComponent(){}
    BaseLogicComponent(IBaseEntity *parent_entity) : BaseComponent(parent_entity, "BaseLogicComponent") {}
    virtual void update(unsigned int frame_count) {}
    virtual void collide(IBaseEntity *other_entity) {}
};


#endif