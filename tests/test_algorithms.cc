#ifndef A2SIMPLENAVIGATOR_V1_0_1_TESTS_TEST_ALGORITHMS_CC_
#define A2SIMPLENAVIGATOR_V1_0_1_TESTS_TEST_ALGORITHMS_CC_

#include <vector>

#include "../graph/s21_graph.h"
#include "../graph_algorithms/s21_graph_algorithms.h"

void check_equals(const std::vector<int> &result,
                  const std::vector<int> &expected) {
  ASSERT_EQ(result.size(), expected.size());
  for (size_t i = 0; i < result.size(); ++i) {
    ASSERT_EQ(result[i], expected[i]);
  }
}

TEST(GraphAlgorhitm, BFS) {
  s21::Graph graph;
  graph.LoadGraphFromFile("./tests/data-samples/graph_example1.txt");
  s21::GraphAlgorithms graph_algorithms;
  auto result = graph_algorithms.BreadthFirstSearch(graph, 1);
  std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  check_equals(result, expected);
}

TEST(GraphAlgorhitm, DFS) {
  s21::Graph graph;
  graph.LoadGraphFromFile("./tests/data-samples/graph_example1.txt");
  s21::GraphAlgorithms graph_algorithms;
  auto result = graph_algorithms.DepthFirstSearch(graph, 1);
  std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  check_equals(result, expected);
}

TEST(GraphAlgorhitm, DFS2) {
  s21::Graph graph;
  graph.LoadGraphFromFile("./tests/data-samples/connected.txt");
  s21::GraphAlgorithms graph_algorithms;
  auto result = graph_algorithms.DepthFirstSearch(graph, 1);
  std::vector<int> expected = {1, 2, 3, 4, 5, 6};
  check_equals(result, expected);
}

TEST(GraphAlgorhitm, DFS3) {
  s21::Graph graph;
  graph.LoadGraphFromFile("./tests/data-samples/7vertices.txt");
  s21::GraphAlgorithms graph_algorithms;
  auto result = graph_algorithms.DepthFirstSearch(graph, 1);
  std::vector<int> expected = {1, 4, 2, 3, 7, 5, 6};  // 1 4 2 3 7 5
  check_equals(result, expected);
}

TEST(GraphAlgorhitm, BFS2) {
  s21::Graph graph;
  graph.LoadGraphFromFile("./tests/data-samples/connected.txt");
  s21::GraphAlgorithms graph_algorithms;
  auto result = graph_algorithms.BreadthFirstSearch(graph, 1);
  std::vector<int> expected = {1, 2, 3, 6, 4, 5};
  check_equals(result, expected);
}

TEST(GraphAlgorhitm, BFS3) {
  s21::Graph graph;
  graph.LoadGraphFromFile("./tests/data-samples/7vertices.txt");
  s21::GraphAlgorithms graph_algorithms;
  auto result = graph_algorithms.BreadthFirstSearch(graph, 1);

  std::vector<int> expected = {1, 4, 5, 7, 2, 3, 6};

  check_equals(result, expected);
}

TEST(GraphAlgorhitm, ShortestPath) {
  s21::Graph graph;
  graph.LoadGraphFromFile("./tests/data-samples/graph_example1.txt");
  s21::GraphAlgorithms graph_algorithms;
  auto result = graph_algorithms.GetShortestPathBetweenVertices(graph, 1, 11);
  size_t distance = 18;
  ASSERT_EQ(result, distance);
}

TEST(GraphAlgorhitm, ShortestPath2) {
  s21::Graph graph;
  graph.LoadGraphFromFile("./tests/data-samples/connected.txt");
  s21::GraphAlgorithms graph_algorithms;
  auto result = graph_algorithms.GetShortestPathBetweenVertices(graph, 1, 6);
  size_t expected = 11;
  ASSERT_EQ(result, expected);
}

TEST(GraphAlgorithms, ShortestPathsBetweenAllVertices) {
  s21::Graph graph;
  graph.LoadGraphFromFile("./tests/data-samples/connected.txt");
  s21::GraphAlgorithms graph_algorithms;
  auto result = graph_algorithms.GetShortestPathsBetweenAllVertices(graph);
  // for (auto row : result) {
  //   for (auto dist : row) {
  //     std::cout << dist << " ";
  //   }
  //   std::cout << std::endl;
  // }

  ASSERT_EQ(result[0][1], 7);
  ASSERT_EQ(result[0][2], 9);
  ASSERT_EQ(result[0][3], 20);
  ASSERT_EQ(result[0][4], 20);
  ASSERT_EQ(result[0][5], 11);
  ASSERT_EQ(result[1][2], 10);
  ASSERT_EQ(result[1][3], 15);
}

TEST(GraphAlgorhitm, S) {}
#endif  // A2SIMPLENAVIGATOR_V1_0_1_TESTS_TEST__CC_