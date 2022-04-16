# version 3.11 or later of CMake or needed later for installing GoogleTest
# so let's require it now.
cmake_minimum_required(VERSION 3.11-3.18)

project(lib)

set(BUILD_SHARED_LIBS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS True)

add_library(lib SHARED src/lib.cpp)

# PUBLIC needed to make both hello.h and hello library available elsewhere in project
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_custom_command(TARGET lib POST_BUILD 
  COMMAND "${CMAKE_COMMAND}" -E copy 
     "$<TARGET_FILE:lib>"
     "../apps/$<CONFIGURATION>/$<TARGET_FILE_NAME:lib>" 
  COMMENT "Copying to output directory")

add_custom_command(TARGET lib POST_BUILD 
  COMMAND "${CMAKE_COMMAND}" -E copy 
     "$<TARGET_FILE:lib>"
     "../tests/$<CONFIGURATION>/$<TARGET_FILE_NAME:lib>" 
  COMMENT "Copying to tests directory")
