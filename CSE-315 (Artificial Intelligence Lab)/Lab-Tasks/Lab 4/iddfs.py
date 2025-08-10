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

def iddfs(graph, start, goal):
    depth = 0
    while True:
        print(f"Searching at depth {depth}...")
        path = dls(graph, start, goal, depth)
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

result = iddfs(graph, start, goal)
if result:
    print("Path found:", result)
else:
    print("No path found")
