set(ExecName "SemProj")
set (CMAKE_CXX_STANDARD 14)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE Debug)
project( ${ExecName} )
find_package( OpenCV REQUIRED )
file(GLOB SOURCES
    "src/*.cpp"
    "main.cpp"
)
include_directories(BEFORE includes)
add_executable( ${ExecName} ${SOURCES}  )
target_link_libraries( ${ExecName} ${OpenCV_LIBS} )
