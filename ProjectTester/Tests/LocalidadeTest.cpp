#include "../../ProjectTester/googletest/include/gtest/gtest.h"
#include "../../Project/Headers/Model/Localidade.h"

// ============================================================
// Testes ao Construtor
// ============================================================

TEST(LocalidadeConstructorTest, ConstrutorValido) {
    // Criar uma localidade normal nao deve lancar excecao
    EXPECT_NO_THROW(Localidade loc("Porto", 20.0f, 15.0f));
}

TEST(LocalidadeConstructorTest, NomeGuardadoCorretamente) {
    // Arrange
    Localidade loc("Porto", 20.0f, 15.0f);
    // Assert
    EXPECT_EQ(loc.getNome(), "Porto");
}

TEST(LocalidadeConstructorTest, CoordenadasGuardadasCorretamente) {
    // Arrange
    Localidade loc("Porto", 20.0f, 15.0f);
    // Assert
    EXPECT_FLOAT_EQ(loc.getCoordenadaX(), 20.0f);
    EXPECT_FLOAT_EQ(loc.getCoordenadaY(), 15.0f);
}

// ============================================================
// Testes a calcularDistancia
// ============================================================

TEST(LocalidadeCalcularDistancia, MesmoLocalDistanciaZero) {
    // Arrange
    Localidade a("Porto", 20.0f, 15.0f);
    Localidade b("Porto2", 20.0f, 15.0f);
    // Act
    float dist = a.calcularDistancia(b);
    // Assert
    EXPECT_FLOAT_EQ(dist, 0.0f);
}

TEST(LocalidadeCalcularDistancia, DistanciaConhecida) {
    // Arrange  pontos (0,0) e (3,4) -> distancia esperada = 5 (triangulo 3-4-5)
    Localidade a("A", 0.0f, 0.0f);
    Localidade b("B", 3.0f, 4.0f);
    // Act
    float dist = a.calcularDistancia(b);
    // Assert
    EXPECT_NEAR(dist, 5.0f, 0.001f);
}

TEST(LocalidadeCalcularDistancia, DistanciaSimetrica) {
    // A distancia de A para B deve ser igual a de B para A
    // Arrange
    Localidade a("Porto", 20.0f, 15.0f);
    Localidade b("Lisboa", 50.1f, 13.7f);
    // Act
    float distAB = a.calcularDistancia(b);
    float distBA = b.calcularDistancia(a);
    // Assert
    EXPECT_NEAR(distAB, distBA, 0.001f);
}

TEST(LocalidadeCalcularDistancia, DistanciaPositiva) {
    // Arrange
    Localidade a("Braga", 18.5f, 41.5f);
    Localidade b("Faro", 15.6f, 2.3f);
    // Act
    float dist = a.calcularDistancia(b);
    // Assert
    EXPECT_GT(dist, 0.0f);
}

TEST(LocalidadeCalcularDistancia, DistanciaHorizontal) {
    // So muda o X -> distancia = diferenca em X
    // Arrange
    Localidade a("A", 0.0f, 0.0f);
    Localidade b("B", 10.0f, 0.0f);
    // Act
    float dist = a.calcularDistancia(b);
    // Assert
    EXPECT_NEAR(dist, 10.0f, 0.001f);
}

TEST(LocalidadeCalcularDistancia, CoordenadasNegativas) {
    // pontos (-3,-4) e (0,0) -> distancia esperada = 5
    // Arrange
    Localidade a("A", -3.0f, -4.0f);
    Localidade b("B", 0.0f, 0.0f);
    // Act
    float dist = a.calcularDistancia(b);
    // Assert
    EXPECT_NEAR(dist, 5.0f, 0.001f);
}
