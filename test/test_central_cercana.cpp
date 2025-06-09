#include "central_cercana.h"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

// Helper para capturar la salida estándar (cout)
class CoutRedirect {
    std::streambuf* old_buf;
    std::stringstream ss;
public:
    CoutRedirect() {
        old_buf = std::cout.rdbuf(ss.rdbuf());
    }
    ~CoutRedirect() {
        std::cout.rdbuf(old_buf);
    }
    std::string getString() const {
        return ss.str();
    }
};

TEST(CentralCercanaOutputTest, ImprimeCentralYCercaniaCorrectamente) {
    vector<pair<int,int>> centrales = { {0,0}, {10,10}, {5,5} };
    pair<int,int> casa = {3,3};

    CoutRedirect redirect;  // redirige cout a stringstream

    central_mas_cercana(centrales, casa);

    std::string salida = redirect.getString();

    // Validamos que contenga la central correcta y la distancia aproximada
    EXPECT_NE(salida.find("(0, 0)"), std::string::npos);
    EXPECT_NE(salida.find("distancia:"), std::string::npos);

    // Ojo: validar números exactos es complicado, pero se puede buscar "distancia: 4.242"
    EXPECT_NE(salida.find("4.242"), std::string::npos);
}

TEST(CentralCercanaOutputTest, ConUnaCentral) {
    vector<pair<int,int>> centrales = { {2,2} };
    pair<int,int> casa = {1,1};

    CoutRedirect redirect;
    central_mas_cercana(centrales, casa);

    std::string salida = redirect.getString();

    EXPECT_NE(salida.find("(2, 2)"), std::string::npos);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
