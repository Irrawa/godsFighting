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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/otbooster/Downloads/2019up/cpp/gods

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/otbooster/Downloads/2019up/cpp/gods/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/gods.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gods.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gods.dir/flags.make

CMakeFiles/gods.dir/main.cpp.o: CMakeFiles/gods.dir/flags.make
CMakeFiles/gods.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/otbooster/Downloads/2019up/cpp/gods/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gods.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gods.dir/main.cpp.o -c /Users/otbooster/Downloads/2019up/cpp/gods/main.cpp

CMakeFiles/gods.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gods.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/otbooster/Downloads/2019up/cpp/gods/main.cpp > CMakeFiles/gods.dir/main.cpp.i

CMakeFiles/gods.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gods.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/otbooster/Downloads/2019up/cpp/gods/main.cpp -o CMakeFiles/gods.dir/main.cpp.s

CMakeFiles/gods.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/gods.dir/main.cpp.o.requires

CMakeFiles/gods.dir/main.cpp.o.provides: CMakeFiles/gods.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/gods.dir/build.make CMakeFiles/gods.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/gods.dir/main.cpp.o.provides

CMakeFiles/gods.dir/main.cpp.o.provides.build: CMakeFiles/gods.dir/main.cpp.o


# Object files for target gods
gods_OBJECTS = \
"CMakeFiles/gods.dir/main.cpp.o"

# External object files for target gods
gods_EXTERNAL_OBJECTS =

gods: CMakeFiles/gods.dir/main.cpp.o
gods: CMakeFiles/gods.dir/build.make
gods: CMakeFiles/gods.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/otbooster/Downloads/2019up/cpp/gods/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gods"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gods.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gods.dir/build: gods

.PHONY : CMakeFiles/gods.dir/build

CMakeFiles/gods.dir/requires: CMakeFiles/gods.dir/main.cpp.o.requires

.PHONY : CMakeFiles/gods.dir/requires

CMakeFiles/gods.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gods.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gods.dir/clean

CMakeFiles/gods.dir/depend:
	cd /Users/otbooster/Downloads/2019up/cpp/gods/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/otbooster/Downloads/2019up/cpp/gods /Users/otbooster/Downloads/2019up/cpp/gods /Users/otbooster/Downloads/2019up/cpp/gods/cmake-build-debug /Users/otbooster/Downloads/2019up/cpp/gods/cmake-build-debug /Users/otbooster/Downloads/2019up/cpp/gods/cmake-build-debug/CMakeFiles/gods.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gods.dir/depend

