# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/d/My documents/Simulator"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/d/My documents/Simulator/build"

# Include any dependencies generated for this target.
include CMakeFiles/MaxFitSimulator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MaxFitSimulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MaxFitSimulator.dir/flags.make

CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.o: CMakeFiles/MaxFitSimulator.dir/flags.make
CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.o: ../max_fit/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/My documents/Simulator/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.o -c "/mnt/d/My documents/Simulator/max_fit/main.cpp"

CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/d/My documents/Simulator/max_fit/main.cpp" > CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.i

CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/d/My documents/Simulator/max_fit/main.cpp" -o CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.s

CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.o.requires:

.PHONY : CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.o.requires

CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.o.provides: CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MaxFitSimulator.dir/build.make CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.o.provides.build
.PHONY : CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.o.provides

CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.o.provides.build: CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.o


CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.o: CMakeFiles/MaxFitSimulator.dir/flags.make
CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.o: ../max_fit/solver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/My documents/Simulator/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.o -c "/mnt/d/My documents/Simulator/max_fit/solver.cpp"

CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/d/My documents/Simulator/max_fit/solver.cpp" > CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.i

CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/d/My documents/Simulator/max_fit/solver.cpp" -o CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.s

CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.o.requires:

.PHONY : CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.o.requires

CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.o.provides: CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.o.requires
	$(MAKE) -f CMakeFiles/MaxFitSimulator.dir/build.make CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.o.provides.build
.PHONY : CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.o.provides

CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.o.provides.build: CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.o


CMakeFiles/MaxFitSimulator.dir/structures.cpp.o: CMakeFiles/MaxFitSimulator.dir/flags.make
CMakeFiles/MaxFitSimulator.dir/structures.cpp.o: ../structures.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/My documents/Simulator/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MaxFitSimulator.dir/structures.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MaxFitSimulator.dir/structures.cpp.o -c "/mnt/d/My documents/Simulator/structures.cpp"

CMakeFiles/MaxFitSimulator.dir/structures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MaxFitSimulator.dir/structures.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/d/My documents/Simulator/structures.cpp" > CMakeFiles/MaxFitSimulator.dir/structures.cpp.i

CMakeFiles/MaxFitSimulator.dir/structures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MaxFitSimulator.dir/structures.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/d/My documents/Simulator/structures.cpp" -o CMakeFiles/MaxFitSimulator.dir/structures.cpp.s

CMakeFiles/MaxFitSimulator.dir/structures.cpp.o.requires:

.PHONY : CMakeFiles/MaxFitSimulator.dir/structures.cpp.o.requires

CMakeFiles/MaxFitSimulator.dir/structures.cpp.o.provides: CMakeFiles/MaxFitSimulator.dir/structures.cpp.o.requires
	$(MAKE) -f CMakeFiles/MaxFitSimulator.dir/build.make CMakeFiles/MaxFitSimulator.dir/structures.cpp.o.provides.build
.PHONY : CMakeFiles/MaxFitSimulator.dir/structures.cpp.o.provides

CMakeFiles/MaxFitSimulator.dir/structures.cpp.o.provides.build: CMakeFiles/MaxFitSimulator.dir/structures.cpp.o


# Object files for target MaxFitSimulator
MaxFitSimulator_OBJECTS = \
"CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.o" \
"CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.o" \
"CMakeFiles/MaxFitSimulator.dir/structures.cpp.o"

# External object files for target MaxFitSimulator
MaxFitSimulator_EXTERNAL_OBJECTS =

MaxFitSimulator: CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.o
MaxFitSimulator: CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.o
MaxFitSimulator: CMakeFiles/MaxFitSimulator.dir/structures.cpp.o
MaxFitSimulator: CMakeFiles/MaxFitSimulator.dir/build.make
MaxFitSimulator: CMakeFiles/MaxFitSimulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/d/My documents/Simulator/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable MaxFitSimulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MaxFitSimulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MaxFitSimulator.dir/build: MaxFitSimulator

.PHONY : CMakeFiles/MaxFitSimulator.dir/build

CMakeFiles/MaxFitSimulator.dir/requires: CMakeFiles/MaxFitSimulator.dir/max_fit/main.cpp.o.requires
CMakeFiles/MaxFitSimulator.dir/requires: CMakeFiles/MaxFitSimulator.dir/max_fit/solver.cpp.o.requires
CMakeFiles/MaxFitSimulator.dir/requires: CMakeFiles/MaxFitSimulator.dir/structures.cpp.o.requires

.PHONY : CMakeFiles/MaxFitSimulator.dir/requires

CMakeFiles/MaxFitSimulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MaxFitSimulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MaxFitSimulator.dir/clean

CMakeFiles/MaxFitSimulator.dir/depend:
	cd "/mnt/d/My documents/Simulator/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/d/My documents/Simulator" "/mnt/d/My documents/Simulator" "/mnt/d/My documents/Simulator/build" "/mnt/d/My documents/Simulator/build" "/mnt/d/My documents/Simulator/build/CMakeFiles/MaxFitSimulator.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/MaxFitSimulator.dir/depend

