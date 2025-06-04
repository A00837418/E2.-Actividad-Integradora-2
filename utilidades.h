
/*
 * Tec de Monterrey - Data Structures and Algorithms
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef TEC_UTILIDADES_H
#define TEC_UTILIDADES_H

#include <vector>
#include <utility>  // para std::pair
#include <queue>
#include <cmath>

namespace tec_ds {

// ---------- variables_globales encapsuladas ----------

/**
 * Clase que encapsula las variables globales y métodos relacionados
 * a grafos y algoritmos (Kruskal, TSP, Ford-Fulkerson).
 */
 // \brief Clase Utilidades
class Utilidades { 
public:
    // Número de nodos en las matrices.
    // \brief Número de nodos
    static int n;

    // Matriz de adyacencia usada en Kruskal y TSP.
    // \brief Matriz de adyacencia
    static std::vector<std::vector<int>> adj_matrix;

    // Matriz de capacidades para Ford-Fulkerson.
    // \brief Matriz de capacidades
    static std::vector<std::vector<int>> capacity_matrix;

    // Coordenadas de las centrales eléctricas.
    // \brief Coordenadas de las centrales eléctricas
    static std::vector<std::pair<int, int>> centrales;

    // Coordenadas de la nueva casa.
    // \brief Coordenadas de la nueva casa
    static std::pair<int, int> nueva_casa;

    // Vector que representa el conjunto disjunto para Kruskal.
    // \brief Vector de padres para Kruskal
    // Este vector se usa para almacenar el padre de cada nodo en el algoritmo de Kruskal.
    static std::vector<int> parent;

    // Costo mínimo encontrado para el TSP.
    // \brief Costo mínimo del TSP
    // Este valor se actualiza durante la ejecución del algoritmo TSP.
    static int tsp_cost;

    // Ruta óptima encontrada para el TSP.
    // \brief Ruta óptima del TSP
    // Este vector almacena el camino óptimo encontrado por el algoritmo TSP.
    static std::vector<int> best_path;

    // ---------- Kruskal ----------

    struct Edge {
        int u;      ///< Nodo origen
        int v;      ///< Nodo destino
        int weight; ///< Peso de la arista

        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }
    };

    /**
     * Encuentra el representante del conjunto del nodo `u` (con compresión de caminos).
     * @param u Nodo del cual se busca el representante.
     * @return Representante del conjunto de `u`.
     */
    static int find(int u);

    /**
     * Une los conjuntos que contienen los nodos `u` y `v`.
     * @param u Nodo 1.
     * @param v Nodo 2.
     */
    static void union_sets(int u, int v);

    /**
     * Ejecuta el algoritmo de Kruskal para generar el árbol de expansión mínima
     * e imprime las aristas seleccionadas.
     */
    static void kruskal_mst();

    // ---------- TSP ----------

    /**
     * Función auxiliar recursiva para resolver el TSP mediante backtracking.
     * @param path Camino actual.
     * @param visited Vector de nodos visitados.
     * @param current_cost Costo acumulado hasta el momento.
     */
    static void tsp_util(std::vector<int>& path, std::vector<bool>& visited, int current_cost);

    /**
     * Resuelve el problema del viajante (TSP) iniciando desde el nodo 0
     * e imprime el camino óptimo y su costo.
     */
    static void solve_tsp();

    // ---------- Ford-Fulkerson ----------

    /**
     * Ejecuta BFS sobre el grafo residual para encontrar un camino aumentante.
     * @param r_graph Grafo residual.
     * @param parent Vector que almacena los padres en el camino aumentante.
     * @return Flujo encontrado en el camino; 0 si no hay camino aumentante.
     */
    static int bfs(const std::vector<std::vector<int>>& r_graph, std::vector<int>& parent);

    /**
     * Implementación del algoritmo de Ford-Fulkerson para encontrar el flujo máximo.
     * @return Flujo máximo desde la fuente hasta el sumidero.
     */
    static int ford_fulkerson();

    // ---------- Central más cercana ----------

    /**
     * Calcula la distancia euclidiana entre dos puntos.
     * @param a Punto A.
     * @param b Punto B.
     * @return Distancia entre `a` y `b`.
     */
    static double dist(const std::pair<int, int>& a, const std::pair<int, int>& b);

    /**
     * Encuentra e imprime la central más cercana a la nueva casa.
     */
    static void central_mas_cercana();

private:
    // Constructor privado para evitar instanciación
    Utilidades() = default;
};

} // namespace tec_ds

#endif // TEC_UTILIDADES_H
