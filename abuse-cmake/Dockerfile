FROM ubuntu:latest

ADD . /opt/build/abuse/

WORKDIR /opt/build/abuse

RUN apt-get update && apt-get install -y \
         apt-utils \
         autoconf \
         build-essential \
         curl \
         file \
         gcc \
         make \
      && rm -rf /var/lib/apt/lists/* \
      && curl https://cmake.org/files/v3.12/cmake-3.12.1-Linux-x86_64.sh -o cmake.sh \
      && sh cmake.sh --skip-license --prefix=/usr/local/ --exclude-subdir \
      && rm cmake.sh \
      && mkdir build \
      && cd build \
      && cmake .. \
      && make
