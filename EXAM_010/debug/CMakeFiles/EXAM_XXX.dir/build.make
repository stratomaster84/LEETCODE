# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = E:\MAXSYS\Cmake\bin\cmake.exe

# The command to remove a file.
RM = E:\MAXSYS\Cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = X:\01-MAXDOCS\Projects\QT\EXAM_XXX

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = X:\01-MAXDOCS\Projects\QT\EXAM_XXX\debug

# Include any dependencies generated for this target.
include CMakeFiles/EXAM_XXX.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EXAM_XXX.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EXAM_XXX.dir/flags.make

CMakeFiles/EXAM_XXX.dir/main.cpp.obj: CMakeFiles/EXAM_XXX.dir/flags.make
CMakeFiles/EXAM_XXX.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=X:\01-MAXDOCS\Projects\QT\EXAM_XXX\debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/EXAM_XXX.dir/main.cpp.obj"
	E:\MAXSYS\MSYS2\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\EXAM_XXX.dir\main.cpp.obj -c X:\01-MAXDOCS\Projects\QT\EXAM_XXX\main.cpp

CMakeFiles/EXAM_XXX.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EXAM_XXX.dir/main.cpp.i"
	E:\MAXSYS\MSYS2\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E X:\01-MAXDOCS\Projects\QT\EXAM_XXX\main.cpp > CMakeFiles\EXAM_XXX.dir\main.cpp.i

CMakeFiles/EXAM_XXX.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EXAM_XXX.dir/main.cpp.s"
	E:\MAXSYS\MSYS2\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S X:\01-MAXDOCS\Projects\QT\EXAM_XXX\main.cpp -o CMakeFiles\EXAM_XXX.dir\main.cpp.s

# Object files for target EXAM_XXX
EXAM_XXX_OBJECTS = \
"CMakeFiles/EXAM_XXX.dir/main.cpp.obj"

# External object files for target EXAM_XXX
EXAM_XXX_EXTERNAL_OBJECTS =

EXAM_XXX.exe: CMakeFiles/EXAM_XXX.dir/main.cpp.obj
EXAM_XXX.exe: CMakeFiles/EXAM_XXX.dir/build.make
EXAM_XXX.exe: CMakeFiles/EXAM_XXX.dir/linklibs.rsp
EXAM_XXX.exe: CMakeFiles/EXAM_XXX.dir/objects1.rsp
EXAM_XXX.exe: CMakeFiles/EXAM_XXX.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=X:\01-MAXDOCS\Projects\QT\EXAM_XXX\debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable EXAM_XXX.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\EXAM_XXX.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EXAM_XXX.dir/build: EXAM_XXX.exe

.PHONY : CMakeFiles/EXAM_XXX.dir/build

CMakeFiles/EXAM_XXX.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\EXAM_XXX.dir\cmake_clean.cmake
.PHONY : CMakeFiles/EXAM_XXX.dir/clean

CMakeFiles/EXAM_XXX.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" X:\01-MAXDOCS\Projects\QT\EXAM_XXX X:\01-MAXDOCS\Projects\QT\EXAM_XXX X:\01-MAXDOCS\Projects\QT\EXAM_XXX\debug X:\01-MAXDOCS\Projects\QT\EXAM_XXX\debug X:\01-MAXDOCS\Projects\QT\EXAM_XXX\debug\CMakeFiles\EXAM_XXX.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EXAM_XXX.dir/depend

