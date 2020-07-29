set(SOURCES
    ${SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/Exceptions.cpp
)

add_subdirectory(Renderer)

set(SOURCES
    ${SOURCES}
    PARENT_SCOPE
)