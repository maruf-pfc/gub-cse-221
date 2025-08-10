import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.cluster import KMeans
from sklearn.metrics import accuracy_score, confusion_matrix

# --- Step 1: Generate the CSV File ---
# This part creates the 'student_performance.csv' file so the script can run.
print("--- Generating sample dataset: student_performance.csv ---")
# Create sample data
data = {
    'hours_studied': np.random.uniform(1, 20, 150).round(1),
    'attendance_pct': np.random.uniform(50, 100, 150).round(1),
}
df_generator = pd.DataFrame(data)
# Create a simple rule for the target variable 'passed_exam' (1 = Passed, 0 = Failed)
df_generator['passed_exam'] = np.where((df_generator['hours_studied'] + df_generator['attendance_pct'] / 5) > 30, 1, 0)
# Save the DataFrame to a CSV file
df_generator.to_csv('student_performance.csv', index=False)
print("Dataset created successfully.\n")


# --- Step 2: Load and Prepare the Data ---
print("--- Loading and preparing data ---")
# Load your student performance data
student_df = pd.read_csv('student_performance.csv')

# Select features (X) and the target (y)
X_student = student_df[['hours_studied', 'attendance_pct']]
y_student = student_df['passed_exam']
print("Data loaded and prepared.\n")


# --- Step 3: Split Data and Train K-Means Model ---
print("--- Training K-Means model with K=2 ---")
# Split the data into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X_student, y_student, test_size=0.3, random_state=42)

# Train K-Means with K=2 clusters
kmeans_student = KMeans(n_clusters=2, random_state=42, n_init=10)
kmeans_student.fit(X_train)
print("Model training complete.\n")


# --- Step 4: Evaluate the Performance on the Test Set ---
# Get the initial, raw predictions from the model
raw_predictions = kmeans_student.predict(X_test)

# To evaluate accuracy, we must first align the arbitrary cluster labels (0, 1) from
# K-Means with the actual labels from the dataset (0 for Fail, 1 for Pass).
# We can use a confusion matrix to discover this mapping.

# Calculate the initial confusion matrix to see the alignment
initial_conf_matrix = confusion_matrix(y_test, raw_predictions)
print("--- Label Alignment Step ---")
print("Initial Confusion Matrix (True Labels vs. Raw K-Means Labels):")
print(initial_conf_matrix)

# Check if the main diagonal (correct predictions) is smaller than the off-diagonal.
# If it is, the labels are likely flipped and need to be remapped.
if np.trace(initial_conf_matrix) < (initial_conf_matrix.sum() / 2):
    print("\nLabels appear to be flipped. Remapping K-Means labels: 0->1, 1->0")
    # Remap the labels: swap 0s and 1s
    aligned_predictions = np.where(raw_predictions == 0, 1, 0)
else:
    print("\nLabels appear to be aligned correctly. Using raw predictions.")
    aligned_predictions = raw_predictions

# Now, calculate the final performance metrics using the aligned predictions
final_accuracy = accuracy_score(y_test, aligned_predictions)
final_conf_matrix = confusion_matrix(y_test, aligned_predictions)

print("\n--- Final Performance Evaluation ---")
print(f"Model Accuracy on Test Set: {final_accuracy:.4f}")
print("\nFinal Aligned Confusion Matrix (True vs. Aligned K-Means):")
print(final_conf_matrix)