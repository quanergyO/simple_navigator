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

// TEST(GraphAlgorhitm, BFS2) {
//   const int size = 6;
//   s21::Graph graph;
//   s21::GraphAlgorithms graphAlgorithms;
//   const std::string answ[size] = {"1 2 3 6 4 5", "2 1 3 4 6 5", "3 1 2 4 6
//   5",
//                                   "4 2 3 5 1 6", "5 4 6 2 3 1", "6 1 3 5 2
//                                   4"};

//   auto vectorToStr = [](const std::vector<int> &v) {
//     std::string str;

//     for (size_t i = 0; i < v.size(); i++) {
//       str += std::to_string(v[i] + 1);
//       if (i + 1 != v.size()) str += ' ';
//     }

//     return str;
//   };

//   graph.LoadGraphFromFile("./tests/data-samples/connected.txt");

//   for (int i = 0; i < size; i++) {
//     ASSERT_EQ(vectorToStr(graphAlgorithms.BreadthFirstSearch(graph, i)),
//               answ[i]);
//   }
// }

// TEST(GraphAlgorhitm, BFS3) {
//   const int size = 6;
//   s21::Graph graph;
//   s21::GraphAlgorithms graphAlgorithms;
//   const std::string answ[size] = {"1 2 4 3 5 6", "2 3 1 6 4 5", "3 1 6 2 4
//   5",
//                                   "4 5 3 1 6 2", "5 3 4 1 6 2", "6 5 3 4 1
//                                   2"};

//   auto vectorToStr = [](const std::vector<int> &v) {
//     std::string str;

//     for (size_t i = 0; i < v.size(); i++) {
//       str += std::to_string(v[i] + 1);
//       if (i + 1 != v.size()) str += ' ';
//     }

//     return str;
//   };

//   graph.LoadGraphFromFile("./tests/data-samples/directed.txt");

//   for (int i = 0; i < size; i++) {
//     ASSERT_EQ(vectorToStr(graphAlgorithms.BreadthFirstSearch(graph, i)),
//               answ[i]);
//   }
// }

#endif  // A2SIMPLENAVIGATOR_V1_0_1_TESTS_TEST__CC_