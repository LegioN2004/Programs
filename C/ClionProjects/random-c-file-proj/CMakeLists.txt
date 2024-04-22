cmake_minimum_required(VERSION 3.28)
project(random_c_file_proj C)

set(CMAKE_C_STANDARD 11)

file(GLOB random_c_file_proj CONFIGURE_DEPENDS "*.cpp" "*.c")

add_executable(random_c_file_proj main.c )
add_executable(Artarisnt artrat.c )

