cmake_minimum_required(VERSION 3.10)

project(Simulator VERSION 1.0)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")

set(SOURCES_BASELINE baseline_solver/main.cpp baseline_solver/baseline_solver.cpp structures.cpp)

add_executable(BaselineSimulator ${SOURCES_BASELINE})
target_include_directories(BaselineSimulator PUBLIC "${PROJECT_BINARY_DIR}")

set(SOURCE_FIRST_FIT first_fit/main.cpp first_fit/solver.cpp structures.cpp)

add_executable(FirstFitSimulator ${SOURCE_FIRST_FIT})
target_include_directories(FirstFitSimulator PUBLIC "${PROJECT_BINARY_DIR}")

set(SOURCE_FIRST_FIT_DECREASING first_fit_decreasing/main.cpp first_fit_decreasing/solver.cpp structures.cpp)

add_executable(FirstFitDecreasingSimulator ${SOURCE_FIRST_FIT_DECREASING})
target_include_directories(FirstFitDecreasingSimulator PUBLIC "${PROJECT_BINARY_DIR}")

set(SOURCE_BEST_FIT_DECREASING best_fit_decreasing/main.cpp best_fit_decreasing/solver.cpp structures.cpp)

add_executable(BestFitDecreasingSimulator ${SOURCE_BEST_FIT_DECREASING})
find_package (Threads)
target_include_directories(BestFitDecreasingSimulator PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries (BestFitDecreasingSimulator ${CMAKE_THREAD_LIBS_INIT})


set(SOURCE_BEST_FIT best_fit/main.cpp best_fit/solver.cpp structures.cpp)

add_executable(BestFitSimulator ${SOURCE_BEST_FIT})
find_package (Threads)
target_include_directories(BestFitSimulator PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries (BestFitSimulator ${CMAKE_THREAD_LIBS_INIT})

set(SOURCE_MAX_FIT max_fit/main.cpp max_fit/solver.cpp structures.cpp)

add_executable(MaxFitSimulator ${SOURCE_MAX_FIT})
find_package (Threads)
target_include_directories(MaxFitSimulator PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries (MaxFitSimulator ${CMAKE_THREAD_LIBS_INIT})


set(SOURCES_SUGGESTED modified_solver/main.cpp modified_solver/modified_solver.cpp baseline_solver/baseline_solver.cpp structures.cpp)

add_executable(SuggestedSimulator ${SOURCES_SUGGESTED})
target_include_directories(SuggestedSimulator PUBLIC "${PROJECT_BINARY_DIR}")


set(TEST_DATA DataAnalysis/main.cpp structures.cpp)

add_executable(TestData ${TEST_DATA})
target_include_directories(TestData PUBLIC "${PROJECT_BINARY_DIR}")