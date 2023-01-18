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