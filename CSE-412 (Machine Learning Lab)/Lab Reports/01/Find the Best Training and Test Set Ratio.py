import pandas as pd
import numpy as np

# Create some sample data
data = {
    'hours_studied': np.random.uniform(1, 20, 150).round(1),
    'attendance_pct': np.random.uniform(50, 100, 150).round(1),
}
df = pd.DataFrame(data)

# Create a simple rule for the target variable 'passed_exam'
# 1 = Passed, 0 = Failed
# Let's say passing depends on a combination of studying and attendance
df['passed_exam'] = np.where( (df['hours_studied'] + df['attendance_pct']/5) > 30, 1, 0)

# Save the DataFrame to a CSV file
file_name = 'student_performance.csv'
df.to_csv(file_name, index=False)

# print(f"Successfully created the sample dataset file: '{file_name}'")
print("First 5 rows of the new dataset:")
print(df.head())

import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score

# --- Part A: Find the Best K for the new dataset ---

# 1. Load the data from the CSV file we created
try:
    df = pd.read_csv('student_performance.csv')
except FileNotFoundError:
    print("Error: 'student_performance.csv' not found. Please run the code from Step 1 first.")
    # Exit or handle error appropriately
    exit()

# 2. Separate features (X) and the target (y)
features = ['hours_studied', 'attendance_pct']
target = 'passed_exam'
X = df[features].values
y = df[target].values

# Find the best K by averaging over 10 runs
k_range = range(1, 20)
n_iterations = 10
k_avg_scores = {}

# print("\n--- Starting Part A: Finding the best K for the new dataset ---")

for k in k_range:
    temp_accuracies = []
    for i in range(n_iterations):
        X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)
        scaler = StandardScaler()
        X_train_scaled = scaler.fit_transform(X_train)
        X_test_scaled = scaler.transform(X_test)
        knn = KNeighborsClassifier(n_neighbors=k)
        knn.fit(X_train_scaled, y_train)
        y_pred = knn.predict(X_test_scaled)
        temp_accuracies.append(accuracy_score(y_test, y_pred))
    k_avg_scores[k] = np.mean(temp_accuracies)

best_k = max(k_avg_scores, key=k_avg_scores.get)
print(f"The most robust K is {best_k}.")


# --- Part B: Find the Best Train/Test Ratio ---

# print(f"\n--- Starting Part B: Finding the best ratio using K={best_k} ---")

# Define ratios to test
ratios = [0.5, 0.4, 0.3, 0.2, 0.1]
ratio_scores = {}

# Loop through each ratio
for ratio in ratios:
    # Use random_state=42 for a fair comparison between ratios
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=ratio, random_state=42)
    
    # Scale the features
    scaler = StandardScaler()
    X_train_scaled = scaler.fit_transform(X_train)
    X_test_scaled = scaler.transform(X_test)
    
    # Train the model with our best K
    knn = KNeighborsClassifier(n_neighbors=best_k)
    knn.fit(X_train_scaled, y_train)
    
    # Evaluate and store the accuracy
    y_pred = knn.predict(X_test_scaled)
    accuracy = accuracy_score(y_test, y_pred)
    ratio_scores[ratio] = accuracy

# Print the final findings
# print("\n--- Findings for 'student_performance.csv' ---")
print("Accuracy for each Train/Test ratio:")
for ratio, score in ratio_scores.items():
    train_percent = (1 - ratio) * 100
    test_percent = ratio * 100
    print(f"Ratio: {train_percent:.0f}% Train / {test_percent:.0f}% Test -> Accuracy: {score:.4f}")

best_ratio = max(ratio_scores, key=ratio_scores.get)
print(f"\nThe best train/test ratio is {best_ratio} with an average accuracy of {ratio_scores[best_ratio]:.4f}.")