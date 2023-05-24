cmake_minimum_required(VERSION 3.0.1)
project(L2D VERSION 0.1.0)

option(BUILD_SHARED_LIBS "Build Shared Libraries" ON) 

set(IMGUI_DIR vendor/imgui)

set (CMAKE_CXX_STANDARD 17)


#SDL2
add_subdirectory(src/L2DEngine/)
include_directories(src/L2DEngine/include/)
link_directories(src/L2DEngine/lib/)

#spdlog
add_subdirectory(vendor/spdlog/)
link_directories(vendor/spdlog/)
include_directories(vendor/spdlog/include/)


add_executable(
        L2D
        ${LDBOX_SRC}
)

target_include_directories(
        L2D
        PUBLIC 
        
        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends/
)

target_link_libraries(
        L2D PUBLIC
        L2DEngine
        spdlog
        )
