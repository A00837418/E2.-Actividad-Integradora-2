#include <gtest/gtest.h>
#include "edge.h"
#include <vector>
#include <algorithm>

using namespace std;

TEST(EdgeTest, SortEdgesByWeight) {
    vector<Edge> edges = {
        {0, 1, 20},
        {1, 2, 10},
        {2, 3, 30},
        {3, 4, 5}
    };

    sort(edges.begin(), edges.end());

    EXPECT_EQ(edges[0].weight, 5);
    EXPECT_EQ(edges[1].weight, 10);
    EXPECT_EQ(edges[2].weight, 20);
    EXPECT_EQ(edges[3].weight, 30);
}
