cmake_minimum_required(VERSION 3.0)
project(Glad)

add_library(glad include/glad/glad.h src/glad.c)
set_target_properties(glad PROPERTIES PREFIX "")
target_include_directories(glad PUBLIC include/)