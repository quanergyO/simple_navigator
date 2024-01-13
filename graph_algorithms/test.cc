#include <iostream>
#include "s21_graph_algorithms.h"
#include "../graph/s21_graph.h"


int main() {
    s21::Graph graph;
    graph.LoadGraphFromFile("/Users/pagemois/school21/A2_SimpleNavigator_v1.0-1/src/tests/data-samples/graph_example1.txt");
    s21::GraphAlgorithms graph_algorithms;
    auto result = graph_algorithms.GetShortestPathsBetweenAllVertices(graph);
    for (auto i : result) {
        for (auto j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}