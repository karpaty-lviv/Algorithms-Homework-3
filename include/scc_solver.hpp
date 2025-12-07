#pragma once
#include "graph.hpp"
#include <vector>
#include <stack>

class SCCSolver
{
private:
    const Graph &graph;
    std::vector<bool> visited;
    std::stack<int> stack;

    void dfs1(int v);
    void dfs2(int v, std::vector<int> &component, const std::vector<std::vector<int>> &adj);

public:
    SCCSolver(const Graph &g);

    // а) Find all Strigly Connected Components
    // Return vector of vectors, where each vector represents the verices belonging to one SCC
    std::vector<std::vector<int>> findSCCs();

    // б) Build a condensation graph
    // returns new DAG graph
    Graph buildCondensationGraph(const std::vector<std::vector<int>> &sccs);

    // в) Topological sort
    // Topological sort of a DAG graph
    static std::vector<int> topologicalSort(const Graph &dag);
};