cmake_minimum_required(VERSION 3.19)
project(PwdManager)
set(CMAKE_CXX_STANDARD 14)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(pwdmanager src/main.cpp src/base64.cpp src/err.cpp src/encdb.cpp src/sha512.cpp src/aes256.cpp)