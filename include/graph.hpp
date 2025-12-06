#pragma once
#include <vector>
#include <iostream>

class Graph
{
public:
    int V;                                 // number of verices
    std::vector<std::vector<int>> adj;     // adj list
    std::vector<std::vector<int>> rev_adj; // transposed graph adj list

    Graph(int V);
    void addEdge(int u, int v);

    void print() const;
};