#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

// Incluye tu header con la implementación
#include "utilidades.h"

// Test para la función find
TEST(DisjointSetTest, FindRoot) {
    std::vector<int> parent = {0, 1, 2, 3};
    // Unión simple: 0 y 1 se unen
    union_sets(0, 1, parent);
    EXPECT_EQ(find(0, parent), find(1, parent));
    // Los demás nodos siguen raíces propias
    EXPECT_EQ(find(2, parent), 2);
    EXPECT_EQ(find(3, parent), 3);
}

// Test para union_sets
TEST(DisjointSetTest, UnionSets) {
    std::vector<int> parent = {0, 1, 2, 3};
    union_sets(0, 2, parent);
    union_sets(1, 3, parent);
    EXPECT_EQ(find(0, parent), find(2, parent));
    EXPECT_EQ(find(1, parent), find(3, parent));
    EXPECT_NE(find(0, parent), find(1, parent));
}

// Test para kruskal_mst
TEST(KruskalTest, MSTOutputTest) {
    std::vector<std::vector<int>> adj = {
        {0, 1, 3, 0},
        {1, 0, 1, 6},
        {3, 1, 0, 4},
        {0, 6, 4, 0}
    };

    // Captura la salida estándar
    testing::internal::CaptureStdout();
    kruskal_mst(adj);
    std::string output = testing::internal::GetCapturedStdout();

    // Mostrar salida para depuración si falla
    std::cout << "Salida kruskal_mst:\n" << output << std::endl;

    // Cuenta líneas y valida que haya 3 aristas impresas
    int lineCount = std::count(output.begin(), output.end(), '\n');
    EXPECT_EQ(lineCount - 1, 3) << "El número de aristas impresas no es correcto";

    // Validar que las aristas del MST están en la salida
    EXPECT_PRED_FORMAT2([](const char* expr1, const char* expr2, const std::string& o, const char*) {
        return o.find("(A, B)") != std::string::npos ? testing::AssertionSuccess() : testing::AssertionFailure() << "No se encontró la arista (A, B)";
    }, "", "", output, "");

    EXPECT_PRED_FORMAT2([](const char* expr1, const char* expr2, const std::string& o, const char*) {
        return o.find("(B, C)") != std::string::npos ? testing::AssertionSuccess() : testing::AssertionFailure() << "No se encontró la arista (B, C)";
    }, "", "", output, "");

    EXPECT_PRED_FORMAT2([](const char* expr1, const char* expr2, const std::string& o, const char*) {
        return o.find("(C, D)") != std::string::npos ? testing::AssertionSuccess() : testing::AssertionFailure() << "No se encontró la arista (C, D)";
    }, "", "", output, "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
