# K-Nearest Neighbors (KNN) classifier

## 🎯 Slide 1 & 2: Objective and Background

The goal of this lab is straightforward: understand and build a **K-Nearest Neighbors (KNN) classifier**.

**What is KNN?**

At its heart, KNN is a "birds of a feather flock together" algorithm. It classifies a new data point based on the classes of its closest neighbors.

- **Analogy:** Imagine you're a new student in a classroom. You don't know if you should join the "Math Club" or the "Art Club". To decide, you look at the **3 students sitting closest to you**. If 2 of them are in the Art Club and 1 is in the Math Club, you'd probably guess you belong in the Art Club. That's KNN in a nutshell.

- **Feature Similarity:** This is the key concept. "Closeness" is measured by calculating the distance between data points. Points that are close together in the feature space are considered similar.
- **Non-parametric:** This is a fancy term meaning the algorithm doesn't make any strong assumptions about the data's structure (e.g., it doesn't assume the data is a straight line or a perfect circle). It figures out the structure directly from the data provided.
- **Lazy Learning:** We'll cover this in more detail next.

---

### ## 🧠 Slide 3, 4, & 5: How KNN Works (and Eager vs. Lazy Learners)

This section explains the mechanics of the algorithm and a very important theoretical distinction.

#### How does it work?

It’s a simple three-step process:

1.  **Calculate Distance:** When you get a new, unclassified data point (let's call it the "test point"), KNN calculates the distance between this test point and _every single point_ in the training dataset. Common distance measures include Euclidean distance (the straight-line distance we all learned in geometry).
2.  **Find Closest Neighbors:** It sorts all those distances from smallest to largest and picks the top `K` points. If `K=5`, it finds the 5 closest training data points.
3.  **Vote for Labels:** It looks at the labels of those `K` neighbors. The new test point is assigned the label that appears most frequently among its neighbors (majority vote). If `K=5` and 3 neighbors are 'Class A' and 2 are 'Class B', the new point is classified as 'Class A'.

#### Eager vs. Lazy Learners

This is a key concept for classifying algorithms.

- **Eager Learners (e.g., Linear Regression, Decision Trees):** These algorithms build a model or a formula during the training phase. They are "eager" to learn a general rule from the training data.
  - **Analogy:** An eager student studies hard _before_ an exam to understand all the concepts. When the exam comes, they can answer questions quickly because they've already done the learning. **Training is slow, but testing is fast.**
- **Lazy Learners (KNN is the prime example):** These algorithms do almost nothing during the training phase. They essentially just memorize or store the entire training dataset. The real work happens during the testing phase.
  - **Analogy:** A lazy student brings all their textbooks to an open-book exam. They don't study beforehand. When they get a question, they search through all the books to find the answer. **Training is instant, but testing is slow and resource-intensive.**

---

### ## ⚠️ Slide 6 & 7: Challenges with KNN

KNN is simple, but it has two major challenges you need to be aware of.

#### The Curse of Dimensionality

This sounds complex, but the idea is simple. As you add more features (dimensions), the distance between data points grows, and they all start to seem equally far apart from each other.

- **Analogy:** Imagine trying to find your friend.
  - In **1D** (a single-file line), it's easy.
  - In **2D** (a crowded square), it's harder.
  - In **3D** (a multi-story building), it's even harder.
  - In **100D**, the space is so vast that the concept of "close" or "nearest neighbor" becomes almost meaningless.

**Key Takeaway:** KNN works best with a low number of features. If you have many features, you should first use a technique like **Principal Component Analysis (PCA)** to reduce the dimensions.

#### How do you choose K?

The number of neighbors, **K**, is a hyperparameter you must choose. This choice involves a critical trade-off:

- **Small K (e.g., K=1):** The model is very sensitive to noise and outliers. It has **low bias** (it makes decisions based on very local data) but **high variance** (its predictions can change drastically if the training data changes slightly). The decision boundary will be very jagged.
- **Large K (e.g., K=lots):** The model is more robust to noise but can miss local patterns. It has **high bias** (it might over-generalize) but **low variance** (its predictions are very stable). The decision boundary will be much smoother.

[Image showing the effect of K on the KNN decision boundary]

**Practical Advice:**

- Start with `K` as an odd number (e.g., 3, 5, 7) to avoid ties in a two-class problem.
- The best way to find the optimal K is to test a range of K values and see which one gives the best performance on your test data.

---

### ## 💻 Slide 8: Implementation Example

This is the practical part where you apply all the theory using Python's Scikit-learn library. Let's walk through the code.

1.  **Load Data:** You start by loading the famous **Iris flower dataset**. It contains 150 samples, each with 4 features (sepal length/width, petal length/width) and a target label (one of three species).
2.  **Split Data (`train_test_split`)**: This is a fundamental step in machine learning. You split your data into a **training set** (to teach the model) and a **testing set** (to evaluate how well it learned). Here, it's a 70/30 split. This prevents the model from "cheating" by testing it on data it has already seen.
3.  **Data Scaling (`StandardScaler`)**: **This is CRITICAL for KNN.** Because KNN is based on distance, features with larger scales (e.g., a salary in dollars) will dominate features with smaller scales (e.g., years of experience). `StandardScaler` transforms all features so they have a mean of 0 and a standard deviation of 1, putting them all on a level playing field.
    - **Important:** You `.fit()` the scaler on the **training data only** to learn the scaling parameters. Then you `.transform()` both the training and test data using those same parameters. This prevents "data leakage" from the test set into the training process.
4.  **Training Loop**: The code cleverly loops through K values from 1 to 14. In each loop, it:
    - Creates a `KNeighborsClassifier` with the current value of `k`.
    - `.fit(X_train, y_train)`: "Trains" the model (for KNN, this just means it stores the training data).
    - `.predict(X_test)`: Makes predictions on the unseen test data.
    - `metrics.accuracy_score()`: Compares the predictions to the true labels (`y_test`) to calculate accuracy.
5.  **Evaluation (`confusion_matrix`, `classification_report`)**:
    - **Accuracy** is good, but these metrics give a much better picture.
    - A **Confusion Matrix** shows you exactly which classes are being confused with which.
    - A **Classification Report** shows you precision, recall, and f1-score for each class, which are often more useful than overall accuracy.
6.  **Plotting Accuracy**: This is the best part. By plotting the accuracy for each K, you can visually find the "elbow" point or the range of K values that give the highest accuracy.
7.  **Final Prediction**: After finding the best K (the manual suggests 8), you retrain the model on the full training set with that K. Then, you test it on two new, hand-made data points.
    - **Potential Issue Here:** The manual's code predicts `[1,1,1,1]` as `virginicia`. This might happen because the new data `x_new` was not scaled using the same `scaler`. For a correct prediction, you must apply the same scaling to any new data: `x_new_scaled = scaler.transform(x_new)`.

---

### ## 🧪 Slide 9: Your Lab Exercises

Here's how to approach your tasks.

1.  **Find the best K using an average:** The manual's code does one train-test split. This result can be lucky or unlucky. A more robust way is to repeat the process. For each value of K:
    - Create a loop that runs 10 times.
    - Inside the loop, perform a `train_test_split` (the split will be different each time if you don't set a `random_state`).
    - Train your model and get the accuracy. Store this accuracy in a list.
    - After the 10 runs, calculate the _average_ accuracy for that K.
    - Do this for all K's, and find the K with the highest average accuracy. This is a simplified version of a technique called **cross-validation**.
2.  **Find the best train/test ratio:** Here, your K is fixed (use the best K from Exercise 1). Your variable is the `test_size` parameter in `train_test_split`.
    - Create a loop that iterates through different ratios, for example: `[0.5, 0.4, 0.3, 0.2, 0.1]`.
    - For each ratio, split the data, train the model, and record the accuracy.
    - See which ratio gives the best performance. You'll likely see a trade-off: more training data usually makes the model better, but leaves less test data for a reliable evaluation.
3.  **Do the same for your own dataset:** This is about applying the skills you've learned. You can either create a simple dataset in a CSV file or use one of the many other datasets available in Scikit-learn (e.g., `load_breast_cancer()`, `load_wine()`). The process is the same: load, split, scale, find the best K, find the best ratio, and report your findings.
