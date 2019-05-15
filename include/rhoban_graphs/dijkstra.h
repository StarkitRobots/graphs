#pragma once

#include "starkit_graphs/graph.h"

namespace starkit_graphs
{
class Djikstra
{
public:
  static std::vector<Graph::Node> findPath(Graph& graph, Graph::Node start, Graph::Node goal, double* score = NULL);
};

}  // namespace starkit_graphs
