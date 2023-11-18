MSVC_GENERATOR="Visual Studio 17 2022"
GCC_CLANG_GENERATOR="Unix Makefiles"

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
	./build/app/Executable.exe

release:
	cd build && cmake -S .. -B . -G $(MSVC_GENERATOR) && cmake --build . --config Release

release-c:
	cd build && cmake -S .. -B . -G $(GCC_CLANG_GENERATOR) && cmake --build . --config Release

run-r:
	./build/Release/Executable.exe