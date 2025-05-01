@echo off
chcp 65001
setlocal

REM Delete existing build directory
if exist build rmdir /s /q build

REM Create build directory
mkdir build
cd build

REM Configure CMake
cmake -G "Ninja" -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake ..

REM Run build
cmake --build .

cd ..
echo Build completed.

REM Run executable
build\json_example.exe