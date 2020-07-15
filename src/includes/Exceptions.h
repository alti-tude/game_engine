#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "string"
#include "iostream"

class CustomBaseException{
private:
    static unsigned int count;
public:
    CustomBaseException(std::string message) { std::cerr << message << std::endl; }
    CustomBaseException(std::string message, std::string cause) { 
        std::cerr << "Err msg count: " << (++count);
        std::cerr << ">>>> " << std::endl;
        std::cerr << message << std::endl;
        std::cerr << ">>>> " << std::endl;
        std::cerr << cause << std::endl;
    }
};
unsigned int CustomBaseException::count = 0;

class ShaderFileLoadException: CustomBaseException{
public:
    ShaderFileLoadException(std::string message, std::string cause) 
        :CustomBaseException(message, cause){};
};

class ShaderCompileException: CustomBaseException{
public:
    ShaderCompileException(std::string message, std::string cause) 
        :CustomBaseException(message, cause){};
};


class ShaderLinkException: CustomBaseException{
public:
    ShaderLinkException(std::string message, std::string cause) 
        :CustomBaseException(message, cause){};
};
#endif
