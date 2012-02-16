cmake_minimum_required(VERSION 2.6)
project(cg1)

find_package (SDL REQUIRED)
if(NOT SDL_FOUND)
	message (FATAL_ERROR "SDL not found!")
endif (NOT SDL_FOUND)

find_package (GLUT REQUIRED)
if(NOT GLUT_FOUND)
    message (FATAL_ERROR "GLUT not found!")
endif (NOT GLUT_FOUND)

find_package (OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message (FATAL_ERROR "OpenGL not found!")
endif (NOT OPENGL_FOUND)

link_libraries(${GLUT_LIBRARIES} ${OPENGL_LIBRARIES} ${SDL_LIBRARY})

file(GLOB SOURCES *.cpp)
add_executable(main ${SOURCES})
