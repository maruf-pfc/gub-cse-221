import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class Task2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int s = sc.nextInt();
        int t = sc.nextInt();

        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        while(m-- > 0){
            int u = sc.nextInt();
            int v = sc.nextInt();

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        System.out.println("DFS Traversal:");
        dfs(adj, n, s, t);

        sc.close();
    }

    static void dfs(List<List<Integer>> adj, int n, int s, int t) {
        boolean[] visited = new boolean[n + 1];
        Stack<Integer> stack = new Stack<>();

        visited[s] = true;
        stack.push(s);

        List<Integer> res = new ArrayList<>();

        while(!stack.isEmpty()) {
            int node = stack.peek();
            stack.pop();

            res.add(node);
            if(node == t) {
                break;
            }

            for(int i = 0; i < adj.get(node).size(); i++) {
                int child = adj.get(node).get(i);
                if(!visited[child]) {
                    visited[child] = true;
                    stack.push(child);
                }
            }
        }

        for(int i = 0; i < res.size(); i++) {
            System.out.print(res.get(i) + " ");
        }

        System.out.println();
    }
}

/*
Input:
6 6 1 4
1 2
1 3
2 4
2 5
3 5
4 6

Output:
Adjacency List:
1 -> 2 3
2 -> 1 4 5
3 -> 1 5
4 -> 2 6
5 -> 2 3
6 -> 4
DFS Traversal:
1 3 5 2 4 6
*/

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)