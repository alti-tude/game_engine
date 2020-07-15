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
        throw new ShaderFileLoadException("Some shade file failed to load", e.what());
    }

}

Shader::Shader(const std::string& vertex_file, const std::string& fragment_file){
    ShaderFiles shader_files = loadShaders(vertex_file, fragment_file);
    std::cout << shader_files.vertex_shader << "\n" << shader_files.fragment_shader << std::endl;
}

