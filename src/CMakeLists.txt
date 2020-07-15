cmake_minimum_required(VERSION 3.0)
project(TRAFFIC_SIMULATOR VERSION 0.0.1 LANGUAGES CXX)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(OpenGL_GL_PREFERENCE "GLVND")


set(SOURCES main.cpp)
add_custom_target(copy_shader_files
    ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/res ${CMAKE_CURRENT_BINARY_DIR}/res
    COMMENT "Copying shader files" VERBATIM
)
set(DEPENDENCIES copy_shader_files)

add_subdirectory(external/glfw-3.3.2)
add_subdirectory(external/glew-2.1.0/build/cmake)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src)

include_directories(
    ${PROJECT_SOURCE_DIR}/external/glfw-3.3.2/include
    ${PROJECT_SOURCE_DIR}/external/glew-2.1.0/include
    ${PROJECT_SOURCE_DIR}/external/glm/glm
    ${PROJECT_SOURCE_DIR}/includes
)
message(STATUS ${SOURCES})
add_executable(simulator ${SOURCES})
target_link_libraries(simulator glew glfw)
add_dependencies(simulator ${DEPENDENCIES})