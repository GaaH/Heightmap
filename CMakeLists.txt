cmake_minimum_required(VERSION 2.8)
project(Heightmap)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE "Debug")
endif()

# Flags
if (CMAKE_CXX_COMPILER MATCHES "clang")
  set(CMAKE_COMPILER_IS_CLANGXX 1)
endif ()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Os")
endif()

file(
  GLOB_RECURSE
  PROJECT_SOURCES
  src/*
  )

set(PROJECT_LIBS "-lsfml-system -lsfml-window -lsfml-graphics")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBS})
