import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;
class points {
    int x, y, cl;
    points(int x, int y) {
        this.x = x;
        this.y = y;
    } // points on the grid (x,y)
    void setClass(int c) {
        cl = c;
    } // cluster number in which this (x,y) point reside
}
class St {
    int pt, ks;
    // pt is the number of points and ks is the number of clusters
    points[] p, k;
    ArrayList < points[] > fkc;
    Random rand = new Random();
    St(int points, int clusters) {
        pt = points;
        ks = clusters;
        fkc = new ArrayList < points[] > ();
        Start();
    }
    void Start() {
        p = new points[pt]; // create random points coordinate
        for (int i = 0; i < pt; i++) {
            int x = rand.nextInt(pt);
            int y = rand.nextInt(pt);
            p[i] = new points(x, y);
        }
        k = new points[ks]; // create random cluster points coordinate
        for (int i = 0; i < ks; i++) {
            int x = rand.nextInt(pt);
            int y = rand.nextInt(pt);
            k[i] = new points(x, y);
        }
        int i, j;
        double min;
        int count = 0;
        while (true) {
            // starting cluster allocation of point p(x,y) based on minimum distance from each cluster points
            for (i = 0; i < pt; i++) {
                for (j = 0, min = 10000; j < ks; j++) {
                    double d1 = Math.sqrt(Math.pow((double)(k[j].x - p[i].x), 2) + Math.pow((double)(k[j].y - p[i].y), 2));
                    if (d1 < min) {
                        p[i].setClass(j);
                        min = d1;
                    }
                }
            }
            points[] kdup = new points[ks];
            // creating duplicate set of cluster points to store starting cluster coordinates
            for (i = 0; i < ks; i++) {
                kdup[i] = new points(k[i].x, k[i].y);
            }
            // calculating mean for each points in different clusters
            for (j = 0; j < ks; j++) {
                int x = 0, y = 0, ci = 0;
                for (i = 0; i < pt; i++) {
                    if (p[i].cl == j) {
                        x += p[i].x;
                        y += p[i].y;
                        ci++;
                    }
                }
                if (ci != 0) { // allocating the mean as new cluster point coordinate
                    k[j].x = x / ci;
                    k[j].y = y / ci;
                }
            }
            int err = 0;
            // claculating error between previous and present cluster points coordinates
            for (i = 0; i < ks; i++) {
                err += (k[i].x - kdup[i].x) + (k[i].y - kdup[i].y);
            }
            count++;
            // 0 error between previous and present cluster points coordinates indicates clustring is finalized

            if (err == 0) {
                break;
            }
        }
        double IntraDis;
        for (i = 0; i < ks; i++) {
            for (j = 0, IntraDis = 0; j < pt; j++) {
                if (p[j].cl == i) {
                    IntraDis += Math.sqrt(Math.pow((double)(k[i].x - p[j].x),
                        2) + Math.pow((double)(k[i].y - p[j].y), 2));
                }
            }
            System.out.println("Cluster " + (i + 1) + " Intra-distance = " +
                IntraDis);
        }
        for (i = 0; i < ks; i++) {
            for (j = 0; j < p.length; j++) {
                if (p[j].cl == i) {
                    System.out.println("Point (" + p[j].x + ", " + p[j].y + ") " + " Cluster - " + (+p[j].cl + 1));
                }
            }
        }
        //System.out.println("count " + count);
        differClass();
        // print a 2D graph alike matrix showing the points and its cluster
        //printGrapgh();
    }
    void differClass() {
        int kval[] = new int[ks];
        int i, j, k;
        for (i = 0; i < pt; i++) {
            kval[p[i].cl]++;
        }
        for (i = 0; i < ks; i++) {
            points[] c1 = new points[kval[i]];
            for (j = 0, k = 0; j < pt; j++) {
                if (p[j].cl == i) {
                    c1[k++] = p[j];
                }
            }
            fkc.add(c1);
            //System.out.println(kval[i]);
        }
        //System.out.println(fkc.size());
        System.out.println();
    }
}

public class K_Means {
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        System.out.println("Insert number of points");
        int points = sc.nextInt();
        System.out.println("Insert number of clusters");
        int clusters = sc.nextInt();
        St s = new St(points, clusters);
    }

}