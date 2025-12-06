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

    // а) Знайти всі сильно зв'язні компоненти
    // Повертає вектор векторів, де кожен внутрішній вектор - це список вершин однієї компоненти
    std::vector<std::vector<int>> findSCCs();

    // б) Побудувати граф конденсації (повертає новий граф, який є DAG)
    // Вхід: список компонентів (результат попереднього кроку)
    Graph buildCondensationGraph(const std::vector<std::vector<int>> &sccs);

    // в) Топологічне сортування
    // Приймає граф (DAG) і повертає вектор вершин у топологічному порядку
    static std::vector<int> topologicalSort(const Graph &dag);
};