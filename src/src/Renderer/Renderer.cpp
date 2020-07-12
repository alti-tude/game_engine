#include "Renderer.h"


Renderer::Renderer() 
    :m_num_vertices(config.num_vertices) 
{    
    glewExperimental=GL_TRUE; // Needed in core profile
    if(glewInit()!=GLEW_OK){
        std::cerr << "Glew Init Error\n";
        glfwTerminate();
        return;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    GLCall(glGenVertexArrays(1, &m_vao_id));
    GLCall(glBindVertexArray(m_vao_id));
    
    GLCall(glGenBuffers(1, &m_vertex_buffer_id));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_vertex_buffer_id));
    GLCall(glBufferData(GL_ARRAY_BUFFER, m_num_vertices*sizeof(Vertex), NULL, GL_DYNAMIC_DRAW));

    GLCall(glGenBuffers(1, &m_index_buffer_id));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_index_buffer_id));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_num_vertices*sizeof(unsigned int), NULL, GL_DYNAMIC_DRAW));

    GLCall(glEnableVertexAttribArray(0));
    GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) 0));
    // glEnableVertexAttribArray(1);
    // glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, color));

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

void Renderer::drawTraingle(std::vector<Vertex> vertices){
    for(Vertex vertex:vertices){
        if(m_index_data.size()>=m_num_vertices){
            endBatch();
            draw();
            startBatch();
        } 
        m_vertex_data.push_back(vertex.position.x);
        m_vertex_data.push_back(vertex.position.y);
        m_vertex_data.push_back(vertex.position.z);
        // m_vertex_data.push_back(vertex.color.r);
        // m_vertex_data.push_back(vertex.color.g);
        // m_vertex_data.push_back(vertex.color.b);
        // m_vertex_data.push_back(vertex.color.a);

        m_index_data.push_back(m_index_data.size());
    }
}
