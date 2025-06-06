
/*
 * Tec de Monterrey - Data Structures and Algorithms
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

/*
 * Tec de Monterrey - Data Structures and Algorithms
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
#include <limits>

using namespace std;

// ---------- definiciones de variables globales ----------
int n = 4;

vector<vector<int>> adj_matrix = {
    {0, 16, 45, 32},
    {16, 0, 18, 21},
    {45, 18, 0, 7},
    {32, 21, 7, 0}
};

vector<vector<int>> capacity_matrix = {
    {0, 48, 12, 18},
    {52, 0, 42, 32},
    {18, 46, 0, 56},
    {24, 36, 52, 0}
};

vector<pair<int, int>> centrales = {
    {200, 500},
    {300, 100},
    {450, 150},
    {520, 480}
};

pair<int, int> nueva_casa = {400, 300};

vector<int> parent;
int tsp_cost = INT_MAX;
vector<int> best_path;

// Definición de la estructura Edge para Kruskal
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// ---------- implementaciones ----------

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void union_sets(int u, int v) {
    parent[find(u)] = find(v);
}

void kruskal_mst() {
    vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (adj_matrix[i][j] > 0) {
                edges.push_back({i, j, adj_matrix[i][j]});
            }
        }
    }

    sort(edges.begin(), edges.end());
    parent.resize(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    cout << "\n1. arbol de expansión minima (Kruskal):\n";
    for (const Edge& e : edges) {
        if (find(e.u) != find(e.v)) {
            union_sets(e.u, e.v);
            cout << "(" << char('A' + e.u) << ", " << char('A' + e.v) << ")\n";
        }
    }
}

void tsp_util(vector<int>& path, vector<bool>& visited, int current_cost) {
    if (path.size() == n) {
        current_cost += adj_matrix[path.back()][path[0]];
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

            int prev;
            if (path.size() >= 2) {
                prev = path[path.size() - 2];
            } else {
                prev = path.back();
            }

            tsp_util(path, visited, current_cost + adj_matrix[prev][i]);

            path.pop_back();
            visited[i] = false;
        }
    }
}


void solve_tsp() {
    vector<bool> visited(n, false);
    vector<int> path;
    path.push_back(0);
    visited[0] = true;
    tsp_cost = INT_MAX; // Reiniciar antes de resolver
    best_path.clear();

    tsp_util(path, visited, 0);

    cout << "\n2. recorrido mas corto (TSP):\n";
    for (int v : best_path) {
        cout << char('A' + v) << " ";
    }
    if (!best_path.empty()) {
        cout << char('A' + best_path[0]) << "\n";
    }
    cout << "costo minimo: " << tsp_cost << "\n";
}

int bfs(vector<vector<int>>& r_graph, vector<int>& parent) {
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
                if (next == n - 1) {
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int ford_fulkerson() {
    vector<vector<int>> r_graph = capacity_matrix;
    parent.resize(n);
    int max_flow = 0;
    int flow;

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

double dist(const pair<int, int>& a, const pair<int, int>& b) {
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

void central_mas_cercana() {
    double min_dist = numeric_limits<double>::max();
    pair<int, int> closest = {-1, -1};
    for (const pair<int, int>& central : centrales) {
        double d = dist(central, nueva_casa);
        if (d < min_dist) {
            min_dist = d;
            closest = central;
        }
    }
    cout << "\n4. central mas cercana a la casa:\n";
    cout << "(" << closest.first << ", " << closest.second << ")\n";
    cout << "distancia: " << min_dist << "\n";
}

// ---------- main ----------
int main() {
    int opcion;
    do {
        cout << "\n----- MENU DE OPCIONES -----\n";
        cout << "1. arbol de expansion minima (Kruskal)\n";
        cout << "2. problema del viajante (TSP)\n";
        cout << "3. flujo maximo (Ford-Fulkerson)\n";
        cout << "4. buscar central mas cercana\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";

        // Validar entrada
        while (!(cin >> opcion)) {
            cout << "Entrada invalida. Intenta de nuevo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (opcion) {
            case 1:
                kruskal_mst();
                break;
            case 2:
                solve_tsp();
                break;
            case 3:
                cout << "\n3. Flujo maximo (Ford-Fulkerson):\n";
                cout << "Flujo maximo: " << ford_fulkerson() << "\n";
                break;
            case 4:
                central_mas_cercana();
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
                break;
        }

    } while (opcion != 0);

    return 0;
}
