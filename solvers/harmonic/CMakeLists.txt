set(SOURCES 
    main.cpp 
    harmonic.cpp)

add_executable(Harmonic ${SOURCES})
target_include_directories(Harmonic PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(Harmonic PRIVATE generic_solver baseline_simulator)