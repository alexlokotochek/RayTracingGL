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

#########################################################
# Include Files
#########################################################
add_executable(RayTracingGL main.cpp View/GlutDrawer.cpp View/GlutDrawer.h Geom/Geom.cpp Geom/Geom.h Objects/IObject3D.cpp Objects/IObject3D.h View/CCamera.cpp View/CCamera.h Objects/CSphere.cpp Objects/CSphere.h View/CScene.cpp View/CScene.h KDTree/CKDTreeCPU.cpp KDTree/CKDTreeCPU.h Light/CLighter.cpp Light/CLighter.h Parser/CParser.cpp Parser/CParser.h Rendering/CRenderer.cpp Rendering/CRenderer.h KDTree/IKDTree.cpp KDTree/IKDTree.h Parser/IParser.cpp Parser/IParser.h)