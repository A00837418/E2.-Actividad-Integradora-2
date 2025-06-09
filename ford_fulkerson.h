
/*
 * Tec de Monterrey - Data Structures and Algorithms
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

/**
 * @brief Algoritmo BFS para encontrar un camino aumentante en el grafo residual.
 * 
 * Este BFS busca un camino desde el nodo fuente (0) hasta el nodo sumidero (n-1) 
 * en el grafo residual. Si encuentra un camino, devuelve el flujo mínimo a lo largo 
 * de ese camino y actualiza el vector `parent` para poder reconstruirlo.
 * 
 * @param r_graph Matriz de adyacencia del grafo residual.
 * @param parent Vector para almacenar el camino encontrado.
 * @return int Flujo mínimo a lo largo del camino encontrado. Devuelve 0 si no hay camino.
 */
int bfs(const vector<vector<int>>& r_graph, vector<int>& parent) {
    int n = r_graph.size();
    fill(parent.begin(), parent.end(), -1);
    queue<pair<int, int>> q;
    q.push({0, INT_MAX});
    parent[0] = -2;

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next = 0; next < n; ++next) {
            if (parent[next] == -1 && r_graph[cur][next] > 0) {
                parent[next] = cur;
                int new_flow = min(flow, r_graph[cur][next]);
                if (next == n - 1)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

/**
 * @brief Implementación del algoritmo de Ford-Fulkerson para hallar el flujo máximo.
 * 
 * A partir de una matriz de capacidades, este algoritmo encuentra el flujo máximo 
 * posible entre el nodo fuente (0) y el nodo sumidero (n-1) utilizando el método 
 * de caminos aumentantes con BFS.
 * 
 * @param capacity_matrix Matriz de capacidades del grafo original.
 * @return int Valor del flujo máximo desde la fuente hasta el sumidero.
 */
int ford_fulkerson(vector<vector<int>> capacity_matrix) {
    int n = capacity_matrix.size();
    vector<vector<int>> r_graph = capacity_matrix;
    vector<int> parent(n);
    int max_flow = 0, flow;

    while ((flow = bfs(r_graph, parent)) != 0) {
        max_flow += flow;
        int cur = n - 1;
        while (cur != 0) {
            int prev = parent[cur];
            r_graph[prev][cur] -= flow;
            r_graph[cur][prev] += flow;
            cur = prev;
        }
    }
    return max_flow;
}

#endif // FORD_FULKERSON_H
