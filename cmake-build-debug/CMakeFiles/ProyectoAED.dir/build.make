# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jleandrojm/CLION/proyecto-proyecto-grupo-4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jleandrojm/CLION/proyecto-proyecto-grupo-4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProyectoAED.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ProyectoAED.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ProyectoAED.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProyectoAED.dir/flags.make

CMakeFiles/ProyectoAED.dir/main.cpp.o: CMakeFiles/ProyectoAED.dir/flags.make
CMakeFiles/ProyectoAED.dir/main.cpp.o: /Users/jleandrojm/CLION/proyecto-proyecto-grupo-4/main.cpp
CMakeFiles/ProyectoAED.dir/main.cpp.o: CMakeFiles/ProyectoAED.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jleandrojm/CLION/proyecto-proyecto-grupo-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProyectoAED.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProyectoAED.dir/main.cpp.o -MF CMakeFiles/ProyectoAED.dir/main.cpp.o.d -o CMakeFiles/ProyectoAED.dir/main.cpp.o -c /Users/jleandrojm/CLION/proyecto-proyecto-grupo-4/main.cpp

CMakeFiles/ProyectoAED.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProyectoAED.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jleandrojm/CLION/proyecto-proyecto-grupo-4/main.cpp > CMakeFiles/ProyectoAED.dir/main.cpp.i

CMakeFiles/ProyectoAED.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProyectoAED.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jleandrojm/CLION/proyecto-proyecto-grupo-4/main.cpp -o CMakeFiles/ProyectoAED.dir/main.cpp.s

# Object files for target ProyectoAED
ProyectoAED_OBJECTS = \
"CMakeFiles/ProyectoAED.dir/main.cpp.o"

# External object files for target ProyectoAED
ProyectoAED_EXTERNAL_OBJECTS =

ProyectoAED: CMakeFiles/ProyectoAED.dir/main.cpp.o
ProyectoAED: CMakeFiles/ProyectoAED.dir/build.make
ProyectoAED: /opt/homebrew/lib/libsfml-graphics.2.5.1.dylib
ProyectoAED: /opt/homebrew/lib/libsfml-audio.2.5.1.dylib
ProyectoAED: /opt/homebrew/lib/libsfml-window.2.5.1.dylib
ProyectoAED: /opt/homebrew/lib/libsfml-system.2.5.1.dylib
ProyectoAED: CMakeFiles/ProyectoAED.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jleandrojm/CLION/proyecto-proyecto-grupo-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ProyectoAED"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProyectoAED.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProyectoAED.dir/build: ProyectoAED
.PHONY : CMakeFiles/ProyectoAED.dir/build

CMakeFiles/ProyectoAED.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProyectoAED.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProyectoAED.dir/clean

CMakeFiles/ProyectoAED.dir/depend:
	cd /Users/jleandrojm/CLION/proyecto-proyecto-grupo-4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jleandrojm/CLION/proyecto-proyecto-grupo-4 /Users/jleandrojm/CLION/proyecto-proyecto-grupo-4 /Users/jleandrojm/CLION/proyecto-proyecto-grupo-4/cmake-build-debug /Users/jleandrojm/CLION/proyecto-proyecto-grupo-4/cmake-build-debug /Users/jleandrojm/CLION/proyecto-proyecto-grupo-4/cmake-build-debug/CMakeFiles/ProyectoAED.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProyectoAED.dir/depend

