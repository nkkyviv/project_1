CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

project(abstractProj)

#tells Cmake to search for header files in lib/include folder
include_directories(lib/include)

set(SourcesLib lib/src/project.cpp)
set(SourcesApp app/src/main.cpp)

#we are telling to cmake to build a library from source code
add_library(file_io_lib ${SourcesLib})

#it is our application
add_executable(myApp ${SourcesApp})

#Link our library to an executable file
target_link_libraries(myApp file_io_lib)



#GoogleTest part

#Include CMake module to be able to download GoogleTest
include(FetchContent)

# Declare git repo and tag to fetch:
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

#Download or check that googletest is downloaded:
FetchContent_MakeAvailable(googletest)

# Build our Unit Tests
add_executable(lib_ut_tests lib/ut/tests.cpp lib/ut/ut_lib_tests.cpp)
target_link_libraries(lib_ut_tests gtest gtest_main file_io_lib)



