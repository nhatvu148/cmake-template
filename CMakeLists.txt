cmake_minimum_required(VERSION 3.22)

project(CppProjectTemplate VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

option(ENABLE_WARNINGS "Enable to add warnings to a target." ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warnings as errors." OFF)

set(LIBRARY_NAME Library)
set(EXECUTABLE_NAME Executable)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)

if(ENABLE_WARNINGS)
    include(Warnings)
endif()

add_git_submodule(external/json)
add_git_submodule(external/fmt)
add_git_submodule(external/spdlog)
add_git_submodule(external/cxxopts)

add_subdirectory(configured)
add_subdirectory(src)
add_subdirectory(app)