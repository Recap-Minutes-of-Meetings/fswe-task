FROM gcc:11.2.0

RUN apt update && apt install -y clang-format git cmake gdb
ARG NUM_CORES=6

# cmake -D CMAKE_INSTALL_PREFIX=/usr/local -D CMAKE_BUILD_TYPE=Release .. && make -j${NUM_CORES} && make install 

RUN ldconfig

WORKDIR /workspace
