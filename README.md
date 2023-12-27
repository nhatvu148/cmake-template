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

## Package managers

- [conan](https://conan.io/center)
- [vckpg](https://vcpkg.io/en/packages)
- [vckpg-link](https://vcpkg.link)
- [cargo](https://crates.io)

## Online editors

- [cppinsights](https://cppinsights.io)
- [wandbox](https://wandbox.org)

## References

- [hackingcpp](https://hackingcpp.com)
- [algorithm](https://en.cppreference.com/w/cpp/algorithm)
- [ranges](https://en.cppreference.com/w/cpp/ranges)
- [awesome-cpp](https://github.com/fffaraz/awesome-cpp)
- [awesome-modern-cpp](https://github.com/rigtorp/awesome-modern-cpp)
