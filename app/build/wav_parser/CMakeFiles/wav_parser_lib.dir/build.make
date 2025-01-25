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
include wav_parser/CMakeFiles/wav_parser_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include wav_parser/CMakeFiles/wav_parser_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include wav_parser/CMakeFiles/wav_parser_lib.dir/progress.make

# Include the compile flags for this target's objects.
include wav_parser/CMakeFiles/wav_parser_lib.dir/flags.make

wav_parser/CMakeFiles/wav_parser_lib.dir/wav_advanced_parser.cpp.o: wav_parser/CMakeFiles/wav_parser_lib.dir/flags.make
wav_parser/CMakeFiles/wav_parser_lib.dir/wav_advanced_parser.cpp.o: /home/anton/Documents/OOP/sound_processor/app/wav_parser/wav_advanced_parser.cpp
wav_parser/CMakeFiles/wav_parser_lib.dir/wav_advanced_parser.cpp.o: wav_parser/CMakeFiles/wav_parser_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anton/Documents/OOP/sound_processor/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object wav_parser/CMakeFiles/wav_parser_lib.dir/wav_advanced_parser.cpp.o"
	cd /home/anton/Documents/OOP/sound_processor/app/build/wav_parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT wav_parser/CMakeFiles/wav_parser_lib.dir/wav_advanced_parser.cpp.o -MF CMakeFiles/wav_parser_lib.dir/wav_advanced_parser.cpp.o.d -o CMakeFiles/wav_parser_lib.dir/wav_advanced_parser.cpp.o -c /home/anton/Documents/OOP/sound_processor/app/wav_parser/wav_advanced_parser.cpp

wav_parser/CMakeFiles/wav_parser_lib.dir/wav_advanced_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/wav_parser_lib.dir/wav_advanced_parser.cpp.i"
	cd /home/anton/Documents/OOP/sound_processor/app/build/wav_parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/Documents/OOP/sound_processor/app/wav_parser/wav_advanced_parser.cpp > CMakeFiles/wav_parser_lib.dir/wav_advanced_parser.cpp.i

wav_parser/CMakeFiles/wav_parser_lib.dir/wav_advanced_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/wav_parser_lib.dir/wav_advanced_parser.cpp.s"
	cd /home/anton/Documents/OOP/sound_processor/app/build/wav_parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/Documents/OOP/sound_processor/app/wav_parser/wav_advanced_parser.cpp -o CMakeFiles/wav_parser_lib.dir/wav_advanced_parser.cpp.s

wav_parser/CMakeFiles/wav_parser_lib.dir/wav_files_condition_keeper.cpp.o: wav_parser/CMakeFiles/wav_parser_lib.dir/flags.make
wav_parser/CMakeFiles/wav_parser_lib.dir/wav_files_condition_keeper.cpp.o: /home/anton/Documents/OOP/sound_processor/app/wav_parser/wav_files_condition_keeper.cpp
wav_parser/CMakeFiles/wav_parser_lib.dir/wav_files_condition_keeper.cpp.o: wav_parser/CMakeFiles/wav_parser_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anton/Documents/OOP/sound_processor/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object wav_parser/CMakeFiles/wav_parser_lib.dir/wav_files_condition_keeper.cpp.o"
	cd /home/anton/Documents/OOP/sound_processor/app/build/wav_parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT wav_parser/CMakeFiles/wav_parser_lib.dir/wav_files_condition_keeper.cpp.o -MF CMakeFiles/wav_parser_lib.dir/wav_files_condition_keeper.cpp.o.d -o CMakeFiles/wav_parser_lib.dir/wav_files_condition_keeper.cpp.o -c /home/anton/Documents/OOP/sound_processor/app/wav_parser/wav_files_condition_keeper.cpp

wav_parser/CMakeFiles/wav_parser_lib.dir/wav_files_condition_keeper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/wav_parser_lib.dir/wav_files_condition_keeper.cpp.i"
	cd /home/anton/Documents/OOP/sound_processor/app/build/wav_parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/Documents/OOP/sound_processor/app/wav_parser/wav_files_condition_keeper.cpp > CMakeFiles/wav_parser_lib.dir/wav_files_condition_keeper.cpp.i

wav_parser/CMakeFiles/wav_parser_lib.dir/wav_files_condition_keeper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/wav_parser_lib.dir/wav_files_condition_keeper.cpp.s"
	cd /home/anton/Documents/OOP/sound_processor/app/build/wav_parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/Documents/OOP/sound_processor/app/wav_parser/wav_files_condition_keeper.cpp -o CMakeFiles/wav_parser_lib.dir/wav_files_condition_keeper.cpp.s

# Object files for target wav_parser_lib
wav_parser_lib_OBJECTS = \
"CMakeFiles/wav_parser_lib.dir/wav_advanced_parser.cpp.o" \
"CMakeFiles/wav_parser_lib.dir/wav_files_condition_keeper.cpp.o"

# External object files for target wav_parser_lib
wav_parser_lib_EXTERNAL_OBJECTS =

wav_parser/libwav_parser_lib.a: wav_parser/CMakeFiles/wav_parser_lib.dir/wav_advanced_parser.cpp.o
wav_parser/libwav_parser_lib.a: wav_parser/CMakeFiles/wav_parser_lib.dir/wav_files_condition_keeper.cpp.o
wav_parser/libwav_parser_lib.a: wav_parser/CMakeFiles/wav_parser_lib.dir/build.make
wav_parser/libwav_parser_lib.a: wav_parser/CMakeFiles/wav_parser_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/anton/Documents/OOP/sound_processor/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libwav_parser_lib.a"
	cd /home/anton/Documents/OOP/sound_processor/app/build/wav_parser && $(CMAKE_COMMAND) -P CMakeFiles/wav_parser_lib.dir/cmake_clean_target.cmake
	cd /home/anton/Documents/OOP/sound_processor/app/build/wav_parser && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wav_parser_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
wav_parser/CMakeFiles/wav_parser_lib.dir/build: wav_parser/libwav_parser_lib.a
.PHONY : wav_parser/CMakeFiles/wav_parser_lib.dir/build

wav_parser/CMakeFiles/wav_parser_lib.dir/clean:
	cd /home/anton/Documents/OOP/sound_processor/app/build/wav_parser && $(CMAKE_COMMAND) -P CMakeFiles/wav_parser_lib.dir/cmake_clean.cmake
.PHONY : wav_parser/CMakeFiles/wav_parser_lib.dir/clean

wav_parser/CMakeFiles/wav_parser_lib.dir/depend:
	cd /home/anton/Documents/OOP/sound_processor/app/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anton/Documents/OOP/sound_processor/app /home/anton/Documents/OOP/sound_processor/app/wav_parser /home/anton/Documents/OOP/sound_processor/app/build /home/anton/Documents/OOP/sound_processor/app/build/wav_parser /home/anton/Documents/OOP/sound_processor/app/build/wav_parser/CMakeFiles/wav_parser_lib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : wav_parser/CMakeFiles/wav_parser_lib.dir/depend

