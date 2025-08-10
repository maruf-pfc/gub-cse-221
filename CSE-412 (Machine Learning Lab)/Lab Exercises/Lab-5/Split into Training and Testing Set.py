import numpy as np
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.cluster import KMeans
from sklearn.metrics import accuracy_score, confusion_matrix
import pandas as pd

# Load and prepare data
iris = load_iris()
x = pd.DataFrame(iris.data, columns=['SL','SW','PL','PW'])
y = pd.DataFrame(iris.target, columns=['Target'])

# 1. Split the data
X_train, X_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random_state=42)

# 2. Train the model ON THE TRAINING SET ONLY
kmeans = KMeans(n_clusters=3, random_state=42)
kmeans.fit(X_train)

# 3. Evaluate on the unseen TEST SET
test_predictions_raw = kmeans.predict(X_test)

# Manually align cluster labels to true labels for accuracy calculation
# This alignment might need to change based on your specific run
# Check the confusion matrix of the training set to find the right mapping
# For this example, let's assume the mapping is [1, 0, 2] as before.
test_predictions_aligned = np.choose(test_predictions_raw, [1, 0, 2]).astype(np.int64)

# 4. Calculate performance on the test set
accuracy = accuracy_score(y_test['Target'], test_predictions_aligned)
conf_matrix = confusion_matrix(y_test['Target'], test_predictions_aligned)

print("--- Performance on Test Set ---")
print(f"Accuracy: {accuracy:.4f}")
print("Confusion Matrix:\n", conf_matrix)