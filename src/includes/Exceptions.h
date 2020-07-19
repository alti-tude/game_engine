#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "string"
#include "iostream"

class CustomBaseException{
private:
    static unsigned int count;

    void printCount(){
        std::cerr << "Err msg count: " << (++count);
        std::cerr << ">>>> " << std::endl;
    }
public:
    CustomBaseException(std::string message) { 
        printCount();
        std::cerr << message << std::endl; 
        std::cerr << ">>>> " << std::endl;
    }
    CustomBaseException(std::string message, std::string cause) { 
        printCount();
        std::cerr << message << std::endl;
        std::cerr << ">>>> " << std::endl;
        std::cerr << cause << std::endl;
        std::cerr << ">>>> " << std::endl;
    }
};
unsigned int CustomBaseException::count = 0;

class ShaderFileLoadException: CustomBaseException{
public:
    ShaderFileLoadException(std::string message, std::string cause) 
        :CustomBaseException(message, cause){}
};

class ShaderCompileException: CustomBaseException{
public:
    ShaderCompileException(std::string message, std::string cause) 
        :CustomBaseException(message, cause){}
};


class ShaderLinkException: CustomBaseException{
public:
    ShaderLinkException(std::string message, std::string cause) 
        :CustomBaseException(message, cause){}
};

class ComponentNameClashes: CustomBaseException{
public:
    ComponentNameClashes(std::string message) 
        :CustomBaseException(message){}
};

class ComponentNameNotFound: CustomBaseException{
public:
    ComponentNameNotFound(std::string message) 
        :CustomBaseException(message){}
};
#endif
