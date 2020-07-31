#include "Renderer.h"

std::shared_ptr<Renderer> Renderer::renderer_instance = std::shared_ptr<Renderer>();
std::shared_ptr<Renderer> Renderer::getInstance(){
    if(renderer_instance==NULL) 
        renderer_instance.reset(new Renderer());
    
    return renderer_instance;
}

static void rendererGlewInit(){
    glewExperimental=GL_TRUE; // Needed in core profile
    if(glewInit()!=GLEW_OK){
        throw GlewInitException("Glew Init Error");
        return;
    }
    std::cout << glGetString(GL_VERSION) << std::endl;
}

Renderer::Renderer() 
    :m_num_vertices(Config::num_vertices) 
{   
    rendererGlewInit();

    GLCall(glGenVertexArrays(1, &m_vao_id));
    GLCall(glBindVertexArray(m_vao_id));
    
    GLCall(glGenBuffers(1, &m_vertex_buffer_id));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_vertex_buffer_id));
    GLCall(glBufferData(GL_ARRAY_BUFFER, m_num_vertices*sizeof(Vertex), NULL, GL_DYNAMIC_DRAW));

    GLCall(glGenBuffers(1, &m_index_buffer_id));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_index_buffer_id));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_num_vertices*sizeof(unsigned int), NULL, GL_DYNAMIC_DRAW));

    GLCall(glEnableVertexAttribArray(0));
    GLCall(glVertexAttribPointer(0, sizeof(Vertex::position)/sizeof(float), GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, position)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, sizeof(Vertex::color)/sizeof(float), GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*) offsetof(Vertex, color));

    GLCall(glBindVertexArray(0));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    GLCall(glDisableVertexAttribArray(0));
} 


void Renderer::startBatch(){
    m_vertex_data.clear();
    m_index_data.clear();
    GLCall(glBindVertexArray(0));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

void Renderer::draw(){
    GLCall(glDrawElements(GL_TRIANGLES, m_index_data.size(), GL_UNSIGNED_INT, NULL));
}

void Renderer::endBatch(){
    GLCall(glBindVertexArray(m_vao_id));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_vertex_buffer_id));
    GLCall(glBufferSubData(GL_ARRAY_BUFFER, 0, m_vertex_data.size()*sizeof(float), (const void*)&m_vertex_data[0]));

    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_index_buffer_id));
    GLCall(glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, m_index_data.size()*sizeof(unsigned int), (const void*)&m_index_data[0]));
}

void Renderer::drawVertices(const std::vector<Vertex>& vertices){
    startBatch();
    for(Vertex vertex:vertices){
        if(m_index_data.size()>=m_num_vertices){
            endBatch();
            draw();
            startBatch();
        } 
        m_vertex_data.push_back(vertex.position.x);
        m_vertex_data.push_back(vertex.position.y);
        m_vertex_data.push_back(vertex.color.r);
        m_vertex_data.push_back(vertex.color.g);
        m_vertex_data.push_back(vertex.color.b);
        m_vertex_data.push_back(vertex.color.a);
        m_index_data.push_back(m_index_data.size());
    }
    endBatch();
    draw();
}
