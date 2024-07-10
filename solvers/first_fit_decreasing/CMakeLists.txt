set(SOURCES 
    main.cpp 
    first_fit_decreasing.cpp)

add_executable(FirstFitDecreasing ${SOURCES})
target_include_directories(FirstFitDecreasing PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(FirstFitDecreasing PRIVATE generic_solver)