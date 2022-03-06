add_library(test1 account.cpp)
target_include_directories (Bank PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(test2 frontEnd.cpp)
target_include_directories (Bank PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(test3 importExportData.cpp)
target_include_directories (Bank PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(test4 pin.cpp)
target_include_directories (Bank PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(test5 transactions.cpp)
target_include_directories (Bank PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})