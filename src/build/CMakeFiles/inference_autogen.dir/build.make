# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/cmake/bin/cmake

# The command to remove a file.
RM = /opt/cmake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/huydung/Deep/code/LeNet/app/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/huydung/Deep/code/LeNet/app/src/build

# Utility rule file for inference_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/inference_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/inference_autogen.dir/progress.make

CMakeFiles/inference_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/huydung/Deep/code/LeNet/app/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target inference"
	/opt/cmake/bin/cmake -E cmake_autogen /home/huydung/Deep/code/LeNet/app/src/build/CMakeFiles/inference_autogen.dir/AutogenInfo.json Debug

inference_autogen: CMakeFiles/inference_autogen
inference_autogen: CMakeFiles/inference_autogen.dir/build.make
.PHONY : inference_autogen

# Rule to build all files generated by this target.
CMakeFiles/inference_autogen.dir/build: inference_autogen
.PHONY : CMakeFiles/inference_autogen.dir/build

CMakeFiles/inference_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/inference_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/inference_autogen.dir/clean

CMakeFiles/inference_autogen.dir/depend:
	cd /home/huydung/Deep/code/LeNet/app/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huydung/Deep/code/LeNet/app/src /home/huydung/Deep/code/LeNet/app/src /home/huydung/Deep/code/LeNet/app/src/build /home/huydung/Deep/code/LeNet/app/src/build /home/huydung/Deep/code/LeNet/app/src/build/CMakeFiles/inference_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/inference_autogen.dir/depend
