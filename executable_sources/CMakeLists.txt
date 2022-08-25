cmake_minimum_required(VERSION 3.14...3.22)

project(MyNotesExecutable LANGUAGES CXX)

# --- Import tools ----

include(../cmake/tools.cmake)

# ---- Dependencies ----

include(../cmake/CPM.cmake)


# ---- Create standalone executable ----

# Adds the custom library to CPM
CPMAddPackage(NAME MyNotesLibraries SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/../lib_sources)

# ---- Add other dependencies ----

# Graphics and OpenGl
find_package(OpenGL REQUIRED)
CPMAddPackage(
  NAME sfml
  GITHUB_REPOSITORY SFML/SFML
  GIT_TAG 2.5.x
)
set_target_properties(sfml-system PROPERTIES CXX_STANDARD 98 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)
set_target_properties(sfml-network PROPERTIES CXX_STANDARD 98 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)
set_target_properties(sfml-graphics PROPERTIES CXX_STANDARD 98 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)
set_target_properties(sfml-window PROPERTIES CXX_STANDARD 98 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)
set_target_properties(sfml-audio PROPERTIES CXX_STANDARD 98 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)
find_package(SFML REQUIRED COMPONENTS graphics window system audio network)


file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

add_executable(${PROJECT_NAME} ${sources})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17 OUTPUT_NAME "MyNotes")

# target_link_libraries(${PROJECT_NAME} MyNotesLibraries)

# Include custom library dependencies here
if (WIN32)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network opengl32
  winmm MyNotesLibraries)
endif (WIN32)

if (UNIX AND NOT APPLE)
target_link_libraries(${PROJECT_NAME} PRIVATE X11 sfml-system sfml-window sfml-graphics sfml-audio sfml-network ${OPENGL_LIBRARIES} MyNotesLibraries)
endif (UNIX AND NOT APPLE)

if (APPLE)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network ${OPENGL_LIBRARIES} MyNotesLibraries)
endif (APPLE)

target_include_directories(
  ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/../include>
                         $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>
)
