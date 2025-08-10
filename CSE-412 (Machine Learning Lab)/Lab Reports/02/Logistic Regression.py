import numpy as np
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression as SklearnLogisticRegression
from sklearn.metrics import accuracy_score

# --- Our "From Scratch" Logistic Regression Class ---
class MyLogisticRegression:
    def __init__(self, learning_rate=0.01, n_iterations=1000):
        self.lr = learning_rate
        self.n_iterations = n_iterations
        self.weights = None
        self.bias = None

    def _sigmoid(self, z):
        # The sigmoid function
        return 1 / (1 + np.exp(-z))

    def fit(self, X, y):
        # 1. Initialize parameters
        n_samples, n_features = X.shape
        self.weights = np.zeros(n_features)
        self.bias = 0

        # 2. Gradient Descent loop
        for _ in range(self.n_iterations):
            # Calculate the linear model part: z = X.w + b
            linear_model = np.dot(X, self.weights) + self.bias
            # Apply the sigmoid function to get probabilities
            y_predicted = self._sigmoid(linear_model)

            # 3. Calculate gradients (derivatives of the cost function)
            dw = (1 / n_samples) * np.dot(X.T, (y_predicted - y))
            db = (1 / n_samples) * np.sum(y_predicted - y)

            # 4. Update parameters
            self.weights -= self.lr * dw
            self.bias -= self.lr * db

    def predict(self, X):
        # Predict the class labels for new data
        linear_model = np.dot(X, self.weights) + self.bias
        y_predicted = self._sigmoid(linear_model)
        # Apply the 0.5 threshold
        y_predicted_cls = [1 if i > 0.5 else 0 for i in y_predicted]
        return np.array(y_predicted_cls)

# --- Compare our model with Scikit-learn's model ---
# 1. Load and prepare data (we'll use a binary version of Iris for simplicity)
iris = load_iris()
X, y = iris.data, iris.target

# Keep only class 0 and 1 to make it a binary problem
X = X[y != 2]
y = y[y != 2]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Scale the features
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# 2. Train and evaluate our "from scratch" model
my_model = MyLogisticRegression(learning_rate=0.1, n_iterations=1000)
my_model.fit(X_train, y_train)
my_predictions = my_model.predict(X_test)
my_accuracy = accuracy_score(y_test, my_predictions)

# 3. Train and evaluate Scikit-learn's model
sklearn_model = SklearnLogisticRegression()
sklearn_model.fit(X_train, y_train)
sklearn_predictions = sklearn_model.predict(X_test)
sklearn_accuracy = accuracy_score(y_test, sklearn_predictions)

# 4. Print the comparison
print("--- Logistic Regression Implementation Comparison ---")
print(f"Accuracy of our 'From Scratch' model: {my_accuracy:.4f}")
print(f"Accuracy of Scikit-learn's model:    {sklearn_accuracy:.4f}")


# Load the full Iris dataset
iris = load_iris()
X_full = iris.data
y = iris.target

# Select only Sepal Length (index 0) and Petal Width (index 3)
X_two_features = X_full[:, [0, 3]]

# Now, use this X_two_features in the train_test_split and the rest of the code
X_train, X_test, y_train, y_test = train_test_split(X_two_features, y, test_size=0.3, random_state=42)

# Scale the two features
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# Train a Scikit-learn model
model = SklearnLogisticRegression()
model.fit(X_train, y_train)

# Make predictions and evaluate
predictions = model.predict(X_test)
accuracy = accuracy_score(y_test, predictions)

print("\n--- Model Performance with Only 2 Features (Sepal Length & Petal Width) ---")
print(f"Accuracy: {accuracy:.4f}")