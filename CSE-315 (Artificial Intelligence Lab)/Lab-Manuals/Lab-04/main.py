class IterativeDeepening:
    def __init__(self):
        self.stack = []
        self.number_of_nodes = 0
        self.depth = 0
        self.max_depth = 0
        self.goal_found = False

    def iterative_deepening(self, adjacency_matrix, destination):
        self.number_of_nodes = len(adjacency_matrix) - 1
        while not self.goal_found:
            self.depth_limited_search(adjacency_matrix, 1, destination)
            self.max_depth += 1
        print(f"\nGoal Found at depth {self.depth}")

    def depth_limited_search(self, adjacency_matrix, source, goal):
        visited = [0] * (self.number_of_nodes + 1)
        self.stack = [source]
        self.depth = 0
        print(f"\nAt Depth {self.max_depth}")
        print(source, end="\t")

        while self.stack:
            element = self.stack[-1]
            destination = 1
            while destination <= self.number_of_nodes:
                if self.depth < self.max_depth:
                    if adjacency_matrix[element][destination] == 1 and not visited[destination]:
                        self.stack.append(destination)
                        visited[destination] = 1
                        print(destination, end="\t")
                        self.depth += 1
                        if goal == destination:
                            self.goal_found = True
                            return
                        element = destination
                        destination = 1
                        continue
                else:
                    break
                destination += 1
            if self.stack:
                popped = self.stack.pop()
                self.depth -= 1
                destination = popped + 1

if __name__ == "__main__":
    try:
        print("Enter the number of nodes in the graph:")
        number_of_nodes = int(input())
        adjacency_matrix = [[0] * (number_of_nodes + 1) for _ in range(number_of_nodes + 1)]

        print("Enter the adjacency matrix:")
        for i in range(1, number_of_nodes + 1):
            row = list(map(int, input().split()))
            if len(row) != number_of_nodes:
                raise ValueError("Each row must have exactly", number_of_nodes, "elements.")
            adjacency_matrix[i][1:] = row

        print("Enter the destination for the graph:")
        destination = int(input())

        id_search = IterativeDeepening()
        id_search.iterative_deepening(adjacency_matrix, destination)

    except ValueError:
        print("Wrong Input format")

'''
Enter the number of nodes in the graph
7
Enter the adjacency matrix
0 1 1 0 0 0 0
0 0 0 1 1 0 0
0 0 0 0 0 1 1
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
Enter the destination for the graph
7

At Depth 0
1
At Depth 1
1       2       3
At Depth 2
1       2       4       5       3       6       7
Goal Found at depth 2
'''