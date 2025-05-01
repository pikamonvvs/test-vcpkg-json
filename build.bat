@echo off
chcp 65001
setlocal

REM 기존 빌드 디렉토리 삭제
if exist build rmdir /s /q build

REM 빌드 디렉토리 생성
mkdir build
cd build

REM CMake 구성
cmake -G "Ninja" -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake ..

REM 빌드 실행
cmake --build .

cd ..
echo Build completed.

REM 실행 파일 실행
build\json_example.exe