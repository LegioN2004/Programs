# question 1 graph greedy

### What does the code do?

It assigns colors to the vertices of a graph such that no two adjacent vertices have the same color, using as few colors as possible (greedy approach).

---

### Step-by-step Explanation

```python
V = int(input("Vertices: "))
E = int(input("Edges: "))

# Build adjacency list
graph = [[] for _ in range(V)]
print("Enter edges:")
for _ in range(E):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
```
- **V**: Number of vertices.
- **E**: Number of edges.
- **graph**: Adjacency list representation of the graph.
- The user enters E edges, each as two integers u and v (0-based indexing).

---

```python
# Color assignment
color = [-1] * V
color[0] = 0
```
- **color**: List to store the color assigned to each vertex. -1 means uncolored.
- The first vertex (vertex 0) is assigned color 0.

---

```python
for u in range(1, V):
    used = {color[v] for v in graph[u] if color[v] != -1}
    c = 0
    while c in used:
        c += 1
    color[u] = c
```
- For each vertex u (from 1 to V-1):
    - **used**: Set of colors already used by its neighbors.
    - **c**: Start from color 0, increment until you find a color not used by neighbors.
    - Assign the found color to vertex u.

---

```python
# Output
print("\nVertex -> Color")
for i in range(V):
    print(f"{i} -> {color[i]}")
```
- Prints the color assigned to each vertex.

---

### Example

Suppose you have the following graph:

- Vertices: 4
- Edges: 5
- Edges entered:
    ```
    0 1
    0 2
    1 2
    1 3
    2 3
    ```

#### Step-by-step coloring:

1. **Vertex 0**: Assign color 0.
2. **Vertex 1**: Neighbors: 0. Used colors: {0}. Assign color 1.
3. **Vertex 2**: Neighbors: 0, 1. Used colors: {0, 1}. Assign color 2.
4. **Vertex 3**: Neighbors: 1, 2. Used colors: {1, 2}. Assign color 0 (since 0 is not used by its neighbors).

#### Output:
```
Vertex -> Color
0 -> 0
1 -> 1
2 -> 2
3 -> 0
```

---

### Summary

- The code colors each vertex with the smallest possible color not used by its neighbors.
- It works for any undirected graph and is a standard greedy solution for the graph coloring problem.  
- The number of colors used may not be minimum for all graphs, but it is efficient and simple.

Let me know if you want a different example or further details!---

### Summary

- The code colors each vertex with the smallest possible color not used by its neighbors.
- It works for any undirected graph and is a standard greedy solution for the graph coloring problem.  
- The number of colors used may not be minimum for all graphs, but it is efficient and simple.

Let me know if you want a different example or further details!