// test_utilidades.cpp
#include <gtest/gtest.h>
#include "utilidades.h"
#include <vector>
#include <climits>

using namespace tec_ds;

class UtilidadesTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Limpiar variables estáticas antes de cada test
        Utilidades::n = 0;
        Utilidades::adj_matrix.clear();
        Utilidades::capacity_matrix.clear();
        Utilidades::centrales.clear();
        Utilidades::nueva_casa = {0, 0};
        Utilidades::parent.clear();
        Utilidades::tsp_cost = INT_MAX;
        Utilidades::best_path.clear();
    }
};

TEST_F(UtilidadesTest, TestKruskalMST) {
    // Grafo simple: 4 nodos, 5 aristas
    Utilidades::n = 4;
    Utilidades::adj_matrix = {
        {0, 1, 4, 0},
        {1, 0, 2, 6},
        {4, 2, 0, 3},
        {0, 6, 3, 0}
    };
    
    // Inicializar parent para Kruskal
    Utilidades::parent.resize(Utilidades::n);
    for(int i = 0; i < Utilidades::n; ++i) Utilidades::parent[i] = i;

    Utilidades::kruskal_mst();

    // Para validar MST, puedes verificar que parent tenga un solo conjunto
    int root = Utilidades::find(0);
    for (int i = 1; i < Utilidades::n; ++i) {
        EXPECT_EQ(Utilidades::find(i), root);
    }
}

TEST_F(UtilidadesTest, TestSolveTSP) {
    Utilidades::n = 4;
    Utilidades::adj_matrix = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    
    Utilidades::solve_tsp();

    // Ruta óptima para este caso: costo esperado es 80 (0->1->3->2->0)
    EXPECT_EQ(Utilidades::tsp_cost, 80);
    EXPECT_EQ(Utilidades::best_path.size(), Utilidades::n + 1);
}

TEST_F(UtilidadesTest, TestFordFulkerson) {
    Utilidades::n = 4;
    Utilidades::capacity_matrix = {
        {0, 3, 2, 0},
        {0, 0, 5, 2},
        {0, 0, 0, 3},
        {0, 0, 0, 0}
    };

    int max_flow = Utilidades::ford_fulkerson();

    // Flujo máximo esperado para esta red es 5
    EXPECT_EQ(max_flow, 5);
}

TEST_F(UtilidadesTest, TestCentralMasCercana) {
    Utilidades::centrales = {{0, 0}, {10, 10}, {5, 5}};
    Utilidades::nueva_casa = {6, 6};

    testing::internal::CaptureStdout();
    Utilidades::central_mas_cercana();
    std::string output = testing::internal::GetCapturedStdout();

    // La central más cercana es la de (5,5)
    EXPECT_NE(output.find("(5, 5)"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
