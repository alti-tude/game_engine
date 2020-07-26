#include "Geometry/Vertex.h"
#include "Renderer.h"
#include "Shader.h"
#include "Exceptions.h"

#include "vector"
#include "string"
#include "map"
#include "memory"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class BaseEntity
{
private:
    std::map<std::string, std::shared_ptr<BaseComponent> > m_component_map;
    std::map<std::string, std::vector<std::string> > m_basename_map;
    std::string m_entity_name;
    bool to_delete;

public:
    BaseEntity() : to_delete(false) {}

    bool componentExists(std::string component_name)
    {
        return m_component_map.find(component_name) != m_component_map.end();
    }
    bool baseComponentExists(std::string base_component_name){
        return m_basename_map.find(base_component_name) != m_basename_map.end();
    }

    template <typename T>
    std::shared_ptr<T> getComponent(std::string component_name)
    {
        if (m_component_map.find(component_name) == m_component_map.end())
            throw ComponentNameNotFound(
                "Component name (" + component_name + ") not found for " + m_entity_name + " entity");
        return std::dynamic_pointer_cast<T>(m_component_map[component_name]);
    };

    std::vector<std::string>& getComponentNamesByBasename(std::string base_component_name)
    {
        if (m_basename_map.find(base_component_name) == m_basename_map.end())
            throw ComponentNameNotFound(
                "Component name (" + base_component_name + ") not found for " + m_entity_name + " entity");
        
        return m_basename_map[base_component_name];
    };

    void registerComponent(std::string component_name, BaseComponent *component)
    {
        if (m_component_map.find(component_name) != m_component_map.end())
            throw ComponentNameClashes(
                "Component name (" + component_name + ") already exists for " + m_entity_name + " entity");
        m_component_map[component_name] = std::make_shared<BaseComponent>(component);
        m_basename_map[component->getBaseComponentName()].push_back(component_name);
    }
};

class BaseComponent
{
private:
    BaseEntity *m_parent_entity;
    std::string m_base_component_name;

public:
    BaseComponent(BaseEntity *parent_entity, std::string base_component_name)
        : m_parent_entity(parent_entity), m_base_component_name(base_component_name) {}
    virtual ~BaseComponent() { onDelete(); }

    std::string getBaseComponentName() { return this->m_base_component_name; }
    BaseEntity *getParentEntity() { return this->m_parent_entity; }

    virtual void onCreate() {}
    virtual void onDelete() {}
};

class BaseRenderComponent : BaseComponent
{
private:
    std::vector<Vertex> m_vertex_data;
    Shader m_shader;

public:
    BaseRenderComponent(BaseEntity *parent_entity) : BaseComponent(parent_entity, "BaseRenderComponent") {}

    virtual void initShader() = 0;
    virtual void preDraw(glm::mat4 VP)
    {
        m_shader.bind();
        glm::mat4 M = getParentEntity()->getComponent<BaseDataComponent>("BaseDataComponent")->getModelMatrix();
        m_shader.setMat4("MVP", M * VP);
    }
    void draw()
    {
        Renderer *renderer = Renderer::getInstance();
        renderer->startBatch();
        renderer->drawVertices(m_vertex_data);
        renderer->endBatch();
        renderer->draw();
    }
};

class BaseDataComponent : BaseComponent
{
private:
    glm::vec2 m_position;
    glm::mat4 m_rotation;
    glm::mat4 m_scale;
    glm::mat4 m_translation;

public:
    BaseDataComponent(BaseEntity *parent_entity) : BaseComponent(parent_entity, "BaseDataComponent") {}

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

class BaseLogicComponent : BaseComponent
{
public:
    BaseLogicComponent(BaseEntity *parent_entity) : BaseComponent(parent_entity, "BaseLogicComponent") {}
    virtual void update(unsigned int frame_count);
    virtual void collide(BaseEntity *other_entity);
};