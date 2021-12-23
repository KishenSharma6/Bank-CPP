cmake_minimum_required(VERSION 3.21)

project(Bank)

set(SOURCES src/main.cpp )
add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(src)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_directories(${PROJECT_NAME} PUBLIC src )
target_link_libraries(${PROJECT_NAME} transactions.cpp)