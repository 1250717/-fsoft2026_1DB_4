#include "../../ProjectTester/googletest/include/gtest/gtest.h"
#include "../../Project/Headers/Model/Camionista.h"
#include "../../Project/Headers/Model/Camiao.h"

TEST(CamionistaConstructorTest, ConstrutorValido) {
    //Arrange
    bool flag = true;
    //Act
    try {
        Camionista camionista("Joao");
    } catch (std::invalid_argument& e) {
        flag = false;
    }
    //Assert
    EXPECT_TRUE(flag);
}

TEST(CamionistaConstructorTest, EstadoInicialDisponivel) {
    //Arrange
    Camionista camionista("Joao");
    //Assert
    EXPECT_EQ(camionista.getEstado(), "Disponivel");
}

TEST(CamionistaValidarNomeTest, NomeValido) {
    //Arrange
    bool flag = true;
    //Act
    try {
        Camionista::validarNome("Joao");
    } catch (std::invalid_argument& e) {
        flag = false;
    }
    //Assert
    EXPECT_TRUE(flag);
}

TEST(CamionistaVerificarDisponivel, SemCamiaoNaoLancaExcecao) {
    //Arrange
    Camionista camionista("Joao");
    bool flag = true;
    //Act
    try {
        camionista.verificarDisponivel();
    } catch (std::invalid_argument& e) {
        flag = false;
    }
    //Assert
    EXPECT_TRUE(flag);
}

TEST(CamionistaVerificarDisponivel, ComCamiaoLancaExcecao) {
    //Arrange
    Camionista camionista("Joao");
    Camiao camiao("AB-12-CD", 500.0f);
    camionista.setCamiao(&camiao);
    bool flag = false;
    //Act
    try {
        camionista.verificarDisponivel();
    } catch (std::invalid_argument& e) {
        flag = true;
    }
    //Assert
    EXPECT_TRUE(flag);
}

TEST(CamionistaSettersTest, SetEstadoAtualizado) {
    //Arrange
    Camionista camionista("Joao");
    //Act
    camionista.setEstado("Atribuido");
    //Assert
    EXPECT_EQ(camionista.getEstado(), "Atribuido");
}

TEST(CamionistaSettersTest, SetCamiaoAtualizado) {
    //Arrange
    Camionista camionista("Joao");
    Camiao camiao("AB-12-CD", 500.0f);
    //Act
    camionista.setCamiao(&camiao);
    //Assert
    EXPECT_EQ(camionista.getCamiao(), &camiao);
}