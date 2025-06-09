#ifndef TSP_H
#define TSP_H

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void tsp_util(const vector<vector<int>>& adj_matrix, vector<int>& path, vector<bool>& visited,
              int current_cost, int& tsp_cost, vector<int>& best_path) {
    int n = adj_matrix.size();
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
            tsp_util(adj_matrix, path, visited, current_cost + adj_matrix[path[path.size() - 2]][i], tsp_cost, best_path);
            path.pop_back();
            visited[i] = false;
        }
    }
}

void solve_tsp(const vector<vector<int>>& adj_matrix) {
    int n = adj_matrix.size();
    vector<bool> visited(n, false);
    vector<int> path;
    vector<int> best_path;
    int tsp_cost = INT_MAX;

    path.push_back(0);
    visited[0] = true;
    tsp_util(adj_matrix, path, visited, 0, tsp_cost, best_path);

    cout << "\n2. recorrido mas corto (TSP):\n";
    for (int v : best_path)
        cout << char('A' + v) << " ";
    if (!best_path.empty())
        cout << char('A' + best_path[0]) << "\n";
    cout << "costo minimo: " << tsp_cost << "\n";
}

#endif // TSP_H
