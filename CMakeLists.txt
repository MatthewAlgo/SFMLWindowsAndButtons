cmake_minimum_required(VERSION 3.14...3.22)

# ---- Project ----

# Note: update this to your new project's name and version
project(
  MyNotesCPP
  VERSION 1.0
  LANGUAGES CXX
)

# ---- Include guards ----

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

# ---- Add dependencies via CPM ----
# see https://github.com/TheLartians/CPM.cmake for more info

include(cmake/CPM.cmake)

# PackageProject.cmake will be used to make our target installable
CPMAddPackage("gh:TheLartians/PackageProject.cmake@1.8.0")

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/executable_sources ${CMAKE_BINARY_DIR}/executable_sources)

# The library will be added by the CPM Package manager
# add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lib_sources ${CMAKE_BINARY_DIR}/lib_sources)
