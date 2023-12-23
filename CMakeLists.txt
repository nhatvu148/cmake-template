cmake_minimum_required(VERSION 3.22)

project(CppProjectTemplate VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

option(USE_CPM "Whether to use CPM" OFF)
option(USE_CONAN "Whether to use Conan" ON)
option(USE_VCPKG "Whether to use VCPKG" OFF)

option(ENABLE_WARNINGS "Enable to add warnings to a target." ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warnings as errors." OFF)

set(LIBRARY_NAME Library)
set(EXECUTABLE_NAME Executable)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)

if(ENABLE_WARNINGS)
    include(Warnings)
endif()

if(USE_CPM)
    # git repos cloned into local, locally compile them, needs to be Cmake projects 
    message(STATUS "Using CPM")
    include(CPM)
    cpmaddpackage("gh:nlohmann/json#v3.11.3")
    cpmaddpackage("gh:fmtlib/fmt#9.1.0")
    cpmaddpackage("gh:gabime/spdlog#v1.12.0")
    cpmaddpackage("gh:jarro2783/cxxopts#v3.1.1")
elseif(USE_CONAN)
    # use this option when there are pre-compiled binaries, needs to be Cmake projects
    message(STATUS "Using Conan")
    include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)
    find_package(nlohmann_json REQUIRED)
    find_package(fmt REQUIRED)
    find_package(spdlog REQUIRED)
    find_package(cxxopts REQUIRED)
elseif(USE_VCPKG)
    # use this option when there are pre-built binaries, needs to be Cmake projects
    message(STATUS "Using VCPKG")
    include(${CMAKE_SOURCE_DIR}/external/vcpkg/scripts/buildsystems/vcpkg.cmake)
    find_package(nlohmann_json REQUIRED)
    find_package(fmt REQUIRED)
    find_package(spdlog REQUIRED)
    find_package(cxxopts REQUIRED)
else()
    # use this else option when the external libs do not use Cmake, just have header files
    add_git_submodule(external/json)
    add_git_submodule(external/fmt)
    add_git_submodule(external/spdlog)
    add_git_submodule(external/cxxopts)
endif()

add_subdirectory(configured)
add_subdirectory(src)
add_subdirectory(app)