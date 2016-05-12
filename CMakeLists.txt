cmake_minimum_required(VERSION 3.4)
project(RayTracingGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -Wno-unused-parameter -Wno-deprecated-declarations")
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

add_executable(RayTracingGL
        main.cpp
        Painting.cpp
        Painting.h
        containers/Container.hpp
        containers/KDTree.hpp
        containers/StupidContainer.hpp
        figures/BoundingBox.hpp
        figures/Figure.hpp
        figures/FlatFigure.hpp
        figures/Sphere.hpp
        figures/Triangle.hpp
        geometry/BasicGeom.hpp
        geometry/Float.hpp
        reading/LightsLoader.hpp
        reading/MyReader.hpp
        reading/STLReader.hpp
        rendering/Image.cpp
        rendering/Image.hpp
        scene/Camera.hpp
        scene/IBody.hpp
        scene/LightSource.hpp
        scene/OneColorBody.hpp
        scene/Scene.hpp
        scene/TexturedBody.hpp)
