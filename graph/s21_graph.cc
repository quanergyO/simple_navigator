#ifndef A2SIMPLENAVIGATOR_V1_0_1_GRAPH_S21_GRAPH_CC_
#define A2SIMPLENAVIGATOR_V1_0_1_GRAPH_S21_GRAPH_CC_

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "s21_graph.h"


namespace s21
{

void Graph::LoadGraphFromFile(std::string filename)
{
    std::fstream file(filename, std::ios::in);
    if (!file.is_open()) {
        throw std::runtime_error("Can't open file");
    }
    std::string line;
    std::getline(file, line);
    int count;
    {
        std::istringstream stream(std::move(line));
        stream >> count;
        if (count <= 0) {
            throw std::invalid_argument("Bad graph size");
        }
    }
    for (int i = 0; i < count; ++i) {
        std::getline(file, line);
        std::istringstream stream(std::move(line));
        std::vector<int> vec_tmp(count);
        for (int j = 0; j < count; ++j) {
            stream >> vec_tmp[j];
        }
        matrix_.emplace_back(vec_tmp);
    }
}

const std::vector<std::vector<int>>& Graph::GetMatrix() const noexcept
{
    return matrix_;
}


} // namespace s21

#endif // A2SIMPLENAVIGATOR_V1_0_1_GRAPH_S21_GRAPH_CC_
