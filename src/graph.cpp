#include "graph.hpp"
#include <iostream>

Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
    rev_adj.resize(V);
}


void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    rev_adj[v].push_back(u);
}


void Graph::print() const{
    std::cout << "Graph Adjacency List:\n";
    for (int i = 0; i < V; ++i){
        std::cout << "[" << i + 1 << "] -> ";
        for (int neighbor : adj[i]){
            std::cout << neighbor + 1 << " ";
        }
        std::cout << "\n";
    }
}
