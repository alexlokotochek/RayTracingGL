cmake_minimum_required(VERSION 3.2)

project(RayTracing_GL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-deprecated-declarations -v")
set(CMAKE_EXE_LINKER_FLAGS " -framework GLUT -framework OpenGL -framework Cocoa")
set(SOURCE_FILES
        main.cpp
        figures/Object.hpp
        figures/Sphere.hpp
        figures/Triangle.hpp
        reading/ConfigReader.hpp
        reading/LightsReader.hpp
        reading/STLReader.hpp
        scene/Body.hpp
        scene/Camera.hpp
        scene/LightSource.hpp
        scene/Scene.hpp
        Geometry.hpp
        Image.hpp
        KDTree.hpp)

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

add_executable(RayTracing_GL ${SOURCE_FILES})