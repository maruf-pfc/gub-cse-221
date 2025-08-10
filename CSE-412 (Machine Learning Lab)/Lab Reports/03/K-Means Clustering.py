import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs

class KMeansClustering:
    """
    A K-Means clustering algorithm implemented in an object-oriented way.
    """
    def __init__(self, k=3, max_iters=100, random_state=42):
        """
        Initializes the K-Means model.

        Args:
            k (int): The number of clusters to form.
            max_iters (int): The maximum number of iterations for the algorithm.
            random_state (int): Seed for the random number generator for reproducibility.
        """
        self.k = k
        self.max_iters = max_iters
        self.random_state = random_state
        # List of sample indices for each cluster
        self.clusters = [[] for _ in range(self.k)]
        # The centers (mean vector) for each cluster
        self.centroids = []

    def _euclidean_distance(self, p1, p2):
        """Helper function to calculate the distance between two points."""
        return np.sqrt(np.sum((p1 - p2)**2))

    def fit(self, X):
        """
        Trains the K-Means model on the input data X.

        Args:
            X (np.ndarray): The training data of shape (n_samples, n_features).
        """
        n_samples, n_features = X.shape

        # 1. Initialize centroids randomly from the dataset
        np.random.seed(self.random_state)
        random_sample_idxs = np.random.choice(n_samples, self.k, replace=False)
        self.centroids = [X[idx] for idx in random_sample_idxs]

        # Main optimization loop
        for _ in range(self.max_iters):
            # 2. Assignment Step: Assign samples to the closest centroids
            self.clusters = self._create_clusters(X)

            # 3. Update Step: Calculate new centroids from the clusters
            old_centroids = self.centroids
            self.centroids = self._get_new_centroids(X)

            # 4. Convergence Check: Check if centroids have converged
            if self._has_converged(old_centroids):
                break

    def predict(self, X):
        """
        Predicts the cluster label for each sample in X using the learned centroids.

        Args:
            X (np.ndarray): New data to predict.

        Returns:
            np.ndarray: An array of cluster labels for each sample.
        """
        # Re-assign points to the final learned clusters
        clusters = self._create_clusters(X)
        
        # Create an array to hold the label for each sample
        labels = np.empty(X.shape[0])
        for cluster_idx, cluster in enumerate(clusters):
            for sample_idx in cluster:
                labels[sample_idx] = cluster_idx
        return labels.astype(int)

    def _create_clusters(self, X):
        """Assigns each sample in X to the nearest centroid."""
        clusters = [[] for _ in range(self.k)]
        for idx, sample in enumerate(X):
            # Find the closest centroid to the current sample
            distances = [self._euclidean_distance(sample, point) for point in self.centroids]
            closest_centroid_idx = np.argmin(distances)
            clusters[closest_centroid_idx].append(idx)
        return clusters

    def _get_new_centroids(self, X):
        """Calculates the new centroids as the mean of the points in each cluster."""
        centroids = np.zeros((self.k, X.shape[1]))
        for cluster_idx, cluster in enumerate(self.clusters):
            # Calculate the mean of the cluster's samples
            cluster_mean = np.mean(X[cluster], axis=0)
            centroids[cluster_idx] = cluster_mean
        return centroids

    def _has_converged(self, old_centroids):
        """Checks if the centroids have stopped moving."""
        distances = [self._euclidean_distance(old_centroids[i], self.centroids[i]) for i in range(self.k)]
        return sum(distances) == 0

# --- Example Usage ---

# 1. Generate sample data using scikit-learn's make_blobs
X, y_true = make_blobs(n_samples=300, centers=3, cluster_std=0.8, random_state=42)

# 2. Instantiate and train our K-Means model
kmeans = KMeansClustering(k=3, max_iters=150, random_state=42)
kmeans.fit(X)

# 3. Get the cluster predictions
y_pred = kmeans.predict(X)

# 4. Visualize the results
plt.figure(figsize=(8, 6))
plt.scatter(X[:, 0], X[:, 1], c=y_pred, s=50, cmap='viridis', label='Data Points')
plt.scatter(kmeans.centroids[:, 0], kmeans.centroids[:, 1], c='red', s=200, marker='X', label='Final Centroids')
plt.title('K-Means Clustering (Object-Oriented Implementation)')
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')
plt.legend()
plt.grid(True)
plt.show()