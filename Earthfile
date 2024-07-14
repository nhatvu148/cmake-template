VERSION 0.8
FROM DOCKERFILE .

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

# build:
#     ARG tag='latest'
#     FROM DOCKERFILE .
#     SAVE IMAGE cmake-app:$tag

# test:
#     FROM earthly/dind:alpine-3.19-docker-25.0.5-r0
#     COPY .env .
#     WITH DOCKER --load cmake-runner:latest=+build
#         RUN docker run --env-file .env cmake-runner:latest
#     END

test:
    FROM +build
    RUN ./build/app/Executable

docker:
    ARG tag='latest'
    FROM +build
    COPY +build/build/app/Executable .
    ENTRYPOINT ["./Executable"]
    SAVE IMAGE cmake-test:$tag