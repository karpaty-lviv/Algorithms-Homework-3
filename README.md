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

## Usage

#### 1. Clone the Repository
Clone the project repository to your local machine:

#### 2. Build the Project
If you are on **Windows** (using MinGW), you can use the provided `Makefile` to compile the project. Run the following command in the root directory:

```powershell
mingw32-make
```

#### 3. Run the Application
Once the compilation is complete, launch the executable:

```powershell
.\scc_app.exe
```

Another way to do this is by using ```run``` command

```powershell
mingw32-make run
```


#### 4. Clean the Project
To remove build artifacts (object files and the executable) and clean up your project directory, run:

```powershell
mingw32-make clean
```


#### 5. Testing different input files
To test different input files, change the filename in the 14th line in the ```main.cpp``` file. For example changing input file to ```input_1.txt```:

```powershell
std::string filename = "data/input_1.txt";
```

### For Linux users

On Linux is all the same, but with slitely different commands

```powershell
make
make run
make clean
```

## Input File Format

The input file (`data/input.txt`) must adhere to the following structure:

1.  **Header:** First row containing two integers separated by space:
    * `V`: Number of vertices in the graph.
    * `E`: Number of edges in the graph.
2.  **Edges:** The following `E` lines each contain two integers `u` and `v`, representing a directed edge from vertex `u` to vertex `v`.


## Example Run

Below is the actual output of the program when running the `data/input.txt` test case. This specific graph contains two distinct cycles connected by a bridge vertex.

**Console Output:**

```powershell
Loading graph from file: data/input.txt
--------------------------------------------------

>>> Step 1: Finding Strongly Connected Components (SCCs)
Result: Found 3 strongly connected components.
  Component #1: { 1 3 2 }
  Component #2: { 4 }
  Component #3: { 5 7 6 8 }
--------------------------------------------------

>>> Step 2: Building Condensation Graph (DAG)
Result: Condensation graph created with 3 vertices (components).
Edges between components:
  [Comp #1] -> [Comp #2]
  [Comp #2] -> [Comp #3]
  [Comp #2] -> [Comp #3]
--------------------------------------------------

>>> Step 3: Topological Sort of the Condensation Graph
Result: Valid topological order of components:
  Comp #1 --> Comp #2 --> Comp #3

--------------------------------------------------
Algorithm Performance (SCC Search): 0.0092 ms
--------------------------------------------------

Done.
```


#### Verification

The output confirms the correct execution of the algorithms:

1. **SCC Identification:** The program correctly identified the three expected components:
    * **Cycle A:** `{1, 2, 3}`
    * **Bridge Node:** `{4}`
    * **Complex Cycle B:** `{5, 6, 7, 8}`



<img width="528" height="528" alt="graph_example" src="https://github.com/user-attachments/assets/2db0a27c-6e05-4b3e-af4d-734f7e3dd627" />



2. **Condensation Graph:** The dependencies between these components are correctly mapped as a Directed Acyclic Graph: `C1 -> C2 -> C3`.


<img width="528" height="528" alt="graph_condanstion" src="https://github.com/user-attachments/assets/947d2683-8f3f-4333-8e47-cfcc090e9a99" />


## Implementation Breakdown

### Algorithm Overview: Kosaraju's Algorithm
To identify all **Strongly Connected Components (SCCs)**, I utilized **Kosaraju's Algorithm**. This is a classic and efficient two-pass algorithm based on Depth First Search (DFS).

The core idea relies on the fact that if you transpose a graph (reverse the direction of all edges), the strongly connected components remain the same, but the direction of the "super-edges" between components is reversed. By processing nodes in a specific order (determined by the finish times of a DFS on the original graph), we can isolate each SCC efficiently.

### File Structure

The project is organized into four primary modules:

* **`graph_utils.cpp`**: Handles file I/O and parsing. It contains the logic to read the input file, validate the format, ignore comments, and construct a `Graph` object.
* **`graph.cpp`**: Implements the `Graph` class.
    * **Properties:** Stores the number of vertices (`V`) and two adjacency lists: `adj` (original graph) and `rev_adj` (transposed graph).
    * **Key Method:** `addEdge(u, v)` simultaneously adds a directed edge $u \to v$ to the original graph and $v \to u$ to the transposed graph. This optimization prevents the need to reverse the graph later during runtime.
* **`scc_solver.cpp`**: Contains the core algorithmic logic. It implements the `SCCSolver` class, which uses helper DFS methods (`dfs1` for stack filling and `dfs2` for component gathering) to solve the problem steps.
* **`main.cpp`**: The entry point. It orchestrates the flow: reading data, solving for SCCs, building the condensation graph, performing topological sorting, and printing the results / performance metrics.


### Key Functions & Logic

#### 1. `findSCCs`
This function identifies the strongly connected components using the two-pass approach:
1.  **First Pass (DFS):** The algorithm performs a DFS on the **original graph**. When the recursion for a node and all its descendants finishes (post-order), the node is pushed onto a **stack**. This ensures that nodes are ordered by their finish times.
2.  **Second Pass (Reverse DFS):** The algorithm processes nodes by popping them from the stack. If a node has not been visited in this pass, it initiates a new DFS (using `dfs2`) on the **transposed graph**.
3.  **Collection:** Because the graph edges are reversed, this second DFS cannot leave the current SCC. All nodes reachable in this pass form exactly one strongly connected component.

#### 2. `buildCondensationGraph`
This method constructs a new graph (a DAG) where every vertex represents an entire SCC from the original graph.
* It creates a mapping array `component_id` to track which SCC each original vertex belongs to.
* It iterates through all edges of the original graph. If an edge connects two vertices that belong to **different** components, a directed edge is added between those component IDs in the new graph.
* **Result:** The output is a Directed Acyclic Graph (DAG) representing the dependencies between components.

#### 3. `topologicalSort`
This function determines a linear ordering of the vertices in the Condensation Graph (DAG) such that for every directed edge $u \to v$, vertex $u$ comes before $v$ in the ordering.
* **Method:** It uses a DFS-based approach.
* **Logic:** When the DFS visits a node, it recursively visits all unvisited neighbors first. Only after all neighbors are processed is the current node added to a list.
* **Result:** This produces a list in *reverse topological order* (children appear before parents). Finally, the list is reversed using `std::reverse` to produce the correct topological sort.


## Performance Comparison

To evaluate the efficiency of the algorithm, I conducted a series of benchmarks comparing this C++ implementation against the popular Python library `networkx`. 

A Python script was used to generate random directed graphs of varying sizes and measure the execution time for finding Strongly Connected Components (SCCs).

### Benchmark Results

| Input File | Vertices | My C++ Implementation | Python `networkx` |
| :--- | :--- | :--- | :--- |
| `input_benchmark1.txt` | 1,000 | **0.44 ms** | 9.37 ms |
| `input_benchmark2.txt` | 10,000 | **2.18 ms** | 96.61 ms |
| `input_benchmark3.txt` | 50,000 | **15.39 ms** | 334.14 ms |
| `input_benchmark4.txt` | 70,000 | **17.13 ms** | 470.42 ms |
| `input_benchmark5.txt` | 90,000 | **27.22 ms** | 592.58 ms |

### Conclusion

The results demonstrate that the native C++ implementation is consistently **over 20 times faster** than the Python `networkx` equivalent.
