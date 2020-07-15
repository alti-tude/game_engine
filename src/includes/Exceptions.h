#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "string"
#include "iostream"

class CustomBaseException{
public:
    CustomBaseException(std::string message) { std::cerr << message << std::endl; }
    CustomBaseException(std::string message, std::string cause) { 
        std::cerr << message << std::endl;
        std::cerr << ">>>> " << std::endl << cause << std::endl;
    }
};

class ShaderFileLoadException: CustomBaseException{
public:
    ShaderFileLoadException(std::string message, std::string cause) 
        :CustomBaseException(message, cause){};
};

#endif
