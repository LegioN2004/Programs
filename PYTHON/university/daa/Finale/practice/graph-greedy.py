vertices = int(input("vertices: "))
edges = int(input("edges: "))

# adjacency list
graph = [[] for _ in range(vertices)]
print("Enter the edges: ")
for _ in range(edges):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

# color initial set
color = [-1] * vertices
color[0] = 0

# color remove
for _ in range(vertices):
    used = {color[v] for v in graph[u] if color[v] != -1}
    c=0
    while c in used:
        c += 1
    color[u] = c


print("Vertices -> Colors")
for i in range(vertices):
    print(f"{i} -> {color[i]}")
