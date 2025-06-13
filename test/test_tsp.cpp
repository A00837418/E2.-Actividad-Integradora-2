#include <gtest/gtest.h>
#include <vector>
#include <climits>
#include <sstream>
#include <iostream>
#include "tsp.h"  // Asegúrate que esta ruta sea correcta

// Helper para capturar salida estándar (cout)
class CoutRedirect {
public:
    CoutRedirect(std::streambuf* new_buffer) : old(std::cout.rdbuf(new_buffer)) {}
    ~CoutRedirect() { std::cout.rdbuf(old); }
private:
    std::streambuf* old;
};

TEST(TSPTest, SmallGraphTest) {
    // Matriz de adyacencia simple (4 nodos)
    std::vector<std::vector<int>> adj_matrix = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Capturamos la salida estándar
    std::stringstream buffer;
    CoutRedirect redirect(buffer.rdbuf());

    // Ejecutar la función
    solve_tsp(adj_matrix);

    std::string output = buffer.str();

    // Verificar que contenga el camino esperado y el costo mínimo
    // El camino esperado más corto puede ser: A B D C A o equivalente
    // Costo mínimo esperado para esta matriz es 80
    EXPECT_NE(output.find("A"), std::string::npos);
    EXPECT_NE(output.find("B"), std::string::npos);
    EXPECT_NE(output.find("C"), std::string::npos);
    EXPECT_NE(output.find("D"), std::string::npos);
    EXPECT_NE(output.find("costo minimo: 80"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
