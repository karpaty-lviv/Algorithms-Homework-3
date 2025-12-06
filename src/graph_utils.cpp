#include "graph_utils.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace GraphUtils
{

    Graph readGraphFromFile(const std::string &filename){
        std::ifstream file(filename);
        if (!file.is_open()){
            throw std::runtime_error("Error: Could not open file " + filename);
        }

        int V, E;
        if (!(file >> V >> E)){
            throw std::runtime_error("Error: Invalid file format or empty file.");
        }

        Graph g(V);

        for (int i = 0; i < E; ++i){
            int u, v;
            file >> u >> v;
            if (u < 1 || u > V || v < 1 || v > V){
                std::cerr << "Warning: Invalid edge " << u << "->" << v
                          << " ignored (vertices must be between 1 and " << V << ")\n";
                continue;
            }
            g.addEdge(u - 1, v - 1);
        }

        file.close();
        return g;
    }
}
