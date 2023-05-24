cmake_minimum_required(VERSION 3.0.1)
project(L2DEngine VERSION 0.1.0)

option(BUILD_SHARED_LIBS "Build Shared Libraries" ON) 

set(IMGUI_DIR ${CMAKE_CURRENT_LIST_DIR}/vendor/imgui)

set (CMAKE_CXX_STANDARD 17)

file(GLOB LDBOX_SRC
    "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/ui/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/core/*.cpp"
    "${IMGUI_DIR}/*.cpp"
    "${IMGUI_DIR}/backends/imgui_impl_sdl2.cpp"
    "${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp"
)

#SDL2
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/vendor/SDL)
include_directories(${CMAKE_CURRENT_LIST_DIR}/vendor/SDL/include)
link_directories(${CMAKE_CURRENT_LIST_DIR}/vendor/SDL/lib)

#spdlog
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/vendor/spdlog/)
link_directories(${CMAKE_CURRENT_LIST_DIR}/vendor/spdlog)
include_directories(${CMAKE_CURRENT_LIST_DIR}/vendor/spdlog/include)

#glad
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/vendor/glad/)
link_directories(${CMAKE_CURRENT_LIST_DIR}/vendor/glad)
include_directories(${CMAKE_CURRENT_LIST_DIR}/vendor/glad/include)

add_library(
        L2DEngine
        ${LDBOX_SRC}
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

target_link_libraries(
        L2DEngine PUBLIC
        SDL2main
        SDL2 
        glad 
        )
