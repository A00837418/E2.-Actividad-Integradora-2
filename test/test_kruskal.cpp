#include <gtest/gtest.h>
#include <sstream>
#include "kruskal.h"

// Test para verificar la comparación de aristas por peso
TEST(EdgeTest, CompareEdgesByWeight) {
    Edge a{0, 1, 4};
    Edge b{1, 2, 7};
    EXPECT_TRUE(a < b);
    EXPECT_FALSE(b < a);
}

// Test para verificar la operación find con compresión de caminos
TEST(DisjointSetTest, FindWithCompression) {
    vector<int> parent = {0, 1, 2, 3};
    union_sets(1, 2, parent);
    union_sets(2, 3, parent);
    int root = find(1, parent);
    EXPECT_EQ(root, find(3, parent));
    EXPECT_EQ(parent[1], root); // Confirmar compresión
}

// Test para verificar la unión de conjuntos disjuntos
TEST(DisjointSetTest, UnionSetsCorrectly) {
    vector<int> parent = {0, 1, 2};
    union_sets(0, 1, parent);
    EXPECT_EQ(find(0, parent), find(1, parent));
}

// Test para verificar que Kruskal imprime el MST esperado
TEST(KruskalTest, MSTOutputTest) {
    vector<vector<int>> adj = {
        {0, 1, 3, 0},
        {1, 0, 1, 6},
        {3, 1, 0, 4},
        {0, 6, 4, 0}
    };

    testing::internal::CaptureStdout();
    kruskal_mst(adj);
    string output = testing::internal::GetCapturedStdout();

    // Esperamos 3 aristas para un grafo de 4 nodos (n-1)
    int count = 0;
    for (char c : output) if (c == '\n') count++;
    EXPECT_EQ(count - 1, 3); // -1 por el encabezado impreso

    // Verifica que algunas aristas específicas estén en la salida
    EXPECT_NE(output.find("(A, B)"), string::npos);
    EXPECT_NE(output.find("(B, C)"), string::npos);
    EXPECT_NE(output.find("(C, D)"), string::npos);
}
