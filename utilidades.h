
/*
 * Tec de Monterrey - Data Structures and Algorithms
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

// Protege el archivo para que no se incluya más de una vez en la compilación.
#ifndef TEC_UTILIDADES_H
#define TEC_UTILIDADES_H

// Incluye la librería para usar std::vector (arreglos dinámicos).
#include <vector>

// Incluye la librería para usar std::pair, estructura que contiene dos valores.
#include <utility>

// Incluye la librería para usar std::queue (cola), usada en BFS.
#include <queue>

// Incluye la librería para usar funciones matemáticas, como sqrt.
#include <cmath>

// Define un espacio de nombres (namespace) para evitar conflictos con otros códigos.
namespace tec_ds {

// Clase que agrupa variables y métodos útiles para manipular grafos y algoritmos específicos.
class Utilidades {
public:
    // Número total de nodos en el grafo, usado para dimensionar matrices y recorrer nodos.
    static int n;

    // Matriz de adyacencia que representa las conexiones entre nodos con sus pesos.
    static std::vector<std::vector<int>> adj_matrix;

    // Matriz que almacena capacidades de las aristas para el algoritmo de flujo máximo.
    static std::vector<std::vector<int>> capacity_matrix;

    // Lista con las coordenadas (x, y) de las centrales eléctricas.
    static std::vector<std::pair<int, int>> centrales;

    // Coordenadas (x, y) de la nueva casa que se analiza para calcular distancias.
    static std::pair<int, int> nueva_casa;

    // Vector que representa a qué conjunto pertenece cada nodo, para estructuras disjuntas.
    static std::vector<int> parent;

    // Valor del costo mínimo encontrado para el problema del viajante (TSP).
    static int tsp_cost;

    // Ruta óptima encontrada para el problema del viajante (TSP).
    static std::vector<int> best_path;

    // ----------- Estructura para representar una arista -----------

    struct Edge {
        int u;      ///< Nodo origen de la arista
        int v;      ///< Nodo destino de la arista
        int weight; ///< Peso o costo asociado a la arista

        // Operador menor para poder ordenar aristas según su peso (útil en Kruskal).
        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }
    };

    // ----------- Métodos para Kruskal -----------

    /**
     * Busca el representante del conjunto donde se encuentra el nodo `u`.
     * Implementa compresión de caminos para optimizar futuras búsquedas.
     * @param u Nodo a consultar.
     * @return Representante del conjunto.
     */
    static int find(int u);

    /**
     * Une los conjuntos que contienen a `u` y `v`.
     * Esto forma parte de la unión de componentes conectados en Kruskal.
     * @param u Nodo 1.
     * @param v Nodo 2.
     */
    static void union_sets(int u, int v);

    /**
     * Ejecuta el algoritmo de Kruskal para construir un árbol de expansión mínima.
     * Imprime las aristas seleccionadas para el árbol.
     */
    static void kruskal_mst();

    // ----------- Métodos para el Problema del Viajante (TSP) -----------

    /**
     * Función recursiva auxiliar para explorar caminos en el TSP usando backtracking.
     * @param path Camino recorrido hasta ahora.
     * @param visited Vector que marca qué nodos ya fueron visitados.
     * @param current_cost Costo acumulado del camino actual.
     */
    static void tsp_util(std::vector<int>& path, std::vector<bool>& visited, int current_cost);

    /**
     * Resuelve el problema del viajante iniciando desde el nodo 0.
     * Al finalizar, imprime el camino óptimo y el costo total.
     */
    static void solve_tsp();

    // ----------- Métodos para Ford-Fulkerson (flujo máximo) -----------

    /**
     * Ejecuta una búsqueda BFS en el grafo residual para encontrar un camino aumentante.
     * @param r_graph Grafo residual representado como matriz.
     * @param parent Vector que guarda el nodo padre de cada nodo en el camino encontrado.
     * @return Flujo mínimo posible en el camino aumentante encontrado (0 si no hay camino).
     */
    static int bfs(const std::vector<std::vector<int>>& r_graph, std::vector<int>& parent);

    /**
     * Ejecuta el algoritmo de Ford-Fulkerson para calcular el flujo máximo entre fuente y sumidero.
     * @return Valor del flujo máximo encontrado.
     */
    static int ford_fulkerson();

    // ----------- Métodos para cálculo de distancias -----------

    /**
     * Calcula la distancia euclidiana entre dos puntos en el plano.
     * @param a Punto A (par de enteros).
     * @param b Punto B (par de enteros).
     * @return Distancia real entre A y B.
     */
    static double dist(const std::pair<int, int>& a, const std::pair<int, int>& b);

    /**
     * Encuentra la central eléctrica más cercana a la nueva casa.
     * Imprime la información de la central más próxima.
     */
    static void central_mas_cercana();

private:
    // Constructor privado para evitar que se creen instancias de esta clase.
    Utilidades() = default;
};

} // namespace tec_ds

#endif // TEC_UTILIDADES_H
