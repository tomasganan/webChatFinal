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
CMAKE_SOURCE_DIR = /home/tomas/Escritorio/webChatFinal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tomas/Escritorio/webChatFinal/build

# Include any dependencies generated for this target.
include libs/CMakeFiles/iniparser.dir/depend.make

# Include the progress variables for this target.
include libs/CMakeFiles/iniparser.dir/progress.make

# Include the compile flags for this target's objects.
include libs/CMakeFiles/iniparser.dir/flags.make

libs/CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.o: libs/CMakeFiles/iniparser.dir/flags.make
libs/CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.o: ../libs/iniparser/src/dictionary.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tomas/Escritorio/webChatFinal/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.o"
	cd /home/tomas/Escritorio/webChatFinal/build/libs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.o   -c /home/tomas/Escritorio/webChatFinal/libs/iniparser/src/dictionary.c

libs/CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.i"
	cd /home/tomas/Escritorio/webChatFinal/build/libs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tomas/Escritorio/webChatFinal/libs/iniparser/src/dictionary.c > CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.i

libs/CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.s"
	cd /home/tomas/Escritorio/webChatFinal/build/libs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tomas/Escritorio/webChatFinal/libs/iniparser/src/dictionary.c -o CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.s

libs/CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.o.requires:

.PHONY : libs/CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.o.requires

libs/CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.o.provides: libs/CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.o.requires
	$(MAKE) -f libs/CMakeFiles/iniparser.dir/build.make libs/CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.o.provides.build
.PHONY : libs/CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.o.provides

libs/CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.o.provides.build: libs/CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.o


libs/CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.o: libs/CMakeFiles/iniparser.dir/flags.make
libs/CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.o: ../libs/iniparser/src/iniparser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tomas/Escritorio/webChatFinal/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object libs/CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.o"
	cd /home/tomas/Escritorio/webChatFinal/build/libs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.o   -c /home/tomas/Escritorio/webChatFinal/libs/iniparser/src/iniparser.c

libs/CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.i"
	cd /home/tomas/Escritorio/webChatFinal/build/libs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tomas/Escritorio/webChatFinal/libs/iniparser/src/iniparser.c > CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.i

libs/CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.s"
	cd /home/tomas/Escritorio/webChatFinal/build/libs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tomas/Escritorio/webChatFinal/libs/iniparser/src/iniparser.c -o CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.s

libs/CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.o.requires:

.PHONY : libs/CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.o.requires

libs/CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.o.provides: libs/CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.o.requires
	$(MAKE) -f libs/CMakeFiles/iniparser.dir/build.make libs/CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.o.provides.build
.PHONY : libs/CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.o.provides

libs/CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.o.provides.build: libs/CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.o


# Object files for target iniparser
iniparser_OBJECTS = \
"CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.o" \
"CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.o"

# External object files for target iniparser
iniparser_EXTERNAL_OBJECTS =

libs/libiniparser.a: libs/CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.o
libs/libiniparser.a: libs/CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.o
libs/libiniparser.a: libs/CMakeFiles/iniparser.dir/build.make
libs/libiniparser.a: libs/CMakeFiles/iniparser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tomas/Escritorio/webChatFinal/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libiniparser.a"
	cd /home/tomas/Escritorio/webChatFinal/build/libs && $(CMAKE_COMMAND) -P CMakeFiles/iniparser.dir/cmake_clean_target.cmake
	cd /home/tomas/Escritorio/webChatFinal/build/libs && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/iniparser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/CMakeFiles/iniparser.dir/build: libs/libiniparser.a

.PHONY : libs/CMakeFiles/iniparser.dir/build

libs/CMakeFiles/iniparser.dir/requires: libs/CMakeFiles/iniparser.dir/iniparser/src/dictionary.c.o.requires
libs/CMakeFiles/iniparser.dir/requires: libs/CMakeFiles/iniparser.dir/iniparser/src/iniparser.c.o.requires

.PHONY : libs/CMakeFiles/iniparser.dir/requires

libs/CMakeFiles/iniparser.dir/clean:
	cd /home/tomas/Escritorio/webChatFinal/build/libs && $(CMAKE_COMMAND) -P CMakeFiles/iniparser.dir/cmake_clean.cmake
.PHONY : libs/CMakeFiles/iniparser.dir/clean

libs/CMakeFiles/iniparser.dir/depend:
	cd /home/tomas/Escritorio/webChatFinal/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tomas/Escritorio/webChatFinal /home/tomas/Escritorio/webChatFinal/libs /home/tomas/Escritorio/webChatFinal/build /home/tomas/Escritorio/webChatFinal/build/libs /home/tomas/Escritorio/webChatFinal/build/libs/CMakeFiles/iniparser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/CMakeFiles/iniparser.dir/depend
