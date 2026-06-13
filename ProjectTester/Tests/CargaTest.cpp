#include "../../ProjectTester/googletest/include/gtest/gtest.h"
#include "../../Project/Headers/Model/Carga.h"


// ============================================================
// Testes ao Construtor
// ============================================================

TEST(CargaConstructorTest, ConstrutorValido) {
    // Arrange
    Localidade loc("Porto", 20.0f, 15.0f);
    // Act + Assert: criar uma carga com peso valido nao deve lancar excecao
    EXPECT_NO_THROW(Carga carga(50.0f, &loc));
}

TEST(CargaConstructorTest, EstadoInicialDisponivel) {
    // Arrange
    Localidade loc("Porto", 20.0f, 15.0f);
    Carga carga(50.0f, &loc);
    // Assert
    EXPECT_EQ(carga.getEstado(), "Disponivel");
}

TEST(CargaConstructorTest, PesoGuardadoCorretamente) {
    // Arrange
    Localidade loc("Porto", 20.0f, 15.0f);
    Carga carga(75.5f, &loc);
    // Assert
    EXPECT_FLOAT_EQ(carga.getPeso(), 75.5f);
}

TEST(CargaConstructorTest, DestinoGuardadoCorretamente) {
    // Arrange
    Localidade loc("Lisboa", 50.1f, 13.7f);
    Carga carga(50.0f, &loc);
    // Assert
    EXPECT_EQ(carga.getDestino()->getNome(), "Lisboa");
}

TEST(CargaConstructorTest, ConstrutorComPesoInvalidoLancaExcecao) {
    // Arrange
    Localidade loc("Porto", 20.0f, 15.0f);
    // Act + Assert: o construtor chama verificarPeso, logo peso invalido lanca
    EXPECT_THROW(Carga carga(2.0f, &loc), std::invalid_argument);
}

// ============================================================
// Testes a verificarPeso (limites: 5 kg a 200 kg)
// ============================================================

TEST(CargaVerificarPesoTest, PesoMinimoValido) {
    // 5 e o limite minimo aceite
    EXPECT_NO_THROW(Carga::verificarPeso(5.0f));
}

TEST(CargaVerificarPesoTest, PesoMaximoValido) {
    // 200 e o limite maximo aceite
    EXPECT_NO_THROW(Carga::verificarPeso(200.0f));
}

TEST(CargaVerificarPesoTest, PesoNormalNoMeio) {
    // Um valor normal dentro do intervalo
    EXPECT_NO_THROW(Carga::verificarPeso(100.0f));
}

TEST(CargaVerificarPesoTest, PesoAbaixoDoMinimo) {
    // 4.9 esta abaixo de 5 -> deve lancar
    EXPECT_THROW(Carga::verificarPeso(4.9f), std::invalid_argument);
}

TEST(CargaVerificarPesoTest, PesoAcimaDoMaximo) {
    // 200.1 esta acima de 200 -> deve lancar
    EXPECT_THROW(Carga::verificarPeso(200.1f), std::invalid_argument);
}

TEST(CargaVerificarPesoTest, PesoNegativo) {
    EXPECT_THROW(Carga::verificarPeso(-10.0f), std::invalid_argument);
}

TEST(CargaVerificarPesoTest, PesoZero) {
    EXPECT_THROW(Carga::verificarPeso(0.0f), std::invalid_argument);
}

// ============================================================
// Testes a setEstado / getEstado
// ============================================================

TEST(CargaSettersTest, SetEstadoAtribuida) {
    // Arrange
    Localidade loc("Porto", 20.0f, 15.0f);
    Carga carga(50.0f, &loc);
    // Act
    carga.setEstado("Atribuida");
    // Assert
    EXPECT_EQ(carga.getEstado(), "Atribuida");
}

TEST(CargaSettersTest, SetEstadoEntregue) {
    // Arrange
    Localidade loc("Porto", 20.0f, 15.0f);
    Carga carga(50.0f, &loc);
    // Act
    carga.setEstado("Entregue");
    // Assert
    EXPECT_EQ(carga.getEstado(), "Entregue");
}
