import java.util.*;

class Solution {
    private static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    private boolean detect(int src, List<Integer>[] adj, int[] vis) {
        vis[src] = 1;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(src, -1));

        while (!q.isEmpty()) {
            int node = q.peek().first;
            int parent = q.peek().second;
            q.poll();

            for (int adjacentNode : adj[node]) {
                if (vis[adjacentNode] == 0) {
                    vis[adjacentNode] = 1;
                    q.add(new Pair(adjacentNode, node));
                } else if (parent != adjacentNode) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean isCycle(int V, List<Integer>[] adj) {
        int[] vis = new int[V];

        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                if (detect(i, adj, vis)) {
                    return true;
                }
            }
        }

        return false;
    }
}

public class DetectCycleUsingBFS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int tc = sc.nextInt();
        while (tc-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();
            List<Integer>[] adj = new ArrayList[V];
            for (int i = 0; i < V; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                adj[u].add(v);
                adj[v].add(u);
            }
            Solution obj = new Solution();
            boolean ans = obj.isCycle(V, adj);
            if (ans) {
                System.out.println("1");
            } else {
                System.out.println("0");
            }
        }

        sc.close();
    }
}

/*
Input:
1
5 5
0 1
1 2
1 4
2 3
3 4

Output:
1
*/