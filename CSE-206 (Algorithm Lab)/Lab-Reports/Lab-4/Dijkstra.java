import java.util.*;

public class Dijkstra {
    static final long infLL = 9000000000000000000L;
    static final int mx = 100005;

    static List<List<Pair>> adj = new ArrayList<>();
    static long[] dist = new long[mx];

    static class Pair {
        int first;
        long second;

        Pair(int first, long second) {
            this.first = first;
            this.second = second;
        }
    }

    static void dijkstra(int s, int n) {
        for (int i = 0; i <= n; i++) {
            dist[i] = infLL;
        }
        dist[s] = 0;
        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingLong(p -> p.second));
        pq.add(new Pair(s, 0));

        while (!pq.isEmpty()) {
            int u = pq.poll().first;
            long d = dist[u];

            if (d > dist[u]) continue;

            for (Pair it : adj.get(u)) {
                int v = it.first;
                long w = it.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.add(new Pair(v, dist[v]));
                }
            }
        }
    }

    static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int e = sc.nextInt();

        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < e; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            adj.get(u).add(new Pair(v, w));
        }

        dijkstra(0, n);

        for (int i = 0; i < n; i++) {
            System.out.println(i + " --> " + dist[i]);
        }
        System.out.println();

        sc.close();
    }

    public static void main(String[] args) {
        int t = 1;
        for (int i = 1; i <= t; i++) {
            solve();
        }
    }
}
