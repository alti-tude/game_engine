#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "string"
#include "iostream"

class CustomBaseException{
private:
    static unsigned int count;

    void printCount();
public:
    CustomBaseException(std::string message);
    CustomBaseException(std::string message, std::string cause);
};

class ShaderFileLoadException: public CustomBaseException{
public:
    ShaderFileLoadException(std::string message, std::string cause) 
        :CustomBaseException(message, cause){}
};

class ShaderCompileException: public CustomBaseException{
public:
    ShaderCompileException(std::string message, std::string cause) 
        :CustomBaseException(message, cause){}
};


class ShaderLinkException: public CustomBaseException{
public:
    ShaderLinkException(std::string message, std::string cause) 
        :CustomBaseException(message, cause){}
};

class ComponentNameClashes: public CustomBaseException{
public:
    ComponentNameClashes(std::string message) 
        :CustomBaseException(message){}
};

class ComponentNameNotFound: public CustomBaseException{
public:
    ComponentNameNotFound(std::string message) 
        :CustomBaseException(message){}
};

class BaseNameNotFound: public CustomBaseException{
    public:
        BaseNameNotFound(std::string message)
            :CustomBaseException(message){}
};

class CameraAlreadInitialised: public CustomBaseException{
public:
    CameraAlreadInitialised(std::string message)
        :CustomBaseException(message){}
};

#endif
