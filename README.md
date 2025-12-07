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

```bash
git clone <your-repository-url-here>
cd <your-project-folder-name>
```

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

#### 4. Clean the Project
To remove build artifacts (object files and the executable) and clean up your project directory, run:

```powershell
mingw32-make clean
```



## Input File Format

The input file (`data/input.txt`) must adhere to the following structure:

1.  **Header:** First row containing two integers separated by space:
    * `V`: Number of vertices in the graph.
    * `E`: Number of edges in the graph.
2.  **Edges:** The following `E` lines each contain two integers `u` and `v`, representing a directed edge from vertex `u` to vertex `v`.
