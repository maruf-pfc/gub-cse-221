def dfs_with_limit(graph, start, goal, depth_limit, visited=None):
    if visited is None:
        visited = set()
    
    if depth_limit == 0:
        if start == goal:
            return [start]
        return None

    visited.add(start)

    for neighbor in graph[start]:
        if neighbor not in visited:
            path = dfs_with_limit(graph, neighbor, goal, depth_limit - 1, visited)
            if path:
                return [start] + path
    
    return None

def iterative_deepening_search(graph, start, goal):
    depth = 0
    while True:
        print(f"Searching at depth {depth}...")
        path = dfs_with_limit(graph, start, goal, depth)
        if path:
            return path
        depth += 1

graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

start = 'A'
goal = 'F'

result = iterative_deepening_search(graph, start, goal)
if result:
    print("Path found:", result)
else:
    print("No path found")
