# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/geogardow/Desktop/Proyecto1Testing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/geogardow/Desktop/Proyecto1Testing/build

# Include any dependencies generated for this target.
include CMakeFiles/unit-test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/unit-test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/unit-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unit-test.dir/flags.make

CMakeFiles/unit-test.dir/tst/serverTest.cpp.o: CMakeFiles/unit-test.dir/flags.make
CMakeFiles/unit-test.dir/tst/serverTest.cpp.o: ../tst/serverTest.cpp
CMakeFiles/unit-test.dir/tst/serverTest.cpp.o: CMakeFiles/unit-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/geogardow/Desktop/Proyecto1Testing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unit-test.dir/tst/serverTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/unit-test.dir/tst/serverTest.cpp.o -MF CMakeFiles/unit-test.dir/tst/serverTest.cpp.o.d -o CMakeFiles/unit-test.dir/tst/serverTest.cpp.o -c /home/geogardow/Desktop/Proyecto1Testing/tst/serverTest.cpp

CMakeFiles/unit-test.dir/tst/serverTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit-test.dir/tst/serverTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/geogardow/Desktop/Proyecto1Testing/tst/serverTest.cpp > CMakeFiles/unit-test.dir/tst/serverTest.cpp.i

CMakeFiles/unit-test.dir/tst/serverTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit-test.dir/tst/serverTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/geogardow/Desktop/Proyecto1Testing/tst/serverTest.cpp -o CMakeFiles/unit-test.dir/tst/serverTest.cpp.s

# Object files for target unit-test
unit__test_OBJECTS = \
"CMakeFiles/unit-test.dir/tst/serverTest.cpp.o"

# External object files for target unit-test
unit__test_EXTERNAL_OBJECTS =

unit-test: CMakeFiles/unit-test.dir/tst/serverTest.cpp.o
unit-test: CMakeFiles/unit-test.dir/build.make
unit-test: lib/libgtest.a
unit-test: lib/libgtest_main.a
unit-test: libcodeToTest.a
unit-test: lib/libgtest.a
unit-test: CMakeFiles/unit-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/geogardow/Desktop/Proyecto1Testing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable unit-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unit-test.dir/build: unit-test
.PHONY : CMakeFiles/unit-test.dir/build

CMakeFiles/unit-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unit-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unit-test.dir/clean

CMakeFiles/unit-test.dir/depend:
	cd /home/geogardow/Desktop/Proyecto1Testing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/geogardow/Desktop/Proyecto1Testing /home/geogardow/Desktop/Proyecto1Testing /home/geogardow/Desktop/Proyecto1Testing/build /home/geogardow/Desktop/Proyecto1Testing/build /home/geogardow/Desktop/Proyecto1Testing/build/CMakeFiles/unit-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unit-test.dir/depend
