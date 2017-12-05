cmake_minimum_required(VERSION 2.8)
project(rhoban_graphs)

find_package(catkin REQUIRED COMPONENTS
  rhoban_geometry
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES rhoban_graphs
  CATKIN_DEPENDS rhoban_geometry
)

include_directories(include ${catkin_INCLUDE_DIRS})

#Enable C++11
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")

#Enable Weird option linker
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

#List Sources sub source directories
set(SOURCES_DIRECTORIES
  src/rhoban_graphs
)

#Include Sources sub sources
foreach (DIRECTORY ${SOURCES_DIRECTORIES})
    message(STATUS "-- Sources: Adding ${DIRECTORY}/")
    include (${DIRECTORY}/Sources.cmake)
    set (PREFIXED_SOURCES)
    foreach (SOURCE ${SOURCES})
        set (PREFIXED_SOURCES ${PREFIXED_SOURCES} ${DIRECTORY}/${SOURCE})
    endforeach (SOURCE)
    set (ALL_SOURCES ${ALL_SOURCES} ${PREFIXED_SOURCES})
endforeach (DIRECTORY)

add_library (rhoban_graphs ${ALL_SOURCES})
target_link_libraries(rhoban_graphs ${catkin_LIBRARIES})

if (RHOBAN_GRAPHS_BUILD_APPS)
#    add_executable (astarTest astar/main.cpp)
#    target_link_libraries (astarTest rhoban_utils)
    add_executable (graphTest graph/test.cpp)
    target_link_libraries (graphTest rhoban_utils)
endif()
