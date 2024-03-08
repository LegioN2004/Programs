cmake_minimum_required (VERSION 3.10)
project(C)
project(C++)

add_subdirectory(C)
add_subdirectory(C++)
add_executable(new_target C/uni-stuff/semester-2/Programming-in-C/areaOfTriangle.c
        C/uni-stuff/semester-2/Programming-in-C/implicitTypeConversion.c)
