# Import all the necessary libraries
import numpy as np
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score

# 1. Load the Iris dataset
iris = load_iris()
X = iris.data
y = iris.target

# 2. Define the range of K values to test and the number of iterations
k_range = range(1, 26) # We will test K from 1 to 25
n_iterations = 10      # We will average over 10 different splits for each K

# A dictionary to store the average accuracy for each K
k_avg_scores = {}

# 3. Outer loop: Iterate through each value of K
for k in k_range:
    # A temporary list to store accuracies for the current K
    temp_accuracies = []
    
    # 4. Inner loop: Run the experiment 10 times for the current K
    for i in range(n_iterations):
        
        # a. Split the data into a new random train/test set for each iteration
        # Note: We do NOT set random_state here, so the split is different each time
        X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)
        
        # b. Scale the features
        scaler = StandardScaler()
        X_train_scaled = scaler.fit_transform(X_train)
        X_test_scaled = scaler.transform(X_test)
        
        # c. Create and train the KNN model
        knn = KNeighborsClassifier(n_neighbors=k)
        knn.fit(X_train_scaled, y_train)
        
        # d. Make predictions and calculate accuracy
        y_pred = knn.predict(X_test_scaled)
        accuracy = accuracy_score(y_test, y_pred)
        temp_accuracies.append(accuracy)
        
    # 5. Calculate the average accuracy for the current K and store it
    k_avg_scores[k] = np.mean(temp_accuracies)

# 6. Find the best K with the highest average accuracy
best_k = max(k_avg_scores, key=k_avg_scores.get)
best_score = k_avg_scores[best_k]

# 7. Print the results
print("Average accuracy for each K:")
for k, score in k_avg_scores.items():
    print(f"K = {k:2d}: Average Accuracy = {score:.4f}")

print("\n--- Findings ---")
print(f"The most robust K is {best_k} with an average accuracy of {best_score:.4f} over {n_iterations} runs.")