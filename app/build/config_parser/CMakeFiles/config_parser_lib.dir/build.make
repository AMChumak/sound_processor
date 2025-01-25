# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/anton/Documents/OOP/sound_processor/app

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anton/Documents/OOP/sound_processor/app/build

# Include any dependencies generated for this target.
include config_parser/CMakeFiles/config_parser_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include config_parser/CMakeFiles/config_parser_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include config_parser/CMakeFiles/config_parser_lib.dir/progress.make

# Include the compile flags for this target's objects.
include config_parser/CMakeFiles/config_parser_lib.dir/flags.make

config_parser/CMakeFiles/config_parser_lib.dir/simple_config_parser.cpp.o: config_parser/CMakeFiles/config_parser_lib.dir/flags.make
config_parser/CMakeFiles/config_parser_lib.dir/simple_config_parser.cpp.o: /home/anton/Documents/OOP/sound_processor/app/config_parser/simple_config_parser.cpp
config_parser/CMakeFiles/config_parser_lib.dir/simple_config_parser.cpp.o: config_parser/CMakeFiles/config_parser_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anton/Documents/OOP/sound_processor/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object config_parser/CMakeFiles/config_parser_lib.dir/simple_config_parser.cpp.o"
	cd /home/anton/Documents/OOP/sound_processor/app/build/config_parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT config_parser/CMakeFiles/config_parser_lib.dir/simple_config_parser.cpp.o -MF CMakeFiles/config_parser_lib.dir/simple_config_parser.cpp.o.d -o CMakeFiles/config_parser_lib.dir/simple_config_parser.cpp.o -c /home/anton/Documents/OOP/sound_processor/app/config_parser/simple_config_parser.cpp

config_parser/CMakeFiles/config_parser_lib.dir/simple_config_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/config_parser_lib.dir/simple_config_parser.cpp.i"
	cd /home/anton/Documents/OOP/sound_processor/app/build/config_parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/Documents/OOP/sound_processor/app/config_parser/simple_config_parser.cpp > CMakeFiles/config_parser_lib.dir/simple_config_parser.cpp.i

config_parser/CMakeFiles/config_parser_lib.dir/simple_config_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/config_parser_lib.dir/simple_config_parser.cpp.s"
	cd /home/anton/Documents/OOP/sound_processor/app/build/config_parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/Documents/OOP/sound_processor/app/config_parser/simple_config_parser.cpp -o CMakeFiles/config_parser_lib.dir/simple_config_parser.cpp.s

# Object files for target config_parser_lib
config_parser_lib_OBJECTS = \
"CMakeFiles/config_parser_lib.dir/simple_config_parser.cpp.o"

# External object files for target config_parser_lib
config_parser_lib_EXTERNAL_OBJECTS =

config_parser/libconfig_parser_lib.a: config_parser/CMakeFiles/config_parser_lib.dir/simple_config_parser.cpp.o
config_parser/libconfig_parser_lib.a: config_parser/CMakeFiles/config_parser_lib.dir/build.make
config_parser/libconfig_parser_lib.a: config_parser/CMakeFiles/config_parser_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/anton/Documents/OOP/sound_processor/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libconfig_parser_lib.a"
	cd /home/anton/Documents/OOP/sound_processor/app/build/config_parser && $(CMAKE_COMMAND) -P CMakeFiles/config_parser_lib.dir/cmake_clean_target.cmake
	cd /home/anton/Documents/OOP/sound_processor/app/build/config_parser && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/config_parser_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
config_parser/CMakeFiles/config_parser_lib.dir/build: config_parser/libconfig_parser_lib.a
.PHONY : config_parser/CMakeFiles/config_parser_lib.dir/build

config_parser/CMakeFiles/config_parser_lib.dir/clean:
	cd /home/anton/Documents/OOP/sound_processor/app/build/config_parser && $(CMAKE_COMMAND) -P CMakeFiles/config_parser_lib.dir/cmake_clean.cmake
.PHONY : config_parser/CMakeFiles/config_parser_lib.dir/clean

config_parser/CMakeFiles/config_parser_lib.dir/depend:
	cd /home/anton/Documents/OOP/sound_processor/app/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anton/Documents/OOP/sound_processor/app /home/anton/Documents/OOP/sound_processor/app/config_parser /home/anton/Documents/OOP/sound_processor/app/build /home/anton/Documents/OOP/sound_processor/app/build/config_parser /home/anton/Documents/OOP/sound_processor/app/build/config_parser/CMakeFiles/config_parser_lib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : config_parser/CMakeFiles/config_parser_lib.dir/depend

