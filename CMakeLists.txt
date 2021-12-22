cmake_minimum_required(VERSION 3.21)

project(Bank)


add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(src)
include_directories(include)
target_link_directories(${PROJECT_NAME} PUBLIC )
target_link_libraries(${PROJECT_NAME} src)