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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexander/projects/Natural

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexander/projects/Natural/build

# Include any dependencies generated for this target.
include CMakeFiles/natural.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/natural.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/natural.dir/flags.make

CMakeFiles/natural.dir/main.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/Natural/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/main.cpp.o -c /home/alexander/projects/Natural/main.cpp

CMakeFiles/natural.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/Natural/main.cpp > CMakeFiles/natural.dir/main.cpp.i

CMakeFiles/natural.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/Natural/main.cpp -o CMakeFiles/natural.dir/main.cpp.s

CMakeFiles/natural.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/main.cpp.o.requires

CMakeFiles/natural.dir/main.cpp.o.provides: CMakeFiles/natural.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/main.cpp.o.provides

CMakeFiles/natural.dir/main.cpp.o.provides.build: CMakeFiles/natural.dir/main.cpp.o

CMakeFiles/natural.dir/common/types.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/types.cpp.o: ../common/types.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/Natural/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/types.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/types.cpp.o -c /home/alexander/projects/Natural/common/types.cpp

CMakeFiles/natural.dir/common/types.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/types.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/Natural/common/types.cpp > CMakeFiles/natural.dir/common/types.cpp.i

CMakeFiles/natural.dir/common/types.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/types.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/Natural/common/types.cpp -o CMakeFiles/natural.dir/common/types.cpp.s

CMakeFiles/natural.dir/common/types.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/types.cpp.o.requires

CMakeFiles/natural.dir/common/types.cpp.o.provides: CMakeFiles/natural.dir/common/types.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/types.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/types.cpp.o.provides

CMakeFiles/natural.dir/common/types.cpp.o.provides.build: CMakeFiles/natural.dir/common/types.cpp.o

CMakeFiles/natural.dir/common/file_helper.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/file_helper.cpp.o: ../common/file_helper.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/Natural/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/file_helper.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/file_helper.cpp.o -c /home/alexander/projects/Natural/common/file_helper.cpp

CMakeFiles/natural.dir/common/file_helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/file_helper.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/Natural/common/file_helper.cpp > CMakeFiles/natural.dir/common/file_helper.cpp.i

CMakeFiles/natural.dir/common/file_helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/file_helper.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/Natural/common/file_helper.cpp -o CMakeFiles/natural.dir/common/file_helper.cpp.s

CMakeFiles/natural.dir/common/file_helper.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/file_helper.cpp.o.requires

CMakeFiles/natural.dir/common/file_helper.cpp.o.provides: CMakeFiles/natural.dir/common/file_helper.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/file_helper.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/file_helper.cpp.o.provides

CMakeFiles/natural.dir/common/file_helper.cpp.o.provides.build: CMakeFiles/natural.dir/common/file_helper.cpp.o

CMakeFiles/natural.dir/common/shader.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/shader.cpp.o: ../common/shader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/Natural/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/shader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/shader.cpp.o -c /home/alexander/projects/Natural/common/shader.cpp

CMakeFiles/natural.dir/common/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/shader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/Natural/common/shader.cpp > CMakeFiles/natural.dir/common/shader.cpp.i

CMakeFiles/natural.dir/common/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/shader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/Natural/common/shader.cpp -o CMakeFiles/natural.dir/common/shader.cpp.s

CMakeFiles/natural.dir/common/shader.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/shader.cpp.o.requires

CMakeFiles/natural.dir/common/shader.cpp.o.provides: CMakeFiles/natural.dir/common/shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/shader.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/shader.cpp.o.provides

CMakeFiles/natural.dir/common/shader.cpp.o.provides.build: CMakeFiles/natural.dir/common/shader.cpp.o

CMakeFiles/natural.dir/common/controls.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/controls.cpp.o: ../common/controls.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/Natural/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/controls.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/controls.cpp.o -c /home/alexander/projects/Natural/common/controls.cpp

CMakeFiles/natural.dir/common/controls.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/controls.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/Natural/common/controls.cpp > CMakeFiles/natural.dir/common/controls.cpp.i

CMakeFiles/natural.dir/common/controls.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/controls.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/Natural/common/controls.cpp -o CMakeFiles/natural.dir/common/controls.cpp.s

CMakeFiles/natural.dir/common/controls.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/controls.cpp.o.requires

CMakeFiles/natural.dir/common/controls.cpp.o.provides: CMakeFiles/natural.dir/common/controls.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/controls.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/controls.cpp.o.provides

CMakeFiles/natural.dir/common/controls.cpp.o.provides.build: CMakeFiles/natural.dir/common/controls.cpp.o

CMakeFiles/natural.dir/common/texture.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/texture.cpp.o: ../common/texture.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/Natural/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/texture.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/texture.cpp.o -c /home/alexander/projects/Natural/common/texture.cpp

CMakeFiles/natural.dir/common/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/texture.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/Natural/common/texture.cpp > CMakeFiles/natural.dir/common/texture.cpp.i

CMakeFiles/natural.dir/common/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/texture.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/Natural/common/texture.cpp -o CMakeFiles/natural.dir/common/texture.cpp.s

CMakeFiles/natural.dir/common/texture.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/texture.cpp.o.requires

CMakeFiles/natural.dir/common/texture.cpp.o.provides: CMakeFiles/natural.dir/common/texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/texture.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/texture.cpp.o.provides

CMakeFiles/natural.dir/common/texture.cpp.o.provides.build: CMakeFiles/natural.dir/common/texture.cpp.o

CMakeFiles/natural.dir/common/shapes.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/shapes.cpp.o: ../common/shapes.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/Natural/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/shapes.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/shapes.cpp.o -c /home/alexander/projects/Natural/common/shapes.cpp

CMakeFiles/natural.dir/common/shapes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/shapes.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/Natural/common/shapes.cpp > CMakeFiles/natural.dir/common/shapes.cpp.i

CMakeFiles/natural.dir/common/shapes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/shapes.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/Natural/common/shapes.cpp -o CMakeFiles/natural.dir/common/shapes.cpp.s

CMakeFiles/natural.dir/common/shapes.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/shapes.cpp.o.requires

CMakeFiles/natural.dir/common/shapes.cpp.o.provides: CMakeFiles/natural.dir/common/shapes.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/shapes.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/shapes.cpp.o.provides

CMakeFiles/natural.dir/common/shapes.cpp.o.provides.build: CMakeFiles/natural.dir/common/shapes.cpp.o

CMakeFiles/natural.dir/common/shader_utils.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/shader_utils.cpp.o: ../common/shader_utils.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/Natural/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/shader_utils.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/shader_utils.cpp.o -c /home/alexander/projects/Natural/common/shader_utils.cpp

CMakeFiles/natural.dir/common/shader_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/shader_utils.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/Natural/common/shader_utils.cpp > CMakeFiles/natural.dir/common/shader_utils.cpp.i

CMakeFiles/natural.dir/common/shader_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/shader_utils.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/Natural/common/shader_utils.cpp -o CMakeFiles/natural.dir/common/shader_utils.cpp.s

CMakeFiles/natural.dir/common/shader_utils.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/shader_utils.cpp.o.requires

CMakeFiles/natural.dir/common/shader_utils.cpp.o.provides: CMakeFiles/natural.dir/common/shader_utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/shader_utils.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/shader_utils.cpp.o.provides

CMakeFiles/natural.dir/common/shader_utils.cpp.o.provides.build: CMakeFiles/natural.dir/common/shader_utils.cpp.o

CMakeFiles/natural.dir/common/text.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/text.cpp.o: ../common/text.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/Natural/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/text.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/text.cpp.o -c /home/alexander/projects/Natural/common/text.cpp

CMakeFiles/natural.dir/common/text.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/text.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/Natural/common/text.cpp > CMakeFiles/natural.dir/common/text.cpp.i

CMakeFiles/natural.dir/common/text.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/text.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/Natural/common/text.cpp -o CMakeFiles/natural.dir/common/text.cpp.s

CMakeFiles/natural.dir/common/text.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/text.cpp.o.requires

CMakeFiles/natural.dir/common/text.cpp.o.provides: CMakeFiles/natural.dir/common/text.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/text.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/text.cpp.o.provides

CMakeFiles/natural.dir/common/text.cpp.o.provides.build: CMakeFiles/natural.dir/common/text.cpp.o

# Object files for target natural
natural_OBJECTS = \
"CMakeFiles/natural.dir/main.cpp.o" \
"CMakeFiles/natural.dir/common/types.cpp.o" \
"CMakeFiles/natural.dir/common/file_helper.cpp.o" \
"CMakeFiles/natural.dir/common/shader.cpp.o" \
"CMakeFiles/natural.dir/common/controls.cpp.o" \
"CMakeFiles/natural.dir/common/texture.cpp.o" \
"CMakeFiles/natural.dir/common/shapes.cpp.o" \
"CMakeFiles/natural.dir/common/shader_utils.cpp.o" \
"CMakeFiles/natural.dir/common/text.cpp.o"

# External object files for target natural
natural_EXTERNAL_OBJECTS =

natural: CMakeFiles/natural.dir/main.cpp.o
natural: CMakeFiles/natural.dir/common/types.cpp.o
natural: CMakeFiles/natural.dir/common/file_helper.cpp.o
natural: CMakeFiles/natural.dir/common/shader.cpp.o
natural: CMakeFiles/natural.dir/common/controls.cpp.o
natural: CMakeFiles/natural.dir/common/texture.cpp.o
natural: CMakeFiles/natural.dir/common/shapes.cpp.o
natural: CMakeFiles/natural.dir/common/shader_utils.cpp.o
natural: CMakeFiles/natural.dir/common/text.cpp.o
natural: CMakeFiles/natural.dir/build.make
natural: /usr/lib/libxml++-2.6.so
natural: /usr/lib/x86_64-linux-gnu/libGLU.so
natural: /usr/lib/x86_64-linux-gnu/libGL.so
natural: /usr/lib/x86_64-linux-gnu/libSM.so
natural: /usr/lib/x86_64-linux-gnu/libICE.so
natural: /usr/lib/x86_64-linux-gnu/libX11.so
natural: /usr/lib/x86_64-linux-gnu/libXext.so
natural: external/libGLFW_276.a
natural: external/libGLEW_190.a
natural: external/bullet-2.81-rev2613/src/BulletDynamics/libBulletDynamics.a
natural: external/bullet-2.81-rev2613/src/BulletCollision/libBulletCollision.a
natural: external/bullet-2.81-rev2613/src/LinearMath/libLinearMath.a
natural: external/freetype-2.5.2/libfreetype.a
natural: /usr/local/lib/libboost_filesystem.so
natural: /usr/local/lib/libboost_system.so
natural: /usr/lib/x86_64-linux-gnu/libGLU.so
natural: /usr/lib/x86_64-linux-gnu/libGL.so
natural: /usr/lib/x86_64-linux-gnu/libSM.so
natural: /usr/lib/x86_64-linux-gnu/libICE.so
natural: /usr/lib/x86_64-linux-gnu/libX11.so
natural: /usr/lib/x86_64-linux-gnu/libXext.so
natural: CMakeFiles/natural.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable natural"
	/usr/bin/cmake -E copy_directory /home/alexander/projects/Natural/shaders /home/alexander/projects/Natural/build
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/natural.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -E copy /home/alexander/projects/Natural/build /home/alexander/projects/Natural/shaders/

# Rule to build all files generated by this target.
CMakeFiles/natural.dir/build: natural
.PHONY : CMakeFiles/natural.dir/build

CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/main.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/types.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/file_helper.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/shader.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/controls.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/texture.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/shapes.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/shader_utils.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/text.cpp.o.requires
.PHONY : CMakeFiles/natural.dir/requires

CMakeFiles/natural.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/natural.dir/cmake_clean.cmake
.PHONY : CMakeFiles/natural.dir/clean

CMakeFiles/natural.dir/depend:
	cd /home/alexander/projects/Natural/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexander/projects/Natural /home/alexander/projects/Natural /home/alexander/projects/Natural/build /home/alexander/projects/Natural/build /home/alexander/projects/Natural/build/CMakeFiles/natural.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/natural.dir/depend

