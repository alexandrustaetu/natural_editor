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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexander/projects/natural_editor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexander/projects/natural_editor/build

# Include any dependencies generated for this target.
include CMakeFiles/natural.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/natural.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/natural.dir/flags.make

CMakeFiles/natural.dir/main.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/main.cpp.o -c /home/alexander/projects/natural_editor/main.cpp

CMakeFiles/natural.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/main.cpp > CMakeFiles/natural.dir/main.cpp.i

CMakeFiles/natural.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/main.cpp -o CMakeFiles/natural.dir/main.cpp.s

CMakeFiles/natural.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/main.cpp.o.requires

CMakeFiles/natural.dir/main.cpp.o.provides: CMakeFiles/natural.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/main.cpp.o.provides

CMakeFiles/natural.dir/main.cpp.o.provides.build: CMakeFiles/natural.dir/main.cpp.o

CMakeFiles/natural.dir/common/handle.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/handle.cpp.o: ../common/handle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/handle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/handle.cpp.o -c /home/alexander/projects/natural_editor/common/handle.cpp

CMakeFiles/natural.dir/common/handle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/handle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/common/handle.cpp > CMakeFiles/natural.dir/common/handle.cpp.i

CMakeFiles/natural.dir/common/handle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/handle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/common/handle.cpp -o CMakeFiles/natural.dir/common/handle.cpp.s

CMakeFiles/natural.dir/common/handle.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/handle.cpp.o.requires

CMakeFiles/natural.dir/common/handle.cpp.o.provides: CMakeFiles/natural.dir/common/handle.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/handle.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/handle.cpp.o.provides

CMakeFiles/natural.dir/common/handle.cpp.o.provides.build: CMakeFiles/natural.dir/common/handle.cpp.o

CMakeFiles/natural.dir/common/text/word.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/text/word.cpp.o: ../common/text/word.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/text/word.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/text/word.cpp.o -c /home/alexander/projects/natural_editor/common/text/word.cpp

CMakeFiles/natural.dir/common/text/word.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/text/word.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/common/text/word.cpp > CMakeFiles/natural.dir/common/text/word.cpp.i

CMakeFiles/natural.dir/common/text/word.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/text/word.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/common/text/word.cpp -o CMakeFiles/natural.dir/common/text/word.cpp.s

CMakeFiles/natural.dir/common/text/word.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/text/word.cpp.o.requires

CMakeFiles/natural.dir/common/text/word.cpp.o.provides: CMakeFiles/natural.dir/common/text/word.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/text/word.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/text/word.cpp.o.provides

CMakeFiles/natural.dir/common/text/word.cpp.o.provides.build: CMakeFiles/natural.dir/common/text/word.cpp.o

CMakeFiles/natural.dir/common/filesystem/disk.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/filesystem/disk.cpp.o: ../common/filesystem/disk.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/filesystem/disk.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/filesystem/disk.cpp.o -c /home/alexander/projects/natural_editor/common/filesystem/disk.cpp

CMakeFiles/natural.dir/common/filesystem/disk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/filesystem/disk.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/common/filesystem/disk.cpp > CMakeFiles/natural.dir/common/filesystem/disk.cpp.i

CMakeFiles/natural.dir/common/filesystem/disk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/filesystem/disk.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/common/filesystem/disk.cpp -o CMakeFiles/natural.dir/common/filesystem/disk.cpp.s

CMakeFiles/natural.dir/common/filesystem/disk.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/filesystem/disk.cpp.o.requires

CMakeFiles/natural.dir/common/filesystem/disk.cpp.o.provides: CMakeFiles/natural.dir/common/filesystem/disk.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/filesystem/disk.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/filesystem/disk.cpp.o.provides

CMakeFiles/natural.dir/common/filesystem/disk.cpp.o.provides.build: CMakeFiles/natural.dir/common/filesystem/disk.cpp.o

CMakeFiles/natural.dir/common/filesystem/directory.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/filesystem/directory.cpp.o: ../common/filesystem/directory.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/filesystem/directory.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/filesystem/directory.cpp.o -c /home/alexander/projects/natural_editor/common/filesystem/directory.cpp

CMakeFiles/natural.dir/common/filesystem/directory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/filesystem/directory.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/common/filesystem/directory.cpp > CMakeFiles/natural.dir/common/filesystem/directory.cpp.i

CMakeFiles/natural.dir/common/filesystem/directory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/filesystem/directory.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/common/filesystem/directory.cpp -o CMakeFiles/natural.dir/common/filesystem/directory.cpp.s

CMakeFiles/natural.dir/common/filesystem/directory.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/filesystem/directory.cpp.o.requires

CMakeFiles/natural.dir/common/filesystem/directory.cpp.o.provides: CMakeFiles/natural.dir/common/filesystem/directory.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/filesystem/directory.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/filesystem/directory.cpp.o.provides

CMakeFiles/natural.dir/common/filesystem/directory.cpp.o.provides.build: CMakeFiles/natural.dir/common/filesystem/directory.cpp.o

CMakeFiles/natural.dir/common/debug.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/debug.cpp.o: ../common/debug.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/debug.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/debug.cpp.o -c /home/alexander/projects/natural_editor/common/debug.cpp

CMakeFiles/natural.dir/common/debug.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/debug.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/common/debug.cpp > CMakeFiles/natural.dir/common/debug.cpp.i

CMakeFiles/natural.dir/common/debug.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/debug.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/common/debug.cpp -o CMakeFiles/natural.dir/common/debug.cpp.s

CMakeFiles/natural.dir/common/debug.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/debug.cpp.o.requires

CMakeFiles/natural.dir/common/debug.cpp.o.provides: CMakeFiles/natural.dir/common/debug.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/debug.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/debug.cpp.o.provides

CMakeFiles/natural.dir/common/debug.cpp.o.provides.build: CMakeFiles/natural.dir/common/debug.cpp.o

CMakeFiles/natural.dir/common/shader.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/shader.cpp.o: ../common/shader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/shader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/shader.cpp.o -c /home/alexander/projects/natural_editor/common/shader.cpp

CMakeFiles/natural.dir/common/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/shader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/common/shader.cpp > CMakeFiles/natural.dir/common/shader.cpp.i

CMakeFiles/natural.dir/common/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/shader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/common/shader.cpp -o CMakeFiles/natural.dir/common/shader.cpp.s

CMakeFiles/natural.dir/common/shader.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/shader.cpp.o.requires

CMakeFiles/natural.dir/common/shader.cpp.o.provides: CMakeFiles/natural.dir/common/shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/shader.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/shader.cpp.o.provides

CMakeFiles/natural.dir/common/shader.cpp.o.provides.build: CMakeFiles/natural.dir/common/shader.cpp.o

CMakeFiles/natural.dir/common/controls.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/controls.cpp.o: ../common/controls.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/controls.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/controls.cpp.o -c /home/alexander/projects/natural_editor/common/controls.cpp

CMakeFiles/natural.dir/common/controls.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/controls.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/common/controls.cpp > CMakeFiles/natural.dir/common/controls.cpp.i

CMakeFiles/natural.dir/common/controls.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/controls.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/common/controls.cpp -o CMakeFiles/natural.dir/common/controls.cpp.s

CMakeFiles/natural.dir/common/controls.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/controls.cpp.o.requires

CMakeFiles/natural.dir/common/controls.cpp.o.provides: CMakeFiles/natural.dir/common/controls.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/controls.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/controls.cpp.o.provides

CMakeFiles/natural.dir/common/controls.cpp.o.provides.build: CMakeFiles/natural.dir/common/controls.cpp.o

CMakeFiles/natural.dir/common/space/object3d.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/space/object3d.cpp.o: ../common/space/object3d.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/space/object3d.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/space/object3d.cpp.o -c /home/alexander/projects/natural_editor/common/space/object3d.cpp

CMakeFiles/natural.dir/common/space/object3d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/space/object3d.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/common/space/object3d.cpp > CMakeFiles/natural.dir/common/space/object3d.cpp.i

CMakeFiles/natural.dir/common/space/object3d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/space/object3d.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/common/space/object3d.cpp -o CMakeFiles/natural.dir/common/space/object3d.cpp.s

CMakeFiles/natural.dir/common/space/object3d.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/space/object3d.cpp.o.requires

CMakeFiles/natural.dir/common/space/object3d.cpp.o.provides: CMakeFiles/natural.dir/common/space/object3d.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/space/object3d.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/space/object3d.cpp.o.provides

CMakeFiles/natural.dir/common/space/object3d.cpp.o.provides.build: CMakeFiles/natural.dir/common/space/object3d.cpp.o

CMakeFiles/natural.dir/common/space/physics.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/space/physics.cpp.o: ../common/space/physics.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/space/physics.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/space/physics.cpp.o -c /home/alexander/projects/natural_editor/common/space/physics.cpp

CMakeFiles/natural.dir/common/space/physics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/space/physics.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/common/space/physics.cpp > CMakeFiles/natural.dir/common/space/physics.cpp.i

CMakeFiles/natural.dir/common/space/physics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/space/physics.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/common/space/physics.cpp -o CMakeFiles/natural.dir/common/space/physics.cpp.s

CMakeFiles/natural.dir/common/space/physics.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/space/physics.cpp.o.requires

CMakeFiles/natural.dir/common/space/physics.cpp.o.provides: CMakeFiles/natural.dir/common/space/physics.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/space/physics.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/space/physics.cpp.o.provides

CMakeFiles/natural.dir/common/space/physics.cpp.o.provides.build: CMakeFiles/natural.dir/common/space/physics.cpp.o

CMakeFiles/natural.dir/common/environment/world.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/environment/world.cpp.o: ../common/environment/world.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/environment/world.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/environment/world.cpp.o -c /home/alexander/projects/natural_editor/common/environment/world.cpp

CMakeFiles/natural.dir/common/environment/world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/environment/world.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/common/environment/world.cpp > CMakeFiles/natural.dir/common/environment/world.cpp.i

CMakeFiles/natural.dir/common/environment/world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/environment/world.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/common/environment/world.cpp -o CMakeFiles/natural.dir/common/environment/world.cpp.s

CMakeFiles/natural.dir/common/environment/world.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/environment/world.cpp.o.requires

CMakeFiles/natural.dir/common/environment/world.cpp.o.provides: CMakeFiles/natural.dir/common/environment/world.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/environment/world.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/environment/world.cpp.o.provides

CMakeFiles/natural.dir/common/environment/world.cpp.o.provides.build: CMakeFiles/natural.dir/common/environment/world.cpp.o

CMakeFiles/natural.dir/common/space/scene.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/space/scene.cpp.o: ../common/space/scene.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/space/scene.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/space/scene.cpp.o -c /home/alexander/projects/natural_editor/common/space/scene.cpp

CMakeFiles/natural.dir/common/space/scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/space/scene.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/common/space/scene.cpp > CMakeFiles/natural.dir/common/space/scene.cpp.i

CMakeFiles/natural.dir/common/space/scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/space/scene.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/common/space/scene.cpp -o CMakeFiles/natural.dir/common/space/scene.cpp.s

CMakeFiles/natural.dir/common/space/scene.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/space/scene.cpp.o.requires

CMakeFiles/natural.dir/common/space/scene.cpp.o.provides: CMakeFiles/natural.dir/common/space/scene.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/space/scene.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/space/scene.cpp.o.provides

CMakeFiles/natural.dir/common/space/scene.cpp.o.provides.build: CMakeFiles/natural.dir/common/space/scene.cpp.o

CMakeFiles/natural.dir/common/text/canvas.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/text/canvas.cpp.o: ../common/text/canvas.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/text/canvas.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/text/canvas.cpp.o -c /home/alexander/projects/natural_editor/common/text/canvas.cpp

CMakeFiles/natural.dir/common/text/canvas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/text/canvas.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/common/text/canvas.cpp > CMakeFiles/natural.dir/common/text/canvas.cpp.i

CMakeFiles/natural.dir/common/text/canvas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/text/canvas.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/common/text/canvas.cpp -o CMakeFiles/natural.dir/common/text/canvas.cpp.s

CMakeFiles/natural.dir/common/text/canvas.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/text/canvas.cpp.o.requires

CMakeFiles/natural.dir/common/text/canvas.cpp.o.provides: CMakeFiles/natural.dir/common/text/canvas.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/text/canvas.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/text/canvas.cpp.o.provides

CMakeFiles/natural.dir/common/text/canvas.cpp.o.provides.build: CMakeFiles/natural.dir/common/text/canvas.cpp.o

CMakeFiles/natural.dir/common/text/text.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/text/text.cpp.o: ../common/text/text.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_14)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/text/text.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/text/text.cpp.o -c /home/alexander/projects/natural_editor/common/text/text.cpp

CMakeFiles/natural.dir/common/text/text.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/text/text.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/common/text/text.cpp > CMakeFiles/natural.dir/common/text/text.cpp.i

CMakeFiles/natural.dir/common/text/text.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/text/text.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/common/text/text.cpp -o CMakeFiles/natural.dir/common/text/text.cpp.s

CMakeFiles/natural.dir/common/text/text.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/text/text.cpp.o.requires

CMakeFiles/natural.dir/common/text/text.cpp.o.provides: CMakeFiles/natural.dir/common/text/text.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/text/text.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/text/text.cpp.o.provides

CMakeFiles/natural.dir/common/text/text.cpp.o.provides.build: CMakeFiles/natural.dir/common/text/text.cpp.o

CMakeFiles/natural.dir/common/texture.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/texture.cpp.o: ../common/texture.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_15)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/texture.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/texture.cpp.o -c /home/alexander/projects/natural_editor/common/texture.cpp

CMakeFiles/natural.dir/common/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/texture.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/common/texture.cpp > CMakeFiles/natural.dir/common/texture.cpp.i

CMakeFiles/natural.dir/common/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/texture.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/common/texture.cpp -o CMakeFiles/natural.dir/common/texture.cpp.s

CMakeFiles/natural.dir/common/texture.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/texture.cpp.o.requires

CMakeFiles/natural.dir/common/texture.cpp.o.provides: CMakeFiles/natural.dir/common/texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/texture.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/texture.cpp.o.provides

CMakeFiles/natural.dir/common/texture.cpp.o.provides.build: CMakeFiles/natural.dir/common/texture.cpp.o

CMakeFiles/natural.dir/common/shader_utils.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/shader_utils.cpp.o: ../common/shader_utils.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_16)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/shader_utils.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/shader_utils.cpp.o -c /home/alexander/projects/natural_editor/common/shader_utils.cpp

CMakeFiles/natural.dir/common/shader_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/shader_utils.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/common/shader_utils.cpp > CMakeFiles/natural.dir/common/shader_utils.cpp.i

CMakeFiles/natural.dir/common/shader_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/shader_utils.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/common/shader_utils.cpp -o CMakeFiles/natural.dir/common/shader_utils.cpp.s

CMakeFiles/natural.dir/common/shader_utils.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/shader_utils.cpp.o.requires

CMakeFiles/natural.dir/common/shader_utils.cpp.o.provides: CMakeFiles/natural.dir/common/shader_utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/shader_utils.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/shader_utils.cpp.o.provides

CMakeFiles/natural.dir/common/shader_utils.cpp.o.provides.build: CMakeFiles/natural.dir/common/shader_utils.cpp.o

CMakeFiles/natural.dir/common/input/menu.cpp.o: CMakeFiles/natural.dir/flags.make
CMakeFiles/natural.dir/common/input/menu.cpp.o: ../common/input/menu.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alexander/projects/natural_editor/build/CMakeFiles $(CMAKE_PROGRESS_17)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/natural.dir/common/input/menu.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/natural.dir/common/input/menu.cpp.o -c /home/alexander/projects/natural_editor/common/input/menu.cpp

CMakeFiles/natural.dir/common/input/menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/natural.dir/common/input/menu.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alexander/projects/natural_editor/common/input/menu.cpp > CMakeFiles/natural.dir/common/input/menu.cpp.i

CMakeFiles/natural.dir/common/input/menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/natural.dir/common/input/menu.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alexander/projects/natural_editor/common/input/menu.cpp -o CMakeFiles/natural.dir/common/input/menu.cpp.s

CMakeFiles/natural.dir/common/input/menu.cpp.o.requires:
.PHONY : CMakeFiles/natural.dir/common/input/menu.cpp.o.requires

CMakeFiles/natural.dir/common/input/menu.cpp.o.provides: CMakeFiles/natural.dir/common/input/menu.cpp.o.requires
	$(MAKE) -f CMakeFiles/natural.dir/build.make CMakeFiles/natural.dir/common/input/menu.cpp.o.provides.build
.PHONY : CMakeFiles/natural.dir/common/input/menu.cpp.o.provides

CMakeFiles/natural.dir/common/input/menu.cpp.o.provides.build: CMakeFiles/natural.dir/common/input/menu.cpp.o

# Object files for target natural
natural_OBJECTS = \
"CMakeFiles/natural.dir/main.cpp.o" \
"CMakeFiles/natural.dir/common/handle.cpp.o" \
"CMakeFiles/natural.dir/common/text/word.cpp.o" \
"CMakeFiles/natural.dir/common/filesystem/disk.cpp.o" \
"CMakeFiles/natural.dir/common/filesystem/directory.cpp.o" \
"CMakeFiles/natural.dir/common/debug.cpp.o" \
"CMakeFiles/natural.dir/common/shader.cpp.o" \
"CMakeFiles/natural.dir/common/controls.cpp.o" \
"CMakeFiles/natural.dir/common/space/object3d.cpp.o" \
"CMakeFiles/natural.dir/common/space/physics.cpp.o" \
"CMakeFiles/natural.dir/common/environment/world.cpp.o" \
"CMakeFiles/natural.dir/common/space/scene.cpp.o" \
"CMakeFiles/natural.dir/common/text/canvas.cpp.o" \
"CMakeFiles/natural.dir/common/text/text.cpp.o" \
"CMakeFiles/natural.dir/common/texture.cpp.o" \
"CMakeFiles/natural.dir/common/shader_utils.cpp.o" \
"CMakeFiles/natural.dir/common/input/menu.cpp.o"

# External object files for target natural
natural_EXTERNAL_OBJECTS =

natural: CMakeFiles/natural.dir/main.cpp.o
natural: CMakeFiles/natural.dir/common/handle.cpp.o
natural: CMakeFiles/natural.dir/common/text/word.cpp.o
natural: CMakeFiles/natural.dir/common/filesystem/disk.cpp.o
natural: CMakeFiles/natural.dir/common/filesystem/directory.cpp.o
natural: CMakeFiles/natural.dir/common/debug.cpp.o
natural: CMakeFiles/natural.dir/common/shader.cpp.o
natural: CMakeFiles/natural.dir/common/controls.cpp.o
natural: CMakeFiles/natural.dir/common/space/object3d.cpp.o
natural: CMakeFiles/natural.dir/common/space/physics.cpp.o
natural: CMakeFiles/natural.dir/common/environment/world.cpp.o
natural: CMakeFiles/natural.dir/common/space/scene.cpp.o
natural: CMakeFiles/natural.dir/common/text/canvas.cpp.o
natural: CMakeFiles/natural.dir/common/text/text.cpp.o
natural: CMakeFiles/natural.dir/common/texture.cpp.o
natural: CMakeFiles/natural.dir/common/shader_utils.cpp.o
natural: CMakeFiles/natural.dir/common/input/menu.cpp.o
natural: CMakeFiles/natural.dir/build.make
natural: /usr/lib/x86_64-linux-gnu/libGLU.so
natural: /usr/lib/x86_64-linux-gnu/libGL.so
natural: /usr/lib/x86_64-linux-gnu/libSM.so
natural: /usr/lib/x86_64-linux-gnu/libICE.so
natural: /usr/lib/x86_64-linux-gnu/libX11.so
natural: /usr/lib/x86_64-linux-gnu/libXext.so
natural: /usr/lib/x86_64-linux-gnu/libgmp.so
natural: /usr/lib/x86_64-linux-gnu/libboost_system.so
natural: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
natural: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
natural: external/libGLFW_276.a
natural: external/libGLEW_190.a
natural: external/bullet-2.81-rev2613/src/BulletDynamics/libBulletDynamics.a
natural: external/bullet-2.81-rev2613/src/BulletCollision/libBulletCollision.a
natural: external/bullet-2.81-rev2613/src/LinearMath/libLinearMath.a
natural: /usr/lib/x86_64-linux-gnu/libGLU.so
natural: /usr/lib/x86_64-linux-gnu/libGL.so
natural: /usr/lib/x86_64-linux-gnu/libSM.so
natural: /usr/lib/x86_64-linux-gnu/libICE.so
natural: /usr/lib/x86_64-linux-gnu/libX11.so
natural: /usr/lib/x86_64-linux-gnu/libXext.so
natural: CMakeFiles/natural.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable natural"
	/usr/bin/cmake -E copy_directory /home/alexander/projects/natural_editor/shaders /home/alexander/projects/natural_editor/build
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/natural.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -E copy /home/alexander/projects/natural_editor/build /home/alexander/projects/natural_editor/shaders/

# Rule to build all files generated by this target.
CMakeFiles/natural.dir/build: natural
.PHONY : CMakeFiles/natural.dir/build

CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/main.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/handle.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/text/word.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/filesystem/disk.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/filesystem/directory.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/debug.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/shader.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/controls.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/space/object3d.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/space/physics.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/environment/world.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/space/scene.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/text/canvas.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/text/text.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/texture.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/shader_utils.cpp.o.requires
CMakeFiles/natural.dir/requires: CMakeFiles/natural.dir/common/input/menu.cpp.o.requires
.PHONY : CMakeFiles/natural.dir/requires

CMakeFiles/natural.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/natural.dir/cmake_clean.cmake
.PHONY : CMakeFiles/natural.dir/clean

CMakeFiles/natural.dir/depend:
	cd /home/alexander/projects/natural_editor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexander/projects/natural_editor /home/alexander/projects/natural_editor /home/alexander/projects/natural_editor/build /home/alexander/projects/natural_editor/build /home/alexander/projects/natural_editor/build/CMakeFiles/natural.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/natural.dir/depend

