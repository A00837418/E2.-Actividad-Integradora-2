#ifndef CENTRAL_CERCANA_H
#define CENTRAL_CERCANA_H

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

double dist(const pair<int, int>& a, const pair<int, int>& b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

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
