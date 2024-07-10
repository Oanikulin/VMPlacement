set(SOURCES 
    main.cpp)

add_executable(DataAnalysis ${SOURCES})
target_include_directories(DataAnalysis PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(DataAnalysis PRIVATE generic_solver)