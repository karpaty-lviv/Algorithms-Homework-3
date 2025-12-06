#include "scc_solver.hpp"
#include <vector>
#include <stack>

SCCSolver::SCCSolver(const Graph &g) : graph(g){
    visited.resize(g.V, false);
}

void SCCSolver::dfs1(int v){
    visited[v] = true;

    for (int neighbor : graph.adj[v]){
        if (!visited[neighbor]){
            dfs1(neighbor);
        }
    }
    stack.push(v);
}

void SCCSolver::dfs2(int v, std::vector<int> &component, const std::vector<std::vector<int>> &adj){
    visited[v] = true;
    component.push_back(v);
    for (int neighbor : adj[v]){
        if (!visited[neighbor]){
            dfs2(neighbor, component, adj);
        }
    }
}

std::vector<std::vector<int>> SCCSolver::findSCCs()
{
    std::vector<std::vector<int>> result;
    std::fill(visited.begin(), visited.end(), false);
    for (int i = 0; i < visited.size(); i++){
        if (!visited[i]){
            dfs1(i);
        }
    }
    std::fill(visited.begin(), visited.end(), false);
    while (!stack.empty()){
        int v = stack.top();
        stack.pop();
        if (!visited[v]){
            std::vector<int> component;
            dfs2(v, component, graph.rev_adj);
            result.push_back(component);
        }
    }
    return result;
}

Graph SCCSolver::buildCondensationGraph(const std::vector<std::vector<int>> &sccs){
    int K = sccs.size(); // number of sccs
    Graph dag(K);

    std::vector<int> component_id(graph.V);

    for (int i = 0; i < K; i++){
        for (int u : sccs[i]){
            component_id[u] = i;
        }
    }

    for (int u = 0; u < graph.V; u++){
        for (int v : graph.adj[u]){
            int u_comp = component_id[u];
            int v_comp = component_id[v];
            if (u_comp != v_comp){
                dag.addEdge(u_comp, v_comp);
            }
        }
    }
    return dag;
}