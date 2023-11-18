# CMake Project Template

## Setup on Windows

- Install Visual Studio 2022 for MSVC, VSCode
- Install gcc, clang at https://winlibs.com/, download GCC 13.2.0 (with POSIX threads) + LLVM/Clang/LLD/LLDB 16.0.6 + MinGW-w64 11.0.0 (UCRT) or newer
- Open Developer Powershell for VS 2022 and open VSCode

## Setup on Ubuntu

- sudo apt-get install build-essential
- sudo apt-cache search gcc | less
- sudo apt-get install gcc-10 g++-10
- sudo apt-get install gdb
- sudo apt-cache search clang | less
- sudo apt-get install clang-12
- cd /usr/bin && ls

## Setup on macOS

- brew install gcc
- brew install llvm
- Copy 'export PATH="/usr/local/opt/llvm/bin:$PATH"' to ~/.bash_profile
- g++-13 --version
- clang++ --version

## Submodules

- git submodule add https://github.com/nlohmann/json external/json
- git submodule add https://github.com/fmtlib/fmt external/fmt
- git submodule add https://github.com/gabime/spdlog external/spdlog
- git submodule add https://github.com/jarro2783/cxxopts external/cxxopts
- git submodule add https://github.com/catchorg/Catch2 external/Catch2
