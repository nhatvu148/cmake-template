MSVC_GENERATOR="Visual Studio 17 2022"
GCC_CLANG_GENERATOR="Unix Makefiles"
BINARY_NAME=Executable

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
build-win:
	cd build && cmake -S .. -B . -G $(MSVC_GENERATOR) && cmake --build .

build-gcc:
	cd build && cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc -S .. -B . -G $(GCC_CLANG_GENERATOR) && cmake --build .

build-clang:
	cd build && cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -S .. -B . -G $(GCC_CLANG_GENERATOR) && cmake --build .

update:
	cd build && cmake .

run-win:
	./build/app/Debug/$(BINARY_NAME).exe

run-gcc:
	./build/app/$(BINARY_NAME)

run-clang:
	./build/app/$(BINARY_NAME)

release-win:
	cd build && cmake -S .. -B . -G $(MSVC_GENERATOR) && cmake --build . --config Release

release-gcc:
	cd build && cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc -S .. -B . -G $(GCC_CLANG_GENERATOR) && cmake --build . --config Release

release-clang:
	cd build && cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -S .. -B . -G $(GCC_CLANG_GENERATOR) && cmake --build . --config Release

run-release-win:
	./build/Release/$(BINARY_NAME).exe