# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/bohdan/clion-2019.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/bohdan/clion-2019.1.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project.dir/flags.make

CMakeFiles/project.dir/main.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/main.cpp.o -c /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/main.cpp

CMakeFiles/project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/main.cpp > CMakeFiles/project.dir/main.cpp.i

CMakeFiles/project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/main.cpp -o CMakeFiles/project.dir/main.cpp.s

CMakeFiles/project.dir/src/widget.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/widget.cpp.o: ../src/widget.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project.dir/src/widget.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/src/widget.cpp.o -c /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/widget.cpp

CMakeFiles/project.dir/src/widget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/widget.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/widget.cpp > CMakeFiles/project.dir/src/widget.cpp.i

CMakeFiles/project.dir/src/widget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/widget.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/widget.cpp -o CMakeFiles/project.dir/src/widget.cpp.s

CMakeFiles/project.dir/src/window.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/window.cpp.o: ../src/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project.dir/src/window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/src/window.cpp.o -c /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/window.cpp

CMakeFiles/project.dir/src/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/window.cpp > CMakeFiles/project.dir/src/window.cpp.i

CMakeFiles/project.dir/src/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/window.cpp -o CMakeFiles/project.dir/src/window.cpp.s

CMakeFiles/project.dir/src/text.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/text.cpp.o: ../src/text.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/project.dir/src/text.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/src/text.cpp.o -c /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/text.cpp

CMakeFiles/project.dir/src/text.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/text.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/text.cpp > CMakeFiles/project.dir/src/text.cpp.i

CMakeFiles/project.dir/src/text.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/text.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/text.cpp -o CMakeFiles/project.dir/src/text.cpp.s

CMakeFiles/project.dir/src/button.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/button.cpp.o: ../src/button.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/project.dir/src/button.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/src/button.cpp.o -c /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/button.cpp

CMakeFiles/project.dir/src/button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/button.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/button.cpp > CMakeFiles/project.dir/src/button.cpp.i

CMakeFiles/project.dir/src/button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/button.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/button.cpp -o CMakeFiles/project.dir/src/button.cpp.s

CMakeFiles/project.dir/src/radiobutton.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/radiobutton.cpp.o: ../src/radiobutton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/project.dir/src/radiobutton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/src/radiobutton.cpp.o -c /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/radiobutton.cpp

CMakeFiles/project.dir/src/radiobutton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/radiobutton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/radiobutton.cpp > CMakeFiles/project.dir/src/radiobutton.cpp.i

CMakeFiles/project.dir/src/radiobutton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/radiobutton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/radiobutton.cpp -o CMakeFiles/project.dir/src/radiobutton.cpp.s

CMakeFiles/project.dir/src/text_input.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/text_input.cpp.o: ../src/text_input.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/project.dir/src/text_input.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/src/text_input.cpp.o -c /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/text_input.cpp

CMakeFiles/project.dir/src/text_input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/text_input.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/text_input.cpp > CMakeFiles/project.dir/src/text_input.cpp.i

CMakeFiles/project.dir/src/text_input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/text_input.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/text_input.cpp -o CMakeFiles/project.dir/src/text_input.cpp.s

CMakeFiles/project.dir/src/MyDialog.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/MyDialog.cpp.o: ../src/MyDialog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/project.dir/src/MyDialog.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/src/MyDialog.cpp.o -c /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/MyDialog.cpp

CMakeFiles/project.dir/src/MyDialog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/MyDialog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/MyDialog.cpp > CMakeFiles/project.dir/src/MyDialog.cpp.i

CMakeFiles/project.dir/src/MyDialog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/MyDialog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/src/MyDialog.cpp -o CMakeFiles/project.dir/src/MyDialog.cpp.s

# Object files for target project
project_OBJECTS = \
"CMakeFiles/project.dir/main.cpp.o" \
"CMakeFiles/project.dir/src/widget.cpp.o" \
"CMakeFiles/project.dir/src/window.cpp.o" \
"CMakeFiles/project.dir/src/text.cpp.o" \
"CMakeFiles/project.dir/src/button.cpp.o" \
"CMakeFiles/project.dir/src/radiobutton.cpp.o" \
"CMakeFiles/project.dir/src/text_input.cpp.o" \
"CMakeFiles/project.dir/src/MyDialog.cpp.o"

# External object files for target project
project_EXTERNAL_OBJECTS =

project: CMakeFiles/project.dir/main.cpp.o
project: CMakeFiles/project.dir/src/widget.cpp.o
project: CMakeFiles/project.dir/src/window.cpp.o
project: CMakeFiles/project.dir/src/text.cpp.o
project: CMakeFiles/project.dir/src/button.cpp.o
project: CMakeFiles/project.dir/src/radiobutton.cpp.o
project: CMakeFiles/project.dir/src/text_input.cpp.o
project: CMakeFiles/project.dir/src/MyDialog.cpp.o
project: CMakeFiles/project.dir/build.make
project: /usr/lib/x86_64-linux-gnu/libX11.so
project: CMakeFiles/project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project.dir/build: project

.PHONY : CMakeFiles/project.dir/build

CMakeFiles/project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project.dir/clean

CMakeFiles/project.dir/depend:
	cd /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/cmake-build-debug /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/cmake-build-debug /home/bohdan/CS_Y3_S1_Labs/OS_Labs/XWS_toolkit-master/cmake-build-debug/CMakeFiles/project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project.dir/depend
