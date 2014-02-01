project(HeightMap)
cmake_minimum_required(VERSION 2.8)

FILE(
  GLOB_RECURSE
  PROJECT_SOURCES
  src/*
  )
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable("${PROJECT_NAME}" ${PROJECT_SOURCES})
