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
include src/CMakeFiles/hello.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/hello.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/hello.dir/flags.make

src/CMakeFiles/hello.dir/main.cpp.obj: src/CMakeFiles/hello.dir/flags.make
src/CMakeFiles/hello.dir/main.cpp.obj: src/CMakeFiles/hello.dir/includes_CXX.rsp
src/CMakeFiles/hello.dir/main.cpp.obj: ../src/main.cpp
src/CMakeFiles/hello.dir/main.cpp.obj: src/CMakeFiles/hello.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/hello.dir/main.cpp.obj"
	cd /d D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\src && D:\Soft\Prog\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/hello.dir/main.cpp.obj -MF CMakeFiles\hello.dir\main.cpp.obj.d -o CMakeFiles\hello.dir\main.cpp.obj -c D:\Tmp\probs\c_tests\cmake_lessons\ex4\src\main.cpp

src/CMakeFiles/hello.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello.dir/main.cpp.i"
	cd /d D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\src && D:\Soft\Prog\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Tmp\probs\c_tests\cmake_lessons\ex4\src\main.cpp > CMakeFiles\hello.dir\main.cpp.i

src/CMakeFiles/hello.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello.dir/main.cpp.s"
	cd /d D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\src && D:\Soft\Prog\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Tmp\probs\c_tests\cmake_lessons\ex4\src\main.cpp -o CMakeFiles\hello.dir\main.cpp.s

src/CMakeFiles/hello.dir/version.cpp.obj: src/CMakeFiles/hello.dir/flags.make
src/CMakeFiles/hello.dir/version.cpp.obj: src/CMakeFiles/hello.dir/includes_CXX.rsp
src/CMakeFiles/hello.dir/version.cpp.obj: ../src/version.cpp
src/CMakeFiles/hello.dir/version.cpp.obj: src/CMakeFiles/hello.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/hello.dir/version.cpp.obj"
	cd /d D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\src && D:\Soft\Prog\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/hello.dir/version.cpp.obj -MF CMakeFiles\hello.dir\version.cpp.obj.d -o CMakeFiles\hello.dir\version.cpp.obj -c D:\Tmp\probs\c_tests\cmake_lessons\ex4\src\version.cpp

src/CMakeFiles/hello.dir/version.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello.dir/version.cpp.i"
	cd /d D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\src && D:\Soft\Prog\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Tmp\probs\c_tests\cmake_lessons\ex4\src\version.cpp > CMakeFiles\hello.dir\version.cpp.i

src/CMakeFiles/hello.dir/version.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello.dir/version.cpp.s"
	cd /d D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\src && D:\Soft\Prog\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Tmp\probs\c_tests\cmake_lessons\ex4\src\version.cpp -o CMakeFiles\hello.dir\version.cpp.s

# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/main.cpp.obj" \
"CMakeFiles/hello.dir/version.cpp.obj"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

src/hello.exe: src/CMakeFiles/hello.dir/main.cpp.obj
src/hello.exe: src/CMakeFiles/hello.dir/version.cpp.obj
src/hello.exe: src/CMakeFiles/hello.dir/build.make
src/hello.exe: lib/liblib.a
src/hello.exe: src/CMakeFiles/hello.dir/linklibs.rsp
src/hello.exe: src/CMakeFiles/hello.dir/objects1.rsp
src/hello.exe: src/CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable hello.exe"
	cd /d D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hello.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/hello.dir/build: src/hello.exe
.PHONY : src/CMakeFiles/hello.dir/build

src/CMakeFiles/hello.dir/clean:
	cd /d D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\src && $(CMAKE_COMMAND) -P CMakeFiles\hello.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/hello.dir/clean

src/CMakeFiles/hello.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Tmp\probs\c_tests\cmake_lessons\ex4 D:\Tmp\probs\c_tests\cmake_lessons\ex4\src D:\Tmp\probs\c_tests\cmake_lessons\ex4\build D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\src D:\Tmp\probs\c_tests\cmake_lessons\ex4\build\src\CMakeFiles\hello.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/hello.dir/depend

