
/*
 * Tec de Monterrey - Data Structures and Algorithms
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef utilidades_h
#define utilidades_h

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <climits>
#include <queue>

using namespace std;

// ---------- variables_globales ----------
extern int n;
extern vector<vector<int>> adj_matrix;
extern vector<vector<int>> capacity_matrix;
extern vector<pair<int, int>> centrales;
extern pair<int, int> nueva_casa;

// ---------- kruskal ----------
struct edge {
    int u, v, weight;
    bool operator<(const edge& other) const {
        return weight < other.weight;
    }
};

extern vector<int> parent;

int find(int u);
void union_sets(int u, int v);
void kruskal_mst();

// ---------- tsp ----------
extern int tsp_cost;
extern vector<int> best_path;

void tsp_util(vector<int>& path, vector<bool>& visited, int current_cost);
void solve_tsp();

// ---------- ford_fulkerson ----------
int bfs(vector<vector<int>>& r_graph, vector<int>& parent);
int ford_fulkerson();

// ---------- central_mas_cercana ----------
double dist(pair<int, int> a, pair<int, int> b);
void central_mas_cercana();

#endif
