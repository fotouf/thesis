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
CMAKE_SOURCE_DIR = "/home/fotis/Documents/Thesis/Sockets&Parsing"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/fotis/Documents/Thesis/Sockets&Parsing/build"

# Include any dependencies generated for this target.
include CMakeFiles/New_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/New_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/New_server.dir/flags.make

CMakeFiles/New_server.dir/server.cpp.o: CMakeFiles/New_server.dir/flags.make
CMakeFiles/New_server.dir/server.cpp.o: ../server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/fotis/Documents/Thesis/Sockets&Parsing/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/New_server.dir/server.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/New_server.dir/server.cpp.o -c "/home/fotis/Documents/Thesis/Sockets&Parsing/server.cpp"

CMakeFiles/New_server.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/New_server.dir/server.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/fotis/Documents/Thesis/Sockets&Parsing/server.cpp" > CMakeFiles/New_server.dir/server.cpp.i

CMakeFiles/New_server.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/New_server.dir/server.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/fotis/Documents/Thesis/Sockets&Parsing/server.cpp" -o CMakeFiles/New_server.dir/server.cpp.s

CMakeFiles/New_server.dir/server.cpp.o.requires:
.PHONY : CMakeFiles/New_server.dir/server.cpp.o.requires

CMakeFiles/New_server.dir/server.cpp.o.provides: CMakeFiles/New_server.dir/server.cpp.o.requires
	$(MAKE) -f CMakeFiles/New_server.dir/build.make CMakeFiles/New_server.dir/server.cpp.o.provides.build
.PHONY : CMakeFiles/New_server.dir/server.cpp.o.provides

CMakeFiles/New_server.dir/server.cpp.o.provides.build: CMakeFiles/New_server.dir/server.cpp.o

CMakeFiles/New_server.dir/Parsing_functions.cpp.o: CMakeFiles/New_server.dir/flags.make
CMakeFiles/New_server.dir/Parsing_functions.cpp.o: ../Parsing_functions.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/fotis/Documents/Thesis/Sockets&Parsing/build/CMakeFiles" $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/New_server.dir/Parsing_functions.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/New_server.dir/Parsing_functions.cpp.o -c "/home/fotis/Documents/Thesis/Sockets&Parsing/Parsing_functions.cpp"

CMakeFiles/New_server.dir/Parsing_functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/New_server.dir/Parsing_functions.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/fotis/Documents/Thesis/Sockets&Parsing/Parsing_functions.cpp" > CMakeFiles/New_server.dir/Parsing_functions.cpp.i

CMakeFiles/New_server.dir/Parsing_functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/New_server.dir/Parsing_functions.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/fotis/Documents/Thesis/Sockets&Parsing/Parsing_functions.cpp" -o CMakeFiles/New_server.dir/Parsing_functions.cpp.s

CMakeFiles/New_server.dir/Parsing_functions.cpp.o.requires:
.PHONY : CMakeFiles/New_server.dir/Parsing_functions.cpp.o.requires

CMakeFiles/New_server.dir/Parsing_functions.cpp.o.provides: CMakeFiles/New_server.dir/Parsing_functions.cpp.o.requires
	$(MAKE) -f CMakeFiles/New_server.dir/build.make CMakeFiles/New_server.dir/Parsing_functions.cpp.o.provides.build
.PHONY : CMakeFiles/New_server.dir/Parsing_functions.cpp.o.provides

CMakeFiles/New_server.dir/Parsing_functions.cpp.o.provides.build: CMakeFiles/New_server.dir/Parsing_functions.cpp.o

# Object files for target New_server
New_server_OBJECTS = \
"CMakeFiles/New_server.dir/server.cpp.o" \
"CMakeFiles/New_server.dir/Parsing_functions.cpp.o"

# External object files for target New_server
New_server_EXTERNAL_OBJECTS =

New_server: CMakeFiles/New_server.dir/server.cpp.o
New_server: CMakeFiles/New_server.dir/Parsing_functions.cpp.o
New_server: CMakeFiles/New_server.dir/build.make
New_server: CMakeFiles/New_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable New_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/New_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/New_server.dir/build: New_server
.PHONY : CMakeFiles/New_server.dir/build

CMakeFiles/New_server.dir/requires: CMakeFiles/New_server.dir/server.cpp.o.requires
CMakeFiles/New_server.dir/requires: CMakeFiles/New_server.dir/Parsing_functions.cpp.o.requires
.PHONY : CMakeFiles/New_server.dir/requires

CMakeFiles/New_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/New_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/New_server.dir/clean

CMakeFiles/New_server.dir/depend:
	cd "/home/fotis/Documents/Thesis/Sockets&Parsing/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/fotis/Documents/Thesis/Sockets&Parsing" "/home/fotis/Documents/Thesis/Sockets&Parsing" "/home/fotis/Documents/Thesis/Sockets&Parsing/build" "/home/fotis/Documents/Thesis/Sockets&Parsing/build" "/home/fotis/Documents/Thesis/Sockets&Parsing/build/CMakeFiles/New_server.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/New_server.dir/depend

