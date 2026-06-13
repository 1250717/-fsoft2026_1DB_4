cmake_minimum_required(VERSION 3.14)
project(ProjectTester)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

include_directories(${CMAKE_SOURCE_DIR}/../Project/Headers)

set(PROJECT_SOURCES
    ../Project/Src/Model/Localidade.cpp
    ../Project/Src/Model/Carga.cpp
    ../Project/Src/Model/CargaContainer.cpp
    ../Project/Src/Model/Camionista.cpp
    ../Project/Src/Model/CamionistaContainer.cpp
    ../Project/Src/Model/Camiao.cpp
    ../Project/Src/Model/CamiaoContainer.cpp
    ../Project/Src/Model/Rota.cpp
    ../Project/Src/Model/RotaContainer.cpp
    ../Project/Src/Model/LocalidadeContainer.cpp
    ../Project/Src/Model/Empresa.cpp
    ../Project/Src/Repository/GeneralRepository.cpp
    ../Project/Src/Service/GestorService.cpp
    ../Project/Src/Service/CamionistaService.cpp
)

set(TEST_SOURCES
    Tests/CamiaoTest.cpp
    Tests/CamionistaTest.cpp
    Tests/CargaTest.cpp
    Tests/LocalidadeTest.cpp
)

add_executable(ProjectTester ${PROJECT_SOURCES} ${TEST_SOURCES})

target_link_libraries(ProjectTester gtest_main)