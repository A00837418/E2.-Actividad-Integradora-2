
/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */


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
extern int n;
extern vector<vector<int>> adj_matrix;
extern vector<vector<int>> capacity_matrix;
extern vector<pair<int, int>> centrales;
extern pair<int, int> nueva_casa;

// ---------- 1. Kruskal ----------
struct edge {
    int u, v, weight;
    bool operator<(const edge& other) const {
        return weight < other.weight;
    }
};

extern vector<int> parent;

int find(int u);
void unionSets(int u, int v);
void kruskalMST();

// ---------- 2. TSP ----------
extern int tsp_cost;
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