// Find the number of distinct minimum spanning trees for a given weighted graph.

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

class Edge implements Comparable<Edge> {
    int src, dest, weight;

    public int compareTo(Edge compareEdge) {
        return this.weight - compareEdge.weight;
    }
}

class Graph {
    int V, E;
    Edge[] edge;

    Graph(int v, int e) {
        V = v;
        E = e;
        edge = new Edge[E];
        for(int i = 0; i < e; i++) {
            edge[i] = new Edge();
        }
    }

    int find(int[] parent, int i) {
        if(parent[i] == -1) {
            return i;
        }
        return find(parent, parent[i]);
    }

    void union(int[] parent, int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);

        parent[xset] = yset;
    }

    int kruskalMST() {
        Edge[] result = new Edge[V];
        int e = 0;
        int i = 0;
        for(i = 0; i < V; i++) {
            result[i] = new Edge();
        }

        Arrays.sort(edge);

        int[] parent = new int[V];
        Arrays.fill(parent, -1);

        i = 0;
        while(e < V - 1) {
            Edge nextEdge = new Edge();
            nextEdge = edge[i++];

            int x = find(parent, nextEdge.src);
            int y = find(parent, nextEdge.dest);

            if(x != y) {
                result[e++] = nextEdge;
                union(parent, x, y);
            }
        }

        int minimumCost = 0;
        for(i = 0; i < e; i++) {
            minimumCost += result[i].weight;
        }

        return minimumCost;
    }
}

class KruskalsAlgo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of vertices: ");
        int n = sc.nextInt();
        System.out.print("Enter the number of edges: ");
        int m = sc.nextInt();

        Graph graph = new Graph(n, m);

        System.out.println("Enter the edges: ");
        for(int i = 0; i < m; i++) {
            graph.edge[i].src = sc.nextInt();
            graph.edge[i].dest = sc.nextInt();
            graph.edge[i].weight = sc.nextInt();
        }

        // print number of distinct MSTs
        System.out.println("Number of distinct MSTs: " + graph.kruskalMST());

        sc.close();
    }
}

/*
Input:
4
5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Output:
Number of distinct MSTs: 2
*/