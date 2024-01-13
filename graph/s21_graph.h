#ifndef A2SIMPLENAVIGATOR_V1_0_1_GRAPH_S21_GRAPH_H_
#define A2SIMPLENAVIGATOR_V1_0_1_GRAPH_S21_GRAPH_H_

#include <string>
#include <vector>

namespace s21
{
    class Graph
    {
    public:
        void LoadGraphFromFile(std::string filename);
        void ExportGraphToDot(std::string filename) const;
        const std::vector<std::vector<int>>& GetMatrix() const noexcept;

    private:
        std::vector<std::vector<int>> matrix_;

    };

} // namespace s21

#endif // A2SIMPLENAVIGATOR_V1_0_1_GRAPH_S21_GRAPH_H_