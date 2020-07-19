#include "Geometry/Vertex.h"
#include "Renderer.h"
#include "Shader.h"
#include "Exceptions.h"

#include "vector"
#include "string"
#include "map"

class BaseEntity{
private:
    std::map<std::string, BaseComponent> m_component_map;
    std::string m_entity_name;
public:
    bool componentExists(std::string component_name){
        return m_component_map.find(component_name) != m_component_map.end();
    }

    template <typename T> T getComponent(std::string component_name){
        if(m_component_map.find(component_name) != m_component_map.end())
            throw ComponentNameNotFound(
                "Component name (" + component_name +") not found for "+m_entity_name+" entity");
        return dynamic_cast<T*> m_component_map[component_name];
    };

    void registerComponent(std::string component_name, BaseComponent component){
        if(m_component_map.find(component_name)!=m_component_map.end()) 
            throw ComponentNameClashes(
                "Component name (" + component_name +") already exists for " +m_entity_name+" entity");
        m_component_map[component_name] = component;    
    }
};

class BaseComponent{
private:
    BaseEntity* m_parent_entity;
    std::string m_component_name;
public:
    BaseComponent(BaseEntity* parent_entity) {this->m_parent_entity = parent_entity;}
    virtual ~BaseComponent(){onDelete();}
    
    std::string getName() {return this->m_component_name;}
    BaseEntity* getParentEntity() {return this->m_parent_entity;}

    virtual void onCreate(){}
    virtual void onDelete(){}

};

class BaseRenderComponent: BaseComponent{
private:
    std::vector<Vertex> m_vertex_data; 
    Shader m_shader;
public:
    BaseRenderComponent(BaseEntity* parent_entity) :BaseComponent(parent_entity){} 

    virtual void initShader() = 0;
    virtual void preDraw() {m_shader.bind();}

    void draw() {
        Renderer* renderer = Renderer::getInstance();
        renderer->startBatch();
        renderer->drawVertices(m_vertex_data);
        renderer->endBatch();
        renderer->draw();
    }
};

class BaseDataComponent: BaseComponent{
private:
    std::vector<BoundingBoxes
}
class BaseLogicComponent: BaseComponent{
public:
    BaseLogicComponent(BaseEntity* parent_entity) :BaseComponent(parent_entity){}
    virtual void update(unsigned int frame_count) = 0;
};