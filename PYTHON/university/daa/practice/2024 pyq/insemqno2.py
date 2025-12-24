# Write a PYTHON program to check whether a given graph is connected or not using the DFS method.

def dfs(graph, visited, v):
    visited[v] = True

    for neighbour in graph[v]:
        if not visited[neighbour]:
            dfs(graph, visited, neighbour)


def is_connected(graph, V):
    visited = [False] * V

    # Start DFS from vertex 0
    dfs(graph, visited, 0)

    # Check if all vertices are visited
    for i in range(V):
        if not visited[i]:
            return False

    return True

graph = {
    0: [1, 2],
    1: [0, 2],
    2: [0, 1, 3],
    3: [2]
}

V = 4


if is_connected(graph, V):
    print("Graph is Connected")
else:
    print("Graph is Not Connected")

# Recompute visited status so we can report per-vertex state
visited = [False] * V
dfs(graph, visited, 0)

for i in range(V):
    print(f"Vertex {i} ---> Visited {visited[i]}")
