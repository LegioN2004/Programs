# Greedy Graph Coloring - Input Based

def graph_coloring(graph, V):
    # Step 1: Initialize all vertices as uncolored
    color = [-1] * V

    # Step 2: Assign first color to first vertex
    color[0] = 0

    # Temporary array to store available colors
    available = [True] * V

    # Step 3: Assign colors to remaining vertices
    for u in range(1, V):
        # Mark colors of adjacent vertices as unavailable
        for v in graph[u]:
            if color[v] != -1:
                available[color[v]] = False

        # Find the first available color
        for c in range(V):
            if available[c]:
                color[u] = c
                break

        # Reset available colors for next vertex
        available = [True] * V

    return color


# -------- MAIN PROGRAM --------

vertices = int(input("Enter number of vertices: "))
edges = int(input("Enter number of edges: "))

# Create adjacency list
graph = {i: [] for i in range(vertices)}

print("Enter edges (u v):")
for _ in range(edges):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)   # Undirected graph

# Perform graph coloring
colors = graph_coloring(graph, vertices)

# Display result
print("\nVertex  ->  Color")
for i in range(vertices):
    print(i, "      ->  ", colors[i])

