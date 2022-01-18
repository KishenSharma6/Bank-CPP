cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 11)
project(Bank)

set(SOURCES src/main.cpp 
            src/transactions.cpp 
            include/transactions.h
            src/customer.cpp
            include/customer.h
            src/machine.cpp
            include/machine.h
            )

            add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

