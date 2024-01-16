#ifndef A2SIMPLENAVIGATOR_V1_0_1_GRAPH_ALGORITHMS_S21_GRAPH_ALGORITHMS_CC_
#define A2SIMPLENAVIGATOR_V1_0_1_GRAPH_ALGORITHMS_S21_GRAPH_ALGORITHMS_CC_

#include "s21_graph_algorithms.h"

#include <limits>
#include <set>
#include <stdexcept>
#include <type_traits>

#include "../utils/queue.h"
#include "../utils/stack.h"

namespace s21 {

std::vector<int> GraphAlgorithms::DepthFirstSearch(Graph &graph,
                                                   int start_vertex) {
  // return FirstSearch<s21::Stack<int>>(graph, start_vertex);
  if (start_vertex <= 0 ||
      start_vertex > static_cast<int>(graph.GetMatrix().size())) {
    throw std::invalid_argument("Invalid argument");
  }
  --start_vertex;
  std::vector<int> path;
  s21::Stack<int> container;
  std::vector<bool> visited(graph.GetMatrix().size(), false);
  visited[start_vertex] = true;
  container.push(start_vertex);
  path.emplace_back(start_vertex + 1);
  while (!container.empty()) {
    auto from = container.top();
    bool is_found = false;
    for (int to = 0, size = graph.GetMatrix().size(); to != size; ++to) {
      if (!visited[to] && graph.GetMatrix()[from][to] != 0) {
        container.push(to);
        is_found = true;
        visited[to] = true;
        path.emplace_back(to + 1);
        from = to;
      }
    }
    if (!is_found) {
      container.pop();
    }
  }
  return path;
}

std::vector<int> GraphAlgorithms::BreadthFirstSearch(Graph &graph,
                                                     int start_vertex) {
  // return FirstSearch<s21::Queue<int>>(graph, start_vertex);
  if (start_vertex <= 0 ||
      start_vertex > static_cast<int>(graph.GetMatrix().size())) {
    throw std::invalid_argument("Invalid argument");
  }
  --start_vertex;
  std::vector<int> path;
  s21::Queue<int> container;
  std::vector<bool> visited(graph.GetMatrix().size(), false);
  visited[start_vertex] = true;
  container.push(start_vertex);
  while (!container.empty()) {
    auto from = container.pop();
    path.emplace_back(from + 1);
    for (int to = 0, size = graph.GetMatrix().size(); to != size; ++to) {
      if (!visited[to] && graph.GetMatrix()[from][to] != 0) {
        container.push(to);
        visited[to] = true;
      }
    }
  }
  return path;
}

size_t GraphAlgorithms::GetShortestPathBetweenVertices(Graph &graph,
                                                       int vertex1,
                                                       int vertex2) {
  if (vertex1 <= 0 || vertex2 <= 0 ||
      vertex1 > static_cast<int>(graph.GetMatrix().size()) ||
      vertex2 > static_cast<int>(graph.GetMatrix().size())) {
    throw std::invalid_argument("Invalid argument");
  }
  --vertex1;
  --vertex2;
  std::vector<size_t> distance(graph.GetMatrix().size(),
                               std::numeric_limits<size_t>::max());
  distance[vertex1] = 0;
  std::set<std::pair<int, int>> queue;
  queue.insert({distance[vertex1], vertex1});
  while (!queue.empty()) {
    auto from = queue.begin()->second;
    queue.erase(queue.begin());
    for (int to = 0, size = graph.GetMatrix().size(); to != size; ++to) {
      bool edge_is_exists = graph.GetMatrix()[from][to] != 0;
      bool new_edge_is_shorter =
          distance[to] > distance[from] + graph.GetMatrix()[from][to];
      if (edge_is_exists && new_edge_is_shorter) {
        queue.erase({distance[to], to});
        distance[to] = distance[from] + graph.GetMatrix()[from][to];
        queue.insert({distance[to], to});
      }
    }
  }
  return distance[vertex2];
}

std::vector<std::vector<int>>
GraphAlgorithms::GetShortestPathsBetweenAllVertices(Graph &graph) {
  const int INF = std::numeric_limits<int>::max();
  const int vertexes_count = graph.GetMatrix().size();
  std::vector<std::vector<int>> distance(vertexes_count,
                                         std::vector<int>(vertexes_count, INF));

  for (int row = 0; row != vertexes_count; ++row) {
    for (int col = 0; col != vertexes_count; ++col) {
      distance[row][col] =
          graph.GetMatrix()[row][col] == 0 ? INF : graph.GetMatrix()[row][col];
      if (row == col) {
        distance[row][col] = 0;
      }
    }
  }

  for (int v = 0; v != vertexes_count; ++v) {
    for (int row = 0; row != vertexes_count; ++row) {
      for (int col = 0; col != vertexes_count; ++col) {
        int weight = distance[row][v] + distance[v][col];
        if (distance[row][v] != INF && distance[v][col] != INF &&
            distance[row][col] > weight) {
          distance[row][col] = weight;
        }
      }
    }
  }
  return distance;
}

std::vector<std::vector<int>> GraphAlgorithms::GetLeastSpanningTree(
    Graph &graph) {
  const size_t vertexes_count = graph.GetMatrix().size();
  std::vector<std::vector<int>> result(vertexes_count,
                                       std::vector<int>(vertexes_count));
  std::vector<bool> visited(vertexes_count, false);
  std::vector<int> distances(vertexes_count, std::numeric_limits<int>::max());
  std::vector<int> parents(vertexes_count, -1);
  distances[0] = 0;
  for (size_t i = 0; i < vertexes_count - 1; ++i) {
    int min_distance = std::numeric_limits<int>::max();
    size_t min_vertex = 0;
    for (size_t j = 0; j < vertexes_count; ++j) {
      if (!visited[j] && distances[j] < min_distance) {
        min_distance = distances[j];
        min_vertex = j;
      }
    }
    visited[min_vertex] = true;
    for (size_t j = 0; j < vertexes_count; ++j) {
      if (graph.GetMatrix()[min_vertex][j] != 0 && !visited[j] &&
          graph.GetMatrix()[min_vertex][j] < distances[j]) {
        distances[j] = graph.GetMatrix()[min_vertex][j];
        parents[j] = min_vertex;
      }
    }
  }
  for (size_t i = 1; i < vertexes_count; ++i) {
    result[i][parents[i]] = distances[i];
    result[parents[i]][i] = distances[i];
  }

  return result;
}

TsmResult GraphAlgorithms::SolveTravelingSalesmanProblem(Graph &) {
  // TODO
  TsmResult result;

  return result;
}

template <typename Container>
std::vector<int> GraphAlgorithms::FirstSearch(Graph &graph, int start_vertex) {
  if (start_vertex <= 0 ||
      start_vertex > static_cast<int>(graph.GetMatrix().size())) {
    throw std::invalid_argument("Invalid argument");
  }
  constexpr bool is_stack = std::is_same_v<Container, s21::Stack<int>>;
  std::vector<int> path;
  std::vector<short> visited(graph.GetMatrix().size());
  Container container;

  --start_vertex;
  visited[start_vertex] = true;
  container.push(start_vertex);
  path.emplace_back(start_vertex + 1);

  while (!container.empty()) {
    int from = -1;
    if constexpr (is_stack) {
      from = container.top();
    } else {
      from = container.front();
      container.pop();
    }
    bool is_found = false;
    for (int to = 0, size = graph.GetMatrix().size(); to != size; ++to) {
      if (!visited[to] && graph.GetMatrix()[from][to] != 0) {
        is_found = true;
        visited[to] = true;
        container.push(to);
        path.emplace_back(to + 1);
        if (is_stack) from = to;
      }
    }

    if (is_stack && !is_found) {
      container.pop();
    }
  }

  return path;
}

}  // namespace s21

#endif  // A2SIMPLENAVIGATOR_V1_0_1_GRAPH_ALGORITHMS_S21_GRAPH_ALGORITHMS_CC_
