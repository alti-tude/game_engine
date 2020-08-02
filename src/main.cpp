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
#include "Ecs/Systems/KinematicSystem.h"
#include "Ecs/Entities/CarEntity.h"
#include "Ecs/Entities/CameraEntity.h"
#include "Ecs/Data.h"

#include "time.h"

int main(){
    Window window = Window(Config::screen_width, Config::screen_height, "simulator"); //GLFW INIT
    std::shared_ptr<Renderer> renderer = Renderer::getInstance();

    for(int i=0;i<1000;i++){
        Data::getInstance()->addEntity<CarEntity>();
    }
    std::cout << "init done" << std::endl;
    Data::getInstance()->addCamera<CameraEntity>();
    RenderSystem render_system = RenderSystem();
    KinematicSystem kinematic_system = KinematicSystem();

    while (!window.closed())
    {
        float st = glfwGetTime();
        glClear(GL_COLOR_BUFFER_BIT);
        kinematic_system.process(); 
        render_system.process();    
        window.swapBuffers();
        window.pollEvents();
        std::cout << 1/(glfwGetTime() - st) << std::endl;
    }
    window.terminate();
    
    return 0;
}