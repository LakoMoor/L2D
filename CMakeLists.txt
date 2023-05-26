cmake_minimum_required(VERSION 3.0.1)
project(L2D VERSION 0.1.0)

option(BUILD_SHARED_LIBS "Build Shared Libraries" ON) 

set (CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/build/Debug/L2D/lib")
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/build/Debug/L2D/lib")
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/build/Debug/L2D/bin")
else()
        set(CMAKE_CXX_FLAGS "-mwindows")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DRELEASE")
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/build/Release/L2D/bin")
endif()

file(GLOB L2D_SRC
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)

#L2DEngine
add_subdirectory(src/L2DEngine/)
include_directories(src/L2DEngine/include/)

add_executable(
        L2D
        ${L2D_SRC}
)

target_include_directories(
        L2D
        PUBLIC 
        src/L2DEngine/include/
)

target_link_libraries(
        L2D PUBLIC
        L2DEngine
        spdlog
        )
