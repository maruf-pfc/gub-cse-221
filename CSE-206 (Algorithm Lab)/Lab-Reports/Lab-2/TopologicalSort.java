import java.util.*;

class Solution {
    private static void dfs(int node, int vis[], Stack<Integer> st, ArrayList<ArrayList<Integer>> adj) {
        vis[node] = 1;
        for (int it : adj.get(node)) {
            if (vis[it] == 0)
                dfs(it, vis, st, adj);
        }
        st.push(node);
    }

    // Function to return list containing vertices in Topological order.
    static int[] topoSort(int V, ArrayList<ArrayList<Integer>> adj) {
        int vis[] = new int[V];
        Stack<Integer> st = new Stack<Integer>();
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                dfs(i, vis, st, adj);
            }
        }

        int ans[] = new int[V];
        int i = 0;
        while (!st.isEmpty()) {
            ans[i++] = st.peek();
            st.pop();
        }
        return ans;
    }
}

public class TopologicalSort  {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while(t-- > 0){
            int n, e;

            n = sc.nextInt();
            e = sc.nextInt();

            ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();

            for(int i = 0; i < n; i++) adj.add(new ArrayList<Integer>());
            
            while(e-- > 0){
                int u, v;
                u = sc.nextInt();
                v = sc.nextInt();
                adj.get(u).add(v);
            }

            int[] res = new Solution().topoSort(n, adj);

            for(int node : res){
                System.out.print(node + " ");
            }

            System.out.println();
        }

        sc.close();
    }
}

/*
Input:
1
6 6
5 0
4 0
5 2
2 3
3 1
4 1

Output:
5 4 2 3 1 0
*/