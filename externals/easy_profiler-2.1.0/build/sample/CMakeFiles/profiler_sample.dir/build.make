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
CMAKE_SOURCE_DIR = /home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0/build

# Include any dependencies generated for this target.
include sample/CMakeFiles/profiler_sample.dir/depend.make

# Include the progress variables for this target.
include sample/CMakeFiles/profiler_sample.dir/progress.make

# Include the compile flags for this target's objects.
include sample/CMakeFiles/profiler_sample.dir/flags.make

sample/CMakeFiles/profiler_sample.dir/main.cpp.o: sample/CMakeFiles/profiler_sample.dir/flags.make
sample/CMakeFiles/profiler_sample.dir/main.cpp.o: ../sample/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object sample/CMakeFiles/profiler_sample.dir/main.cpp.o"
	cd /home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0/build/sample && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/profiler_sample.dir/main.cpp.o -c /home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0/sample/main.cpp

sample/CMakeFiles/profiler_sample.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/profiler_sample.dir/main.cpp.i"
	cd /home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0/build/sample && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0/sample/main.cpp > CMakeFiles/profiler_sample.dir/main.cpp.i

sample/CMakeFiles/profiler_sample.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/profiler_sample.dir/main.cpp.s"
	cd /home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0/build/sample && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0/sample/main.cpp -o CMakeFiles/profiler_sample.dir/main.cpp.s

# Object files for target profiler_sample
profiler_sample_OBJECTS = \
"CMakeFiles/profiler_sample.dir/main.cpp.o"

# External object files for target profiler_sample
profiler_sample_EXTERNAL_OBJECTS =

bin/profiler_sample: sample/CMakeFiles/profiler_sample.dir/main.cpp.o
bin/profiler_sample: sample/CMakeFiles/profiler_sample.dir/build.make
bin/profiler_sample: bin/libeasy_profiler.so
bin/profiler_sample: sample/CMakeFiles/profiler_sample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/profiler_sample"
	cd /home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0/build/sample && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/profiler_sample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sample/CMakeFiles/profiler_sample.dir/build: bin/profiler_sample

.PHONY : sample/CMakeFiles/profiler_sample.dir/build

sample/CMakeFiles/profiler_sample.dir/clean:
	cd /home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0/build/sample && $(CMAKE_COMMAND) -P CMakeFiles/profiler_sample.dir/cmake_clean.cmake
.PHONY : sample/CMakeFiles/profiler_sample.dir/clean

sample/CMakeFiles/profiler_sample.dir/depend:
	cd /home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0 /home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0/sample /home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0/build /home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0/build/sample /home/efarhan/Development/NekoEngine/externals/easy_profiler-2.1.0/build/sample/CMakeFiles/profiler_sample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sample/CMakeFiles/profiler_sample.dir/depend

