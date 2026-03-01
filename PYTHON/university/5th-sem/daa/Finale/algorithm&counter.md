# Graph Coloring Algorithm - Complete Guide

## What is Graph Coloring?

Graph coloring is the problem of assigning colors to vertices of a graph such that **no two adjacent vertices have the same color**. The minimum number of colors needed is called the **chromatic number**. The greedy approach doesn't always guarantee the minimum colors but provides a practical solution.

## Applications
- **Scheduling problems**: Assigning time slots to exams without conflicts
- **Register allocation**: In compilers for CPU register management
- **Map coloring**: Coloring countries on a map where adjacent countries need different colors
- **Sudoku solving**: Each row/column/box is a clique needing different numbers

## Formal Algorithm

```
Algorithm: GREEDY_GRAPH_COLORING(Graph G, V vertices)

Input: Graph G with V vertices and adjacency list adj[]
Output: Color assignment for each vertex

1. Initialize result[] array with -1 for all vertices
    result[i] = -1 for i = 0 to V-1
    
2. Assign first color to first vertex
    result[0] = 0
    
3. Create available[] array of size V, initialized to TRUE
    available[i] = TRUE for i = 0 to V-1
    
4. FOR each vertex u from 1 to V-1 DO:
    
    4.1. FOR each adjacent vertex i of u DO:
              IF result[i] ≠ -1 THEN
                  available[result[i]] = FALSE
          END FOR
    
    4.2. Find the first available color
          cr = 0
          WHILE cr < V DO:
              IF available[cr] == TRUE THEN
                  BREAK
              cr = cr + 1
          END WHILE
    
    4.3. Assign the found color
          result[u] = cr
    
    4.4. Reset available[] for next iteration
          FOR each adjacent vertex i of u DO:
              IF result[i] ≠ -1 THEN
                  available[result[i]] = TRUE
          END FOR
          
5. RETURN result[]
```

## Working Example

Let's trace the algorithm with this graph:
```
Vertices: 5 (0,1,2,3,4)
Edges: (0,1), (0,2), (1,2), (1,3), (2,3), (3,4)

Adjacency List:
0: [1, 2]
1: [0, 2, 3]
2: [0, 1, 3]
3: [1, 2, 4]
4: [3]
```

**Step-by-step execution:**

| Vertex | Neighbors | Colors Used by Neighbors | Assigned Color |
|--------|-----------|-------------------------|----------------|
| 0 | - | - | 0 (first vertex) |
| 1 |  | {0} | 1 |
| 2 | [5] | {0, 1} | 2 |
| 3 | [5][6] | {1, 2} | 0 |
| 4 | [7] | {0} | 1 |

**Result:** Colors =, **Chromatic number = 3**

## Time Complexity Using Counter Method

Let me count operations for each part of the algorithm:

### Initialization Phase
```python
result = [-1] * V              # V assignments: O(V)
result[0] = 0                  # 1 assignment: O(1)
available = [False] * V        # V assignments: O(V)
```
**Count: 2V + 1 operations**

### Main Loop Analysis
```python
for u in range(1, V):          # Runs (V-1) times
```

For each vertex u:

**Step 1: Mark neighbors' colors as unavailable**
```python
for i in adj[u]:
     if result[i] != -1:
          available[result[i]] = False
```
- Let deg(u) = degree of vertex u
- Operations per vertex: deg(u) comparisons + deg(u) assignments
- **Count: 2 × deg(u)**

**Step 2: Find first available color**
```python
cr = 0
while cr < V:
     if available[cr] == False:
          break
     cr += 1
```
- Worst case: checks all V colors
- **Count: O(V) comparisons**

**Step 3: Assign color**
```python
result[u] = cr
```
- **Count: 1 assignment**

**Step 4: Reset available array**
```python
for i in adj[u]:
     if result[i] != -1:
          available[result[i]] = True
```
- **Count: 2 × deg(u)**

### Total Operations per Vertex u
```
Operations = 2×deg(u) + V + 1 + 2×deg(u)
              = 4×deg(u) + V + 1
```

### Total for All Vertices
```
Total = Σ(u=1 to V-1) [4×deg(u) + V + 1]

        = 4 × Σ deg(u) + (V-1)×V + (V-1)
```

By **Handshaking Lemma**: Σ deg(u) = 2E

```
Total = 4×(2E) + V² - V + V - 1
        = 8E + V² - 1
        = O(V² + E)
```

### In Terms of Adjacency Representation

**For Adjacency List:**
- Each edge is visited constant times
- **Time Complexity: O(V² + E)** in worst case
- **Practical case: O(V + E)** when edges are sparse

**For Adjacency Matrix:**
- Checking all neighbors takes O(V) for each vertex
- **Time Complexity: O(V²)**

## Space Complexity

```
result[] array:     O(V)
available[] array:  O(V)
Adjacency list:     O(V + E)
Total:              O(V + E)
```

## Key Properties

1. **Greedy doesn't guarantee minimum colors**: The chromatic number might be less than what greedy produces
2. **Vertex order matters**: Different orderings can produce different results
3. **Upper bound**: Greedy uses at most Δ+1 colors (where Δ = maximum degree)
4. **Fast and practical**: Much better than brute force O(k^V) where k is number of colors

## Summary Table

| Aspect | Value |
|--------|-------|
| Time Complexity | O(V² + E) worst case |
| Space Complexity | O(V + E) |
| Optimality | Not guaranteed |
| Colors Used | ≤ Δ + 1 (Δ = max degree) |
| Best for | Sparse graphs, quick approximations |

The greedy graph coloring algorithm is widely used in competitive programming and real-world applications where a quick, reasonable solution is more valuable than the absolute optimal one.
