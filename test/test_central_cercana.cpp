#include "central_cercana.h"
#include <gtest/gtest.h>

TEST(CentralCercanaTest, CasoBasico) {
    vector<pair<int, int>> centrales = { {0,0}, {10,10}, {5,5} };
    pair<int, int> casa = {3,3};
    
    auto resultado = central_mas_cercana(centrales, casa);
    EXPECT_EQ(resultado.first, make_pair(0,0));
    EXPECT_NEAR(resultado.second, 4.2426, 0.0001);  // sqrt(3² + 3²)
}

TEST(CentralCercanaTest, DistanciaCero) {
    vector<pair<int, int>> centrales = { {1,1}, {2,2} };
    pair<int, int> casa = {1,1};
    
    auto resultado = central_mas_cercana(centrales, casa);
    EXPECT_EQ(resultado.first, make_pair(1,1));
    EXPECT_DOUBLE_EQ(resultado.second, 0.0);
}

TEST(CentralCercanaTest, UnicaCentral) {
    vector<pair<int, int>> centrales = { {100,100} };
    pair<int, int> casa = {50,50};
    
    auto resultado = central_mas_cercana(centrales, casa);
    EXPECT_EQ(resultado.first, make_pair(100,100));
}

TEST(CentralCercanaTest, VectorVacio) {
    vector<pair<int, int>> centrales = {};
    pair<int, int> casa = {0,0};
    
    EXPECT_THROW(central_mas_cercana(centrales, casa), invalid_argument);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
