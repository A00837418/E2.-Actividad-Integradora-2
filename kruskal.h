
/*
 * Tec de Monterrey - Data Structures and Algorithms
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
 
#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @struct Edge
 * @brief Representa una arista en un grafo con dos nodos y un peso.
 */
struct Edge {
    int u;       ///< Nodo de origen
    int v;       ///< Nodo de destino
    int weight;  ///< Peso de la arista

    /**
     * @brief Sobrecarga del operador < para ordenar las aristas por peso.
     */
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

/**
 * @brief Encuentra la raíz del conjunto al que pertenece el nodo 'u' usando búsqueda con compresión de caminos.
 * 
 * @param u Nodo del cual se quiere conocer la raíz.
 * @param parent Vector que representa los padres de cada nodo en la estructura de conjuntos disjuntos.
 * @return int Raíz del conjunto al que pertenece 'u'.
 */
int find(int u, vector<int>& parent) {
    if (parent[u] != u)
        parent[u] = find(parent[u], parent);
    return parent[u];
}

/**
 * @brief Une los conjuntos disjuntos que contienen a los nodos 'u' y 'v'.
 * 
 * @param u Primer nodo.
 * @param v Segundo nodo.
 * @param parent Vector que representa los padres de cada nodo en la estructura de conjuntos disjuntos.
 */
void union_sets(int u, int v, vector<int>& parent) {
    parent[find(u, parent)] = find(v, parent);
}

/**
 * @brief Algoritmo de Kruskal para calcular el Árbol de Expansión Mínima (MST).
 * 
 * Dado un grafo representado por una matriz de adyacencia, calcula e imprime las aristas del MST.
 * 
 * @param adj_matrix Matriz de adyacencia que representa el grafo.
 */
void kruskal_mst(const vector<vector<int>>& adj_matrix) {
    int n = adj_matrix.size();
    vector<Edge> edges;
    vector<int> parent(n);

    // Generar lista de aristas válidas
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (adj_matrix[i][j] > 0)
                edges.push_back({i, j, adj_matrix[i][j]});

    sort(edges.begin(), edges.end());
    for (int i = 0; i < n; ++i) parent[i] = i;

    cout << "\n1. arbol de expansión minima (Kruskal):\n";
    for (const Edge& e : edges) {
        if (find(e.u, parent) != find(e.v, parent)) {
            union_sets(e.u, e.v, parent);
            cout << "(" << char('A' + e.u) << ", " << char('A' + e.v) << ")\n";
        }
    }
}

#endif // KRUSKAL_H
