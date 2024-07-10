set(SOURCES 
    main.cpp 
    max_fit.cpp)

add_executable(MaxFit ${SOURCES})
target_include_directories(MaxFit PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(MaxFit PRIVATE generic_solver)