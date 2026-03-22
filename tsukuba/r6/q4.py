from collections import deque

def bfs(graph, start):
    visited = {start: 0}
    queue = deque([start])

    while queue:
        v = queue.popleft()
        print(v, visited[v])
        for adj in graph[v]:
            if adj not in visited:
                visited[adj] = visited[v] + 1
                queue.append(adj)

graph = {
    0: [1, 2, 4],
    1: [0, 3, 6],
    2: [0, 5],
    3: [1, 7],
    4: [0, 6],
    5: [2, 6, 7],
    6: [1, 4, 5],
    7: [3, 5],
}
bfs(graph, 0)
