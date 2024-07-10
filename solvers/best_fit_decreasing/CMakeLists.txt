set(SOURCES 
    main.cpp 
    best_fit_decreasing.cpp)

add_executable(BestFitDecreasing ${SOURCES})
target_include_directories(BestFitDecreasing PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(BestFitDecreasing PRIVATE generic_solver)