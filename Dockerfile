FROM ubuntu:22.04

ARG DEFAULT_TZ=America/Los_Angeles
ENV DEFAULT_TZ=$DEFAULT_TZ

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive TZ=$DEFAULT_TZ apt-get install -y \
    make build-essential libssl-dev zlib1g-dev \
    libbz2-dev libreadline-dev libsqlite3-dev wget curl git llvm \
    libncursesw5-dev xz-utils tk-dev libxml2-dev libxmlsec1-dev \
    libffi-dev liblzma-dev \
    software-properties-common && \
    add-apt-repository -y ppa:ubuntu-toolchain-r/test

RUN apt-get install -y gcc-13 g++-13 gdb python3.10 python3-pip && \
    apt-get install -y python3.10-distutils && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* && \
    ln -s /usr/bin/g++-13 /usr/local/bin/g++ && \
    ln -s /usr/bin/gcc-13 /usr/local/bin/gcc

# RUN wget https://apt.llvm.org/llvm.sh \
#     && chmod u+x llvm.sh \
#     && /llvm.sh 17 && \
#     ln -s /usr/bin/clang-17 /usr/local/bin/clang && \
#     ln -s /usr/bin/clang++-17 /usr/local/bin/clang++

RUN wget https://github.com/Kitware/CMake/releases/download/v3.28.1/cmake-3.28.1-Linux-x86_64.sh \
    -q -O /tmp/cmake-install.sh \
    && chmod u+x /tmp/cmake-install.sh \
    && mkdir /opt/cmake-3.28.1 \
    && /tmp/cmake-install.sh --skip-license --prefix=/opt/cmake-3.28.1 \
    && rm /tmp/cmake-install.sh \
    && ln -s /opt/cmake-3.28.1/bin/* /usr/local/bin

WORKDIR /app
COPY entrypoint.sh /app/entrypoint.sh
RUN chmod +x /app/entrypoint.sh

COPY requirements.txt /app
RUN pip install -r /app/requirements.txt && \
    conan profile detect

CMD ["sh", "/app/entrypoint.sh"]