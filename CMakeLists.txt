cmake_minimum_required(VERSION 3.4)
project(RayTracingGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -Wno-deprecated-declarations")
set(CMAKE_EXE_LINKER_FLAGS " -framework GLUT -framework OpenGL -framework Cocoa")
#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)

#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

#########################################################
# Include Files
#########################################################
add_executable(RayTracingGL main.cpp GlutDrawer.cpp GlutDrawer.h)
#        Color.cpp
#        Geometry3d/Vector.cpp Geometry3d/Segment.cpp Geometry3d/Line.cpp Geometry3d/Ray.cpp Geometry3d/Sphere.cpp
#        Geometry3d/Parallelogram.cpp Geometry3d/Intersection.cpp Scene.cpp)