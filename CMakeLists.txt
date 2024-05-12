cmake_minimum_required(VERSION 3.28)
project(doomlike)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
link_libraries(OpenGL::GL)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/glfw)
link_libraries(glfw)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(glew-cmake_BUILD_SHARED OFF CACHE BOOL "" FORCE)
set(ONLY_LIBS ON CACHE BOOL "" FORCE)
set(glew-cmake_BUILD_STATIC ON CACHE BOOL "" FORCE)
add_subdirectory(lib/glew)
link_libraries(libglew_static)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp)
include_directories(include/)

add_executable(${PROJECT_NAME} main.cpp ${sources})