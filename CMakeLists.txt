cmake_minimum_required(VERSION 2.6)
project(cg1)

find_package (SDL REQUIRED)
if(NOT SDL_FOUND)
	message (FATAL_ERROR "SDL not found!")
endif (NOT SDL_FOUND)

link_libraries(glut ${SDL_LIBRARY}) 

file(GLOB SOURCES *.cpp)
add_executable(main ${SOURCES})
