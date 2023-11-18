cmake_minimum_required(VERSION 3.20.0)
project(DisplayImage)

find_package(OpenCV REQUIRED PATHS C:/Users/nhatv/Work/open-source/opencv/build/x64/vc16/lib)

add_executable(DisplayImage main.cpp)

target_include_directories(DisplayImage PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(DisplayImage PUBLIC ${OpenCV_LIBS})

message("OpenCV Include Directories: "${OpenCV_INCLUDE_DIRS})
message("OpenCV Libraries: "${OpenCV_LIBS})
