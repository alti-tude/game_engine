#ifndef BUFFER_H
#define BUFFER_H

#include "Message/Messages.h"

#include "map"
#include "string"
#include "vector"
#include "memory"

class Buffer{
private:
    static std::shared_ptr<Buffer> buffer_instance;
    std::map<std::string, std::vector<std::shared_ptr<BaseMessage> > > m_message_map;
    //! FIXME why do i need to define(declare + {}) the constructor here
    //!       when I don't have to do that in renderer.
    Buffer(){}

public:
    static std::shared_ptr<Buffer> getInstance(){
        if(!buffer_instance){
            buffer_instance.reset(new Buffer());
        }
        return buffer_instance;
    }

    void pushMessage(BaseMessage* message){
        m_message_map[message->getName()].push_back(std::shared_ptr<BaseMessage>(message));
    }

    template<typename T>
    std::vector<std::shared_ptr<T> > getMessages(){
        std::string name = T::staticGetName();
        std::vector<std::shared_ptr<T> > messages;
        for(auto message: m_message_map[name]) 
            messages.push_back(std::dynamic_pointer_cast<T>(message));
        return messages;
    }
    
    template<typename T>
    bool messageAvailable(){
        return m_message_map[T::staticGetName()] != m_message_map.end();
    }

    void reset(){
        m_message_map.clear();
    }
};
std::shared_ptr<Buffer> Buffer::buffer_instance = std::shared_ptr<Buffer>();

#endif