# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/fotis/Documents/Thesis/git_folder/Sockets&Parsing"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/fotis/Documents/Thesis/git_folder/Sockets&Parsing/build"

# Include any dependencies generated for this target.
include CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

CMakeFiles/client.dir/client.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/client.cpp.o: ../client.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/fotis/Documents/Thesis/git_folder/Sockets&Parsing/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/client.dir/client.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client.dir/client.cpp.o -c "/home/fotis/Documents/Thesis/git_folder/Sockets&Parsing/client.cpp"

CMakeFiles/client.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/client.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/fotis/Documents/Thesis/git_folder/Sockets&Parsing/client.cpp" > CMakeFiles/client.dir/client.cpp.i

CMakeFiles/client.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/client.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/fotis/Documents/Thesis/git_folder/Sockets&Parsing/client.cpp" -o CMakeFiles/client.dir/client.cpp.s

CMakeFiles/client.dir/client.cpp.o.requires:
.PHONY : CMakeFiles/client.dir/client.cpp.o.requires

CMakeFiles/client.dir/client.cpp.o.provides: CMakeFiles/client.dir/client.cpp.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/client.cpp.o.provides.build
.PHONY : CMakeFiles/client.dir/client.cpp.o.provides

CMakeFiles/client.dir/client.cpp.o.provides.build: CMakeFiles/client.dir/client.cpp.o

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/client.cpp.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

client: CMakeFiles/client.dir/client.cpp.o
client: CMakeFiles/client.dir/build.make
client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: client
.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/requires: CMakeFiles/client.dir/client.cpp.o.requires
.PHONY : CMakeFiles/client.dir/requires

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend:
	cd "/home/fotis/Documents/Thesis/git_folder/Sockets&Parsing/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/fotis/Documents/Thesis/git_folder/Sockets&Parsing" "/home/fotis/Documents/Thesis/git_folder/Sockets&Parsing" "/home/fotis/Documents/Thesis/git_folder/Sockets&Parsing/build" "/home/fotis/Documents/Thesis/git_folder/Sockets&Parsing/build" "/home/fotis/Documents/Thesis/git_folder/Sockets&Parsing/build/CMakeFiles/client.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/client.dir/depend

