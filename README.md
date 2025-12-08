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


#### 5. Testing different input files
To test different input files, change the filename in the 14th line in the ```main.cpp``` file. For example changing input file to ```input_1.txt```:

```powershell
std::string filename = "data/input_1.txt";
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




