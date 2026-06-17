cmake_minimum_required(VERSION 3.10)
project(Project)

set(CMAKE_CXX_STANDARD 20)

# Esta linha recolhe automaticamente todos os .cpp da pasta Src e subpastas
file(GLOB_RECURSE SOURCES "Src/*.cpp")

# Esta linha diz ao CMake para compilar o projeto com o main.cpp e todos os .cpp encontrados
add_executable(Project main.cpp ${SOURCES})
