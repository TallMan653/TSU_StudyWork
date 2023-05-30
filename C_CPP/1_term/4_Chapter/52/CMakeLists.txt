cmake_minimum_required(VERSION 3.0.0)
project(Chapter_4_52 VERSION 0.1.0)

include(CTest)
enable_testing()
add_library(
    tmcor-c-lib
    tmcor_c_lib.cpp
    tmcor_c_lib.h
)
add_executable(Chapter_4_52 main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE tmcor-c-lib)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
