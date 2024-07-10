set(SOURCES 
    main.cpp 
    segmented.cpp)

add_executable(Segmented ${SOURCES})
target_include_directories(Segmented PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(Segmented PRIVATE generic_solver baseline_simulator)