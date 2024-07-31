MSVC_GENERATOR="Visual Studio 17 2022"
GCC_CLANG_GENERATOR="Unix Makefiles"
BINARY_NAME=Executable

.PHONY: all
all: build-gcc run-gcc

dependency:
	cd build && cmake -S .. -B . -G $(GCC_CLANG_GENERATOR) --graphviz=graph.dot && dot -Tpng graph.dot -o graphImage.png

init:
	git submodule add --force https://github.com/microsoft/vcpkg external/vcpkg

restore:
	cd external/vcpkg && git submodule update --init --recursive

clean:
	rm -rf build
	mkdir build

.PHONY: build
build-win:
	cd build && cmake -S .. -B . -G $(MSVC_GENERATOR) && cmake --build .

build-gcc:
	cd build && cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc -DCMAKE_BUILD_TYPE=Debug -S .. -B . -G $(GCC_CLANG_GENERATOR) && cmake --build .

build-clang:
	cd build && cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -DCMAKE_BUILD_TYPE=Debug -S .. -B . -G $(GCC_CLANG_GENERATOR) && cmake --build .

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
	./build/app/Release/$(BINARY_NAME).exe

run:
	docker compose up

exec:
	docker compose exec -it cmake-runner bash

conan_d:
	rm -rf build
	mkdir build
	cd build && conan install .. -s build_type=Debug -s compiler.cppstd=23 --output-folder=. --build missing

conan_r:
	rm -rf build
	mkdir build
	cd build && conan install .. -s build_type=Release -s compiler.cppstd=23 --output-folder=. --build missing

install-vcpkg:
	# apt-get install -y curl zip unzip tar
	cd external/vcpkg/ && sh ./bootstrap-vcpkg.sh -disableMetrics

conan-config:
	# apt-get install -y vim
	vim $$(conan profile path default)

earth:
	earthly --allow-privileged +test
	# podman run --rm cmake-test:latest