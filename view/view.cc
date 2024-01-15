#ifndef A2SIMPLENAVIGATOR_V1_0_1_VIEW_VIEW_CC_
#define A2SIMPLENAVIGATOR_V1_0_1_VIEW_VIEW_CC_

#include <iostream>
#include <string>
#include "../graph/s21_graph.h"
#include "../graph_algorithms/s21_graph_algorithms.h"

void print_menu() {
    std::cout << "1. Load Graph From File\n"
              << "2. BFS\n"
              << "3. DFS\n"
              << "4. Find smallest Path\n"
              << "5. Find all paths\n"
              << "6. Find tree\n"
              << "7. Voyajer task\n"
              << "8. Quit\n";
}

void case1(s21::Graph& graph)
{
    std::cout << "Input path for file: ";
    std::string filePath;
    std::cin >> filePath;
    try {
        graph.LoadGraphFromFile(filePath);
        std::cout << "Done\n";
    } catch (std::exception &e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

void case2(s21::Graph &graph) {
    s21::GraphAlgorithms algorithm;
    int start_vertex;
    std::cout << "Input start point: ";
    std::cin >> start_vertex;
    try {

        auto path = algorithm.BreadthFirstSearch(graph, start_vertex);
        for (auto num : path) {
            std::cout << num << ' ';
        }
    } catch (std::exception &e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

void case3(s21::Graph &graph) {
    s21::GraphAlgorithms algorithm;
    int start_vertex;
    std::cout << "Input start point: ";
    std::cin >> start_vertex;
    try {
        auto path = algorithm.DepthFirstSearch(graph, start_vertex);
        for (auto num : path) {
            std::cout << num << ' ';
        }
    } catch (std::exception &e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

void case4(s21::Graph &graph) {
    s21::GraphAlgorithms algorithm;
    int start_vertex, end_vertex;
    std::cout << "Input start point: ";
    std::cin >> start_vertex;
    std::cout << "Input end point: ";
    std::cin >> end_vertex;
    try {
        size_t size = algorithm.GetShortestPathBetweenVertices(graph, start_vertex, end_vertex);
        std::cout << size;
    } catch (std::exception &e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

void case5(s21::Graph &graph) {
    s21::GraphAlgorithms algorithm;
    auto matrixPaths = algorithm.GetShortestPathsBetweenAllVertices(graph);
    for (const auto& path : matrixPaths) {
        for (int num : path) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }
}


void case6(s21::Graph &graph) {
    s21::GraphAlgorithms algorithm;
    auto matrixTree = algorithm.GetLeastSpanningTree(graph);
    for (const auto &vertecis : matrixTree) {
        for (int num : vertecis) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }
}

void case7(s21::Graph &graph) {
    s21::GraphAlgorithms algorithm;
    // TODO
}

int main() {
    s21::Graph graph;
    char choice = 0;
    bool quit = false;
    while (!quit) {
        print_menu();
        std::cin >> choice;
        switch (choice) {
            case '1': case1(graph); break;
            case '2': case2(graph); break;
            case '3': case3(graph); break;
            case '4': case4(graph); break;
            case '5': case5(graph); break;
            case '6': case6(graph); break;
            case '7': case7(graph); break;
            case '8': quit = true;
        }
    }

    return 0;
}

#endif // A2SIMPLENAVIGATOR_V1_0_1_VIEW_VIEW_CC_
