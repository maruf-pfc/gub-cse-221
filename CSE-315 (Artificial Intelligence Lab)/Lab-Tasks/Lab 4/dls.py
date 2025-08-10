def dls(graph, start, goal, depth_limit):
    if start == goal:
        return [start]
    
    if depth_limit == 0:
        return None
    
    for neighbor in graph[start]:
        path = dls(graph, neighbor, goal, depth_limit - 1)
        if path:
            return [start] + path
    
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
depth_limit = 3

result = dls(graph, start, goal, depth_limit)
if result:
    print("Path found:", result)
else:
    print("No path found within the depth limit")
