#include <gtest/gtest.h>
#include <vector>
#include <sstream>
#include <iostream>
#include "tsp.h"  // incluye tu header original sin modificaciones

// Clase auxiliar para capturar la salida estándar (std::cout)
class CoutRedirect {
public:
    CoutRedirect(std::streambuf* new_buffer) : old(std::cout.rdbuf(new_buffer)) {}
    ~CoutRedirect() { std::cout.rdbuf(old); }
private:
    std::streambuf* old;
};

TEST(TSPTest, SmallGraphTest) {
    std::vector<std::vector<int>> adj_matrix = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    std::stringstream buffer;
    CoutRedirect redirect(buffer.rdbuf());  // redirige cout a buffer

    solve_tsp(adj_matrix);

    std::string output = buffer.str();

    // Verifica que se imprimen todas las ciudades y el costo mínimo esperado
    EXPECT_NE(output.find("A"), std::string::npos);
    EXPECT_NE(output.find("B"), std::string::npos);
    EXPECT_NE(output.find("C"), std::string::npos);
    EXPECT_NE(output.find("D"), std::string::npos);
    EXPECT_NE(output.find("costo minimo: 80"), std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
