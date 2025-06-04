
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

using namespace std;

// ---------- variables_globales ----------

/** Número de nodos en las matrices. */
extern int n;

/** Matriz de adyacencia usada en Kruskal y TSP. */
extern vector<vector<int>> adj_matrix;

/** Matriz de capacidades para Ford-Fulkerson. */
extern vector<vector<int>> capacity_matrix;

/** Coordenadas de las centrales eléctricas. */
extern vector<pair<int, int>> centrales;

/** Coordenadas de la nueva casa. */
extern pair<int, int> nueva_casa;

// ---------- kruskal ----------

/**
 * Estructura para representar una arista con peso para Kruskal.
 */
struct edge {
    int u;      ///< Nodo origen
    int v;      ///< Nodo destino
    int weight; ///< Peso de la arista

    /// Comparador para ordenar aristas por peso
    bool operator<(const edge& other) const {
        return weight < other.weight;
    }
};

/** Vector que representa el conjunto disjunto para Kruskal. */
extern vector<int> parent;

/**
 * Encuentra el representante del conjunto del nodo `u` (con compresión de caminos).
 * @param u Nodo del cual se busca el representante.
 * @return Representante del conjunto de `u`.
 */
int find(int u);

/**
 * Une los conjuntos que contienen los nodos `u` y `v`.
 * @param u Nodo 1.
 * @param v Nodo 2.
 */
void union_sets(int u, int v);

/**
 * Ejecuta el algoritmo de Kruskal para generar el árbol de expansión mínima
 * e imprime las aristas seleccionadas.
 */
void kruskal_mst();

// ---------- tsp ----------

/** Costo mínimo encontrado para el TSP. */
extern int tsp_cost;

/** Ruta óptima encontrada para el TSP. */
extern vector<int> best_path;

/**
 * Función auxiliar recursiva para resolver el TSP mediante backtracking.
 * @param path Camino actual.
 * @param visited Vector de nodos visitados.
 * @param current_cost Costo acumulado hasta el momento.
 */
void tsp_util(vector<int>& path, vector<bool>& visited, int current_cost);

/**
 * Resuelve el problema del viajante (TSP) iniciando desde el nodo 0
 * e imprime el camino óptimo y su costo.
 */
void solve_tsp();

// ---------- ford_fulkerson ----------

/**
 * Ejecuta BFS sobre el grafo residual para encontrar un camino aumentante.
 * @param r_graph Grafo residual.
 * @param parent Vector que almacena los padres en el camino aumentante.
 * @return Flujo encontrado en el camino; 0 si no hay camino aumentante.
 */
int bfs(vector<vector<int>>& r_graph, vector<int>& parent);

/**
 * Implementación del algoritmo de Ford-Fulkerson para encontrar el flujo máximo.
 * @return Flujo máximo desde la fuente hasta el sumidero.
 */
int ford_fulkerson();

// ---------- central_mas_cercana ----------

/**
 * Calcula la distancia euclidiana entre dos puntos.
 * @param a Punto A.
 * @param b Punto B.
 * @return Distancia entre `a` y `b`.
 */
double dist(pair<int, int> a, pair<int, int> b);

/**
 * Encuentra e imprime la central más cercana a la nueva casa.
 */
void central_mas_cercana();

#endif // utilidades_h
