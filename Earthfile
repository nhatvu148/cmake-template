VERSION 0.8
FROM DOCKERFILE .
WORKDIR /app

deps:
    COPY conanfile.py .
    RUN rm -rf build && mkdir build
    RUN cd build && conan install .. -s build_type=Debug -s compiler.cppstd=23 --output-folder=. --build missing
    SAVE ARTIFACT build AS LOCAL local-output/build
    
build:
    FROM +deps
    COPY . .
    RUN cd build && cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc -DCMAKE_BUILD_TYPE=Debug -S .. -B . -G "Unix Makefiles" && cmake --build .
    SAVE ARTIFACT build AS LOCAL local-output/build

test:
    FROM +build
    RUN ./build/app/Executable

docker:
    ARG tag='latest'
    FROM +build
    COPY +build/build/app/Executable .
    ENTRYPOINT ["/app/Executable"]
    SAVE IMAGE cmake-test:$tag