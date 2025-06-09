#include "central_cercana.h"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

using namespace std;

// Función auxiliar para capturar la salida estándar
string captureOutput(const vector<pair<int, int>>& centrales, const pair<int, int>& casa) {
    ostringstream oss;
    streambuf* oldCout = cout.rdbuf(oss.rdbuf()); // Redirige cout

    central_mas_cercana(centrales, casa);

    cout.rdbuf(oldCout); // Restaura cout
    return oss.str();
}

TEST(CentralCercanaTest, CentralMasCercanaBasico) {
    vector<pair<int, int>> centrales = {{0, 0}, {5, 5}, {10, 10}};
    pair<int, int> casa = {3, 4};

    string salida = captureOutput(centrales, casa);

    // La central más cercana a (3,4) es (5,5) con distancia ≈ 2.236
    EXPECT_NE(salida.find("(5, 5)"), string::npos);
    EXPECT_NE(salida.find("distancia"), string::npos);
}

TEST(CentralCercanaTest, CentralUnica) {
    vector<pair<int, int>> centrales = {{7, 8}};
    pair<int, int> casa = {10, 12};

    string salida = captureOutput(centrales, casa);

    EXPECT_NE(salida.find("(7, 8)"), string::npos);
}

TEST(CentralCercanaTest, DistanciaCero) {
    vector<pair<int, int>> centrales = {{3, 3}, {10, 10}};
    pair<int, int> casa = {3, 3};

    string salida = captureOutput(centrales, casa);

    EXPECT_NE(salida.find("distancia: 0"), string::npos);
}

TEST(CentralCercanaTest, SinCentrales) {
    vector<pair<int, int>> centrales = {};
    pair<int, int> casa = {1, 1};

    string salida = captureOutput(centrales, casa);

    EXPECT_NE(salida.find("(-1, -1)"), string::npos);
}
