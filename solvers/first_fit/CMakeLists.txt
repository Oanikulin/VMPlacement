set(SOURCES 
    main.cpp 
    first_fit.cpp)

add_executable(FirstFit ${SOURCES})
target_include_directories(FirstFit PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(FirstFit PRIVATE generic_solver)