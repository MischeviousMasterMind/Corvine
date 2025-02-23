cmake_minimum_required(VERSION 3.24...3.30)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ====================================================================================================
# Fetching Google Test and FreeGLUT dependencies via URL

include(FetchContent)

# Google Test
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# FreeGLUT (v3.6.0)
FetchContent_Declare(
  freeglut
  URL https://github.com/freeglut/freeglut/releases/download/v3.6.0/freeglut-3.6.0.tar.gz
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest freeglut)

# Finding OpenGL within the operating system, including its header files, and linking its libraries
include(FindOpenGL)

set(FreeGLUT_DIR ${freeglut_BINARY_DIR}/FreeGLUT)
find_package(FreeGLUT REQUIRED)

find_package(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
  message(ERROR "OpenGL not found!")
endif()
include_directories(OPENGL_INCLUDE_DIR)

# ====================================================================================================

project(Corvine VERSION 1.0.0)

include_directories(include)

add_executable(${PROJECT_NAME})
add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} 
  FreeGLUT::freeglut
  OpenGL::GL
)