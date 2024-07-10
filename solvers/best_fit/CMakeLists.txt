set(SOURCES 
    main.cpp 
    best_fit.cpp)

add_executable(BestFit ${SOURCES})
target_include_directories(BestFit PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(BestFit PRIVATE generic_solver)