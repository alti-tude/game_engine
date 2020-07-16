set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Renderer)

set(SOURCES
    ${SOURCES}
    PARENT_SCOPE
)
