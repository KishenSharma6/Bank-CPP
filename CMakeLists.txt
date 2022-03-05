cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 11)
project(Bank)

set(SOURCES src/main.cpp 
            src/account.cpp
            include/account.h
            src/frontEnd.cpp
            include/frontEnd.h
            src/importExportData.cpp
            include/importExportData.h
            src/pin.cpp
            include/pin.h
            src/transactions.cpp
            include/transactions.h
            )

            add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

