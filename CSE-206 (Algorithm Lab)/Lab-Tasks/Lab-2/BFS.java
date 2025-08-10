import java.util.LinkedList;
import java.util.Queue;

public class BFS {
    private int V;
    private LinkedList<Integer> adj[];
    private Queue<Integer> q;

    BFS(int v){
        V = v;
        adj = new LinkedList[v];

        for(int i = 0; i < v; i++){
            adj[i]  = new LinkedList<>();
        }
        q = new LinkedList<Integer>();
    }

    void addEdge(int v, int w){
        adj[v].add(w);
    }
    void bfsTraverse(int n){
        boolean nodes[] = new boolean[V];
        int a = 0;

        nodes[0] = true;
        q.add(n);

        while(!q.isEmpty()){
            n = q.poll();
            System.out.println(n + " ");

            for(int i = 0; i < adj[n].size(); i++){
                a = adj[n].get(i);
                if(!nodes[a]){
                    nodes[a] = true;
                    q.add(a);
                }
            }
        }
    }
    public static void main(String[] args) {
        BFS graph = new BFS();
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 2);
        graph.addEdge(2, 0);
        graph.addEdge(2, 3);
        graph.addEdge(3, 4);
        graph.addEdge(4, 5);
        graph.addEdge(5, 6);
        graph.addEdge(6, 7);
        graph.addEdge(7, 8);
        graph.addEdge(8, 9);
        graph.addEdge(9, 10);
        graph.addEdge(10, 11);
        graph.addEdge(11, 12);
        graph.addEdge(12, 13);
        graph.addEdge(13, 14);

        graph.bfsTraverse(0);
    }
}
