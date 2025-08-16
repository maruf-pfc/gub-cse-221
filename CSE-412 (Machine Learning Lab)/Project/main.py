# --- Step 1: Import Libraries and Load Data ---
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
import warnings

# Ignore potential warnings for a cleaner output
warnings.filterwarnings('ignore')

csvFileName = 'heart_disease_uci.csv'

# Load the dataset from the CSV file
try:
    df = pd.read_csv(csvFileName)
except FileNotFoundError:
    print(f"Error: '{csvFileName}' not found.")
    print("Please download the dataset from Kaggle and place it in the correct folder.")
    exit()

# --- Step 2: Explore the Data ---
print("--- Data Exploration ---")
print("First 5 rows of the dataset:")
print(df.head())
print("\nDataset Information:")
df.info()
print("\nStatistical Summary:")
print(df.describe())
print("\nMissing values in each column (before cleaning):")
print(df.isnull().sum())


# --- Step 3: Comprehensive Data Preprocessing ---
print("\n--- Data Preprocessing ---")

# Drop irrelevant columns
df = df.drop(['id', 'dataset'], axis=1)

# Correct the target variable: 'num' is the original target column.
# We will convert it to a binary target: 0 = no disease, 1 = disease present.
df['target'] = (df['num'] > 0).astype(int)
df = df.drop('num', axis=1)

# Separate features by data type
categorical_features = df.select_dtypes(include=['object']).columns
numerical_features = df.select_dtypes(include=np.number).drop('target', axis=1).columns

# Handle missing values (Imputation)
# For numerical features, fill with the median
for col in numerical_features:
    median_val = df[col].median()
    df[col].fillna(median_val, inplace=True)

# For categorical features, fill with the mode (most frequent value)
for col in categorical_features:
    mode_val = df[col].mode()[0]
    df[col].fillna(mode_val, inplace=True)

print("\nMissing values handled.")
print(f"Total missing values after cleaning: {df.isnull().sum().sum()}") # Should be 0

# --- Step 4: Data Visualization ---
print("\n--- Data Visualization ---")

# Plot 1: Distribution of the target variable
plt.figure(figsize=(8, 6))
sns.countplot(x='target', data=df)
plt.title('Distribution of Heart Disease (0 = No Disease, 1 = Disease)')
plt.xlabel('Heart Disease')
plt.ylabel('Patient Count')
plt.xticks([0, 1], ['No Disease', 'Has Disease'])
plt.show()

# Plot 2: Correlation heatmap for numerical features
plt.figure(figsize=(12, 10))
# We create a temporary dataframe with the original numerical features for a cleaner correlation plot
correlation_df = df[list(numerical_features) + ['target']]
sns.heatmap(correlation_df.corr(), annot=True, cmap='coolwarm', fmt='.2f')
plt.title('Correlation Matrix of Numerical Features')
plt.show()


# Convert categorical variables into dummy/indicator variables (One-Hot Encoding)
df = pd.get_dummies(df, columns=categorical_features, drop_first=True)
print("\nCategorical features converted to numerical format.")


# --- Step 5: Define Features and Target, then Split Data ---
print("\n--- Splitting Data ---")

# Define our features (X) and target (y)
X = df.drop('target', axis=1)
y = df['target']

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42, stratify=y)
print(f"Training set shape: {X_train.shape}")
print(f"Testing set shape: {X_test.shape}")

# Scale the features
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)
print("\nData has been successfully split and scaled.")


# --- Step 6: Model Training ---
print("\n--- Model Training ---")

# We will use Logistic Regression
model = LogisticRegression(max_iter=1000) # Increased max_iter for convergence

# Train the model
model.fit(X_train, y_train)
print("Model training complete.")


# --- Step 7: Model Evaluation ---
print("\n--- Model Evaluation ---")

# Make predictions on the test data
y_pred = model.predict(X_test)

# Calculate and display metrics
accuracy = accuracy_score(y_test, y_pred)
print(f"Model Accuracy: {accuracy * 100:.2f}%")

print("\nClassification Report:")
print(classification_report(y_test, y_pred))

# Plot 3: Confusion Matrix Heatmap
cm = confusion_matrix(y_test, y_pred)
plt.figure(figsize=(8, 6))
sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', xticklabels=['No Disease', 'Has Disease'], yticklabels=['No Disease', 'Has Disease'])
plt.title('Confusion Matrix')
plt.xlabel('Predicted Label')
plt.ylabel('True Label')
plt.show()
