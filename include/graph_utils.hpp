#pragma once
#include "graph.hpp"
#include <string>

namespace GraphUtils
{
    // read graph and return Graph object
    Graph readGraphFromFile(const std::string &filename);
}
