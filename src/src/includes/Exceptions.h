#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "string"

class BaseException{
    BaseException(std::string message);
};

class NoGlwfWindowContextException: BaseException{
    NoGlwfWindowContextException() 
        :BaseException("No glfw window context provided to renderer. Call with window argument first")
};
#endif
