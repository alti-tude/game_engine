cmake_minimum_required(VERSION 3.0)
project(TRAFFIC_SIMULATOR VERSION 0.0.1 LANGUAGES CXX)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(OpenGL_GL_PREFERENCE "GLVND")
set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_subdirectory(external/glfw-3.3.2)
add_subdirectory(external/glew-2.1.0/build/cmake)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)

include_directories(
    external/glfw-3.3.2/include
    external/glew-2.1.0/include
    external/glm/glm
    src/includes
)

add_executable(simmulator ${SOURCES})
target_link_libraries(simmulator glew glfw)
