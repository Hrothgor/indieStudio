# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /home/julesminguet/EPI_2020/indieStudio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/julesminguet/EPI_2020/indieStudio/build

# Include any dependencies generated for this target.
include CMakeFiles/my_project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_project.dir/flags.make

CMakeFiles/my_project.dir/src/Entities/Bomb.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/Entities/Bomb.cpp.o: ../src/Entities/Bomb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_project.dir/src/Entities/Bomb.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/Entities/Bomb.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/Entities/Bomb.cpp

CMakeFiles/my_project.dir/src/Entities/Bomb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/Entities/Bomb.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/Entities/Bomb.cpp > CMakeFiles/my_project.dir/src/Entities/Bomb.cpp.i

CMakeFiles/my_project.dir/src/Entities/Bomb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/Entities/Bomb.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/Entities/Bomb.cpp -o CMakeFiles/my_project.dir/src/Entities/Bomb.cpp.s

CMakeFiles/my_project.dir/src/Entities/Bomberman.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/Entities/Bomberman.cpp.o: ../src/Entities/Bomberman.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/my_project.dir/src/Entities/Bomberman.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/Entities/Bomberman.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/Entities/Bomberman.cpp

CMakeFiles/my_project.dir/src/Entities/Bomberman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/Entities/Bomberman.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/Entities/Bomberman.cpp > CMakeFiles/my_project.dir/src/Entities/Bomberman.cpp.i

CMakeFiles/my_project.dir/src/Entities/Bomberman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/Entities/Bomberman.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/Entities/Bomberman.cpp -o CMakeFiles/my_project.dir/src/Entities/Bomberman.cpp.s

CMakeFiles/my_project.dir/src/Entities/Camera.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/Entities/Camera.cpp.o: ../src/Entities/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/my_project.dir/src/Entities/Camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/Entities/Camera.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/Entities/Camera.cpp

CMakeFiles/my_project.dir/src/Entities/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/Entities/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/Entities/Camera.cpp > CMakeFiles/my_project.dir/src/Entities/Camera.cpp.i

CMakeFiles/my_project.dir/src/Entities/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/Entities/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/Entities/Camera.cpp -o CMakeFiles/my_project.dir/src/Entities/Camera.cpp.s

CMakeFiles/my_project.dir/src/Entities/Entity.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/Entities/Entity.cpp.o: ../src/Entities/Entity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/my_project.dir/src/Entities/Entity.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/Entities/Entity.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/Entities/Entity.cpp

CMakeFiles/my_project.dir/src/Entities/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/Entities/Entity.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/Entities/Entity.cpp > CMakeFiles/my_project.dir/src/Entities/Entity.cpp.i

CMakeFiles/my_project.dir/src/Entities/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/Entities/Entity.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/Entities/Entity.cpp -o CMakeFiles/my_project.dir/src/Entities/Entity.cpp.s

CMakeFiles/my_project.dir/src/Entities/Light.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/Entities/Light.cpp.o: ../src/Entities/Light.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/my_project.dir/src/Entities/Light.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/Entities/Light.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/Entities/Light.cpp

CMakeFiles/my_project.dir/src/Entities/Light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/Entities/Light.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/Entities/Light.cpp > CMakeFiles/my_project.dir/src/Entities/Light.cpp.i

CMakeFiles/my_project.dir/src/Entities/Light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/Entities/Light.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/Entities/Light.cpp -o CMakeFiles/my_project.dir/src/Entities/Light.cpp.s

CMakeFiles/my_project.dir/src/Models/ParticleTexturedModel.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/Models/ParticleTexturedModel.cpp.o: ../src/Models/ParticleTexturedModel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/my_project.dir/src/Models/ParticleTexturedModel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/Models/ParticleTexturedModel.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/Models/ParticleTexturedModel.cpp

CMakeFiles/my_project.dir/src/Models/ParticleTexturedModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/Models/ParticleTexturedModel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/Models/ParticleTexturedModel.cpp > CMakeFiles/my_project.dir/src/Models/ParticleTexturedModel.cpp.i

CMakeFiles/my_project.dir/src/Models/ParticleTexturedModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/Models/ParticleTexturedModel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/Models/ParticleTexturedModel.cpp -o CMakeFiles/my_project.dir/src/Models/ParticleTexturedModel.cpp.s

CMakeFiles/my_project.dir/src/Models/TexturedModel.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/Models/TexturedModel.cpp.o: ../src/Models/TexturedModel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/my_project.dir/src/Models/TexturedModel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/Models/TexturedModel.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/Models/TexturedModel.cpp

CMakeFiles/my_project.dir/src/Models/TexturedModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/Models/TexturedModel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/Models/TexturedModel.cpp > CMakeFiles/my_project.dir/src/Models/TexturedModel.cpp.i

CMakeFiles/my_project.dir/src/Models/TexturedModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/Models/TexturedModel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/Models/TexturedModel.cpp -o CMakeFiles/my_project.dir/src/Models/TexturedModel.cpp.s

CMakeFiles/my_project.dir/src/Particles/Particle.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/Particles/Particle.cpp.o: ../src/Particles/Particle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/my_project.dir/src/Particles/Particle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/Particles/Particle.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/Particles/Particle.cpp

CMakeFiles/my_project.dir/src/Particles/Particle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/Particles/Particle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/Particles/Particle.cpp > CMakeFiles/my_project.dir/src/Particles/Particle.cpp.i

CMakeFiles/my_project.dir/src/Particles/Particle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/Particles/Particle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/Particles/Particle.cpp -o CMakeFiles/my_project.dir/src/Particles/Particle.cpp.s

CMakeFiles/my_project.dir/src/Particles/ParticleSystem.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/Particles/ParticleSystem.cpp.o: ../src/Particles/ParticleSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/my_project.dir/src/Particles/ParticleSystem.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/Particles/ParticleSystem.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/Particles/ParticleSystem.cpp

CMakeFiles/my_project.dir/src/Particles/ParticleSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/Particles/ParticleSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/Particles/ParticleSystem.cpp > CMakeFiles/my_project.dir/src/Particles/ParticleSystem.cpp.i

CMakeFiles/my_project.dir/src/Particles/ParticleSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/Particles/ParticleSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/Particles/ParticleSystem.cpp -o CMakeFiles/my_project.dir/src/Particles/ParticleSystem.cpp.s

CMakeFiles/my_project.dir/src/RenderEngine/DisplayManager.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/RenderEngine/DisplayManager.cpp.o: ../src/RenderEngine/DisplayManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/my_project.dir/src/RenderEngine/DisplayManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/RenderEngine/DisplayManager.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/RenderEngine/DisplayManager.cpp

CMakeFiles/my_project.dir/src/RenderEngine/DisplayManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/RenderEngine/DisplayManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/RenderEngine/DisplayManager.cpp > CMakeFiles/my_project.dir/src/RenderEngine/DisplayManager.cpp.i

CMakeFiles/my_project.dir/src/RenderEngine/DisplayManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/RenderEngine/DisplayManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/RenderEngine/DisplayManager.cpp -o CMakeFiles/my_project.dir/src/RenderEngine/DisplayManager.cpp.s

CMakeFiles/my_project.dir/src/RenderEngine/EntityRenderer.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/RenderEngine/EntityRenderer.cpp.o: ../src/RenderEngine/EntityRenderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/my_project.dir/src/RenderEngine/EntityRenderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/RenderEngine/EntityRenderer.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/RenderEngine/EntityRenderer.cpp

CMakeFiles/my_project.dir/src/RenderEngine/EntityRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/RenderEngine/EntityRenderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/RenderEngine/EntityRenderer.cpp > CMakeFiles/my_project.dir/src/RenderEngine/EntityRenderer.cpp.i

CMakeFiles/my_project.dir/src/RenderEngine/EntityRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/RenderEngine/EntityRenderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/RenderEngine/EntityRenderer.cpp -o CMakeFiles/my_project.dir/src/RenderEngine/EntityRenderer.cpp.s

CMakeFiles/my_project.dir/src/RenderEngine/FrameRate.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/RenderEngine/FrameRate.cpp.o: ../src/RenderEngine/FrameRate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/my_project.dir/src/RenderEngine/FrameRate.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/RenderEngine/FrameRate.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/RenderEngine/FrameRate.cpp

CMakeFiles/my_project.dir/src/RenderEngine/FrameRate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/RenderEngine/FrameRate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/RenderEngine/FrameRate.cpp > CMakeFiles/my_project.dir/src/RenderEngine/FrameRate.cpp.i

CMakeFiles/my_project.dir/src/RenderEngine/FrameRate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/RenderEngine/FrameRate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/RenderEngine/FrameRate.cpp -o CMakeFiles/my_project.dir/src/RenderEngine/FrameRate.cpp.s

CMakeFiles/my_project.dir/src/RenderEngine/MasterRenderer.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/RenderEngine/MasterRenderer.cpp.o: ../src/RenderEngine/MasterRenderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/my_project.dir/src/RenderEngine/MasterRenderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/RenderEngine/MasterRenderer.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/RenderEngine/MasterRenderer.cpp

CMakeFiles/my_project.dir/src/RenderEngine/MasterRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/RenderEngine/MasterRenderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/RenderEngine/MasterRenderer.cpp > CMakeFiles/my_project.dir/src/RenderEngine/MasterRenderer.cpp.i

CMakeFiles/my_project.dir/src/RenderEngine/MasterRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/RenderEngine/MasterRenderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/RenderEngine/MasterRenderer.cpp -o CMakeFiles/my_project.dir/src/RenderEngine/MasterRenderer.cpp.s

CMakeFiles/my_project.dir/src/RenderEngine/ParticlesRenderer.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/RenderEngine/ParticlesRenderer.cpp.o: ../src/RenderEngine/ParticlesRenderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/my_project.dir/src/RenderEngine/ParticlesRenderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/RenderEngine/ParticlesRenderer.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/RenderEngine/ParticlesRenderer.cpp

CMakeFiles/my_project.dir/src/RenderEngine/ParticlesRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/RenderEngine/ParticlesRenderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/RenderEngine/ParticlesRenderer.cpp > CMakeFiles/my_project.dir/src/RenderEngine/ParticlesRenderer.cpp.i

CMakeFiles/my_project.dir/src/RenderEngine/ParticlesRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/RenderEngine/ParticlesRenderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/RenderEngine/ParticlesRenderer.cpp -o CMakeFiles/my_project.dir/src/RenderEngine/ParticlesRenderer.cpp.s

CMakeFiles/my_project.dir/src/Shaders/LightShader.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/Shaders/LightShader.cpp.o: ../src/Shaders/LightShader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/my_project.dir/src/Shaders/LightShader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/Shaders/LightShader.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/Shaders/LightShader.cpp

CMakeFiles/my_project.dir/src/Shaders/LightShader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/Shaders/LightShader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/Shaders/LightShader.cpp > CMakeFiles/my_project.dir/src/Shaders/LightShader.cpp.i

CMakeFiles/my_project.dir/src/Shaders/LightShader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/Shaders/LightShader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/Shaders/LightShader.cpp -o CMakeFiles/my_project.dir/src/Shaders/LightShader.cpp.s

CMakeFiles/my_project.dir/src/Shaders/ParticlesShader.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/Shaders/ParticlesShader.cpp.o: ../src/Shaders/ParticlesShader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/my_project.dir/src/Shaders/ParticlesShader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/Shaders/ParticlesShader.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/Shaders/ParticlesShader.cpp

CMakeFiles/my_project.dir/src/Shaders/ParticlesShader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/Shaders/ParticlesShader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/Shaders/ParticlesShader.cpp > CMakeFiles/my_project.dir/src/Shaders/ParticlesShader.cpp.i

CMakeFiles/my_project.dir/src/Shaders/ParticlesShader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/Shaders/ParticlesShader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/Shaders/ParticlesShader.cpp -o CMakeFiles/my_project.dir/src/Shaders/ParticlesShader.cpp.s

CMakeFiles/my_project.dir/src/Tools/Clock.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/Tools/Clock.cpp.o: ../src/Tools/Clock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/my_project.dir/src/Tools/Clock.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/Tools/Clock.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/Tools/Clock.cpp

CMakeFiles/my_project.dir/src/Tools/Clock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/Tools/Clock.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/Tools/Clock.cpp > CMakeFiles/my_project.dir/src/Tools/Clock.cpp.i

CMakeFiles/my_project.dir/src/Tools/Clock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/Tools/Clock.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/Tools/Clock.cpp -o CMakeFiles/my_project.dir/src/Tools/Clock.cpp.s

CMakeFiles/my_project.dir/src/Tools/Maths.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/Tools/Maths.cpp.o: ../src/Tools/Maths.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/my_project.dir/src/Tools/Maths.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/Tools/Maths.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/Tools/Maths.cpp

CMakeFiles/my_project.dir/src/Tools/Maths.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/Tools/Maths.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/Tools/Maths.cpp > CMakeFiles/my_project.dir/src/Tools/Maths.cpp.i

CMakeFiles/my_project.dir/src/Tools/Maths.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/Tools/Maths.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/Tools/Maths.cpp -o CMakeFiles/my_project.dir/src/Tools/Maths.cpp.s

CMakeFiles/my_project.dir/src/main.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/my_project.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/src/main.cpp.o -c /home/julesminguet/EPI_2020/indieStudio/src/main.cpp

CMakeFiles/my_project.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julesminguet/EPI_2020/indieStudio/src/main.cpp > CMakeFiles/my_project.dir/src/main.cpp.i

CMakeFiles/my_project.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julesminguet/EPI_2020/indieStudio/src/main.cpp -o CMakeFiles/my_project.dir/src/main.cpp.s

# Object files for target my_project
my_project_OBJECTS = \
"CMakeFiles/my_project.dir/src/Entities/Bomb.cpp.o" \
"CMakeFiles/my_project.dir/src/Entities/Bomberman.cpp.o" \
"CMakeFiles/my_project.dir/src/Entities/Camera.cpp.o" \
"CMakeFiles/my_project.dir/src/Entities/Entity.cpp.o" \
"CMakeFiles/my_project.dir/src/Entities/Light.cpp.o" \
"CMakeFiles/my_project.dir/src/Models/ParticleTexturedModel.cpp.o" \
"CMakeFiles/my_project.dir/src/Models/TexturedModel.cpp.o" \
"CMakeFiles/my_project.dir/src/Particles/Particle.cpp.o" \
"CMakeFiles/my_project.dir/src/Particles/ParticleSystem.cpp.o" \
"CMakeFiles/my_project.dir/src/RenderEngine/DisplayManager.cpp.o" \
"CMakeFiles/my_project.dir/src/RenderEngine/EntityRenderer.cpp.o" \
"CMakeFiles/my_project.dir/src/RenderEngine/FrameRate.cpp.o" \
"CMakeFiles/my_project.dir/src/RenderEngine/MasterRenderer.cpp.o" \
"CMakeFiles/my_project.dir/src/RenderEngine/ParticlesRenderer.cpp.o" \
"CMakeFiles/my_project.dir/src/Shaders/LightShader.cpp.o" \
"CMakeFiles/my_project.dir/src/Shaders/ParticlesShader.cpp.o" \
"CMakeFiles/my_project.dir/src/Tools/Clock.cpp.o" \
"CMakeFiles/my_project.dir/src/Tools/Maths.cpp.o" \
"CMakeFiles/my_project.dir/src/main.cpp.o"

# External object files for target my_project
my_project_EXTERNAL_OBJECTS =

my_project: CMakeFiles/my_project.dir/src/Entities/Bomb.cpp.o
my_project: CMakeFiles/my_project.dir/src/Entities/Bomberman.cpp.o
my_project: CMakeFiles/my_project.dir/src/Entities/Camera.cpp.o
my_project: CMakeFiles/my_project.dir/src/Entities/Entity.cpp.o
my_project: CMakeFiles/my_project.dir/src/Entities/Light.cpp.o
my_project: CMakeFiles/my_project.dir/src/Models/ParticleTexturedModel.cpp.o
my_project: CMakeFiles/my_project.dir/src/Models/TexturedModel.cpp.o
my_project: CMakeFiles/my_project.dir/src/Particles/Particle.cpp.o
my_project: CMakeFiles/my_project.dir/src/Particles/ParticleSystem.cpp.o
my_project: CMakeFiles/my_project.dir/src/RenderEngine/DisplayManager.cpp.o
my_project: CMakeFiles/my_project.dir/src/RenderEngine/EntityRenderer.cpp.o
my_project: CMakeFiles/my_project.dir/src/RenderEngine/FrameRate.cpp.o
my_project: CMakeFiles/my_project.dir/src/RenderEngine/MasterRenderer.cpp.o
my_project: CMakeFiles/my_project.dir/src/RenderEngine/ParticlesRenderer.cpp.o
my_project: CMakeFiles/my_project.dir/src/Shaders/LightShader.cpp.o
my_project: CMakeFiles/my_project.dir/src/Shaders/ParticlesShader.cpp.o
my_project: CMakeFiles/my_project.dir/src/Tools/Clock.cpp.o
my_project: CMakeFiles/my_project.dir/src/Tools/Maths.cpp.o
my_project: CMakeFiles/my_project.dir/src/main.cpp.o
my_project: CMakeFiles/my_project.dir/build.make
my_project: /usr/local/lib64/libraylib.so
my_project: CMakeFiles/my_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking CXX executable my_project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_project.dir/build: my_project

.PHONY : CMakeFiles/my_project.dir/build

CMakeFiles/my_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_project.dir/clean

CMakeFiles/my_project.dir/depend:
	cd /home/julesminguet/EPI_2020/indieStudio/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julesminguet/EPI_2020/indieStudio /home/julesminguet/EPI_2020/indieStudio /home/julesminguet/EPI_2020/indieStudio/build /home/julesminguet/EPI_2020/indieStudio/build /home/julesminguet/EPI_2020/indieStudio/build/CMakeFiles/my_project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_project.dir/depend

