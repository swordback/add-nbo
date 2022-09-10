1. How to build

rm -rf CMakeCache.txt
rm -rf cmake_install.cmake
rm -rf ./CMakeFiles

cmake CMakeLists.txt
make clean && make

2. How to execute

./add-nbo thousand.bin five-hundred.bin

3. Environment

- Kali linux-2022.3-virtualbox
