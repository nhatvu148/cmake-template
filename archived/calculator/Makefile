MSVC_GENERATOR="Visual Studio 17 2022"
GCC_CLANG_GENERATOR="Unix Makefiles"
BINARY_NAME=calculator

dependency:
	cd build && cmake -S .. -B . -G $(GCC_CLANG_GENERATOR) --graphviz=graph.dot && dot -Tpng graph.dot -o graphImage.png

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
	./build/Debug/$(BINARY_NAME).exe

run-gcc:
	./build/$(BINARY_NAME)

run-clang:
	./build/$(BINARY_NAME)

release-win:
	cd build && cmake -S .. -B . -G $(MSVC_GENERATOR) && cmake --build . --config Release

release-gcc:
	cd build && cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc -S .. -B . -G $(GCC_CLANG_GENERATOR) && cmake --build . --config Release

release-clang:
	cd build && cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -S .. -B . -G $(GCC_CLANG_GENERATOR) && cmake --build . --config Release

run-release-win:
	./build/Release/$(BINARY_NAME).exe