
/*
 * Tec de Monterrey - Data Structures and Algorithms
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef utilidades_h
#define utilidades_h

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <climits>
#include <queue>

/**
 * @file utilidades.h
 * @brief Funciones y estructuras auxiliares para algoritmos de grafos como Kruskal, TSP y Ford-Fulkerson.
 */

/// Namespace del proyecto
namespace tec_ds {

/**
 * @class Utilidades
 * @brief Contenedor estático de estructuras, variables y métodos auxiliares.
 */
class Utilidades {
public:
    // ---------- Variables globales ----------

    /** 
     * @brief Número de nodos en las matrices de grafos.
     */
    static inline int n = 0;

    /**
     * @brief Matriz de adyacencia usada en Kruskal y TSP.
     */
    static inline std::vector<std::vector<int>> adj_matrix;

    /**
     * @brief Matriz de capacidades utilizada en Ford-Fulkerson.
     */
    static inline std::vector<std::vector<int>> capacity_matrix;

    /**
     * @brief Coordenadas de las centrales eléctricas.
     */
    static inline std::vector<std::pair<int, int>> centrales;

    /**
     * @brief Coordenadas de la nueva casa a conectar.
     */
    static inline std::pair<int, int> nueva_casa;

    /**
     * @brief Vector para representar conjuntos disjuntos en Kruskal.
     */
    static inline std::vector<int> parent;

    // ---------- kruskal ----------

    /**
     * @struct Edge
     * @brief Representa una arista con peso para el algoritmo de Kruskal.
     */
    struct Edge {
        int u;      ///< Nodo origen
        int v;      ///< Nodo destino
        int weight; ///< Peso de la arista

        /**
         * @brief Operador para ordenar aristas por peso.
         * @param other Otra arista a comparar.
         * @return `true` si esta arista tiene menor peso que la otra.
         */
        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }
    };

    /**
     * @brief Encuentra el representante del conjunto del nodo `u` (compresión de caminos).
     * @param u Nodo cuyo conjunto se busca.
     * @return Representante del conjunto.
     */
    static int find(int u);

    /**
     * @brief Une los conjuntos disjuntos que contienen `u` y `v`.
     * @param u Nodo 1.
     * @param v Nodo 2.
     */
    static void union_sets(int u, int v);

    /**
     * @brief Ejecuta el algoritmo de Kruskal para generar el árbol de expansión mínima.
     */
    static void kruskal_mst();

    // ---------- tsp ----------

    /**
     * @brief Costo mínimo encontrado por el algoritmo TSP.
     */
    static inline int tsp_cost = INT_MAX;

    /**
     * @brief Ruta óptima calculada por el algoritmo TSP.
     */
    static inline std::vector<int> best_path;

    /**
     * @brief Función recursiva auxiliar para resolver el TSP con backtracking.
     * @param path Camino actual.
     * @param visited Vector de nodos visitados.
     * @param current_cost Costo acumulado hasta el momento.
     */
    static void tsp_util(std::vector<int>& path, std::vector<bool>& visited, int current_cost);

    /**
     * @brief Resuelve el problema del viajante (TSP) e imprime el camino óptimo y su costo.
     */
    static void solve_tsp();

    // ---------- ford_fulkerson ----------

    /**
     * @brief Ejecuta BFS sobre el grafo residual para encontrar un camino aumentante.
     * @param r_graph Grafo residual.
     * @param parent Vector que almacena los padres en el camino aumentante.
     * @return Flujo encontrado en el camino; 0 si no hay.
     */
    static int bfs(std::vector<std::vector<int>>& r_graph, std::vector<int>& parent);

    /**
     * @brief*
