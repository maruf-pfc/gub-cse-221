from collections import deque

def bfs(graph, start, goal):
    queue = deque([[start]])
    visited = set([start])
    
    while queue:
        path = queue.popleft()
        node = path[-1]
        
        if node == goal:
            return path
        
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(path + [neighbor])
    
    return None

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

result = bfs(graph, start, goal)
if result:
    print("Path found:", result)
else:
    print("No path found")
