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
include CMakeFiles/projeto.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/projeto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projeto.dir/flags.make

CMakeFiles/projeto.dir/Generator/generator.cpp.o: CMakeFiles/projeto.dir/flags.make
CMakeFiles/projeto.dir/Generator/generator.cpp.o: ../Generator/generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clock/Aulas/CG/Projeto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/projeto.dir/Generator/generator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projeto.dir/Generator/generator.cpp.o -c /home/clock/Aulas/CG/Projeto/Generator/generator.cpp

CMakeFiles/projeto.dir/Generator/generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projeto.dir/Generator/generator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clock/Aulas/CG/Projeto/Generator/generator.cpp > CMakeFiles/projeto.dir/Generator/generator.cpp.i

CMakeFiles/projeto.dir/Generator/generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projeto.dir/Generator/generator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clock/Aulas/CG/Projeto/Generator/generator.cpp -o CMakeFiles/projeto.dir/Generator/generator.cpp.s

CMakeFiles/projeto.dir/Structs/Ponto.cpp.o: CMakeFiles/projeto.dir/flags.make
CMakeFiles/projeto.dir/Structs/Ponto.cpp.o: ../Structs/Ponto.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clock/Aulas/CG/Projeto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/projeto.dir/Structs/Ponto.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projeto.dir/Structs/Ponto.cpp.o -c /home/clock/Aulas/CG/Projeto/Structs/Ponto.cpp

CMakeFiles/projeto.dir/Structs/Ponto.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projeto.dir/Structs/Ponto.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clock/Aulas/CG/Projeto/Structs/Ponto.cpp > CMakeFiles/projeto.dir/Structs/Ponto.cpp.i

CMakeFiles/projeto.dir/Structs/Ponto.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projeto.dir/Structs/Ponto.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clock/Aulas/CG/Projeto/Structs/Ponto.cpp -o CMakeFiles/projeto.dir/Structs/Ponto.cpp.s

CMakeFiles/projeto.dir/Structs/Forma.cpp.o: CMakeFiles/projeto.dir/flags.make
CMakeFiles/projeto.dir/Structs/Forma.cpp.o: ../Structs/Forma.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clock/Aulas/CG/Projeto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/projeto.dir/Structs/Forma.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projeto.dir/Structs/Forma.cpp.o -c /home/clock/Aulas/CG/Projeto/Structs/Forma.cpp

CMakeFiles/projeto.dir/Structs/Forma.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projeto.dir/Structs/Forma.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clock/Aulas/CG/Projeto/Structs/Forma.cpp > CMakeFiles/projeto.dir/Structs/Forma.cpp.i

CMakeFiles/projeto.dir/Structs/Forma.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projeto.dir/Structs/Forma.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clock/Aulas/CG/Projeto/Structs/Forma.cpp -o CMakeFiles/projeto.dir/Structs/Forma.cpp.s

CMakeFiles/projeto.dir/Generator/plane.cpp.o: CMakeFiles/projeto.dir/flags.make
CMakeFiles/projeto.dir/Generator/plane.cpp.o: ../Generator/plane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clock/Aulas/CG/Projeto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/projeto.dir/Generator/plane.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projeto.dir/Generator/plane.cpp.o -c /home/clock/Aulas/CG/Projeto/Generator/plane.cpp

CMakeFiles/projeto.dir/Generator/plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projeto.dir/Generator/plane.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clock/Aulas/CG/Projeto/Generator/plane.cpp > CMakeFiles/projeto.dir/Generator/plane.cpp.i

CMakeFiles/projeto.dir/Generator/plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projeto.dir/Generator/plane.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clock/Aulas/CG/Projeto/Generator/plane.cpp -o CMakeFiles/projeto.dir/Generator/plane.cpp.s

CMakeFiles/projeto.dir/Generator/box.cpp.o: CMakeFiles/projeto.dir/flags.make
CMakeFiles/projeto.dir/Generator/box.cpp.o: ../Generator/box.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clock/Aulas/CG/Projeto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/projeto.dir/Generator/box.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projeto.dir/Generator/box.cpp.o -c /home/clock/Aulas/CG/Projeto/Generator/box.cpp

CMakeFiles/projeto.dir/Generator/box.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projeto.dir/Generator/box.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clock/Aulas/CG/Projeto/Generator/box.cpp > CMakeFiles/projeto.dir/Generator/box.cpp.i

CMakeFiles/projeto.dir/Generator/box.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projeto.dir/Generator/box.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clock/Aulas/CG/Projeto/Generator/box.cpp -o CMakeFiles/projeto.dir/Generator/box.cpp.s

# Object files for target projeto
projeto_OBJECTS = \
"CMakeFiles/projeto.dir/Generator/generator.cpp.o" \
"CMakeFiles/projeto.dir/Structs/Ponto.cpp.o" \
"CMakeFiles/projeto.dir/Structs/Forma.cpp.o" \
"CMakeFiles/projeto.dir/Generator/plane.cpp.o" \
"CMakeFiles/projeto.dir/Generator/box.cpp.o"

# External object files for target projeto
projeto_EXTERNAL_OBJECTS =

projeto: CMakeFiles/projeto.dir/Generator/generator.cpp.o
projeto: CMakeFiles/projeto.dir/Structs/Ponto.cpp.o
projeto: CMakeFiles/projeto.dir/Structs/Forma.cpp.o
projeto: CMakeFiles/projeto.dir/Generator/plane.cpp.o
projeto: CMakeFiles/projeto.dir/Generator/box.cpp.o
projeto: CMakeFiles/projeto.dir/build.make
projeto: /usr/lib/x86_64-linux-gnu/libGL.so
projeto: /usr/lib/x86_64-linux-gnu/libGLU.so
projeto: /usr/lib/x86_64-linux-gnu/libglut.so
projeto: /usr/lib/x86_64-linux-gnu/libXmu.so
projeto: /usr/lib/x86_64-linux-gnu/libXi.so
projeto: CMakeFiles/projeto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/clock/Aulas/CG/Projeto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable projeto"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projeto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projeto.dir/build: projeto

.PHONY : CMakeFiles/projeto.dir/build

CMakeFiles/projeto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projeto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projeto.dir/clean

CMakeFiles/projeto.dir/depend:
	cd /home/clock/Aulas/CG/Projeto/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/clock/Aulas/CG/Projeto /home/clock/Aulas/CG/Projeto /home/clock/Aulas/CG/Projeto/build /home/clock/Aulas/CG/Projeto/build /home/clock/Aulas/CG/Projeto/build/CMakeFiles/projeto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/projeto.dir/depend
