cmake_minimum_required(VERSION 3.12)
project(MyProgram C)

add_compile_options("-fmacro-prefix-map=${CMAKE_SOURCE_DIR}/=")

add_compile_options(-Wall -g)

add_library(ex22_obj OBJECT ex22.c ex22.h)

add_executable(ex22 ex22_main.c)

target_link_libraries(ex22 PRIVATE ex22_obj)
