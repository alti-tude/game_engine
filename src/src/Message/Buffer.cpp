#include "Message/Buffer.h"

std::shared_ptr<Buffer> Buffer::buffer_instance = std::shared_ptr<Buffer>();

std::shared_ptr<Buffer> Buffer::getInstance(){
    if(!buffer_instance){
        buffer_instance.reset(new Buffer());
    }
    return buffer_instance;
}

void Buffer::pushMessage(BaseMessage* message){
    m_message_map[message->getName()].push_back(std::shared_ptr<BaseMessage>(message));
}