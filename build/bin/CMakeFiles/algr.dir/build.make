# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pineapple/leet/leetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pineapple/leet/leetcode/build

# Include any dependencies generated for this target.
include bin/CMakeFiles/algr.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/algr.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/algr.dir/flags.make

bin/CMakeFiles/algr.dir/algorithm.o: bin/CMakeFiles/algr.dir/flags.make
bin/CMakeFiles/algr.dir/algorithm.o: ../src/algorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pineapple/leet/leetcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/algr.dir/algorithm.o"
	cd /home/pineapple/leet/leetcode/build/bin && /usr/lib/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/algr.dir/algorithm.o -c /home/pineapple/leet/leetcode/src/algorithm.cpp

bin/CMakeFiles/algr.dir/algorithm.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algr.dir/algorithm.i"
	cd /home/pineapple/leet/leetcode/build/bin && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pineapple/leet/leetcode/src/algorithm.cpp > CMakeFiles/algr.dir/algorithm.i

bin/CMakeFiles/algr.dir/algorithm.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algr.dir/algorithm.s"
	cd /home/pineapple/leet/leetcode/build/bin && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pineapple/leet/leetcode/src/algorithm.cpp -o CMakeFiles/algr.dir/algorithm.s

# Object files for target algr
algr_OBJECTS = \
"CMakeFiles/algr.dir/algorithm.o"

# External object files for target algr
algr_EXTERNAL_OBJECTS =

bin/algr: bin/CMakeFiles/algr.dir/algorithm.o
bin/algr: bin/CMakeFiles/algr.dir/build.make
bin/algr: bin/CMakeFiles/algr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pineapple/leet/leetcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable algr"
	cd /home/pineapple/leet/leetcode/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/algr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/algr.dir/build: bin/algr

.PHONY : bin/CMakeFiles/algr.dir/build

bin/CMakeFiles/algr.dir/clean:
	cd /home/pineapple/leet/leetcode/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/algr.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/algr.dir/clean

bin/CMakeFiles/algr.dir/depend:
	cd /home/pineapple/leet/leetcode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pineapple/leet/leetcode /home/pineapple/leet/leetcode/src /home/pineapple/leet/leetcode/build /home/pineapple/leet/leetcode/build/bin /home/pineapple/leet/leetcode/build/bin/CMakeFiles/algr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/algr.dir/depend
