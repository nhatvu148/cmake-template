VERSION 0.8
FROM ubuntu:22.04
WORKDIR /app

build:
    ARG tag='latest'
    FROM DOCKERFILE .
    SAVE IMAGE cmake-app:$tag

test:
    FROM earthly/dind:alpine-3.19-docker-25.0.5-r0
    COPY .env .
    WITH DOCKER --load cmake-runner:latest=+build
        RUN docker run --env-file .env cmake-runner:latest
    END