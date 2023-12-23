FROM ubuntu:22.04

ARG DEFAULT_TZ=America/Los_Angeles
ENV DEFAULT_TZ=$DEFAULT_TZ

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive TZ=$DEFAULT_TZ apt-get install -y \
    make build-essential libssl-dev zlib1g-dev \
    libbz2-dev libreadline-dev libsqlite3-dev wget curl git llvm \
    libncursesw5-dev xz-utils tk-dev libxml2-dev libxmlsec1-dev \
    libffi-dev liblzma-dev && \
    apt-get install -y gcc-10 g++-10 gdb clang-12 python3.10 python3-pip && \
    apt-get install -y python3.10-distutils && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN wget https://github.com/Kitware/CMake/releases/download/v3.28.1/cmake-3.28.1-Linux-x86_64.sh \
      -q -O /tmp/cmake-install.sh \
      && chmod u+x /tmp/cmake-install.sh \
      && mkdir /opt/cmake-3.28.1 \
      && /tmp/cmake-install.sh --skip-license --prefix=/opt/cmake-3.28.1 \
      && rm /tmp/cmake-install.sh \
      && ln -s /opt/cmake-3.28.1/bin/* /usr/local/bin

COPY entrypoint.sh /usr/bin/entrypoint.sh
RUN chmod +x /usr/bin/entrypoint.sh

CMD ["/usr/bin/entrypoint.sh"]