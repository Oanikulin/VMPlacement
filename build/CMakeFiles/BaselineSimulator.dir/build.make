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
include CMakeFiles/BaselineSimulator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BaselineSimulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BaselineSimulator.dir/flags.make

CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.o: CMakeFiles/BaselineSimulator.dir/flags.make
CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.o: ../baseline_solver/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/My documents/Simulator/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.o -c "/mnt/d/My documents/Simulator/baseline_solver/main.cpp"

CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/d/My documents/Simulator/baseline_solver/main.cpp" > CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.i

CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/d/My documents/Simulator/baseline_solver/main.cpp" -o CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.s

CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.o.requires:

.PHONY : CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.o.requires

CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.o.provides: CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/BaselineSimulator.dir/build.make CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.o.provides.build
.PHONY : CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.o.provides

CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.o.provides.build: CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.o


CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.o: CMakeFiles/BaselineSimulator.dir/flags.make
CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.o: ../baseline_solver/baseline_solver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/My documents/Simulator/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.o -c "/mnt/d/My documents/Simulator/baseline_solver/baseline_solver.cpp"

CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/d/My documents/Simulator/baseline_solver/baseline_solver.cpp" > CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.i

CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/d/My documents/Simulator/baseline_solver/baseline_solver.cpp" -o CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.s

CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.o.requires:

.PHONY : CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.o.requires

CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.o.provides: CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.o.requires
	$(MAKE) -f CMakeFiles/BaselineSimulator.dir/build.make CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.o.provides.build
.PHONY : CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.o.provides

CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.o.provides.build: CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.o


CMakeFiles/BaselineSimulator.dir/structures.cpp.o: CMakeFiles/BaselineSimulator.dir/flags.make
CMakeFiles/BaselineSimulator.dir/structures.cpp.o: ../structures.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/My documents/Simulator/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/BaselineSimulator.dir/structures.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BaselineSimulator.dir/structures.cpp.o -c "/mnt/d/My documents/Simulator/structures.cpp"

CMakeFiles/BaselineSimulator.dir/structures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BaselineSimulator.dir/structures.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/d/My documents/Simulator/structures.cpp" > CMakeFiles/BaselineSimulator.dir/structures.cpp.i

CMakeFiles/BaselineSimulator.dir/structures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BaselineSimulator.dir/structures.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/d/My documents/Simulator/structures.cpp" -o CMakeFiles/BaselineSimulator.dir/structures.cpp.s

CMakeFiles/BaselineSimulator.dir/structures.cpp.o.requires:

.PHONY : CMakeFiles/BaselineSimulator.dir/structures.cpp.o.requires

CMakeFiles/BaselineSimulator.dir/structures.cpp.o.provides: CMakeFiles/BaselineSimulator.dir/structures.cpp.o.requires
	$(MAKE) -f CMakeFiles/BaselineSimulator.dir/build.make CMakeFiles/BaselineSimulator.dir/structures.cpp.o.provides.build
.PHONY : CMakeFiles/BaselineSimulator.dir/structures.cpp.o.provides

CMakeFiles/BaselineSimulator.dir/structures.cpp.o.provides.build: CMakeFiles/BaselineSimulator.dir/structures.cpp.o


# Object files for target BaselineSimulator
BaselineSimulator_OBJECTS = \
"CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.o" \
"CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.o" \
"CMakeFiles/BaselineSimulator.dir/structures.cpp.o"

# External object files for target BaselineSimulator
BaselineSimulator_EXTERNAL_OBJECTS =

BaselineSimulator: CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.o
BaselineSimulator: CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.o
BaselineSimulator: CMakeFiles/BaselineSimulator.dir/structures.cpp.o
BaselineSimulator: CMakeFiles/BaselineSimulator.dir/build.make
BaselineSimulator: CMakeFiles/BaselineSimulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/d/My documents/Simulator/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable BaselineSimulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BaselineSimulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BaselineSimulator.dir/build: BaselineSimulator

.PHONY : CMakeFiles/BaselineSimulator.dir/build

CMakeFiles/BaselineSimulator.dir/requires: CMakeFiles/BaselineSimulator.dir/baseline_solver/main.cpp.o.requires
CMakeFiles/BaselineSimulator.dir/requires: CMakeFiles/BaselineSimulator.dir/baseline_solver/baseline_solver.cpp.o.requires
CMakeFiles/BaselineSimulator.dir/requires: CMakeFiles/BaselineSimulator.dir/structures.cpp.o.requires

.PHONY : CMakeFiles/BaselineSimulator.dir/requires

CMakeFiles/BaselineSimulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BaselineSimulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BaselineSimulator.dir/clean

CMakeFiles/BaselineSimulator.dir/depend:
	cd "/mnt/d/My documents/Simulator/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/d/My documents/Simulator" "/mnt/d/My documents/Simulator" "/mnt/d/My documents/Simulator/build" "/mnt/d/My documents/Simulator/build" "/mnt/d/My documents/Simulator/build/CMakeFiles/BaselineSimulator.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/BaselineSimulator.dir/depend

