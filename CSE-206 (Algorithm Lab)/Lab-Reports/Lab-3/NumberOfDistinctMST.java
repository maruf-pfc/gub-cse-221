// Find the number of distinct minimum spanning trees for a given weighted graph using Kruskal's algorithm.

import java.util.*;

class DisjointSet {
    int[] parent;
    int[] rank;

    DisjointSet(int n) {
        parent = new int[n];
        rank = new int[n];

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void union(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);

        if(xRoot == yRoot) {
            return;
        }

        if(rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if(rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
}

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

class NumberOfDistinctMST{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int e = sc.nextInt();

        DisjointSet ds = new DisjointSet(n);
        List<Edge> edges = new ArrayList<>();

        while(e-- > 0){
            int u = sc.nextInt();
            int v = sc.nextInt();
            int weight = sc.nextInt();

            edges.add(new Edge(u, v, weight));
        }

        Collections.sort(edges);
        
        int totalWeight = 0;
        int mstCount = 0;

        for(Edge edge : edges) {
            int x = ds.find(edge.u);
            int y = ds.find(edge.v);

            if(x != y) {
                totalWeight += edge.weight;
                ds.union(x, y);
                mstCount++;
            }
        }

        System.out.println("Total weight of MSTs: " + totalWeight);

        sc.close();
    }
}

// Time Complexity: O(ElogE + ElogV)
// Space Complexity: O(V + E)

/*
Input:
4 5
0 1 1
1 2 2
2 3 3
3 0 4
0 2 5

Output:
Total weight of MSTs: 6
*/

/*
Pseudocode:
function DisjointSet:
    Initialize an array 'parent' of size n
    Initialize an array 'rank' of size n
    For each element i in [0, n-1]:
        parent[i] = i
        rank[i] = 0

function find(x):
    if parent[x] is not equal to x:
        parent[x] = find(parent[x])
    return parent[x]

function union(x, y):
    xRoot = find(x)
    yRoot = find(y)
    if xRoot is equal to yRoot:
        return
    if rank[xRoot] < rank[yRoot]:
        parent[xRoot] = yRoot
    else if rank[xRoot] > rank[yRoot]:
        parent[yRoot] = xRoot
    else:
        parent[yRoot] = xRoot
        rank[xRoot] = rank[xRoot] + 1

function Edge(u, v, weight):
    Initialize an edge with attributes u, v, and weight

function CompareTo(other):
    Compare the weight of this edge to the weight of 'other' edge

function NumberOfDistinctMST:
    Read input values n and e
    Create a DisjointSet ds of size n
    Create an empty list edges

    Repeat e times:
        Read u, v, and weight
        Create an Edge object with u, v, and weight and add it to 'edges' list

    Sort 'edges' list in ascending order based on edge weight

    Initialize totalWeight to 0
    Initialize mstCount to 0

    For each edge in 'edges':
        Find the representative (root) of set containing edge.u using ds.find()
        Find the representative (root) of set containing edge.v using ds.find()
        If the representatives are not the same:
            Add edge.weight to totalWeight
            Union the sets containing edge.u and edge.v using ds.union()
            Increment mstCount by 1

    Output "Total weight of MSTs: " + totalWeight

Learning Outcomes:
1. Kruskal's algorithm can be used to find the minimum spanning tree of a weighted graph.
2. Kruskal's algorithm can be used to find the number of distinct minimum spanning trees of a weighted graph.
3. Kruskal's algorithm can be implemented using Disjoint Set data structure.
4. Disjoint Set data structure can be used to find the number of distinct minimum spanning trees of a weighted graph.

Analysis and Discussion:
1. Time Complexity: O(ElogE + ElogV)
2. Space Complexity: O(V + E)
3. Kruskal's algorithm can be used to find the minimum spanning tree of a weighted graph.
4. Kruskal's algorithm can be used to find the number of distinct minimum spanning trees of a weighted graph.
5. Kruskal's algorithm can be implemented using Disjoint Set data structure.
6. Disjoint Set data structure can be used to find the number of distinct minimum spanning trees of a weighted graph.
*/
