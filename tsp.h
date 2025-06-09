/*
 * Tec de Monterrey - Data Structures and Algorithms
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef TSP_H
#define TSP_H

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/**
 * @brief Función auxiliar recursiva para resolver el problema del viajante (TSP) usando backtracking.
 * 
 * Esta función intenta construir todas las permutaciones posibles del recorrido y mantiene
 * el de menor costo. Utiliza una matriz de adyacencia para calcular los costos entre nodos.
 * 
 * @param adj_matrix Matriz de adyacencia que representa los costos entre ciudades.
 * @param path Camino actual construido.
 * @param visited Vector que indica qué nodos ya han sido visitados.
 * @param current_cost Costo acumulado del recorrido actual.
 * @param tsp_cost Referencia al costo mínimo encontrado hasta el momento.
 * @param best_path Referencia al camino que produce el costo mínimo.
 */
void tsp_util(const vector<vector<int>>& adj_matrix, vector<int>& path, vector<bool>& visited,
              int current_cost, int& tsp_cost, vector<int>& best_path) {
    int n = adj_matrix.size();
    if (path.size() == n) {
        current_cost += adj_matrix[path.back()][path[0]];  // Cerrar el ciclo
        if (current_cost < tsp_cost) {
            tsp_cost = current_cost;
            best_path = path;
        }
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            path.push_back(i);
            tsp_util(adj_matrix, path, visited, current_cost + adj_matrix[path[path.size() - 2]][i], tsp_cost, best_path);
            path.pop_back();
            visited[i] = false;
        }
    }
}

/**
 * @brief Función principal para resolver el problema del viajante (TSP).
 * 
 * Inicia el recorrido desde el nodo 0 y encuentra el camino mínimo que pasa por
 * todos los nodos y regresa al origen. Imprime el camino más corto y su costo.
 * 
 * @param adj_matrix Matriz de adyacencia que representa los costos entre ciudades.
 */
void solve_tsp(const vector<vector<int>>& adj_matrix) {
    int n = adj_matrix.size();
    vector<bool> visited(n, false);
    vector<int> path;
    vector<int> best_path;
    int tsp_cost = INT_MAX;

    path.push_back(0);        // Comenzar desde la ciudad 0
    visited[0] = true;
    tsp_util(adj_matrix, path, visited, 0, tsp_cost, best_path);

    cout << "\n2. recorrido mas corto (TSP):\n";
    for (int v : best_path)
        cout << char('A' + v) << " ";
    if (!best_path.empty())
        cout << char('A' + best_path[0]) << "\n";  // Volver a la ciudad de origen
    cout << "costo minimo: " << tsp_cost << "\n";
}

#endif // TSP_H
