import numpy as np
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn import metrics

def find_best_ratio_iris():
    iris = load_iris()
    X_iris = iris.data
    y_iris = iris.target

    # Use an optimal K value. Based on Exercise 1, a K around 12 is a good choice.
    best_k = 14
    print(f"Running experiments with a fixed K={best_k}.\n")

    # Define a range of test set sizes to evaluate (e.g., 10%, 20%, ..., 50%)
    test_sizes = [0.1, 0.2, 0.3, 0.4, 0.5]
    
    # Dictionary to store the average accuracy for each ratio
    ratio_accuracies = {}

    # Loop over each test size
    for size in test_sizes:
        accuracies = []
        # Repeat the experiment 10 times for each ratio for stable results
        for i in range(10):
            # Split data with the current test size and a different random_state
            X_train, X_test, y_train, y_test = train_test_split(X_iris, y_iris, test_size=size, random_state=i)

            # Scale the features
            scaler = StandardScaler()
            X_train_scaled = scaler.fit_transform(X_train)
            X_test_scaled = scaler.transform(X_test)

            # Initialize and train the KNN classifier with the fixed K
            knn = KNeighborsClassifier(n_neighbors=best_k)
            knn.fit(X_train_scaled, y_train)

            # Predict and calculate accuracy
            y_pred = knn.predict(X_test_scaled)
            accuracies.append(metrics.accuracy_score(y_test, y_pred))

        # Calculate the average accuracy for the current ratio
        train_percent = int((1 - size) * 100)
        test_percent = int(size * 100)
        ratio_key = f"{train_percent}/{test_percent}"
        ratio_accuracies[ratio_key] = np.mean(accuracies)

    # print("Average accuracy for different train/test ratios on Iris Dataset:")
    for ratio, acc in ratio_accuracies.items():
        print(f"Ratio (Train/Test) = {ratio}: Average Accuracy = {acc:.4f}")

    # Find and print the best ratio
    best_ratio = max(ratio_accuracies, key=ratio_accuracies.get)
    print(f"\nThe best train/test ratio is {best_ratio} with an average accuracy of {ratio_accuracies[best_ratio]:.4f}.")

if __name__ == '__main__':
    find_best_ratio_iris()