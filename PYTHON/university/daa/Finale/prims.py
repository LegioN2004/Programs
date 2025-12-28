# question 2 prim's
import sys


def prim(graph):
    n = len(graph)

    selected = [False] * n  # tracks vertices in MST
    selected[0] = True  # start from vertex 0

    total_cost = 0

    print("Edge : Weight")

    for _ in range(n - 1):
        minimum = sys.maxsize
        x = y = 0

        for i in range(n):
            if selected[i]:
                for j in range(n):
                    if not selected[j] and graph[i][j] != 0:
                        if graph[i][j] < minimum:
                            minimum = graph[i][j]
                            x = i
                            y = j

        print(f"{x} - {y} : {graph[x][y]}")
        total_cost += graph[x][y]
        selected[y] = True

    print("Total cost of MST:", total_cost)


# Example graph
graph = [
    [0, 2, 0, 6, 0],
    [2, 0, 3, 8, 5],
    [0, 3, 0, 0, 7],
    [6, 8, 0, 0, 9],
    [0, 5, 7, 9, 0],
]

prim(graph)
