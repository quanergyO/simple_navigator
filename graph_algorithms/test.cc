// #include <iostream>

// #include "../graph/s21_graph.h"
// #include "s21_graph_algorithms.h"

// int main() {
//   s21::Graph graph;
//   graph.LoadGraphFromFile(
//       "/Users/haegonta/Downloads/simple_navigator/tests/data-samples/"
//       "graph_example1.txt");
//   s21::GraphAlgorithms graph_algorithms;
//   auto result = graph_algorithms.GetLeastSpanningTree(graph);
//   for (auto row : result) {
//     for (auto dist : row) {
//       std::cout << dist << " ";
//     }
//     std::cout << std::endl;
//   }

//   return 0;
// }