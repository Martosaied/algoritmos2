# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/martin/Documents/facultad/algoritmos_2/git/ejercitacion_taller_21-4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/martin/Documents/facultad/algoritmos_2/git/ejercitacion_taller_21-4/build

# Include any dependencies generated for this target.
include CMakeFiles/ej11.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ej11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej11.dir/flags.make

CMakeFiles/ej11.dir/tests/test_recordatorios.cpp.o: CMakeFiles/ej11.dir/flags.make
CMakeFiles/ej11.dir/tests/test_recordatorios.cpp.o: ../tests/test_recordatorios.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/martin/Documents/facultad/algoritmos_2/git/ejercitacion_taller_21-4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ej11.dir/tests/test_recordatorios.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej11.dir/tests/test_recordatorios.cpp.o -c /home/martin/Documents/facultad/algoritmos_2/git/ejercitacion_taller_21-4/tests/test_recordatorios.cpp

CMakeFiles/ej11.dir/tests/test_recordatorios.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej11.dir/tests/test_recordatorios.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/martin/Documents/facultad/algoritmos_2/git/ejercitacion_taller_21-4/tests/test_recordatorios.cpp > CMakeFiles/ej11.dir/tests/test_recordatorios.cpp.i

CMakeFiles/ej11.dir/tests/test_recordatorios.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej11.dir/tests/test_recordatorios.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/martin/Documents/facultad/algoritmos_2/git/ejercitacion_taller_21-4/tests/test_recordatorios.cpp -o CMakeFiles/ej11.dir/tests/test_recordatorios.cpp.s

# Object files for target ej11
ej11_OBJECTS = \
"CMakeFiles/ej11.dir/tests/test_recordatorios.cpp.o"

# External object files for target ej11
ej11_EXTERNAL_OBJECTS =

ej11: CMakeFiles/ej11.dir/tests/test_recordatorios.cpp.o
ej11: CMakeFiles/ej11.dir/build.make
ej11: libgtest.a
ej11: libgtest_main.a
ej11: CMakeFiles/ej11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/martin/Documents/facultad/algoritmos_2/git/ejercitacion_taller_21-4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ej11"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ej11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej11.dir/build: ej11

.PHONY : CMakeFiles/ej11.dir/build

CMakeFiles/ej11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej11.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej11.dir/clean

CMakeFiles/ej11.dir/depend:
	cd /home/martin/Documents/facultad/algoritmos_2/git/ejercitacion_taller_21-4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/martin/Documents/facultad/algoritmos_2/git/ejercitacion_taller_21-4 /home/martin/Documents/facultad/algoritmos_2/git/ejercitacion_taller_21-4 /home/martin/Documents/facultad/algoritmos_2/git/ejercitacion_taller_21-4/build /home/martin/Documents/facultad/algoritmos_2/git/ejercitacion_taller_21-4/build /home/martin/Documents/facultad/algoritmos_2/git/ejercitacion_taller_21-4/build/CMakeFiles/ej11.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ej11.dir/depend

