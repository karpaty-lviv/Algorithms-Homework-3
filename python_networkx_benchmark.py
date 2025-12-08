import networkx as nx
import random
import time
import os

NUM_VERTICES = 90000
NUM_EDGES = 100000
OUTPUT_FILE = "data/input_benchmark5.txt"

def generate_and_save_graph():
    print(f"Generating random graph ({NUM_VERTICES} vertices, {NUM_EDGES} edges)")

    edges = []
    for _ in range(NUM_EDGES):
        u = random.randint(1, NUM_VERTICES)
        v = random.randint(1, NUM_VERTICES)
        if u != v:
            edges.append((u, v))

    actual_edges_count = len(edges)

    print(f"Save to {OUTPUT_FILE}")
    with open(OUTPUT_FILE, 'w') as f:
        f.write(f"{NUM_VERTICES} {actual_edges_count}\n")
        for u, v in edges:
            f.write(f"{u} {v}\n")
    return edges

def benchmark_networkx(edges):
    print("Loading graph into NetworkX")
    G = nx.DiGraph()
    G.add_edges_from(edges)

    print(f"Graph loaded. Nodes: {G.number_of_nodes()}, Edges: {G.number_of_edges()}")
    print("Running NetworkX strongly_connected_components")

    start_time = time.perf_counter()
    sccs = list(nx.strongly_connected_components(G))
    end_time = time.perf_counter()


    duration_ms = (end_time - start_time) * 1000

    print("-" * 40)
    print(f"NetworkX Found {len(sccs)} SCCs.")
    print(f"NetworkX Execution Time: {duration_ms:.4f} ms")
    print("-" * 40)

if __name__ == "__main__":
    try:
        edges = generate_and_save_graph()
        benchmark_networkx(edges)
    except KeyboardInterrupt:
        print("\nProcess interrupted.")