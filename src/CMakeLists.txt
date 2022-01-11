add_library(test1 transactions.cpp)
target_include_directories (Bank PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(test2 customer.cpp)
target_include_directories (Bank PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
