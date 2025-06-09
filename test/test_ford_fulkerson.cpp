#include <iostream>
#include <vector>
#include <cassert>
#include "ford_fulkerson.h"

void test_ford_fulkerson() {
    // Grafo ejemplo: 4 nodos, matriz de capacidades
    // Fuente = 0, Sumidero = 3
    // Capacidades:
    // 0->1: 3, 0->2: 2
    // 1->2: 5, 1->3: 2
    // 2->3: 3
    std::vector<std::vector<int>> capacity = {
        {0, 3, 2, 0},
        {0, 0, 5, 2},
        {0, 0, 0, 3},
        {0, 0, 0, 0}
    };

    int max_flow = ford_fulkerson(capacity);
    std::cout << "Flujo máximo calculado: " << max_flow << std::endl;
    assert(max_flow == 5); // Esperamos flujo máximo = 5
}

int main() {
    test_ford_fulkerson();
    std::cout << "Test passed!" << std::endl;
    return 0;
}
