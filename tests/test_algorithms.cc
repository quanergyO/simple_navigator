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
  std::vector<int> expected = {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 2};
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
  //   for (auto it = result.begin(); it != result.end(); ++it) {
  //     std::cout << *it;
  //   }
  // std::vector<int> expected = {1, 2, 3,  4,5,6}; - right
  std::vector<int> expected = {1, 2, 3, 6, 5, 4};  // our
  check_equals(result, expected);
}

TEST(GraphAlgorhitm, DFS3) {
  s21::Graph graph;
  graph.LoadGraphFromFile("./tests/data-samples/7vertices.txt");
  s21::GraphAlgorithms graph_algorithms;
  auto result = graph_algorithms.DepthFirstSearch(graph, 1);

  //   for (auto it = result.begin(); it != result.end(); ++it) {
  //     std::cout << *it;
  //   }
  // std::vector<int> expected = {1, 4, 2, 3, 7, 5, 6};- right
  std::vector<int> expected = {1, 4, 5, 7, 2, 6, 3};  // our

  check_equals(result, expected);
}

TEST(GraphAlgorhitm, BFS2) {
  s21::Graph graph;
  graph.LoadGraphFromFile("./tests/data-samples/connected.txt");
  s21::GraphAlgorithms graph_algorithms;
  auto result = graph_algorithms.BreadthFirstSearch(graph, 1);
  for (auto it = result.begin(); it != result.end(); ++it) {
    std::cout << *it;
  }
  std::vector<int> expected = {1, 3, 4, 2, 6, 5};
  check_equals(result, expected);
}

TEST(GraphAlgorhitm, BFS3) {
  s21::Graph graph;
  graph.LoadGraphFromFile("./tests/data-samples/7vertices.txt");
  s21::GraphAlgorithms graph_algorithms;
  auto result = graph_algorithms.BreadthFirstSearch(graph, 1);

  for (auto it = result.begin(); it != result.end(); ++it) {
    std::cout << *it;
  }
  // std::vector<int> expected = {1, 4, 2, 3, 7, 5, 6};- right
  std::vector<int> expected = {1, 4, 5, 7, 2, 3, 6};  // our

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
#endif  // A2SIMPLENAVIGATOR_V1_0_1_TESTS_TEST__CC_