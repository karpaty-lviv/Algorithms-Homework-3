# Homework 3. Algorithms on Graphs

## Variant 16: Strongly Connected Components and Graph Condensation

**Problem Statement**

Given a directed graph $G = (V, E)$. The objective is to:

a) Find all **Strongly Connected Components (SCCs)** within the graph.<br>
b) Construct the **condensation graph** (component graph), which is a **Directed Acyclic Graph (DAG)**.<br>
c) Find one valid **topological ordering** (topological sort) of this DAG.

**Input Format**
* The number of vertices.
* A list of directed edges.

**Output Format**
* Partition of vertices into SCCs.
* The edge list of the condensation DAG.
* The topological ordering of the constructed DAG.


Input file format:
first number - number of vertices V
second number - number of edges E
next - list of edges
