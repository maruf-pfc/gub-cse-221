import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
import warnings

warnings.filterwarnings('ignore')

csvFileName = 'heart_disease_uci.csv'

try:
    df = pd.read_csv(csvFileName)
except FileNotFoundError:
    print(f"Error: '{csvFileName}' not found.")
    exit()

print("First 5 rows of the dataset:")
print(df.head())
print("\nDataset Information:")
df.info()
print("\nStatistical Summary:")
print(df.describe())
print("\nMissing values in each column")
print(df.isnull().sum())

df = df.drop(['id', 'dataset'], axis=1)
df['target'] = (df['num'] > 0).astype(int)
df = df.drop('num', axis=1)

categorical_features = df.select_dtypes(include=['object']).columns
numerical_features = df.select_dtypes(include=np.number).drop('target', axis=1).columns

print("Categorical Features")
print(categorical_features)
print("Numerical Features")
print(numerical_features)

for col in numerical_features:
    median = df[col].median()
    df[col].fillna(median, inplace=True)

for col in categorical_features:
    mode = df[col].mode()[0]
    df[col].fillna(mode, inplace=True)

print(f"Total missing values after cleaning: {df.isnull().sum().sum()}")

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
correlation_df = df[list(numerical_features) + ['target']]
sns.heatmap(correlation_df.corr(), annot=True, cmap='coolwarm', fmt='.2f')
plt.title('Correlation Matrix of Numerical Features')
plt.show()

# One-Hot Encoding
df = pd.get_dummies(df, columns=categorical_features, drop_first=True)

X = df.drop('target', axis=1)
y = df['target']

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42, stratify=y)
print(f"Training set shape: {X_train.shape}")
print(f"Testing set shape: {X_test.shape}")

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

model = LogisticRegression(max_iter=1000)

model.fit(X_train, y_train)

y_pred = model.predict(X_test)

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
