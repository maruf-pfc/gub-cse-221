import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class Edge implements Comparable<Edge> {
    int u, v, weight;

    public Edge(int u, int v, int weight) {
        this.u = u;
        this.v = v;
        this.weight = weight;
    }

    @Override
    public int compareTo(Edge other) {
        return Integer.compare(this.weight, other.weight);
    }
}

public class KruskalMSTCount {
    private int V;
    private List<Edge> edges;

    public KruskalMSTCount(int V) {
        this.V = V;
        edges = new ArrayList<>();
    }

    public void addEdge(int u, int v, int weight) {
        edges.add(new Edge(u, v, weight));
    }

    private int find(int[] parent, int vertex) {
        if (parent[vertex] == -1)
            return vertex;
        return find(parent, parent[vertex]);
    }

    private void union(int[] parent, int x, int y) {
        int xRoot = find(parent, x);
        int yRoot = find(parent, y);
        parent[xRoot] = yRoot;
    }

    public int countMSTs() {
        int[] parent = new int[V];
        Arrays.fill(parent, -1);

        Collections.sort(edges);
        int totalWeight = 0;
        int mstCount = 0;

        for (Edge edge : edges) {
            int x = find(parent, edge.u);
            int y = find(parent, edge.v);

            if (x != y) {
                totalWeight += edge.weight;
                union(parent, x, y);
            } else {
                // This edge is part of the MST, but we don't increment mstCount.
                // It will still be counted as one MST.
            }
        }

        return totalWeight;
    }

    public static void main(String[] args) {
        KruskalMSTCount graph = new KruskalMSTCount(4);
        graph.addEdge(0, 1, 1);
        graph.addEdge(1, 2, 2);
        graph.addEdge(2, 3, 3);
        graph.addEdge(3, 0, 4);
        graph.addEdge(0, 2, 5);

        int totalMSTWeight = graph.countMSTs();
        System.out.println("Total weight of the MST: " + totalMSTWeight);
    }
}

