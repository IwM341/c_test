# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Soft\Prog\Tools\CMake_64\bin\cmake.exe

# The command to remove a file.
RM = D:\Soft\Prog\Tools\CMake_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Tmp\probs\c_tests\cmake_lessons\ex4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Tmp\probs\c_tests\cmake_lessons\ex4\build

# Include any dependencies generated for this target.
include lib/CMakeFiles/lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/CMakeFiles/lib.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/lib.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/lib.dir/flags.make

lib/CMakeFiles/lib.dir/src/lib.cpp.obj: lib/CMakeFiles/lib.dir/flags.make
lib/CMakeFiles/lib.dir/src/lib.cpp.obj: ../lib/src/lib.cpp
lib/CMakeFiles/lib.dir/src/lib.cpp.obj: lib/CMakeFiles/lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/lib.dir/src/lib.cpp.obj"
	cd /d D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\lib && D:\Soft\Prog\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/CMakeFiles/lib.dir/src/lib.cpp.obj -MF CMakeFiles\lib.dir\src\lib.cpp.obj.d -o CMakeFiles\lib.dir\src\lib.cpp.obj -c D:\Tmp\probs\c_tests\cmake_lessons\ex4\lib\src\lib.cpp

lib/CMakeFiles/lib.dir/src/lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/src/lib.cpp.i"
	cd /d D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\lib && D:\Soft\Prog\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Tmp\probs\c_tests\cmake_lessons\ex4\lib\src\lib.cpp > CMakeFiles\lib.dir\src\lib.cpp.i

lib/CMakeFiles/lib.dir/src/lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/src/lib.cpp.s"
	cd /d D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\lib && D:\Soft\Prog\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Tmp\probs\c_tests\cmake_lessons\ex4\lib\src\lib.cpp -o CMakeFiles\lib.dir\src\lib.cpp.s

# Object files for target lib
lib_OBJECTS = \
"CMakeFiles/lib.dir/src/lib.cpp.obj"

# External object files for target lib
lib_EXTERNAL_OBJECTS =

lib/liblib.a: lib/CMakeFiles/lib.dir/src/lib.cpp.obj
lib/liblib.a: lib/CMakeFiles/lib.dir/build.make
lib/liblib.a: lib/CMakeFiles/lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblib.a"
	cd /d D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\lib && $(CMAKE_COMMAND) -P CMakeFiles\lib.dir\cmake_clean_target.cmake
	cd /d D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/lib.dir/build: lib/liblib.a
.PHONY : lib/CMakeFiles/lib.dir/build

lib/CMakeFiles/lib.dir/clean:
	cd /d D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\lib && $(CMAKE_COMMAND) -P CMakeFiles\lib.dir\cmake_clean.cmake
.PHONY : lib/CMakeFiles/lib.dir/clean

lib/CMakeFiles/lib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Tmp\probs\c_tests\cmake_lessons\ex4 D:\Tmp\probs\c_tests\cmake_lessons\ex4\lib D:\Tmp\probs\c_tests\cmake_lessons\ex4\build D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\lib D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\lib\CMakeFiles\lib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/lib.dir/depend

