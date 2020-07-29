#include "Exceptions.h"

unsigned int CustomBaseException::count = 0;

void CustomBaseException::printCount(){
    std::cerr << "Err msg count: " << (++count);
    std::cerr << ">>>> " << std::endl;
}

CustomBaseException::CustomBaseException(std::string message){ 
    printCount();
    std::cerr << message << std::endl; 
    std::cerr << ">>>> " << std::endl;
}

CustomBaseException::CustomBaseException(std::string message, std::string cause) { 
    printCount();
    std::cerr << message << std::endl;
    std::cerr << ">>>> " << std::endl;
    std::cerr << cause << std::endl;
    std::cerr << ">>>> " << std::endl;
}