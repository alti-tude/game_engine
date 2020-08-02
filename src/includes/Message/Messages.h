#ifndef MESSAGES_H
#define MESSAGES_H

#include "glm/glm.hpp"

#include "string"

class BaseMessage{
public:
    virtual ~BaseMessage(){}
};

class CarPositionMessage: public BaseMessage{
private: 
    glm::vec2 position;
public:
    static const std::string name;
    CarPositionMessage();
    CarPositionMessage(glm::vec2 position): position(position) {}

    glm::vec2 getPosition(){return position;}
    CarPositionMessage* setPosition(glm::vec2 position){
        this->position = position;
        return this;
    }
};

class CarRandomMessage: public BaseMessage{
private: 
    std::string msg;
public:
    static const std::string name;
    CarRandomMessage();
    CarRandomMessage(std::string msg): msg(msg) {}

    std::string getMsg(){return msg;}
    CarRandomMessage* setMsg(std::string msg){
        this->msg = msg;
        return this;
    }
};

#endif