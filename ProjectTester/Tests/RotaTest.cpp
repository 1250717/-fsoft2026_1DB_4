#include "../../ProjectTester/googletest/include/gtest/gtest.h"
#include "../../Project/Headers/Model/Rota.h"
 
 
TEST(RotaConstructorTest, ConstrutorValido) {
    //Arrange
    std::vector<std::string> destinos = {"Lisboa", "Porto"};
    bool flag = true;
    //Act
    try {
        Rota rota(1, "Joao", "AB-12-CD", 150.0f, destinos);
    } catch (std::invalid_argument& e) {
        flag = false;
    }
    //Assert
    EXPECT_TRUE(flag);
}
 
TEST(RotaConstructorTest, AtributosGuardadosCorretamente) {
    //Arrange
    std::vector<std::string> destinos = {"Lisboa"};
    Rota rota(1, "Joao", "AB-12-CD", 150.0f, destinos);
    //Assert
    EXPECT_EQ(rota.getIdRota(), 1);
    EXPECT_EQ(rota.getNomeCamionista(), "Joao");
    EXPECT_EQ(rota.getMatriculaCamiao(), "AB-12-CD");
    EXPECT_FLOAT_EQ(rota.getDistanciaTotal(), 150.0f);
}
 
TEST(RotaConstructorTest, ConstrutorComDestinosVazios) {
    //Arrange
    std::vector<std::string> destinos = {};
    bool flag = true;
    //Act
    try {
        Rota rota(1, "Joao", "AB-12-CD", 0.0f, destinos);
    } catch (std::invalid_argument& e) {
        flag = false;
    }
    //Assert
    EXPECT_TRUE(flag);
}
 
// ============================================================
// Função: getDestinos
// ============================================================
 
TEST(RotaGetDestinosTest, DestinosCorretosVariosDestinos) {
    //Arrange
    std::vector<std::string> destinos = {"Lisboa", "Porto", "Braga"};
    Rota rota(1, "Joao", "AB-12-CD", 150.0f, destinos);
    //Assert
    EXPECT_EQ(rota.getDestinos()[0], "Lisboa");
    EXPECT_EQ(rota.getDestinos()[1], "Porto");
    EXPECT_EQ(rota.getDestinos()[2], "Braga");
}
 