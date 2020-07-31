#include "Shader.h"
#include "Exceptions.h"

struct ShaderFiles{
    std::string vertex_shader;
    std::string fragment_shader;
};

static ShaderFiles loadShaders(const std::string& vertex_file_name, const std::string& fragment_file_name){
    std::ifstream vertex_file;
    std::ifstream fragment_file;

    vertex_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragment_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try{
        vertex_file.open(vertex_file_name.c_str(), std::ios::in);
        fragment_file.open(fragment_file_name.c_str(), std::ios::in);

        std::stringstream vertex_stream;
        std::stringstream fragment_stream;

        vertex_stream << vertex_file.rdbuf();
        fragment_stream << fragment_file.rdbuf();

        vertex_file.close();
        fragment_file.close();

        return {vertex_stream.str(), fragment_stream.str()};
        
    } catch(std::ifstream::failure e){
        throw new ShaderFileLoadException("Some shader file failed to load", e.what());
    }

}

static unsigned int compileShader(const std::string& shader_code, unsigned int shader_type){
    unsigned int shader_id = glCreateShader(shader_type);
    const char* shader_source_pointer = shader_code.c_str();
    glShaderSource(shader_id, 1, &shader_source_pointer, NULL);
    glCompileShader(shader_id);

    int success;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        int err_length;
        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &err_length);
        char log[err_length];
        glGetShaderInfoLog(shader_id, err_length, NULL, log);
        
        throw new ShaderCompileException("Shader compile error", std::string(log));
    };

    return shader_id;
}

static unsigned int linkShaders(const std::vector<unsigned int>& shader_ids){
    unsigned int program_id = glCreateProgram();
    for(auto shader_id: shader_ids) glAttachShader(program_id, shader_id);
    glLinkProgram(program_id);

    int success;
    glGetProgramiv(program_id, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        int err_length;
        glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &err_length);
        char log[err_length];
        glGetShaderInfoLog(program_id, err_length, NULL, log);
        
        throw new ShaderLinkException("Shaders linking error", std::string(log));
    };

    for(auto shader_id: shader_ids) glDeleteShader(shader_id);
    return program_id;
}

Shader::Shader(const std::string& vertex_file, const std::string& fragment_file){
    ShaderFiles shader_files = loadShaders(vertex_file, fragment_file);
    unsigned int vertex_shader_id = compileShader(shader_files.vertex_shader, GL_VERTEX_SHADER);
    unsigned int fragment_shader_id = compileShader(shader_files.fragment_shader, GL_FRAGMENT_SHADER);
    m_shader_program_id = linkShaders(std::vector<unsigned int> {vertex_shader_id, fragment_shader_id});
    bind();
}

void Shader::setMat4(std::string name, glm::mat4 value){
    this->bind();
    unsigned int location = glGetUniformLocation(m_shader_program_id, name.c_str());
    if(location == -1) std::cerr << "Uniform " + name + " not found" << std::endl;
    else glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
}

void Shader::set1f(std::string name, float value){
    this->bind();
    unsigned int location = glGetUniformLocation(m_shader_program_id, name.c_str());
    if(location == -1) std::cerr << "Uniform " + name + " not found" << std::endl;
    else glUniform1f(location, value); 
}
