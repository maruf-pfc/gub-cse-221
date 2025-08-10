# Logistic Regression

## \#\# 🎯 Section 1 & 2: Objective and Concept

The primary goal of Logistic Regression is **binary classification**—categorizing data into one of two classes (e.g., Yes/No, True/False, 1/0).

The key difference from Linear Regression is that instead of predicting a number that can go on forever, Logistic Regression predicts a **probability** that an input belongs to a specific class. This probability is always a value between 0 and 1.

### The Decision Boundary

To separate two classes, we need to define a dividing line or curve. This is called the **decision boundary**.
The model first calculates a score `z` using a linear equation, just like in linear regression:
$$z(x) = \theta_0 + \theta_1x_1 + \theta_2x_2 + \dots + \theta_nx_n = \theta^T x$$

Think of `z(x)` as representing the signed distance to this boundary. If a point is on one side, `z` might be positive; on the other side, it's negative. If a point is exactly on the boundary, `z` is 0.

#### The Logistic (Sigmoid) Function

How do we convert this score `z` (which can be any real number) into a probability between 0 and 1? We use the **Logistic Function**, also known as the **Sigmoid Function**.

$$g(z) = \frac{1}{1 + e^{-z}}$$

- **Analogy:** Think of the sigmoid function as a "squashing machine." It takes any number `z` and squashes it down to fit neatly between 0 and 1.

- If `z` is a large positive number, `g(z)` gets very close to **1**.

- If `z` is a large negative number, `g(z)` gets very close to **0**.

- If `z` is exactly 0 (on the decision boundary), `g(z)` is **0.5**.

We use this 0.5 value as our classification threshold. The model's final prediction, `h(x)`, is the probability that the class is 1.

- If `h(x) ≥ 0.5`, we predict the class is **1**.
- If `h(x) < 0.5`, we predict the class is **0**.

---

### \#\# 📉 Section 2.3 & 2.4: The Cost Function and Gradient Descent

We need a way to measure how "wrong" our model is so we can improve it. This is the **cost function**.

For Linear Regression, we used Mean Squared Error. That doesn't work well here because it creates a "non-convex" cost function—one with many local minimums.

- **Analogy:** Imagine trying to find the lowest point in a bumpy, mountainous region. You might get stuck in a small valley (a local minimum) instead of finding the absolute lowest point (the global minimum).

To solve this, Logistic Regression uses a cost function called **Binary Cross-Entropy**. The logic is brilliant:

- **If the true class `y` is 1:** The cost is `-log(h(x))`.
  - If our model correctly predicts a high probability (e.g., `h(x) = 0.99`), the cost `-log(0.99)` is very small.
  - If our model incorrectly predicts a low probability (e.g., `h(x) = 0.01`), the cost `-log(0.01)` is huge.
- **If the true class `y` is 0:** The cost is `-log(1 - h(x))`.
  - The logic is the same but flipped. A correct low-probability prediction gives a small cost, while an incorrect high-probability prediction gives a huge cost.

This cost function heavily penalizes confident but incorrect predictions. We then use **Gradient Descent** (the same "walking downhill" algorithm from the last lab) to find the parameters `θ` that minimize this cost.

---

### \#\# Section 3 & 4: Multiclass Classification and Implementation

What if you have more than two classes, like in the Iris dataset (Setosa, Versicolour, Virginica)?

We use a strategy called **One-vs-All (or One-vs-Rest)**.

- **Analogy:** To classify three types of animals (Cats, Dogs, Birds), you train three separate binary classifiers:
  1.  Classifier \#1: **Cat** vs. (Not a Cat)
  2.  Classifier \#2: **Dog** vs. (Not a Dog)
  3.  Classifier \#3: **Bird** vs. (Not a Bird)

When a new animal comes along, you show it to all three classifiers. Whichever one returns the highest probability wins. For example, if the predictions are `P(Cat)=0.1`, `P(Dog)=0.8`, `P(Bird)=0.3`, your model predicts "Dog".

The implementation code in your manual follows the standard Scikit-learn pattern. When you call `.fit()` on the Iris dataset, `LogisticRegression()` automatically detects that there are three classes and applies the One-vs-All strategy behind the scenes.

---

### \#\# 🧪 Section 5: Lab Exercises

These exercises are more advanced. Let's tackle them.

#### Exercise 1: Implement Logistic Regression from Scratch

This is a fantastic way to truly understand the algorithm. We need to build a class that mimics Scikit-learn's `.fit()` and `.predict()` methods by implementing the math ourselves.

Here is the complete code for a "from scratch" implementation.

```python
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
```

#### Exercise 2: Evaluate Using Only Two Features

This exercise tests how the model performs with less information. To do this, you just need to change the data preparation step.

```python
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
```

You should use `StandardScaler` whenever your machine learning algorithm is **sensitive to the scale or range of your input features**. It's a crucial preprocessing step for many models.

The main situations when you need to use it are:

1.  **Distance-Based Algorithms:** This is the most important case. Algorithms like **K-Nearest Neighbors (KNN)**, **Support Vector Machines (SVMs)**, and **K-Means Clustering** work by calculating the distance between data points.

    - **Analogy:** Imagine you have two features: a person's height in meters (e.g., 1.7) and their salary in dollars (e.g., 50,000). When calculating distance, the salary number is so much larger that it will completely dominate the height value. The algorithm would mistakenly think that salary is thousands of times more important than height. `StandardScaler` rescales both features so they have a comparable range, preventing this issue.

2.  **Gradient-Based Algorithms:** Models that use Gradient Descent for optimization, such as **Logistic Regression**, **Linear Regression**, and **Neural Networks**, converge much faster and more reliably when features are scaled.

    - **Reasoning:** When features are on vastly different scales, the cost function surface becomes stretched out and elliptical. This makes it difficult for gradient descent to find the direct path to the minimum, causing it to take a slow, zig-zagging path. Scaling the features makes the cost function surface more symmetrical, allowing for a quicker, more direct descent to the optimal solution.

3.  **Principal Component Analysis (PCA):** PCA works by finding the directions of maximum variance in the data. If one feature has a much larger variance than others simply because of its scale, it will dominate the PCA result. Scaling is essential to ensure that PCA finds the true principal components based on the data's underlying structure, not its arbitrary scales.

---

### When Is It NOT Necessary?

You generally don't need to use `StandardScaler` for **tree-based algorithms**. This includes models like **Decision Trees**, **Random Forest**, and **Gradient Boosting (e.g., XGBoost)**.

These models work by splitting data based on thresholds for individual features (e.g., is `age > 40?`). The scale of the feature doesn't affect where these optimal split points are found, so scaling is not required.
