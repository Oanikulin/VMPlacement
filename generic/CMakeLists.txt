add_library(generic_solver STATIC src/structures.cpp)

target_include_directories(generic_solver PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include/)