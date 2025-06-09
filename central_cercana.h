
/*
 * Tec de Monterrey - Data Structures and Algorithms
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#ifndef CENTRAL_CERCANA_H
#define CENTRAL_CERCANA_H

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

/**
 * @brief Calcula la distancia euclidiana entre dos puntos en un plano 2D.
 * 
 * @param a Coordenadas del primer punto (par de enteros: x, y).
 * @param b Coordenadas del segundo punto (par de enteros: x, y).
 * @return double La distancia euclidiana entre los dos puntos.
 */
double dist(const pair<int, int>& a, const pair<int, int>& b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

/**
 * @brief Encuentra y muestra la central más cercana a una nueva casa.
 * 
 * Recorre una lista de coordenadas de centrales eléctricas y determina cuál está más cerca
 * de la casa indicada. Imprime la central más cercana y la distancia a esta.
 * 
 * @param centrales Vector de pares de enteros que representan las coordenadas de las centrales.
 * @param nueva_casa Par de enteros que representa las coordenadas de la nueva casa.
 */
void central_mas_cercana(const vector<pair<int, int>>& centrales, const pair<int, int>& nueva_casa) {
    double min_dist = numeric_limits<double>::max();
    pair<int, int> closest = {-1, -1};
    for (const auto& central : centrales) {
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

#endif // CENTRAL_CERCANA_H
