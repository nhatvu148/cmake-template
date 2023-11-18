MSVC_GENERATOR="Visual Studio 17 2022"
GCC_CLANG_GENERATOR="Unix Makefiles"

dependency:
	cd build && cmake -S .. -B . -G $(GCC_CLANG_GENERATOR) --graphviz=graph.dot && dot -Tpng graph.dot -o graphImage.png

restore:
	git submodule add --force https://github.com/nlohmann/json external/json
	git submodule add --force https://github.com/fmtlib/fmt external/fmt
	git submodule add --force https://github.com/gabime/spdlog external/spdlog
	git submodule add --force https://github.com/jarro2783/cxxopts external/cxxopts

clean:
	rm -rf build
	mkdir build

.PHONY: build
build:
	cd build && cmake -S .. -B . -G $(MSVC_GENERATOR) && cmake --build .

build-c:
	cd build && cmake -S .. -B . -G $(GCC_CLANG_GENERATOR) && cmake --build .

update:
	cd build && cmake .

run:
	./build/app/Debug/Executable.exe

run-c:
	./build/app/Executable

release:
	cd build && cmake -S .. -B . -G $(MSVC_GENERATOR) && cmake --build . --config Release

release-c:
	cd build && cmake -S .. -B . -G $(GCC_CLANG_GENERATOR) && cmake --build . --config Release

run-r:
	./build/Release/Executable.exe