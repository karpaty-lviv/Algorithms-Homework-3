#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

#include "graph.hpp"
#include "scc_solver.hpp"
#include "graph_utils.hpp"

int main()
{
    try
    {
        // reading the data
        std::string filename = "data/input.txt";
        std::cout << "Loading graph from file: " << filename << "\n";

        Graph g = GraphUtils::readGraphFromFile(filename);

        std::cout << "--------------------------------------------------\n\n";

        // find SCCs
        std::cout << ">>> Step 1: Finding Strongly Connected Components (SCCs)\n";

        SCCSolver solver(g);

        // measure findSCCs 
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<std::vector<int>> sccs = solver.findSCCs();
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duration = end - start;

        std::cout << "Result: Found " << sccs.size() << " strongly connected components.\n";

        // display every component
        for (size_t i = 0; i < sccs.size(); ++i){
            std::cout << "  Component #" << i + 1 << ": { ";
            for (int v : sccs[i]){
                std::cout << (v + 1) << " ";
            }
            std::cout << "}\n";
        }
        std::cout << "--------------------------------------------------\n\n";

        // build condansation graph
        std::cout << ">>> Step 2: Building Condensation Graph (DAG)\n";

        Graph dag = solver.buildCondensationGraph(sccs);

        std::cout << "Result: Condensation graph created with " << dag.V << " vertices (components).\n";
        std::cout << "Edges between components:\n";

        bool hasEdges = false;
        for (int u = 0; u < dag.V; ++u){
            for (int v : dag.adj[u]){
                std::cout << "  [Comp #" << (u + 1) << "] -> [Comp #" << (v + 1) << "]\n";
                hasEdges = true;
            }
        }
        if (!hasEdges)
            std::cout << "  (No edges between components)\n";
        std::cout << "--------------------------------------------------\n\n";

        // topological sort
        std::cout << ">>> Step 3: Topological Sort of the Condensation Graph\n";

        std::vector<int> sortedOrder = SCCSolver::topologicalSort(dag);

        std::cout << "Result: Valid topological order of components:\n  ";
        for (size_t i = 0; i < sortedOrder.size(); ++i){
            std::cout << "Comp #" << (sortedOrder[i] + 1);
            if (i < sortedOrder.size() - 1){
                std::cout << " --> ";
            }
        }

        std::cout << "\n\n--------------------------------------------------";
        std::cout << "\nAlgorithm Performance (SCC Search): ";
        std::cout << std::fixed << std::setprecision(4) << duration.count() << " ms";
        std::cout << "\n--------------------------------------------------";

        std::cout << "\n\nDone.\n";
    }
    catch (const std::exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}