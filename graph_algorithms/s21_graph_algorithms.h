#ifndef A2SIMPLENAVIGATOR_V1_0_1_GRAPH_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#define A2SIMPLENAVIGATOR_V1_0_1_GRAPH_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_

#include <vector>
#include "../graph/s21_graph.h"

namespace s21
{

struct TsmResult {
    std::vector<int> vertices;   
    double distance;
};


class GraphAlgorithms
{
public:
    std::vector<int> DepthFirstSearch(Graph &graph, int start_vertex);
    std::vector<int> BreadthFirstSearch(Graph &graph, int start_vertex);

    size_t GetShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
    std::vector<std::vector<int>> GetShortestPathsBetweenAllVertices(Graph &graph);

    std::vector<std::vector<int>> GetLeastSpanningTree(Graph &graph);
    TsmResult SolveTravelingSalesmanProblem(Graph &graph);
    
private:
    template< typename Container>
    std::vector<int> FirstSearch(Graph &graph, int start_vertex);
};


} // namespace s21

#endif // A2SIMPLENAVIGATOR_V1_0_1_GRAPH_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_