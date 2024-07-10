set(SOURCES 
    main.cpp 
    modified.cpp)

add_executable(Modified ${SOURCES})
target_include_directories(Modified PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(Modified PRIVATE generic_solver baseline_simulator)