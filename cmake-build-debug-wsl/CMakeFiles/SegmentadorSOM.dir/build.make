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
CMAKE_SOURCE_DIR = /mnt/d/Documentos/CLionProjects/SegmentadorSOM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Documentos/CLionProjects/SegmentadorSOM/cmake-build-debug-wsl

# Include any dependencies generated for this target.
include CMakeFiles/SegmentadorSOM.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SegmentadorSOM.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SegmentadorSOM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SegmentadorSOM.dir/flags.make

CMakeFiles/SegmentadorSOM.dir/main.cpp.o: CMakeFiles/SegmentadorSOM.dir/flags.make
CMakeFiles/SegmentadorSOM.dir/main.cpp.o: ../main.cpp
CMakeFiles/SegmentadorSOM.dir/main.cpp.o: CMakeFiles/SegmentadorSOM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Documentos/CLionProjects/SegmentadorSOM/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SegmentadorSOM.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SegmentadorSOM.dir/main.cpp.o -MF CMakeFiles/SegmentadorSOM.dir/main.cpp.o.d -o CMakeFiles/SegmentadorSOM.dir/main.cpp.o -c /mnt/d/Documentos/CLionProjects/SegmentadorSOM/main.cpp

CMakeFiles/SegmentadorSOM.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SegmentadorSOM.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Documentos/CLionProjects/SegmentadorSOM/main.cpp > CMakeFiles/SegmentadorSOM.dir/main.cpp.i

CMakeFiles/SegmentadorSOM.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SegmentadorSOM.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Documentos/CLionProjects/SegmentadorSOM/main.cpp -o CMakeFiles/SegmentadorSOM.dir/main.cpp.s

CMakeFiles/SegmentadorSOM.dir/Calculos/Calculos.cpp.o: CMakeFiles/SegmentadorSOM.dir/flags.make
CMakeFiles/SegmentadorSOM.dir/Calculos/Calculos.cpp.o: ../Calculos/Calculos.cpp
CMakeFiles/SegmentadorSOM.dir/Calculos/Calculos.cpp.o: CMakeFiles/SegmentadorSOM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Documentos/CLionProjects/SegmentadorSOM/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SegmentadorSOM.dir/Calculos/Calculos.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SegmentadorSOM.dir/Calculos/Calculos.cpp.o -MF CMakeFiles/SegmentadorSOM.dir/Calculos/Calculos.cpp.o.d -o CMakeFiles/SegmentadorSOM.dir/Calculos/Calculos.cpp.o -c /mnt/d/Documentos/CLionProjects/SegmentadorSOM/Calculos/Calculos.cpp

CMakeFiles/SegmentadorSOM.dir/Calculos/Calculos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SegmentadorSOM.dir/Calculos/Calculos.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Documentos/CLionProjects/SegmentadorSOM/Calculos/Calculos.cpp > CMakeFiles/SegmentadorSOM.dir/Calculos/Calculos.cpp.i

CMakeFiles/SegmentadorSOM.dir/Calculos/Calculos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SegmentadorSOM.dir/Calculos/Calculos.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Documentos/CLionProjects/SegmentadorSOM/Calculos/Calculos.cpp -o CMakeFiles/SegmentadorSOM.dir/Calculos/Calculos.cpp.s

CMakeFiles/SegmentadorSOM.dir/Codificador/Dado.cpp.o: CMakeFiles/SegmentadorSOM.dir/flags.make
CMakeFiles/SegmentadorSOM.dir/Codificador/Dado.cpp.o: ../Codificador/Dado.cpp
CMakeFiles/SegmentadorSOM.dir/Codificador/Dado.cpp.o: CMakeFiles/SegmentadorSOM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Documentos/CLionProjects/SegmentadorSOM/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SegmentadorSOM.dir/Codificador/Dado.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SegmentadorSOM.dir/Codificador/Dado.cpp.o -MF CMakeFiles/SegmentadorSOM.dir/Codificador/Dado.cpp.o.d -o CMakeFiles/SegmentadorSOM.dir/Codificador/Dado.cpp.o -c /mnt/d/Documentos/CLionProjects/SegmentadorSOM/Codificador/Dado.cpp

CMakeFiles/SegmentadorSOM.dir/Codificador/Dado.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SegmentadorSOM.dir/Codificador/Dado.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Documentos/CLionProjects/SegmentadorSOM/Codificador/Dado.cpp > CMakeFiles/SegmentadorSOM.dir/Codificador/Dado.cpp.i

CMakeFiles/SegmentadorSOM.dir/Codificador/Dado.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SegmentadorSOM.dir/Codificador/Dado.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Documentos/CLionProjects/SegmentadorSOM/Codificador/Dado.cpp -o CMakeFiles/SegmentadorSOM.dir/Codificador/Dado.cpp.s

CMakeFiles/SegmentadorSOM.dir/SOM/Arranjo.cpp.o: CMakeFiles/SegmentadorSOM.dir/flags.make
CMakeFiles/SegmentadorSOM.dir/SOM/Arranjo.cpp.o: ../SOM/Arranjo.cpp
CMakeFiles/SegmentadorSOM.dir/SOM/Arranjo.cpp.o: CMakeFiles/SegmentadorSOM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Documentos/CLionProjects/SegmentadorSOM/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SegmentadorSOM.dir/SOM/Arranjo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SegmentadorSOM.dir/SOM/Arranjo.cpp.o -MF CMakeFiles/SegmentadorSOM.dir/SOM/Arranjo.cpp.o.d -o CMakeFiles/SegmentadorSOM.dir/SOM/Arranjo.cpp.o -c /mnt/d/Documentos/CLionProjects/SegmentadorSOM/SOM/Arranjo.cpp

CMakeFiles/SegmentadorSOM.dir/SOM/Arranjo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SegmentadorSOM.dir/SOM/Arranjo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Documentos/CLionProjects/SegmentadorSOM/SOM/Arranjo.cpp > CMakeFiles/SegmentadorSOM.dir/SOM/Arranjo.cpp.i

CMakeFiles/SegmentadorSOM.dir/SOM/Arranjo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SegmentadorSOM.dir/SOM/Arranjo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Documentos/CLionProjects/SegmentadorSOM/SOM/Arranjo.cpp -o CMakeFiles/SegmentadorSOM.dir/SOM/Arranjo.cpp.s

CMakeFiles/SegmentadorSOM.dir/SOM/Neuronio.cpp.o: CMakeFiles/SegmentadorSOM.dir/flags.make
CMakeFiles/SegmentadorSOM.dir/SOM/Neuronio.cpp.o: ../SOM/Neuronio.cpp
CMakeFiles/SegmentadorSOM.dir/SOM/Neuronio.cpp.o: CMakeFiles/SegmentadorSOM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Documentos/CLionProjects/SegmentadorSOM/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SegmentadorSOM.dir/SOM/Neuronio.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SegmentadorSOM.dir/SOM/Neuronio.cpp.o -MF CMakeFiles/SegmentadorSOM.dir/SOM/Neuronio.cpp.o.d -o CMakeFiles/SegmentadorSOM.dir/SOM/Neuronio.cpp.o -c /mnt/d/Documentos/CLionProjects/SegmentadorSOM/SOM/Neuronio.cpp

CMakeFiles/SegmentadorSOM.dir/SOM/Neuronio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SegmentadorSOM.dir/SOM/Neuronio.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Documentos/CLionProjects/SegmentadorSOM/SOM/Neuronio.cpp > CMakeFiles/SegmentadorSOM.dir/SOM/Neuronio.cpp.i

CMakeFiles/SegmentadorSOM.dir/SOM/Neuronio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SegmentadorSOM.dir/SOM/Neuronio.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Documentos/CLionProjects/SegmentadorSOM/SOM/Neuronio.cpp -o CMakeFiles/SegmentadorSOM.dir/SOM/Neuronio.cpp.s

CMakeFiles/SegmentadorSOM.dir/SOM/SOM.cpp.o: CMakeFiles/SegmentadorSOM.dir/flags.make
CMakeFiles/SegmentadorSOM.dir/SOM/SOM.cpp.o: ../SOM/SOM.cpp
CMakeFiles/SegmentadorSOM.dir/SOM/SOM.cpp.o: CMakeFiles/SegmentadorSOM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Documentos/CLionProjects/SegmentadorSOM/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SegmentadorSOM.dir/SOM/SOM.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SegmentadorSOM.dir/SOM/SOM.cpp.o -MF CMakeFiles/SegmentadorSOM.dir/SOM/SOM.cpp.o.d -o CMakeFiles/SegmentadorSOM.dir/SOM/SOM.cpp.o -c /mnt/d/Documentos/CLionProjects/SegmentadorSOM/SOM/SOM.cpp

CMakeFiles/SegmentadorSOM.dir/SOM/SOM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SegmentadorSOM.dir/SOM/SOM.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Documentos/CLionProjects/SegmentadorSOM/SOM/SOM.cpp > CMakeFiles/SegmentadorSOM.dir/SOM/SOM.cpp.i

CMakeFiles/SegmentadorSOM.dir/SOM/SOM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SegmentadorSOM.dir/SOM/SOM.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Documentos/CLionProjects/SegmentadorSOM/SOM/SOM.cpp -o CMakeFiles/SegmentadorSOM.dir/SOM/SOM.cpp.s

CMakeFiles/SegmentadorSOM.dir/Visualizacao/MapaContextual.cpp.o: CMakeFiles/SegmentadorSOM.dir/flags.make
CMakeFiles/SegmentadorSOM.dir/Visualizacao/MapaContextual.cpp.o: ../Visualizacao/MapaContextual.cpp
CMakeFiles/SegmentadorSOM.dir/Visualizacao/MapaContextual.cpp.o: CMakeFiles/SegmentadorSOM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Documentos/CLionProjects/SegmentadorSOM/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SegmentadorSOM.dir/Visualizacao/MapaContextual.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SegmentadorSOM.dir/Visualizacao/MapaContextual.cpp.o -MF CMakeFiles/SegmentadorSOM.dir/Visualizacao/MapaContextual.cpp.o.d -o CMakeFiles/SegmentadorSOM.dir/Visualizacao/MapaContextual.cpp.o -c /mnt/d/Documentos/CLionProjects/SegmentadorSOM/Visualizacao/MapaContextual.cpp

CMakeFiles/SegmentadorSOM.dir/Visualizacao/MapaContextual.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SegmentadorSOM.dir/Visualizacao/MapaContextual.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Documentos/CLionProjects/SegmentadorSOM/Visualizacao/MapaContextual.cpp > CMakeFiles/SegmentadorSOM.dir/Visualizacao/MapaContextual.cpp.i

CMakeFiles/SegmentadorSOM.dir/Visualizacao/MapaContextual.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SegmentadorSOM.dir/Visualizacao/MapaContextual.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Documentos/CLionProjects/SegmentadorSOM/Visualizacao/MapaContextual.cpp -o CMakeFiles/SegmentadorSOM.dir/Visualizacao/MapaContextual.cpp.s

# Object files for target SegmentadorSOM
SegmentadorSOM_OBJECTS = \
"CMakeFiles/SegmentadorSOM.dir/main.cpp.o" \
"CMakeFiles/SegmentadorSOM.dir/Calculos/Calculos.cpp.o" \
"CMakeFiles/SegmentadorSOM.dir/Codificador/Dado.cpp.o" \
"CMakeFiles/SegmentadorSOM.dir/SOM/Arranjo.cpp.o" \
"CMakeFiles/SegmentadorSOM.dir/SOM/Neuronio.cpp.o" \
"CMakeFiles/SegmentadorSOM.dir/SOM/SOM.cpp.o" \
"CMakeFiles/SegmentadorSOM.dir/Visualizacao/MapaContextual.cpp.o"

# External object files for target SegmentadorSOM
SegmentadorSOM_EXTERNAL_OBJECTS =

SegmentadorSOM: CMakeFiles/SegmentadorSOM.dir/main.cpp.o
SegmentadorSOM: CMakeFiles/SegmentadorSOM.dir/Calculos/Calculos.cpp.o
SegmentadorSOM: CMakeFiles/SegmentadorSOM.dir/Codificador/Dado.cpp.o
SegmentadorSOM: CMakeFiles/SegmentadorSOM.dir/SOM/Arranjo.cpp.o
SegmentadorSOM: CMakeFiles/SegmentadorSOM.dir/SOM/Neuronio.cpp.o
SegmentadorSOM: CMakeFiles/SegmentadorSOM.dir/SOM/SOM.cpp.o
SegmentadorSOM: CMakeFiles/SegmentadorSOM.dir/Visualizacao/MapaContextual.cpp.o
SegmentadorSOM: CMakeFiles/SegmentadorSOM.dir/build.make
SegmentadorSOM: CMakeFiles/SegmentadorSOM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Documentos/CLionProjects/SegmentadorSOM/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable SegmentadorSOM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SegmentadorSOM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SegmentadorSOM.dir/build: SegmentadorSOM
.PHONY : CMakeFiles/SegmentadorSOM.dir/build

CMakeFiles/SegmentadorSOM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SegmentadorSOM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SegmentadorSOM.dir/clean

CMakeFiles/SegmentadorSOM.dir/depend:
	cd /mnt/d/Documentos/CLionProjects/SegmentadorSOM/cmake-build-debug-wsl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Documentos/CLionProjects/SegmentadorSOM /mnt/d/Documentos/CLionProjects/SegmentadorSOM /mnt/d/Documentos/CLionProjects/SegmentadorSOM/cmake-build-debug-wsl /mnt/d/Documentos/CLionProjects/SegmentadorSOM/cmake-build-debug-wsl /mnt/d/Documentos/CLionProjects/SegmentadorSOM/cmake-build-debug-wsl/CMakeFiles/SegmentadorSOM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SegmentadorSOM.dir/depend

