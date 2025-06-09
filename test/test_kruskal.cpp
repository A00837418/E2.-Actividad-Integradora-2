#include <gtest/gtest.h>
#include <vector>
#include <sstream>
#include <iostream>

// Incluimos el archivo con la implementación de Kruskal
#include "kruskal.h"

// Helper para capturar la salida estándar (cout)
class CoutCapture {
public:
    void start() {
        old_buf = std::cout.rdbuf(capture.rdbuf());
    }
    std::string stop() {
        std::cout.rdbuf(old_buf);
        return capture.str();
    }
private:
    std::stringstream capture;
    std::streambuf* old_buf;
};

TEST(KruskalTest, BasicGraph) {
    // Grafo con 4 nodos (A, B, C, D)
    // Matriz de adyacencia simétrica, 0 indica no hay arista
    std::vector<std::vector<int>> adj_matrix = {
        {0, 1, 3, 0},
        {1, 0, 1, 4},
        {3, 1, 0, 2},
        {0, 4, 2, 0}
    };

    // Capturamos la salida de kruskal_mst para comparar
    CoutCapture capture;
    capture.start();
    kruskal_mst(adj_matrix);
    std::string output = capture.stop();

    // La salida esperada (orden puede variar si hay pesos iguales, pero aquí está el esperado)
    std::string expected_output = "\n1. arbol de expansión minima (Kruskal):\n"
                                  "(A, B)\n"
                                  "(B, C)\n"
                                  "(C, D)\n";

    // Verificamos que la salida sea igual a la esperada
    EXPECT_EQ(output, expected_output);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
