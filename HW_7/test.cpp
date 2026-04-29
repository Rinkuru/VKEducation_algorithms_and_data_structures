#include <climits>
#include <gtest/gtest.h>
#include "src.cpp"

TEST(HW7, test_hasCycle) {
  EXPECT_FALSE(hasCycle({}));
  EXPECT_FALSE(hasCycle(std::vector<std::vector<int>>({
    {1},
    {0, 2},
    {1, 3},
    {2}
  })));
  EXPECT_TRUE(hasCycle(std::vector<std::vector<int>>({
    {1, 2},
    {0, 2},
    {0, 1}
  })));
  EXPECT_TRUE(hasCycle(std::vector<std::vector<int>>({
    {1},
    {0},
    {3, 4},
    {2, 4},
    {2, 3}
  })));
}

TEST(HW7, test_isTree) {
  EXPECT_TRUE(isTree({}));
  EXPECT_TRUE(isTree(std::vector<std::vector<int>>({{}})));
  EXPECT_TRUE(isTree(std::vector<std::vector<int>>({
    {1, 2},
    {0, 3},
    {0},
    {1}
  })));
  EXPECT_FALSE(isTree(std::vector<std::vector<int>>({
    {1, 2},
    {0, 2},
    {0, 1}
  })));
  EXPECT_FALSE(isTree(std::vector<std::vector<int>>({
    {1},
    {0},
    {}
  })));
}

TEST(HW7, test_dijkstra) {
  std::vector<std::vector<std::pair<int, int>>> graph = {
    {{1, 1}, {2, 4}},
    {{0, 1}, {2, 2}, {3, 6}},
    {{0, 4}, {1, 2}, {3, 3}},
    {{1, 6}, {2, 3}},
    {}
  };
  EXPECT_EQ(dijkstra(graph, 0), std::vector<int>({0, 1, 3, 6, INT_MAX}));

  std::vector<std::vector<std::pair<int, int>>> single = {
    {}
  };
  EXPECT_EQ(dijkstra(single, 0), std::vector<int>({0}));
}

TEST(HW7, test_isBipartite) {
  EXPECT_TRUE(isBipartite({}));
  EXPECT_TRUE(isBipartite(std::vector<std::vector<int>>({
    {1},
    {0, 2},
    {1, 3},
    {2}
  })));
  EXPECT_TRUE(isBipartite(std::vector<std::vector<int>>({
    {1, 3},
    {0, 2},
    {1, 3},
    {0, 2}
  })));
  EXPECT_FALSE(isBipartite(std::vector<std::vector<int>>({
    {1, 2},
    {0, 2},
    {0, 1}
  })));
  EXPECT_TRUE(isBipartite(std::vector<std::vector<int>>({
    {1},
    {0},
    {3},
    {2, 4},
    {3},
    {}
  })));
}
