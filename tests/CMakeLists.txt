file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS *.cpp)

add_executable(corvine_test ${SOURCE_FILES})