#include <gtest/gtest.h>
#include "utilidades.h"

// Test 1: Kruskal debe generar 3 aristas (n=4 -> n-1)
TEST(KruskalTest, AristasCorrectas) {
    // Capturamos la salida estándar
    testing::internal::CaptureStdout();
    kruskal_mst();
    std::string output = testing::internal::GetCapturedStdout();
    // Contamos las líneas con paréntesis, deben ser exactamente 3
    int count = 0;
    for (char c : output) if (c == '(') ++count;
    EXPECT_EQ(count, 3);
}

// Test 2: TSP debe encontrar camino A–B–D–C–A con costo mínimo
TEST(TSPTest, CostoCorrectoYRecorrido) {
    testing::internal::CaptureStdout();
    solve_tsp();
    std::string output = testing::internal::GetCapturedStdout();
    // Revisamos que se imprima “costo minimo: 66”
    EXPECT_NE(output.find("costo minimo: 66"), std::string::npos);
    // Revisamos que el tipo de camino empiece en A
    EXPECT_NE(output.find("A "), std::string::npos);
}

// Test 3: Ford-Fulkerson debe devolver flujo máximo 60
TEST(FordFulkersonTest, FlujoMaximoCorrecto) {
    testing::internal::CaptureStdout();
    // Ejecutamos opción 3 directamente
    std::cout << "\n3. Flujo maximo (Ford-Fulkerson):\n";
    std::cout << "Flujo maximo: " << ford_fulkerson() << "\n";
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Flujo maximo: 60"), std::string::npos);
}

// Test 4: Central más cercana a casa (400,300) debe ser (450,150)
TEST(CentralMasCercanaTest, CoordenadasYDistancia) {
    testing::internal::CaptureStdout();
    central_mas_cercana();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("(450, 150)"), std::string::npos);
    // La distancia aproximada es sqrt((50)^2 + (150)^2) = ~158.11388
    EXPECT_NE(output.find("distancia: 158.113"), std::string::npos);
}

// main de pruebas
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
