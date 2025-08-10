import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, accuracy_score, confusion_matrix

# 1. Load the dataset from the Kaggle link provided in the manual
#    You'll need to download 'diabetes.csv' and upload it to your environment.
try:
    df = pd.read_csv('diabetes.csv')
except FileNotFoundError:
    print("Error: 'diabetes.csv' not found. Please download it and place it in the correct directory.")
    exit()

# 2. Prepare the data
#    Features (X) are all columns except 'Outcome'
#    Target (y) is the 'Outcome' column
X = df.drop('Outcome', axis=1) 
y = df['Outcome']

# 3. Split data into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 4. Train the Linear Regression model
#    Even though it's a classification problem, we use LinearRegression as asked.
regressor = LinearRegression()
regressor.fit(X_train, y_train)

# 5. Make predictions
#    The predictions will be continuous values, not 0s and 1s.
y_pred_continuous = regressor.predict(X_test)

# 6. Convert continuous predictions into class labels (0 or 1)
#    A common way to do this is to set a threshold of 0.5.
#    If the predicted value is > 0.5, we classify it as 1 (diabetic), otherwise 0.
y_pred_class = [1 if pred > 0.5 else 0 for pred in y_pred_continuous]

# 7. Evaluate the performance
print("--- Evaluation Report ---")

# You can still calculate MSE, but it's less meaningful for classification.
mse = mean_squared_error(y_test, y_pred_continuous)
print(f"Mean Squared Error (on continuous predictions): {mse:.4f}")

# Classification metrics are more appropriate here.
accuracy = accuracy_score(y_test, y_pred_class)
conf_matrix = confusion_matrix(y_test, y_pred_class)

print(f"\nAccuracy (after applying 0.5 threshold): {accuracy:.4f}")
print("\nConfusion Matrix:")
print(conf_matrix)

print("\n--- Conclusion ---")
print("We used Linear Regression for a classification task as requested.")
print("To get class labels, we had to manually apply a threshold.")
print("For this type of problem, a dedicated classification algorithm like Logistic Regression would be a more appropriate choice.")