# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /mnt/c/dev/project_1/project_1/File_IO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/dev/project_1/project_1/File_IO/build

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/c/dev/project_1/project_1/File_IO/build/CMakeFiles /mnt/c/dev/project_1/project_1/File_IO/build//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/c/dev/project_1/project_1/File_IO/build/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named work_cmake

# Build rule for target.
work_cmake: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 work_cmake
.PHONY : work_cmake

# fast build rule for target.
work_cmake/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/work_cmake.dir/build.make CMakeFiles/work_cmake.dir/build
.PHONY : work_cmake/fast

project.o: project.cpp.o
.PHONY : project.o

# target to build an object file
project.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/work_cmake.dir/build.make CMakeFiles/work_cmake.dir/project.cpp.o
.PHONY : project.cpp.o

project.i: project.cpp.i
.PHONY : project.i

# target to preprocess a source file
project.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/work_cmake.dir/build.make CMakeFiles/work_cmake.dir/project.cpp.i
.PHONY : project.cpp.i

project.s: project.cpp.s
.PHONY : project.s

# target to generate assembly for a file
project.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/work_cmake.dir/build.make CMakeFiles/work_cmake.dir/project.cpp.s
.PHONY : project.cpp.s

test.o: test.cpp.o
.PHONY : test.o

# target to build an object file
test.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/work_cmake.dir/build.make CMakeFiles/work_cmake.dir/test.cpp.o
.PHONY : test.cpp.o

test.i: test.cpp.i
.PHONY : test.i

# target to preprocess a source file
test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/work_cmake.dir/build.make CMakeFiles/work_cmake.dir/test.cpp.i
.PHONY : test.cpp.i

test.s: test.cpp.s
.PHONY : test.s

# target to generate assembly for a file
test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/work_cmake.dir/build.make CMakeFiles/work_cmake.dir/test.cpp.s
.PHONY : test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... work_cmake"
	@echo "... project.o"
	@echo "... project.i"
	@echo "... project.s"
	@echo "... test.o"
	@echo "... test.i"
	@echo "... test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

