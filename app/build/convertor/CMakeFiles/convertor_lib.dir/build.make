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
include convertor/CMakeFiles/convertor_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include convertor/CMakeFiles/convertor_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include convertor/CMakeFiles/convertor_lib.dir/progress.make

# Include the compile flags for this target's objects.
include convertor/CMakeFiles/convertor_lib.dir/flags.make

convertor/CMakeFiles/convertor_lib.dir/inverse_convertor_creator.cpp.o: convertor/CMakeFiles/convertor_lib.dir/flags.make
convertor/CMakeFiles/convertor_lib.dir/inverse_convertor_creator.cpp.o: /home/anton/Documents/OOP/sound_processor/app/convertor/inverse_convertor_creator.cpp
convertor/CMakeFiles/convertor_lib.dir/inverse_convertor_creator.cpp.o: convertor/CMakeFiles/convertor_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anton/Documents/OOP/sound_processor/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object convertor/CMakeFiles/convertor_lib.dir/inverse_convertor_creator.cpp.o"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT convertor/CMakeFiles/convertor_lib.dir/inverse_convertor_creator.cpp.o -MF CMakeFiles/convertor_lib.dir/inverse_convertor_creator.cpp.o.d -o CMakeFiles/convertor_lib.dir/inverse_convertor_creator.cpp.o -c /home/anton/Documents/OOP/sound_processor/app/convertor/inverse_convertor_creator.cpp

convertor/CMakeFiles/convertor_lib.dir/inverse_convertor_creator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/convertor_lib.dir/inverse_convertor_creator.cpp.i"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/Documents/OOP/sound_processor/app/convertor/inverse_convertor_creator.cpp > CMakeFiles/convertor_lib.dir/inverse_convertor_creator.cpp.i

convertor/CMakeFiles/convertor_lib.dir/inverse_convertor_creator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/convertor_lib.dir/inverse_convertor_creator.cpp.s"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/Documents/OOP/sound_processor/app/convertor/inverse_convertor_creator.cpp -o CMakeFiles/convertor_lib.dir/inverse_convertor_creator.cpp.s

convertor/CMakeFiles/convertor_lib.dir/inverse_convertor.cpp.o: convertor/CMakeFiles/convertor_lib.dir/flags.make
convertor/CMakeFiles/convertor_lib.dir/inverse_convertor.cpp.o: /home/anton/Documents/OOP/sound_processor/app/convertor/inverse_convertor.cpp
convertor/CMakeFiles/convertor_lib.dir/inverse_convertor.cpp.o: convertor/CMakeFiles/convertor_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anton/Documents/OOP/sound_processor/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object convertor/CMakeFiles/convertor_lib.dir/inverse_convertor.cpp.o"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT convertor/CMakeFiles/convertor_lib.dir/inverse_convertor.cpp.o -MF CMakeFiles/convertor_lib.dir/inverse_convertor.cpp.o.d -o CMakeFiles/convertor_lib.dir/inverse_convertor.cpp.o -c /home/anton/Documents/OOP/sound_processor/app/convertor/inverse_convertor.cpp

convertor/CMakeFiles/convertor_lib.dir/inverse_convertor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/convertor_lib.dir/inverse_convertor.cpp.i"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/Documents/OOP/sound_processor/app/convertor/inverse_convertor.cpp > CMakeFiles/convertor_lib.dir/inverse_convertor.cpp.i

convertor/CMakeFiles/convertor_lib.dir/inverse_convertor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/convertor_lib.dir/inverse_convertor.cpp.s"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/Documents/OOP/sound_processor/app/convertor/inverse_convertor.cpp -o CMakeFiles/convertor_lib.dir/inverse_convertor.cpp.s

convertor/CMakeFiles/convertor_lib.dir/mix_convertor_creator.cpp.o: convertor/CMakeFiles/convertor_lib.dir/flags.make
convertor/CMakeFiles/convertor_lib.dir/mix_convertor_creator.cpp.o: /home/anton/Documents/OOP/sound_processor/app/convertor/mix_convertor_creator.cpp
convertor/CMakeFiles/convertor_lib.dir/mix_convertor_creator.cpp.o: convertor/CMakeFiles/convertor_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anton/Documents/OOP/sound_processor/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object convertor/CMakeFiles/convertor_lib.dir/mix_convertor_creator.cpp.o"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT convertor/CMakeFiles/convertor_lib.dir/mix_convertor_creator.cpp.o -MF CMakeFiles/convertor_lib.dir/mix_convertor_creator.cpp.o.d -o CMakeFiles/convertor_lib.dir/mix_convertor_creator.cpp.o -c /home/anton/Documents/OOP/sound_processor/app/convertor/mix_convertor_creator.cpp

convertor/CMakeFiles/convertor_lib.dir/mix_convertor_creator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/convertor_lib.dir/mix_convertor_creator.cpp.i"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/Documents/OOP/sound_processor/app/convertor/mix_convertor_creator.cpp > CMakeFiles/convertor_lib.dir/mix_convertor_creator.cpp.i

convertor/CMakeFiles/convertor_lib.dir/mix_convertor_creator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/convertor_lib.dir/mix_convertor_creator.cpp.s"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/Documents/OOP/sound_processor/app/convertor/mix_convertor_creator.cpp -o CMakeFiles/convertor_lib.dir/mix_convertor_creator.cpp.s

convertor/CMakeFiles/convertor_lib.dir/mix_convertor.cpp.o: convertor/CMakeFiles/convertor_lib.dir/flags.make
convertor/CMakeFiles/convertor_lib.dir/mix_convertor.cpp.o: /home/anton/Documents/OOP/sound_processor/app/convertor/mix_convertor.cpp
convertor/CMakeFiles/convertor_lib.dir/mix_convertor.cpp.o: convertor/CMakeFiles/convertor_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anton/Documents/OOP/sound_processor/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object convertor/CMakeFiles/convertor_lib.dir/mix_convertor.cpp.o"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT convertor/CMakeFiles/convertor_lib.dir/mix_convertor.cpp.o -MF CMakeFiles/convertor_lib.dir/mix_convertor.cpp.o.d -o CMakeFiles/convertor_lib.dir/mix_convertor.cpp.o -c /home/anton/Documents/OOP/sound_processor/app/convertor/mix_convertor.cpp

convertor/CMakeFiles/convertor_lib.dir/mix_convertor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/convertor_lib.dir/mix_convertor.cpp.i"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/Documents/OOP/sound_processor/app/convertor/mix_convertor.cpp > CMakeFiles/convertor_lib.dir/mix_convertor.cpp.i

convertor/CMakeFiles/convertor_lib.dir/mix_convertor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/convertor_lib.dir/mix_convertor.cpp.s"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/Documents/OOP/sound_processor/app/convertor/mix_convertor.cpp -o CMakeFiles/convertor_lib.dir/mix_convertor.cpp.s

convertor/CMakeFiles/convertor_lib.dir/mute_convertor_creator.cpp.o: convertor/CMakeFiles/convertor_lib.dir/flags.make
convertor/CMakeFiles/convertor_lib.dir/mute_convertor_creator.cpp.o: /home/anton/Documents/OOP/sound_processor/app/convertor/mute_convertor_creator.cpp
convertor/CMakeFiles/convertor_lib.dir/mute_convertor_creator.cpp.o: convertor/CMakeFiles/convertor_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anton/Documents/OOP/sound_processor/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object convertor/CMakeFiles/convertor_lib.dir/mute_convertor_creator.cpp.o"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT convertor/CMakeFiles/convertor_lib.dir/mute_convertor_creator.cpp.o -MF CMakeFiles/convertor_lib.dir/mute_convertor_creator.cpp.o.d -o CMakeFiles/convertor_lib.dir/mute_convertor_creator.cpp.o -c /home/anton/Documents/OOP/sound_processor/app/convertor/mute_convertor_creator.cpp

convertor/CMakeFiles/convertor_lib.dir/mute_convertor_creator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/convertor_lib.dir/mute_convertor_creator.cpp.i"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/Documents/OOP/sound_processor/app/convertor/mute_convertor_creator.cpp > CMakeFiles/convertor_lib.dir/mute_convertor_creator.cpp.i

convertor/CMakeFiles/convertor_lib.dir/mute_convertor_creator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/convertor_lib.dir/mute_convertor_creator.cpp.s"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/Documents/OOP/sound_processor/app/convertor/mute_convertor_creator.cpp -o CMakeFiles/convertor_lib.dir/mute_convertor_creator.cpp.s

convertor/CMakeFiles/convertor_lib.dir/mute_convertor.cpp.o: convertor/CMakeFiles/convertor_lib.dir/flags.make
convertor/CMakeFiles/convertor_lib.dir/mute_convertor.cpp.o: /home/anton/Documents/OOP/sound_processor/app/convertor/mute_convertor.cpp
convertor/CMakeFiles/convertor_lib.dir/mute_convertor.cpp.o: convertor/CMakeFiles/convertor_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anton/Documents/OOP/sound_processor/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object convertor/CMakeFiles/convertor_lib.dir/mute_convertor.cpp.o"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT convertor/CMakeFiles/convertor_lib.dir/mute_convertor.cpp.o -MF CMakeFiles/convertor_lib.dir/mute_convertor.cpp.o.d -o CMakeFiles/convertor_lib.dir/mute_convertor.cpp.o -c /home/anton/Documents/OOP/sound_processor/app/convertor/mute_convertor.cpp

convertor/CMakeFiles/convertor_lib.dir/mute_convertor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/convertor_lib.dir/mute_convertor.cpp.i"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/Documents/OOP/sound_processor/app/convertor/mute_convertor.cpp > CMakeFiles/convertor_lib.dir/mute_convertor.cpp.i

convertor/CMakeFiles/convertor_lib.dir/mute_convertor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/convertor_lib.dir/mute_convertor.cpp.s"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/Documents/OOP/sound_processor/app/convertor/mute_convertor.cpp -o CMakeFiles/convertor_lib.dir/mute_convertor.cpp.s

# Object files for target convertor_lib
convertor_lib_OBJECTS = \
"CMakeFiles/convertor_lib.dir/inverse_convertor_creator.cpp.o" \
"CMakeFiles/convertor_lib.dir/inverse_convertor.cpp.o" \
"CMakeFiles/convertor_lib.dir/mix_convertor_creator.cpp.o" \
"CMakeFiles/convertor_lib.dir/mix_convertor.cpp.o" \
"CMakeFiles/convertor_lib.dir/mute_convertor_creator.cpp.o" \
"CMakeFiles/convertor_lib.dir/mute_convertor.cpp.o"

# External object files for target convertor_lib
convertor_lib_EXTERNAL_OBJECTS =

convertor/libconvertor_lib.a: convertor/CMakeFiles/convertor_lib.dir/inverse_convertor_creator.cpp.o
convertor/libconvertor_lib.a: convertor/CMakeFiles/convertor_lib.dir/inverse_convertor.cpp.o
convertor/libconvertor_lib.a: convertor/CMakeFiles/convertor_lib.dir/mix_convertor_creator.cpp.o
convertor/libconvertor_lib.a: convertor/CMakeFiles/convertor_lib.dir/mix_convertor.cpp.o
convertor/libconvertor_lib.a: convertor/CMakeFiles/convertor_lib.dir/mute_convertor_creator.cpp.o
convertor/libconvertor_lib.a: convertor/CMakeFiles/convertor_lib.dir/mute_convertor.cpp.o
convertor/libconvertor_lib.a: convertor/CMakeFiles/convertor_lib.dir/build.make
convertor/libconvertor_lib.a: convertor/CMakeFiles/convertor_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/anton/Documents/OOP/sound_processor/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libconvertor_lib.a"
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && $(CMAKE_COMMAND) -P CMakeFiles/convertor_lib.dir/cmake_clean_target.cmake
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/convertor_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
convertor/CMakeFiles/convertor_lib.dir/build: convertor/libconvertor_lib.a
.PHONY : convertor/CMakeFiles/convertor_lib.dir/build

convertor/CMakeFiles/convertor_lib.dir/clean:
	cd /home/anton/Documents/OOP/sound_processor/app/build/convertor && $(CMAKE_COMMAND) -P CMakeFiles/convertor_lib.dir/cmake_clean.cmake
.PHONY : convertor/CMakeFiles/convertor_lib.dir/clean

convertor/CMakeFiles/convertor_lib.dir/depend:
	cd /home/anton/Documents/OOP/sound_processor/app/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anton/Documents/OOP/sound_processor/app /home/anton/Documents/OOP/sound_processor/app/convertor /home/anton/Documents/OOP/sound_processor/app/build /home/anton/Documents/OOP/sound_processor/app/build/convertor /home/anton/Documents/OOP/sound_processor/app/build/convertor/CMakeFiles/convertor_lib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : convertor/CMakeFiles/convertor_lib.dir/depend

