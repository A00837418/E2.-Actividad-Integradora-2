#include <gtest/gtest.h>
#include <vector>
#include <climits>
#include <sstream>
#include <iostream>
#include "tsp.h"  // Asegúrate de que esta ruta y solve_tsp() existan

// Helper para redirigir cout a un buffer
class CoutRedirect {
public:
    CoutRedirect(std::streambuf* new_buffer) : old(std::cout.rdbuf(new_buffer)) {}
    ~CoutRedirect() { std::cout.rdbuf(old); }
private:
    std::streambuf* old;
};

// =======================
// TEST 1: TinyGraphTest (3 nodos)
// =======================
TEST(TSPTest, TinyGraphTest) {
    std::vector<std::vector<int>> adj_matrix = {
        {0, 8, 15},  // A
        {8, 0, 10},  // B
        {15, 10, 0}  // C
    };

    std::stringstream buffer;
    CoutRedirect redirect(buffer.rdbuf());

    solve_tsp(adj_matrix);
    std::string output = buffer.str();

    EXPECT_NE(output.find("A"), std::string::npos);
    EXPECT_NE(output.find("B"), std::string::npos);
    EXPECT_NE(output.find("C"), std::string::npos);
    EXPECT_NE(output.find("costo minimo: 33"), std::string::npos);  // Ruta A-B-C-A
}

// =======================
// TEST 2: SmallGraphTest (4 nodos)
// =======================
TEST(TSPTest, SmallGraphTest) {
    std::vector<std::vector<int>> adj_matrix = {
        {0, 10, 15, 20},   // A
        {10, 0, 35, 25},   // B
        {15, 35, 0, 30},   // C
        {20, 25, 30, 0}    // D
    };

    std::stringstream buffer;
    CoutRedirect redirect(buffer.rdbuf());

    solve_tsp(adj_matrix);
    std::string output = buffer.str();

    EXPECT_NE(output.find("A"), std::string::npos);
    EXPECT_NE(output.find("B"), std::string::npos);
    EXPECT_NE(output.find("C"), std::string::npos);
    EXPECT_NE(output.find("D"), std::string::npos);
    EXPECT_NE(output.find("costo minimo: 80"), std::string::npos);
}

// =======================
// TEST 3: MediumGraphTest (5 nodos)
// =======================
TEST(TSPTest, MediumGraphTest) {
    std::vector<std::vector<int>> adj_matrix = {
        {0, 14, 10, 20, 30},   // A
        {14, 0, 18, 22, 16},   // B
        {10, 18, 0, 12, 24},   // C
        {20, 22, 12, 0, 26},   // D
        {30, 16, 24, 26, 0}    // E
    };

    std::stringstream buffer;
    CoutRedirect redirect(buffer.rdbuf());

    solve_tsp(adj_matrix);
    std::string output = buffer.str();

    EXPECT_NE(output.find("A"), std::string::npos);
    EXPECT_NE(output.find("B"), std::string::npos);
    EXPECT_NE(output.find("C"), std::string::npos);
    EXPECT_NE(output.find("D"), std::string::npos);
    EXPECT_NE(output.find("E"), std::string::npos);
    EXPECT_NE(output.find("costo minimo: 72"), std::string::npos);  // Ajusta si cambia la lógica
}

// =======================
// MAIN
// =======================
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
