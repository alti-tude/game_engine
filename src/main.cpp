#include "iostream"
#include "memory"
#include "vector"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"

#include "Config.h"
#include "Renderer.h"
#include "Window.h"
#include "Shader.h"

#include "Message/Messages.h"
#include "Message/Buffer.h"

#include "Ecs/BaseComponents.h"
#include "Ecs/BaseEntity.h"
#include "Ecs/Systems/RenderSystem.h"
#include "Ecs/Entities/CarEntity.h"
#include "Ecs/Entities/CameraEntity.h"
#include "Ecs/Data.h"


int main(){
    Window window = Window(Config::screen_width, Config::screen_height, "simulator"); //GLFW INIT
    std::shared_ptr<Renderer> renderer = Renderer::getInstance();

    Data::getInstance()->addCamera(new CameraEntity());
    Data::getInstance()->addEntity(new CarEntity());
    Data::getInstance()->addEntity(new CarEntity());
    Data::getInstance()->getEntities()[0]->markForDelete();
    Data::getInstance()->garbageCollect();
    std::static_pointer_cast<CameraEntity::DataComponent>(Data::getInstance()->getCamera()->getComponent("DataComponent"))->rotate(30);
    RenderSystem render_system = RenderSystem();

    while (!window.closed())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        render_system.run();    
        window.swapBuffers();
        window.pollEvents();
    }
    window.terminate();
    
    return 0;
}