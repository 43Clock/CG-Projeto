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
CMAKE_COMMAND = /snap/clion/139/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/139/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/clock/Aulas/CG/Projeto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/clock/Aulas/CG/Projeto/build

# Include any dependencies generated for this target.
include CMakeFiles/Projeto.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Projeto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projeto.dir/flags.make

CMakeFiles/Projeto.dir/main.cpp.o: CMakeFiles/Projeto.dir/flags.make
CMakeFiles/Projeto.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clock/Aulas/CG/Projeto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Projeto.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Projeto.dir/main.cpp.o -c /home/clock/Aulas/CG/Projeto/main.cpp

CMakeFiles/Projeto.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clock/Aulas/CG/Projeto/main.cpp > CMakeFiles/Projeto.dir/main.cpp.i

CMakeFiles/Projeto.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clock/Aulas/CG/Projeto/main.cpp -o CMakeFiles/Projeto.dir/main.cpp.s

# Object files for target Projeto
Projeto_OBJECTS = \
"CMakeFiles/Projeto.dir/main.cpp.o"

# External object files for target Projeto
Projeto_EXTERNAL_OBJECTS =

Projeto: CMakeFiles/Projeto.dir/main.cpp.o
Projeto: CMakeFiles/Projeto.dir/build.make
Projeto: CMakeFiles/Projeto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/clock/Aulas/CG/Projeto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Projeto"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Projeto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projeto.dir/build: Projeto

.PHONY : CMakeFiles/Projeto.dir/build

CMakeFiles/Projeto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Projeto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Projeto.dir/clean

CMakeFiles/Projeto.dir/depend:
	cd /home/clock/Aulas/CG/Projeto/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/clock/Aulas/CG/Projeto /home/clock/Aulas/CG/Projeto /home/clock/Aulas/CG/Projeto/build /home/clock/Aulas/CG/Projeto/build /home/clock/Aulas/CG/Projeto/build/CMakeFiles/Projeto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Projeto.dir/depend
