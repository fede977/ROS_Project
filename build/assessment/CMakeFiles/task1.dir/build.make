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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fede/Desktop/Assessment/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fede/Desktop/Assessment/build

# Include any dependencies generated for this target.
include assessment/CMakeFiles/task1.dir/depend.make

# Include the progress variables for this target.
include assessment/CMakeFiles/task1.dir/progress.make

# Include the compile flags for this target's objects.
include assessment/CMakeFiles/task1.dir/flags.make

assessment/CMakeFiles/task1.dir/src/task1.cpp.o: assessment/CMakeFiles/task1.dir/flags.make
assessment/CMakeFiles/task1.dir/src/task1.cpp.o: /home/fede/Desktop/Assessment/src/assessment/src/task1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fede/Desktop/Assessment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object assessment/CMakeFiles/task1.dir/src/task1.cpp.o"
	cd /home/fede/Desktop/Assessment/build/assessment && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task1.dir/src/task1.cpp.o -c /home/fede/Desktop/Assessment/src/assessment/src/task1.cpp

assessment/CMakeFiles/task1.dir/src/task1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task1.dir/src/task1.cpp.i"
	cd /home/fede/Desktop/Assessment/build/assessment && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fede/Desktop/Assessment/src/assessment/src/task1.cpp > CMakeFiles/task1.dir/src/task1.cpp.i

assessment/CMakeFiles/task1.dir/src/task1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task1.dir/src/task1.cpp.s"
	cd /home/fede/Desktop/Assessment/build/assessment && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fede/Desktop/Assessment/src/assessment/src/task1.cpp -o CMakeFiles/task1.dir/src/task1.cpp.s

assessment/CMakeFiles/task1.dir/src/task1.cpp.o.requires:

.PHONY : assessment/CMakeFiles/task1.dir/src/task1.cpp.o.requires

assessment/CMakeFiles/task1.dir/src/task1.cpp.o.provides: assessment/CMakeFiles/task1.dir/src/task1.cpp.o.requires
	$(MAKE) -f assessment/CMakeFiles/task1.dir/build.make assessment/CMakeFiles/task1.dir/src/task1.cpp.o.provides.build
.PHONY : assessment/CMakeFiles/task1.dir/src/task1.cpp.o.provides

assessment/CMakeFiles/task1.dir/src/task1.cpp.o.provides.build: assessment/CMakeFiles/task1.dir/src/task1.cpp.o


# Object files for target task1
task1_OBJECTS = \
"CMakeFiles/task1.dir/src/task1.cpp.o"

# External object files for target task1
task1_EXTERNAL_OBJECTS =

/home/fede/Desktop/Assessment/devel/lib/assessment/task1: assessment/CMakeFiles/task1.dir/src/task1.cpp.o
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: assessment/CMakeFiles/task1.dir/build.make
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /opt/ros/melodic/lib/libtf.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /opt/ros/melodic/lib/libtf2_ros.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /opt/ros/melodic/lib/libactionlib.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /opt/ros/melodic/lib/libmessage_filters.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /opt/ros/melodic/lib/libroscpp.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /opt/ros/melodic/lib/libtf2.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /opt/ros/melodic/lib/librosconsole.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /opt/ros/melodic/lib/librostime.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /opt/ros/melodic/lib/libcpp_common.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/fede/Desktop/Assessment/devel/lib/assessment/task1: assessment/CMakeFiles/task1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fede/Desktop/Assessment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/fede/Desktop/Assessment/devel/lib/assessment/task1"
	cd /home/fede/Desktop/Assessment/build/assessment && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
assessment/CMakeFiles/task1.dir/build: /home/fede/Desktop/Assessment/devel/lib/assessment/task1

.PHONY : assessment/CMakeFiles/task1.dir/build

assessment/CMakeFiles/task1.dir/requires: assessment/CMakeFiles/task1.dir/src/task1.cpp.o.requires

.PHONY : assessment/CMakeFiles/task1.dir/requires

assessment/CMakeFiles/task1.dir/clean:
	cd /home/fede/Desktop/Assessment/build/assessment && $(CMAKE_COMMAND) -P CMakeFiles/task1.dir/cmake_clean.cmake
.PHONY : assessment/CMakeFiles/task1.dir/clean

assessment/CMakeFiles/task1.dir/depend:
	cd /home/fede/Desktop/Assessment/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fede/Desktop/Assessment/src /home/fede/Desktop/Assessment/src/assessment /home/fede/Desktop/Assessment/build /home/fede/Desktop/Assessment/build/assessment /home/fede/Desktop/Assessment/build/assessment/CMakeFiles/task1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : assessment/CMakeFiles/task1.dir/depend

