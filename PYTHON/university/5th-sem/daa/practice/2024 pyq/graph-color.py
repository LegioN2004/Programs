# GREEDY GRAPH COLORING - SHORT VERSION

V = int(input("Vertices: "))
E = int(input("Edges: "))

# Build adjacency list
graph = [[] for _ in range(V)]
print("Enter edges:")
for _ in range(E):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

# Color assignment
color = [-1] * V
color[0] = 0

for u in range(1, V):
    used = {color[v] for v in graph[u] if color[v] != -1}
    c = 0
    while c in used:
        c += 1
    color[u] = c

# Output
print("\nVertex -> Color")
for i in range(V):
    print(f"{i} -> {color[i]}")
