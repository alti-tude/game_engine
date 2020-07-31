set(SOURCES
    ${SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/Exceptions.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Config.cpp
)

add_subdirectory(Renderer)
add_subdirectory(Message)
add_subdirectory(Ecs)
set(SOURCES
    ${SOURCES}
    PARENT_SCOPE
)