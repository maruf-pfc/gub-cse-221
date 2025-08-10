class GraphColoring:
    def __init__(self):
        self.V = 0
        self.num_of_colors = 0
        self.color = []
        self.graph = []

    def graph_color(self, g, noc):
        self.V = len(g)
        self.num_of_colors = noc
        self.color = [0] * self.V
        self.graph = g
        try:
            self.solve(0)
            print("No solution")
        except Exception as e:
            print("\nSolution exists")
            self.display()

    def solve(self, v):
        # base case - solution found
        if v == self.V:
            raise Exception("Solution found")

        # try all colors
        for c in range(1, self.num_of_colors + 1):
            if self.is_possible(v, c):
                self.color[v] = c
                self.solve(v + 1)
                self.color[v] = 0  # backtrack

    def is_possible(self, v, c):
        for i in range(self.V):
            if self.graph[v][i] == 1 and self.color[i] == c:
                return False
        return True

    def display(self):
        text_color = [
            "",
            "RED", "GREEN", "BLUE", "YELLOW", "ORANGE",
            "PINK", "BLACK", "BROWN", "WHITE", "PURPLE", "VIOLET"
        ]
        print("\nColors :", end=" ")
        for i in range(self.V):
            print(text_color[self.color[i]], end=" ")
        print()

if __name__ == "__main__":
    print("Graph Coloring Algorithm Test\n")
    V = int(input("Enter number of vertices: "))
    print("Enter adjacency matrix:")
    graph = []
    for i in range(V):
        row = list(map(int, input().split()))
        if len(row) != V:
            raise ValueError("Matrix row must have same number of elements as vertices.")
        graph.append(row)

    c = int(input("Enter number of colors: "))
    gc = GraphColoring()
    gc.graph_color(graph, c)

'''
Graph Coloring Algorithm Test

Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
Enter number of colors: 3

Solution exists 
Colors : RED GREEN BLUE GREEN 
'''