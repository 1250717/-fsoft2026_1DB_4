#include "../../ProjectTester/googletest/include/gtest/gtest.h"
#include "../../Project/Headers/Model/Camiao.h"
#include "../../Project/Headers/Model/Camionista.h"
#include "../../Project/Headers/Model/Carga.h"
#include "../../Project/Headers/Model/Localidade.h"

TEST(CamiaoConstructorTest, ConstrutorValido) {
    //Arrange
    bool flag = true;
    //Act
    try {
        Camiao camiao("AB-12-CD", 500.0f);
    } catch (std::invalid_argument& e) {
        flag = false;
    }
    //Assert
    EXPECT_TRUE(flag);
}

TEST(CamiaoValidarMatriculaTest, MatriculaFormatoValido) {
    //Arrange
    bool flag = true;
    //Act
    try {
        Camiao::validarMatricula("AB-12-CD");
    } catch (std::invalid_argument& e) {
        flag = false;
    }
    //Assert
    EXPECT_TRUE(flag);
}

TEST(CamiaoValidarCapacidadeTest, CapacidadeMinima) {
    //Arrange
    bool flag = true;
    //Act
    try {
        Camiao::validarCapacidade(100.0f);
    } catch (std::invalid_argument& e) {
        flag = false;
    }
    //Assert
    EXPECT_TRUE(flag);
}

TEST(CamiaoValidarCapacidadeTest, CapacidadeMaxima) {
    //Arrange
    bool flag = true;
    //Act
    try {
        Camiao::validarCapacidade(10000.0f);
    } catch (std::invalid_argument& e) {
        flag = false;
    }
    //Assert
    EXPECT_TRUE(flag);
}

TEST(CamiaoGestaoCargas, AdicionarCargaAumentaLista) {
    //Arrange
    Camiao camiao("AB-12-CD", 500.0f);
    Localidade loc("Porto", 20.0f, 15.0f);
    Carga carga(50.0f, &loc);
    //Act
    camiao.adicionarCarga(&carga);
    //Assert
    EXPECT_EQ(camiao.getCargas().size(), 1u);
}

TEST(CamiaoGestaoCargas, RemoverCargaDecrementaLista) {
    //Arrange
    Camiao camiao("AB-12-CD", 500.0f);
    Localidade loc("Porto", 20.0f, 15.0f);
    Carga carga(50.0f, &loc);
    camiao.adicionarCarga(&carga);
    //Act
    camiao.removerCarga(&carga);
    //Assert
    EXPECT_EQ(camiao.getCargas().size(), 0u);
}

TEST(CamiaoSettersTest, SetEstadoAtualizado) {
    //Arrange
    Camiao camiao("AB-12-CD", 500.0f);
    //Act
    camiao.setEstado("Atribuido");
    //Assert
    EXPECT_EQ(camiao.getEstado(), "Atribuido");
}
 
TEST(CamiaoSettersTest, SetCapacidadeDisponivelAtualizado) {
    //Arrange
    Camiao camiao("AB-12-CD", 500.0f);
    //Act
    camiao.setCapacidadeDisponivel(300.0f);
    //Assert
    EXPECT_FLOAT_EQ(camiao.getCapacidadeDisponivel(), 300.0f);
}