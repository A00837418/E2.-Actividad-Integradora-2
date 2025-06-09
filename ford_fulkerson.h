#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

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
