cmake_minimum_required(VERSION 3.10)

# Project
project(Tater VERSION 1.0)

# vcpkg 
set(CMAKE_TOOLCHAIN_FILE ./vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")