# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/war/study/project/NetServer/test/c++/yaLanTingLibs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/war/study/project/NetServer/test/c++/yaLanTingLibs/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rpcServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rpcServer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rpcServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rpcServer.dir/flags.make

CMakeFiles/rpcServer.dir/RpcServer.cpp.o: CMakeFiles/rpcServer.dir/flags.make
CMakeFiles/rpcServer.dir/RpcServer.cpp.o: ../RpcServer.cpp
CMakeFiles/rpcServer.dir/RpcServer.cpp.o: CMakeFiles/rpcServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/war/study/project/NetServer/test/c++/yaLanTingLibs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rpcServer.dir/RpcServer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rpcServer.dir/RpcServer.cpp.o -MF CMakeFiles/rpcServer.dir/RpcServer.cpp.o.d -o CMakeFiles/rpcServer.dir/RpcServer.cpp.o -c /home/war/study/project/NetServer/test/c++/yaLanTingLibs/RpcServer.cpp

CMakeFiles/rpcServer.dir/RpcServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpcServer.dir/RpcServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/war/study/project/NetServer/test/c++/yaLanTingLibs/RpcServer.cpp > CMakeFiles/rpcServer.dir/RpcServer.cpp.i

CMakeFiles/rpcServer.dir/RpcServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpcServer.dir/RpcServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/war/study/project/NetServer/test/c++/yaLanTingLibs/RpcServer.cpp -o CMakeFiles/rpcServer.dir/RpcServer.cpp.s

# Object files for target rpcServer
rpcServer_OBJECTS = \
"CMakeFiles/rpcServer.dir/RpcServer.cpp.o"

# External object files for target rpcServer
rpcServer_EXTERNAL_OBJECTS =

rpcServer: CMakeFiles/rpcServer.dir/RpcServer.cpp.o
rpcServer: CMakeFiles/rpcServer.dir/build.make
rpcServer: CMakeFiles/rpcServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/war/study/project/NetServer/test/c++/yaLanTingLibs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rpcServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rpcServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rpcServer.dir/build: rpcServer
.PHONY : CMakeFiles/rpcServer.dir/build

CMakeFiles/rpcServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rpcServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rpcServer.dir/clean

CMakeFiles/rpcServer.dir/depend:
	cd /home/war/study/project/NetServer/test/c++/yaLanTingLibs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/war/study/project/NetServer/test/c++/yaLanTingLibs /home/war/study/project/NetServer/test/c++/yaLanTingLibs /home/war/study/project/NetServer/test/c++/yaLanTingLibs/cmake-build-debug /home/war/study/project/NetServer/test/c++/yaLanTingLibs/cmake-build-debug /home/war/study/project/NetServer/test/c++/yaLanTingLibs/cmake-build-debug/CMakeFiles/rpcServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rpcServer.dir/depend

