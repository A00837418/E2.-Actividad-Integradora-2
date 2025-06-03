#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <climits>
#include <queue>

using namespace std;

// ---------- VARIABLES GLOBALES ----------
extern int N;
extern vector<vector<int>> adjMatrix;
extern vector<vector<int>> capacityMatrix;
extern vector<pair<int, int>> centrales;
extern pair<int, int> nuevaCasa;

// ---------- 1. Kruskal ----------
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

extern vector<int> parent;

int find(int u);
void unionSets(int u, int v);
void kruskalMST();

// ---------- 2. TSP ----------
extern int tspCost;
extern vector<int> bestPath;

void tspUtil(vector<int>& path, vector<bool>& visited, int currentCost);
void solveTSP();

// ---------- 3. Ford-Fulkerson ----------
int bfs(vector<vector<int>>& rGraph, vector<int>& parent);
int fordFulkerson();

// ---------- 4. Central más cercana ----------
double dist(pair<int, int> a, pair<int, int> b);
void centralMasCercana();

#endif
