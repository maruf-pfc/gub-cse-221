def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    print(start, end=' ')
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)
    return visited

# Example usage:
graph = {
    1: [2, 4],
    2: [1, 3],
    3: [2, 5],
    4: [1, 5],
    5: [3, 4]
}

print("DFS traversal starting from node 1:")
dfs(graph, 1)
print()