#include <gtest/gtest.h>
#include "utilidades.h"
#include <vector>
#include <algorithm>

TEST(EdgeTest, SortEdgesByWeight) {
    std::vector<tec_ds::Utilidades::Edge> edges = {
        {0, 1, 20},
        {1, 2, 10},
        {2, 3, 30},
        {3, 4, 5}
    };

    std::sort(edges.begin(), edges.end());

    EXPECT_EQ(edges[0].weight, 5);
    EXPECT_EQ(edges[1].weight, 10);
    EXPECT_EQ(edges[2].weight, 20);
    EXPECT_EQ(edges[3].weight, 30);
}
