add_library(test transactions.cpp)
target_include_directories (Bank PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
