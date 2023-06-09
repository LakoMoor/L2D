cmake_minimum_required(VERSION 3.0.1)
project(L2DEngine VERSION 0.1.0)

option(BUILD_SHARED_LIBS "Build Shared Libraries" ON) 

set(IMGUI_DIR ../../vendor/imgui)

set (CMAKE_CXX_STANDARD 17)

file(GLOB L2DEngine_SRC
    "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/ui/*.cpp"
    "${IMGUI_DIR}/*.cpp"
    "${IMGUI_DIR}/backends/imgui_impl_sdl2.cpp"
    "${IMGUI_DIR}/backends/imgui_impl_sdlrenderer.cpp"
    "${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp"
)

#SDL2
add_subdirectory(../../vendor/SDL ../../vendor/SDL)
include_directories(../../vendor/SDL/include/)

#SDL_image
add_subdirectory(../../vendor/SDL_image ../../vendor/SDL_image)
include_directories(../../vendor/SDL_image/)

#spdlog
add_subdirectory(../../vendor/spdlog  ../../vendor/spdlog)
include_directories(../../vendor/spdlog/include/)

#glad
add_subdirectory(../../vendor/glad  ../../vendor/glad )
include_directories(../../vendor/glad/include/)

add_library(
        L2DEngine
        ${L2DEngine_SRC}
)

include_directories(
        include/L2DE
)

target_include_directories(
        L2DEngine
        PUBLIC 
        include/L2DE
        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends/
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
set_target_properties(L2DEngine PROPERTIES PREFIX "Debug_")
else(CMAKE_BUILD_TYPE STREQUAL "Release")
set_target_properties(L2DEngine PROPERTIES PREFIX "")
endif()
if(CMAKE_BUILD_TYPE STREQUAL "OpenGL")
set_target_properties(L2DEngine PROPERTIES PREFIX "GL")
endif()

target_link_libraries(
        L2DEngine PUBLIC
        SDL2main
        SDL2 
        SDL2_image
        glad 
        )
