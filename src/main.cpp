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

    Data::getInstance()->addEntity<CarEntity>();
    Data::getInstance()->addEntity<CarEntity>();
    Data::getInstance()->removeEntity(1);
    Data::getInstance()->garbageCollect();
    Data::getInstance()->addCamera<CameraEntity>();
    Data::getInstance()->getComponent<BaseTransformComponent>(Data::getInstance()->getCamera()->getId())->translateBy(glm::vec2(200,2));
    RenderSystem render_system = RenderSystem();

    while (!window.closed())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        render_system.process();    
        window.swapBuffers();
        window.pollEvents();
    }
    window.terminate();
    
    return 0;
}