#include "Message/Buffer.h"

std::shared_ptr<Buffer> Buffer::buffer_instance = std::shared_ptr<Buffer>();

std::shared_ptr<Buffer> Buffer::getInstance(){
    if(!buffer_instance){
        buffer_instance.reset(new Buffer());
    }
    return buffer_instance;
}