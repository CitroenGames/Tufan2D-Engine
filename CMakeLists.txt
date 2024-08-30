cmake_minimum_required(VERSION 3.16)

project(Engine)

set(CMAKE_CXX_STANDARD 20)

include(cmake/group_sources.cmake)
add_subdirectory(deps)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
    "src/*.h"
    "src/*.cpp"
)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
    group_sources(SOURCE_FILES)
endif()

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC src)

target_link_libraries(${PROJECT_NAME} PUBLIC
    sfml-graphics
    sfml-audio
    imgui
    ECS
    Pakker
    FunctionSpeaker
)