#include "utilidades.h"

// ---------- DEFINICIONES DE VARIABLES GLOBALES ----------
int N = 4;

vector<vector<int>> adjMatrix = {
    {0, 16, 45, 32},
    {16, 0, 18, 21},
    {45, 18, 0, 7},
    {32, 21, 7, 0}
};

vector<vector<int>> capacityMatrix = {
    {0, 48, 12, 18},
    {52, 0, 42, 32},
    {18, 46, 0, 56},
    {24, 36, 52, 0}
};

vector<pair<int, int>> centrales = {
    {200, 500}, {300, 100}, {450, 150}, {520, 480}
};

pair<int, int> nuevaCasa = {400, 300};

vector<int> parent;
int tspCost = INT_MAX;
vector<int> bestPath;

// ---------- IMPLEMENTACIONES ----------
int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void unionSets(int u, int v) {
    parent[find(u)] = find(v);
}

void kruskalMST() {
    vector<Edge> edges;
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            if (adjMatrix[i][j] > 0)
                edges.push_back({i, j, adjMatrix[i][j]});

    sort(edges.begin(), edges.end());
    parent.resize(N);
    for (int i = 0; i < N; ++i) parent[i] = i;

    cout << "\n1. Árbol de expansión minima (Kruskal):\n";
    for (const Edge& e : edges) {
        if (find(e.u) != find(e.v)) {
            unionSets(e.u, e.v);
            cout << "(" << char('A' + e.u) << ", " << char('A' + e.v) << ")\n";
        }
    }
}

void tspUtil(vector<int>& path, vector<bool>& visited, int currentCost) {
    if (path.size() == N) {
        currentCost += adjMatrix[path.back()][path[0]];
        if (currentCost < tspCost) {
            tspCost = currentCost;
            bestPath = path;
        }
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            path.push_back(i);
            tspUtil(path, visited, currentCost + adjMatrix[path[path.size() - 2]][i]);
            path.pop_back();
            visited[i] = false;
        }
    }
}

void solveTSP() {
    vector<bool> visited(N, false);
    vector<int> path = {0};
    visited[0] = true;
    tspUtil(path, visited, 0);

    cout << "\n2. Recorrido mas corto (TSP):\n";
    for (int v : bestPath) cout << char('A' + v) << " ";
    cout << char('A' + bestPath[0]) << "\n";
    cout << "Costo minimo: " << tspCost << "\n";
}

int bfs(vector<vector<int>>& rGraph, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    queue<pair<int, int>> q;
    q.push({0, INT_MAX});
    parent[0] = -2;

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next = 0; next < N; ++next) {
            if (parent[next] == -1 && rGraph[cur][next] > 0) {
                parent[next] = cur;
                int new_flow = min(flow, rGraph[cur][next]);
                if (next == N - 1) return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int fordFulkerson() {
    vector<vector<int>> rGraph = capacityMatrix;
    parent.resize(N);
    int maxFlow = 0, flow;

    while ((flow = bfs(rGraph, parent)) != 0) {
        maxFlow += flow;
        int cur = N - 1;
        while (cur != 0) {
            int prev = parent[cur];
            rGraph[prev][cur] -= flow;
            rGraph[cur][prev] += flow;
            cur = prev;
        }
    }
    return maxFlow;
}

double dist(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

void centralMasCercana() {
    double minDist = 1e9;
    pair<int, int> closest;
    for (auto& central : centrales) {
        double d = dist(central, nuevaCasa);
        if (d < minDist) {
            minDist = d;
            closest = central;
        }
    }
    cout << "\n4. Central mas cercana a la casa:\n";
    cout << "(" << closest.first << ", " << closest.second << ")\n";
    cout << "Distancia: " << minDist << "\n";
}

// ---------- MAIN ----------
int main() {
    int opcion;
    do {
        cout << "\n----- MENU DE OPCIONES -----\n";
        cout << "1. Arbol de expansion minima (Kruskal)\n";
        cout << "2. Problema del viajante (TSP)\n";
        cout << "3. Flujo maximo (Ford-Fulkerson)\n";
        cout << "4. Buscar central mas cercana\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: kruskalMST(); break;
            case 2: solveTSP(); break;
            case 3:
                cout << "\n3. Flujo maximo (Ford-Fulkerson):\n";
                cout << "Flujo maximo: " << fordFulkerson() << "\n";
                break;
            case 4: centralMasCercana(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion no valida.\n"; break;
        }

    } while (opcion != 0);

    return 0;
}
