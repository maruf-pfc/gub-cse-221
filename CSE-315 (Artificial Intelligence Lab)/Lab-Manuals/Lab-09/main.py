import random
import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.cl = -1  # cluster assignment

    def set_cluster(self, cl):
        self.cl = cl


class St:
    def __init__(self, num_points, num_clusters):
        self.pt = num_points
        self.ks = num_clusters
        self.p = []
        self.k = []
        self.fkc = []  # Final cluster list
        self.rand = random.Random()
        self.start()

    def start(self):
        # Initialize points randomly
        self.p = [Point(self.rand.randint(0, self.pt), self.rand.randint(0, self.pt)) for _ in range(self.pt)]

        # Initialize cluster centers randomly
        self.k = [Point(self.rand.randint(0, self.pt), self.rand.randint(0, self.pt)) for _ in range(self.ks)]

        count = 0
        while True:
            # Assign points to the nearest cluster
            for i in range(self.pt):
                min_dist = float('inf')
                for j in range(self.ks):
                    d1 = math.sqrt((self.k[j].x - self.p[i].x) ** 2 + (self.k[j].y - self.p[i].y) ** 2)
                    if d1 < min_dist:
                        self.p[i].set_cluster(j)
                        min_dist = d1

            # Duplicate cluster centers
            kdup = [Point(k.x, k.y) for k in self.k]

            # Update cluster centers based on the mean of assigned points
            for j in range(self.ks):
                x_sum = y_sum = count_in_cluster = 0
                for i in range(self.pt):
                    if self.p[i].cl == j:
                        x_sum += self.p[i].x
                        y_sum += self.p[i].y
                        count_in_cluster += 1
                if count_in_cluster > 0:
                    self.k[j].x = x_sum // count_in_cluster
                    self.k[j].y = y_sum // count_in_cluster

            # Calculate error between old and new cluster centers
            err = sum(abs(self.k[i].x - kdup[i].x) + abs(self.k[i].y - kdup[i].y) for i in range(self.ks))
            count += 1
            if err == 0:
                break

        # Calculate intra-cluster distance
        for i in range(self.ks):
            intra_dist = 0.0
            for j in range(self.pt):
                if self.p[j].cl == i:
                    intra_dist += math.sqrt((self.k[i].x - self.p[j].x) ** 2 + (self.k[i].y - self.p[j].y) ** 2)
            print(f"Cluster {i + 1} Intra-distance = {intra_dist}")

        # Print point assignments
        for i in range(self.ks):
            for j in range(self.pt):
                if self.p[j].cl == i:
                    print(f"Point ({self.p[j].x}, {self.p[j].y}) Cluster - {self.p[j].cl + 1}")

        # Separate points by cluster
        self.differ_class()

    def differ_class(self):
        kval = [0] * self.ks
        for i in range(self.pt):
            kval[self.p[i].cl] += 1

        for i in range(self.ks):
            cluster_points = []
            for j in range(self.pt):
                if self.p[j].cl == i:
                    cluster_points.append(self.p[j])
            self.fkc.append(cluster_points)
        print()


if __name__ == "__main__":
    points = int(input("Insert number of points: "))
    clusters = int(input("Insert number of clusters: "))
    St(points, clusters)
