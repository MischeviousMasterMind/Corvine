cmake_minimum_required(VERSION 3.24...3.30)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Corvine VERSION 1.0.0)

# ====================================================================================================
# Fetching Google Test via URL
include(FetchContent)

# Google Test
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Including FreeGLUT's header files and linking its libraries
include(FindGLUT)

if(GLUT_FOUND)
  find_package(GLUT REQUIRED)
  include_directories(GLUT_INCLUDE_DIR)
else()
  message("GLUT not found, installing using vcpckg")
  execute_process(COMMAND vcpkg install freeglut)
endif()

# Finding OpenGL within the operating system, including its header files, and linking its libraries
include(FindOpenGL)

if(NOT OPENGL_FOUND)
  message(ERROR "OpenGL not found!")
endif()
find_package(OpenGL REQUIRED)
include_directories(OPENGL_INCLUDE_DIR)
link_directories(OpenGL::GL)

# ====================================================================================================

# Includes root project header files in the include directory
include_directories(include)

add_executable(${PROJECT_NAME})
add_subdirectory(src)

# Links FreeGLUT and OpenGL libraries
target_link_libraries(${PROJECT_NAME} GLUT::GLUT OpenGL::GL)
