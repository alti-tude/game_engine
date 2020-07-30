#ifndef MESSAGES_H
#define MESSAGES_H

#include "glm/glm.hpp"

#include "string"

class BaseMessage{
public:
    virtual ~BaseMessage(){}

    virtual std::string getName() = 0;
};

class CarPositionMessage: public BaseMessage{
private: 
    static const std::string name;
    glm::vec2 position;
public:
    CarPositionMessage();
    CarPositionMessage(glm::vec2 position): position(position) {}

    std::string getName(){return name;}
    static std::string staticGetName(){return name;}

    glm::vec2 getPosition(){return position;}
    CarPositionMessage* setPosition(glm::vec2 position){
        this->position = position;
        return this;
    }
};

class CarRandomMessage: public BaseMessage{
private: 
    static const std::string name;
    std::string msg;
public:
    CarRandomMessage();
    CarRandomMessage(std::string msg): msg(msg) {}

    std::string getName(){return name;}
    static std::string staticGetName(){return name;}
    
    std::string getMsg(){return msg;}
    CarRandomMessage* setMsg(std::string msg){
        this->msg = msg;
        return this;
    }
};

#endif