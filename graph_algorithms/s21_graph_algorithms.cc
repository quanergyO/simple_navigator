#ifndef A2SIMPLENAVIGATOR_V1_0_1_GRAPH_ALGORITHMS_S21_GRAPH_ALGORITHMS_CC_
#define A2SIMPLENAVIGATOR_V1_0_1_GRAPH_ALGORITHMS_S21_GRAPH_ALGORITHMS_CC_

#include "s21_graph_algorithms.h"
#include "../utils/queue.h"
#include "../utils/stack.h"
#include <set>
#include <stdexcept>
#include <limits>


namespace s21
{

std::vector<int> GraphAlgorithms::DepthFirstSearch(Graph &graph, int start_vertex) {
    return FirstSearch<s21::Stack<int>>(graph, start_vertex);
}

std::vector<int> GraphAlgorithms::BreadthFirstSearch(Graph &graph, int start_vertex) {
    return FirstSearch<s21::Queue<int>>(graph, start_vertex);
}

size_t GraphAlgorithms::GetShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2)
{
    if (vertex1 <= 0 || vertex2 <= 0)
    {
        throw std::invalid_argument("Invalid argument");
    }
    --vertex1;
    --vertex2;
    std::vector<size_t> distance(graph.GetMatrix().size(), std::numeric_limits<size_t>::max());
    distance[vertex1] = 0;
    std::set<std::pair<int, int>> queue;
    queue.insert({distance[vertex1], vertex1});
    while (!queue.empty()) {
        auto from = queue.begin()->second;
        queue.erase(queue.begin());
        for (int to = 0, size = graph.GetMatrix().size(); to != size; ++to) {
            bool edge_is_exists = graph.GetMatrix()[from][to] != 0;
            bool new_edge_is_shorter = distance[to] > distance[from] + graph.GetMatrix()[from][to];
            if (edge_is_exists && new_edge_is_shorter) {
                queue.erase({distance[to], to});
                distance[to] = distance[from] + graph.GetMatrix()[from][to];
                queue.insert({distance[to], to});
            }
        }
    }
    return distance[vertex2];
}

std::vector<std::vector<int>> GraphAlgorithms::GetShortestPathsBetweenAllVertices(Graph &graph)
{
    const int INF = std::numeric_limits<int>::max();
    const int vertexes_count = graph.GetMatrix().size();
    std::vector<std::vector<int>> distance(vertexes_count, std::vector<int>(vertexes_count, INF));

    for (int row = 0; row != vertexes_count; ++row) {
        for (int col = 0; col != vertexes_count; ++col) {
            distance[row][col] = graph.GetMatrix()[row][col] == 0 ? INF : graph.GetMatrix()[row][col];
            if (row == col) {
                distance[row][col] = 0;
            }
        }
    }

    for (int v = 0; v != vertexes_count; ++v) {
        for (int row = 0; row != vertexes_count; ++row) {
            for (int col = 0; col != vertexes_count; ++col) {
                int weight = distance[row][v] + distance[v][col];
                if (distance[row][v] != INF && distance[v][col] != INF && distance[row][col] > weight) {
                    distance[row][col] = weight;
                }
            }
        }
    }
    return distance;
}

std::vector<std::vector<int>> GraphAlgorithms::GetLeastSpanningTree(Graph &graph) 
{
    const size_t vertexes_count = graph.GetMatrix().size();
    std::vector<std::vector<int>> result(vertexes_count, std::vector<int>(vertexes_count));
    std::vector<int> visited;
    std::vector<int> unvisited;
    size_t start_vertex = 0;
    visited.emplace_back(start_vertex);
    for (size_t i = 1; i < vertexes_count; ++i) {
        unvisited.emplace_back(i);
    }

    while (!unvisited.empty()) {
        for (int from : visited) {
            int to_value = std::numeric_limits<int>::max();
            int to = 0; 
            for (int it : unvisited) {
                if (graph.GetMatrix()[from][it] < to_value) {
                    to_value = graph.GetMatrix()[from][it];
                    to = it;
                }
            }
            result[from][to] = to_value;
            // heap
        }
    }
    return result;
}

template <typename Container>
std::vector<int> GraphAlgorithms::FirstSearch(Graph &graph, int start_vertex)
{
    Container container;
    container.push(start_vertex);
    std::vector<int> path;
    std::vector<int> visited(graph.GetMatrix().size(), 0);
    --start_vertex;
    visited[start_vertex] = 1;
    container.push(start_vertex);
    path.emplace_back(start_vertex + 1);
    while (!container.empty())
    {
        auto from = container.pop();
        for (int to = 0, size = graph.GetMatrix().size(); to != size; ++to) {
            if (!visited[to] && graph.GetMatrix()[from][to] != 0) {
                visited[to] = 1;
                container.push(to);
                path.emplace_back(to + 1);
            }
        }
    }
    return path;
}


}

#endif // A2SIMPLENAVIGATOR_V1_0_1_GRAPH_ALGORITHMS_S21_GRAPH_ALGORITHMS_CC_