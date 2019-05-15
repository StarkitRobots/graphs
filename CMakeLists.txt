cmake_minimum_required(VERSION 2.8)
project(starkit_graphs)

option (STARKIT_GRAPHS_BUILD_APPS "Build starkit_graphs apps" OFF)

find_package(catkin REQUIRED COMPONENTS
  starkit_geometry
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES starkit_graphs
  CATKIN_DEPENDS starkit_geometry
)

include_directories(include ${catkin_INCLUDE_DIRS})

#Enable C++17
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra")

#Enable Weird option linker
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

#List Sources sub source directories
set(SOURCES_DIRECTORIES
  src/starkit_graphs
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

add_library (starkit_graphs ${ALL_SOURCES})
target_link_libraries(starkit_graphs ${catkin_LIBRARIES})

if (STARKIT_GRAPHS_BUILD_APPS)
    add_executable (astarTest src/a_star_test.cpp)
    target_link_libraries (astarTest starkit_graphs ${catkin_LIBRARIES})
    
    add_executable (graphTest src/test.cpp)
    target_link_libraries (graphTest starkit_graphs ${catkin_LIBRARIES})
endif()
