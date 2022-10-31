git submodule update --init --recursive;
cd submodules/googletest;
mkdir -p build;
cd build;
cmake ..;
make;
