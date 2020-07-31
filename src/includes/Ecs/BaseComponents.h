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

class BaseComponent{
protected:
    unsigned int m_parent_entity_id;
    unsigned int m_component_id;
public:
    BaseComponent(unsigned int parent_id)
        :m_parent_entity_id(parent_id){}
    BaseComponent(){}
    virtual ~BaseComponent(){}

    void setParentEntityId(unsigned int id){this->m_parent_entity_id = id;}
    unsigned int getParentEntityId() {return this->m_parent_entity_id;}
};

class BaseRenderComponent: public BaseComponent{
protected:
    Shader m_shader;
    std::vector<Vertex> m_mesh_data;
public:
    static const std::string name;

    BaseRenderComponent(){initShader();}
    BaseRenderComponent(unsigned int parent_id)
        : BaseComponent(parent_id){initShader();}
    virtual void initShader(){m_shader = Shader();}
    virtual void draw(glm::mat4 PVM);
};

class BaseTransformComponent: public BaseComponent{
protected:
    glm::vec2 m_position;
    glm::mat4 m_rotation;
    glm::mat4 m_translation;
    glm::mat4 m_scale;
public:
    static const std::string name;
    
    BaseTransformComponent(){}
    BaseTransformComponent(unsigned int parent_id)
        :BaseComponent(parent_id), m_rotation(glm::mat4(1)), m_translation(glm::mat4(1)), m_scale(glm::mat4(1)){}
    virtual void scale(glm::vec2 scale);
    virtual void scale(float scale);
    virtual void rotate(float degrees);
    virtual void translateBy(glm::vec2 move_by);
    virtual void translateTo(glm::vec2 move_to);
    virtual glm::mat4 getTransformMatrix(){return m_translation*m_rotation*m_scale;}
};

class BaseLogicComponent: public BaseComponent{
public:
    static const std::string name;

    BaseLogicComponent(){}
    BaseLogicComponent(unsigned int parent_id)
        :BaseComponent(parent_id){}
    virtual void process(unsigned int frame_count){}    
};

#endif