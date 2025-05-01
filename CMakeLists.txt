cmake_minimum_required(VERSION 3.10)
project(json_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# MinGW 사용 시 정적 라이브러리 사용
set(YAML_CPP_BUILD_SHARED OFF CACHE BOOL "yaml-cpp 정적 라이브러리 사용")

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()

find_package(nlohmann_json CONFIG REQUIRED)

add_executable(json_example main.cpp)
target_link_libraries(json_example PRIVATE nlohmann_json::nlohmann_json)