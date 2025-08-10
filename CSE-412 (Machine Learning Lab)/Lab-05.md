# K-Means Clustering

## \#\# 🎯 Section 1 & 2: Objective and What is Clustering?

The main goal of this lab is to understand and implement **K-Means Clustering**.

### Supervised vs. Unsupervised Learning

So far, you've been doing **supervised learning**. You had features (`X`) and corresponding correct labels (`y`). The goal was to train a model that could predict the label for new data.

**Clustering** is a type of **unsupervised learning**. This means we only have the features (`X`) and **no labels (`y`)**. The goal is not to predict a known outcome, but to discover natural groupings or **clusters** in the data on its own.

- **Analogy:**
  - **Supervised:** Learning with a teacher who shows you pictures of animals and tells you, "This is a cat, this is a dog."
  - **Unsupervised:** Being given a box full of photos of different animals and being asked to sort them into piles based on similarity, without being told what the animal types are. You would naturally create a "cat pile," a "dog pile," etc., by identifying similar features.

Clustering helps us find meaningful structure in our data, which is useful for things like customer segmentation, document analysis, and identifying patterns in scientific data.

---

### \#\# 🧠 Section 4: The K-Means Algorithm

K-Means is one of the simplest and most popular clustering algorithms. It partitions data into a pre-determined number of clusters, `K`.

- **Analogy: The Pizza Shop Problem**
  Imagine you want to open `K=3` new pizza shops in a city to serve all the residents (the data points). Where should you build them?

  1.  **Step 1: Initialization**
      You randomly drop 3 pins on a map of the city. These are your initial, randomly placed pizza shops (called **centroids**).

  2.  **Step 2: Assignment Step**
      For every resident in the city, you find which of the 3 pizza shops is closest to them. Every resident is assigned to their nearest shop. This creates 3 distinct customer groups or "clusters."

  3.  **Step 3: Update Step**
      Now, for each of the 3 customer groups, you find the _actual center of gravity_ of that group (the average location of all its customers). You move your pizza shop (the centroid) to this new, better location.

  4.  **Step 4: Repeat**
      You repeat Steps 2 and 3. Now that the shops have moved, some residents might find that a different shop is now closer to them. So, they get reassigned. This, in turn, changes the center of the groups, so the shops move again. This process is repeated until the shops stop moving, which means you have found the optimal locations for your pizza shops—the final, stable clusters.

This iterative process of **Assigning** points and **Updating** centroids is the core of the K-Means algorithm.

---

### \#\# 💻 Section 5 & 6: K-Means on the Iris Dataset

This section shows you how to implement the K-Means algorithm using Python and Scikit-learn.

1.  **Loading & Preparing Data**: The code loads the Iris dataset and, for convenience, puts it into a Pandas DataFrame. This allows you to refer to the columns by name (e.g., `'SL'`, `'PL'`) instead of by index number.

2.  **Visualization**: The code creates scatter plots to show the natural groupings of the data. Notice that at this stage, the model hasn't been built yet; this is just for us to see what the data looks like. The points are colored using the _true_ labels to give us a "ground truth" reference for what the clusters should ideally look like.

3.  **Training the Model**: This is a very simple step in Scikit-learn.

    ```python
    from sklearn.cluster import KMeans
    iris_k_mean_model = KMeans(n_clusters=3) # We tell the model to find K=3 clusters
    iris_k_mean_model.fit(x) # This runs the iterative algorithm
    ```

    The `.fit()` method performs the entire iterative process (assigning points, updating centroids) until the clusters are stable.

4.  **Analyzing Results**:

    - **Cluster Centers**: `iris_k_mean_model.cluster_centers_` will show you the final coordinates of your `K` centroids (the final pizza shop locations). By inspecting these coordinates, you can often understand what each cluster represents (e.g., one centroid will have low petal measurements, matching the Setosa species).
    - **Visualizing Predictions**: The code plots the data twice: once colored by the true labels and once colored by the labels predicted by the K-Means model. This gives you a powerful visual comparison of how well the algorithm did.
    - **The Relabeling Trick**: Look closely at this line:
      ```python
      predictedY = np.choose(iris_k_mean_model.labels_, [1, 0, 2])
      ```
      This is a **very important** and often confusing step. K-Means assigns cluster numbers (0, 1, 2) arbitrarily. It might call the Setosa cluster '1', the Versicolor cluster '0', and the Virginica cluster '2'. These do not necessarily match the original labels where Setosa was 0, Versicolor was 1, etc. This line is a **manual relabeling** step to align the model's cluster labels with the ground truth labels so that we can accurately calculate the performance.
    - **Evaluation**: Even though K-Means is unsupervised, we can use the true labels _after_ training to check its performance. The **accuracy score** and **confusion matrix** tell you how well the discovered clusters map to the actual flower species.

---

### \#\# 🧪 Section 7: Lab Exercises

Here's how to approach your lab exercises.

#### Exercise 1: Split into Training and Testing Set

The manual's example trains on the entire dataset. Standard practice is to fit the model only on the training set.

```python
from sklearn.model_selection import train_test_split
from sklearn.cluster import KMeans
from sklearn.metrics import accuracy_score, confusion_matrix
import pandas as pd

# Load and prepare data
iris = datasets.load_iris()
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
```

#### Exercise 2: Evaluate Using Only Two Features

This is a data preparation task. Simply select the two columns you need before splitting and training.

```python
# Select only Sepal Length (SL) and Petal Width (PW)
X_two_features = x[['SL', 'PW']]

# Now, use this X_two_features in the train_test_split and the rest of the code
X_train, X_test, y_train, y_test = train_test_split(X_two_features, y, test_size=0.3, random_state=42)

# ... then proceed with training and evaluation as in Exercise 1 ...
```

#### Exercise 3: Use Your Own Dataset

Apply the same K-Means process to the `student_performance.csv` file you created in a previous lab. Since that dataset has a clear binary outcome ('passed_exam'), you would set `K=2`.

```python
# 1. Load your student performance data
student_df = pd.read_csv('student_performance.csv')

# 2. Select features
X_student = student_df[['hours_studied', 'attendance_pct']]
y_student = student_df['passed_exam']

# 3. Split the data
X_train, X_test, y_train, y_test = train_test_split(X_student, y_student, test_size=0.3, random_state=42)

# 4. Train K-Means with K=2
kmeans_student = KMeans(n_clusters=2, random_state=42)
kmeans_student.fit(X_train)

# 5. Evaluate the performance on the test set (remember to align labels if needed)
predictions = kmeans_student.predict(X_test)
# ... align labels and calculate accuracy/confusion matrix ...
```
