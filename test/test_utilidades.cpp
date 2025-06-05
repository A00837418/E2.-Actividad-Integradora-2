// test_utilidades.cpp
#include <gtest/gtest.h>
#include "utilidades.h"

TEST(KruskalTest, MSTEdgesCount) {
    std::vector<std::pair<char, char>> result;
    kruskal_mst_output(result);
    EXPECT_EQ(result.size(), 3); // n - 1 edges
}

TEST(TSPTest, ShortestPathCost) {
    std::vector<int> path;
    std::vector<std::vector<int>> matrix = {
        {0, 16, 45, 32},
        {16, 0, 18, 21},
        {45, 18, 0, 7},
        {32, 21, 7, 0}
    };
    int cost = tsp_solver(matrix, path);
    EXPECT_EQ(cost, 66); // Optimal TSP cost for this matrix
}

TEST(FordFulkersonTest, MaxFlowCorrect) {
    std::vector<std::vector<int>> capacity = {
        {0, 48, 12, 18},
        {52, 0, 42, 32},
        {18, 46, 0, 56},
        {24, 36, 52, 0}
    };
    int maxFlow = ford_fulkerson_solver(capacity);
    EXPECT_EQ(maxFlow, 60);
}

TEST(CentralTest, NearestCentralCorrect) {
    std::vector<std::pair<int, int>> centrales = {
        {200, 500}, {300, 100}, {450, 150}, {520, 480}
    };
    std::pair<int, int> casa = {400, 300};
    auto result = central_mas_cercana_solver(centrales, casa);
    EXPECT_EQ(result.first, std::make_pair(450, 150));
}
