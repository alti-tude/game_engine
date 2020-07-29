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
private:
    IBaseEntity *m_parent_entity;
    std::string m_base_component_name;

public:
    BaseComponent(IBaseEntity *parent_entity, std::string base_component_name)
        : m_parent_entity(parent_entity), m_base_component_name(base_component_name) {}
    virtual ~BaseComponent() { onDelete(); }

    std::string getBaseComponentName() { return this->m_base_component_name; }
    IBaseEntity *getParentEntity() { return this->m_parent_entity; }

    virtual void onCreate() {}
    virtual void onDelete() {}
};

class BaseRenderComponent : public BaseComponent
{
private:
    std::vector<Vertex> m_vertex_data;
    Shader m_shader;

public:
    BaseRenderComponent(IBaseEntity *parent_entity) : BaseComponent(parent_entity, "BaseRenderComponent") {}

    virtual void initShader() = 0;
    virtual void preDraw(glm::mat4 PV);
    void draw()
    {
        Renderer *renderer = Renderer::getInstance();
        renderer->startBatch();
        renderer->drawVertices(m_vertex_data);
        renderer->endBatch();
        renderer->draw();
    }
};

class BaseDataComponent : public BaseComponent
{
private:
    glm::vec2 m_position;
    glm::mat4 m_rotation;
    glm::mat4 m_scale;
    glm::mat4 m_translation;

public:
    BaseDataComponent(IBaseEntity *parent_entity) : BaseComponent(parent_entity, "BaseDataComponent") {}

    virtual void scale(glm::vec2 scale)
    {
        m_scale = glm::scale(m_scale, glm::vec3(scale, 1));
    }
    virtual void scale(float scale)
    {
        this->scale(glm::vec2(scale, scale));
    }

    virtual void rotate(float degrees)
    {
        m_rotation = glm::rotate(m_rotation, glm::radians(degrees), glm::vec3(0, 0, 1));
    }

    virtual void translateBy(glm::vec2 move_by)
    {
        m_translation = glm::translate(m_translation, glm::vec3(move_by, 1));
        m_position += glm::vec2(move_by);
    }
    virtual void translateTo(glm::vec2 move_to)
    {
        translateBy(move_to - m_position);
    }

    glm::vec2 getPosition() { return m_position; }
    glm::mat4 getModelMatrix() { return m_translation * m_rotation * m_scale; }
};

class BaseLogicComponent : public BaseComponent
{
public:
    BaseLogicComponent(IBaseEntity *parent_entity) : BaseComponent(parent_entity, "BaseLogicComponent") {}
    virtual void update(unsigned int frame_count) {}
    virtual void collide(IBaseEntity *other_entity) {}
};


#endif