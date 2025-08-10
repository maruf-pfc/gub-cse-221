def dfs_iterative(graph, start):
    visited = set()
    stack = [start]

    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            print(vertex, end=' ')
            visited.add(vertex)
            # Add neighbors in reverse order to visit in correct order
            stack.extend(reversed(graph[vertex]))

# Example graph (directed graph)
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

print("Iterative DFS traversal starting from node 'A':")
dfs_iterative(graph, 'A')
print()