# Heart Disease Detection

## **Project Notes and Code Explanation**

### **Step 1: Import Libraries and Load Data**

This section is about setting up your toolbox. You're importing all the necessary functions and classes that you'll need to build your project.

```python
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
```

- **`import pandas as pd`**:
  - **What it does:** Imports the Pandas library, which is the standard for data manipulation and analysis in Python. We give it the alias `pd` by convention.
  - **Why it's needed:** To read the `.csv` file into a structured format called a DataFrame, which is like a powerful spreadsheet you can control with code.
- **`import numpy as np`**:
  - **What it does:** Imports the NumPy library, the fundamental package for numerical computation in Python. The alias is `np`.
  - **Why it's needed:** Pandas is built on top of NumPy. We use it for numerical operations, especially when handling missing values.
- **`import matplotlib.pyplot as plt`** and **`import seaborn as sns`**:
  - **What they do:** Import the two main data visualization libraries. Matplotlib is the foundation, and Seaborn is built on top of it to make more attractive statistical plots.
  - **Why they're needed:** To create the charts and heatmaps that help us understand the data and our model's results. A picture is worth a thousand words, especially in data analysis.
- **`from sklearn... import ...`**:
  - **What it does:** Imports specific tools from the Scikit-learn library, the most important machine learning library in Python.
  - **`train_test_split`**: A function to split our data into training and testing sets.
  - **`StandardScaler`**: A tool to standardize our data's features.
  - **`LogisticRegression`**: The machine learning model we're using for classification.
  - **`accuracy_score`, `confusion_matrix`, `classification_report`**: Functions to evaluate how well our model performed.
- **`warnings.filterwarnings('ignore')`**:
  - **What it does:** Tells the program to hide any warning messages that might pop up.
  - **Why it's needed:** Sometimes, libraries will show warnings about future updates that don't affect our results. This line keeps the final output clean and professional.

### **Step 2: Explore the Data**

This is your first contact with the data. The goal is to understand its structure, find problems, and get a general feel for it.

```python
# --- Step 2: Explore the Data ---
print("--- Data Exploration ---")
print(df.head())
df.info()
print(df.describe())
print(df.isnull().sum())
```

- **`df.head()`**:
  - **What it does:** Shows the first 5 rows of the DataFrame.
  - **Why it's needed:** It’s a quick and easy way to see what the columns are named and what kind of data they contain (numbers, text, etc.).
- **`df.info()`**:
  - **What it does:** Provides a technical summary of the DataFrame, including the number of entries, the name of each column, the number of non-null values, and the data type (`Dtype`).
  - **Why it's needed:** This is crucial for debugging. It immediately shows us which columns have **missing data** (non-null count is less than the total entries) and which columns are **not numerical** (`Dtype` is `object`).
- **`df.describe()`**:
  - **What it does:** Generates descriptive statistics for the numerical columns (count, mean, standard deviation, min, max, etc.).
  - **Why it's needed:** Helps you spot anomalies. For example, if `trestbps` (blood pressure) had a `min` of 0, you'd know there's an error in the data, as that's not biologically possible.
- **`df.isnull().sum()`**:
  - **What it does:** Counts the number of missing (`null`) values in each column.
  - **Why it's needed:** This is the most direct way to see the scale of the missing data problem. We can see that columns like `ca` (611 missing) and `thal` (486 missing) have serious issues that must be fixed.

**Faculty Questions:**

- **Q: Why did you choose to explore the data first?**
  - **A:** "I explored the data first to understand its structure and identify potential problems. Without this step, I wouldn't have known about the extensive missing values or the non-numeric columns, and the model would have failed. It's a critical diagnostic step in any machine learning project."

### **Step 3: Comprehensive Data Preprocessing**

This is the "data cleaning" phase. You're fixing the problems you found in Step 2 to make the data usable for a machine learning model.

```python
# Drop irrelevant columns
df = df.drop(['id', 'dataset'], axis=1)

# Correct the target variable
df['target'] = (df['num'] > 0).astype(int)
df = df.drop('num', axis=1)

# Handle missing values (Imputation)
for col in numerical_features:
    median_val = df[col].median()
    df[col].fillna(median_val, inplace=True)
```

- **`df = df.drop(...)`**:
  - **What it does:** Removes the `id` and `dataset` columns.
  - **Why it's needed:** These columns don't contain medical information that can help predict heart disease. The `id` is just a row number, and `dataset` just says where the data came from. They are noise, not signal.
- **`df['target'] = (df['num'] > 0).astype(int)`**:
  - **What it does:** This is a two-part command. `(df['num'] > 0)` checks each row in the `num` column. If the value is greater than 0, it returns `True`; otherwise, `False`. Then, `.astype(int)` converts `True` to `1` and `False` to `0`.
  - **Why it's needed:** The original `num` column has values from 0 to 4, representing different stages of heart disease. For this project, we simplified it to a **binary classification** problem: `0` (no disease) vs. `1` (disease is present). This is a very common and practical simplification.
- **`df[col].fillna(median_val, inplace=True)`**:
  - **What it does:** Fills any missing (`NaN`) values in a numerical column with the **median** of that column.
  - **Why it's needed:** Machine learning models cannot handle missing data. We have to fill it in.
  - **Faculty Question: Why did you use the median and not the mean?**
    - **A:** "I chose the median because it's more robust to outliers. For example, in the `chol` (cholesterol) column, a few extremely high values could skew the mean upwards, making it a less representative value for the typical patient. The median, being the middle value, is not affected by these extreme outliers."

### **Step 4 & 5: Visualization and Splitting**

You visualize the cleaned data and then prepare it for the model by splitting it.

```python
# Convert categorical variables into dummy/indicator variables (One-Hot Encoding)
df = pd.get_dummies(df, columns=categorical_features, drop_first=True)

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42, stratify=y)

# Scale the features
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)
```

- **`pd.get_dummies(...)`**:
  - **What it does:** This performs **one-hot encoding**. It takes a categorical column (e.g., `sex` with values 'Male', 'Female') and converts it into numerical columns (e.g., `sex_Male` with values 0 or 1).
  - **Why it's needed:** Models only understand numbers. This is the standard way to convert non-numeric text data into a format the model can use without implying an incorrect order.
- **`train_test_split(...)`**:
  - **What it does:** Splits the data into four pieces: `X_train` (features for training), `X_test` (features for testing), `y_train` (answers for training), and `y_test` (answers for testing). `test_size=0.2` means 20% of the data is held back for testing.
  - **Why it's needed:** This is the **most important rule in machine learning**. You must evaluate your model on data it has **never seen before**. If you test on the same data you trained on, the model might just memorize the answers, giving you a falsely high score.
  - **Faculty Question: What does `stratify=y` do?**
    - **A:** "`stratify=y` ensures that the proportion of patients with and without heart disease is the same in both the training and testing sets. This is crucial for an imbalanced dataset like ours, as it prevents a situation where, by random chance, the test set has very few examples of one class, which would make the evaluation unreliable."
- **`StandardScaler()`**:
  - **What it does:** It rescales all numerical features to have a mean of 0 and a standard deviation of 1.
  - **Why it's needed:** Features are on different scales (e.g., `age` is 28-77, while `oldpeak` is -2.6 to 6.2). Algorithms like Logistic Regression can be biased towards features with larger scales. Scaling puts all features on a level playing field, ensuring the model learns their true importance.
  - **Faculty Question: Why do you `fit_transform` on the training data but only `transform` on the test data?**
    - **A:** "This is to prevent **data leakage**. The `fit` step calculates the mean and standard deviation needed for scaling. These should only be learned from the training data. We then use those same parameters to `transform` the test data, simulating how the model would handle new, unseen data in the real world. If I were to `fit` on the test data too, information from the test set would 'leak' into the training process, leading to an overly optimistic performance score."

### **Step 6 & 7: Model Training and Evaluation**

This is the core machine learning part. You train the model and then critically evaluate its performance.

```python
# We will use Logistic Regression
model = LogisticRegression(max_iter=1000)

# Train the model
model.fit(X_train, y_train)

# Calculate and display metrics
print(f"Model Accuracy: {accuracy * 100:.2f}%")
print("\nClassification Report:")
print(classification_report(y_test, y_pred))

# Plot 3: Confusion Matrix Heatmap
sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', ...)
```

- **`model = LogisticRegression(...)`**:
  - **What it does:** Creates an instance of the Logistic Regression model.
  - **Why it's needed:** This is the algorithm we've chosen. It's a reliable and interpretable choice for binary classification problems.
- **`model.fit(X_train, y_train)`**:
  - **What it does:** This is the **training** step. The model looks at the training features (`X_train`) and the corresponding answers (`y_train`) and learns the mathematical relationship between them.
- **`accuracy_score(...)`**:
  - **What it does:** Calculates the overall accuracy: (Correct Predictions) / (Total Predictions).
  - **Why it's needed:** It's a simple, high-level metric of performance.
- **`classification_report(...)`**:
  - **What it does:** Provides a more detailed report, including **Precision**, **Recall**, and **F1-Score**.
  - **Why it's needed:** Accuracy can be misleading, especially with imbalanced classes.
    - **Precision:** Of all the patients the model said had heart disease, how many actually did? (Measures false positives).
    - **Recall:** Of all the patients who truly had heart disease, how many did the model correctly identify? (Measures false negatives).
- **`confusion_matrix(...)`**:
  - **What it does:** Creates a table that breaks down the predictions into four categories: True Positives, True Negatives, False Positives, and False Negatives.
  - **Why it's needed:** It gives you a complete picture of the model's performance, showing you exactly where it's succeeding and where it's failing. For a medical diagnosis, you are often most concerned with minimizing **False Negatives** (telling a sick person they are healthy).
