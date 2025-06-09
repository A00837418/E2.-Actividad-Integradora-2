#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int find(int u, vector<int>& parent) {
    if (parent[u] != u)
        parent[u] = find(parent[u], parent);
    return parent[u];
}

void union_sets(int u, int v, vector<int>& parent) {
    parent[find(u, parent)] = find(v, parent);
}

void kruskal_mst(const vector<vector<int>>& adj_matrix) {
    int n = adj_matrix.size();
    vector<Edge> edges;
    vector<int> parent(n);

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
