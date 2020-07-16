add_library(imgui 
    SHARED 
    ${CMAKE_CURRENT_LIST_DIR}/imgui.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui_demo.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui_draw.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui_impl_glfw.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui_impl_opengl3.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui_widgets.cpp
)

target_include_directories(imgui PUBLIC ${CMAKE_CURRENT_LIST_DIR})