# Data Preprocessing Techniques — Complete Notes & Lab Solutions

**Course:** Data Mining LAB (CSE 424)

**Department:** Computer Science and Engineering — Green University of Bangladesh

---

## Objective

* To transform raw data so it can be more easily and effectively processed in data mining, machine learning, and other data-science tasks.

---

## Table of Contents

1. Introduction to Data Preprocessing
2. Why preprocessing matters (quality checks)
3. Typical preprocessing steps — workflow
4. Worked example: Titanic dataset (complete pipeline)

   * Loading the data
   * Exploratory information (`.head()`, `.info()`, `.describe()`)
   * Dropping irrelevant columns
   * Handling missing values (several approaches)
   * Detecting and handling noisy data
   * Categorical encoding (label, ordinal, one-hot)
   * Discretization (binning)
   * Normalization & Standardization
   * Final dataset ready for ML
5. Lab Task solutions (fully implemented code blocks + explanations)

   * Task 1: Impute null values using average of previous & next values
   * Task 2: Convert categorical columns to numerical with one-hot encoding
6. Additional examples & utilities (functions you can reuse)
7. Best practices, pitfalls, and checklist for submission
8. Lab exercise (how to prepare the notebook & what to submit)
9. Discussion & Conclusion

---

# 1. Introduction to Data Preprocessing

Data preprocessing is the set of techniques used to convert raw data into a form suitable for modeling or analysis. Real-world datasets contain missing values, errors, inconsistent formatting, and outliers. Good preprocessing improves model quality, interpretability, and generalization.

Key ideas:

* Treat *missing values* smartly — blind deletion can remove signal.
* Choose encodings that reflect variable meaning (ordinal vs nominal).
* Scale numeric features when models are sensitive to feature scales (e.g., distance-based methods, gradient descent).
* Keep reproducibility — use pipelines and random seeds.

---

# 2. Quality checks for data

Before transforming, check these properties:

* **Accuracy:** Are values correct (e.g., age 200)?
* **Completeness:** How many missing values and where?
* **Consistency:** Are values formatted uniformly (e.g., `M` vs `Male`)?
* **Timeliness:** Are values up-to-date?
* **Believability:** Are values believable / realistic?
* **Interpretability:** Can humans understand the fields and units?

Use `df.info()`, `df.describe()`, `df.isnull().sum()`, and simple histograms to inspect these.

---

# 3. Typical preprocessing workflow

1. Load data
2. Inspect columns & data types
3. Drop or keep columns (domain knowledge matters)
4. Fix data types (e.g., string → datetime)
5. Handle missing values (imputation / deletion / marking)
6. Fix inconsistent categories and noisy entries
7. Encode categorical variables
8. Scale / normalize numeric variables if needed
9. Split into train/test (do this before using information from target on test)
10. Persist pipeline (scikit-learn `Pipeline`, `ColumnTransformer`, joblib)

---

# 4. Worked example: Titanic dataset (Kaggle)

> **Note**: The code below is formatted for a Jupyter notebook. Replace `titanic_dataset.csv` with the actual path you downloaded from Kaggle.

```python
# Imports (common libraries you'll need)
import pandas as pd
import numpy as np
from sklearn.preprocessing import LabelEncoder, OrdinalEncoder, OneHotEncoder, MinMaxScaler, StandardScaler
from sklearn.impute import SimpleImputer

# Load dataset
df = pd.read_csv('titanic_dataset.csv')

# Quick inspection
print(df.shape)        # rows, columns
print(df.head())
print(df.info())
print(df.describe())
print(df.isnull().sum())
```

**Common columns in Titanic dataset**: `PassengerId, Survived, Pclass, Name, Sex, Age, SibSp, Parch, Ticket, Fare, Cabin, Embarked`.

## 4.1 Dropping irrelevant columns

Sometimes features like `Name`, `Ticket`, or `PassengerId` are not useful directly. But think: `Cabin` may carry deck info and may be useful.

```python
cols_to_drop = ['Name', 'Ticket', 'PassengerId']
df = df.drop(columns=[c for c in cols_to_drop if c in df.columns])
```

Explain: drop columns only after thinking through whether they contain useful signal. `Cabin` often has many missing values; before dropping, consider extracting the first letter (deck) if available.

## 4.2 Handling missing values — overview

Check missing counts with `df.isnull().sum()`.

Approaches:

* Fill numerical columns with mean/median, or a value like `-999` for tree-based models.
* Fill categorical columns with mode or a special category like `'Unknown'`.
* Interpolate missing numerical values considering order (e.g., timeseries) or use interpolation between neighbors.
* Delete columns or rows only if missingness is extreme or if deletion is justified.

### Example — fill `Age` with mean

```python
# Simple imputation (mean)
df['Age_mean_imputed'] = df['Age'].fillna(df['Age'].mean())
```

### Example — drop columns with too many missing values

```python
threshold = 0.5  # drop column if more than 50% missing
df = df.loc[:, df.isnull().mean() < threshold]
```

## 4.3 Advanced: impute Age using interpolation or neighbors

If ages are missing, you might interpolate by passenger index, or better: use median age per `Pclass` and `Sex`.

```python
# Median age by Pclass and Sex
df['Age_med_by_group'] = df.groupby(['Pclass','Sex'])['Age'].transform(lambda x: x.fillna(x.median()))
```

Explain: grouping often preserves more structure than a global mean.

## 4.4 Handling noisy data

Noisy data = random errors or outliers.

* **Binning (smoothing)**: group continuous values into bins and replace with bin mean/median.
* **Clipping**: cap values at a percentile (e.g., 1st and 99th percentiles).
* **Outlier removal**: remove points outside of a plausible domain (careful: might remove true signal).

Example: cap Fare at 99th percentile

```python
upper = df['Fare'].quantile(0.99)
df['Fare_clipped'] = df['Fare'].clip(upper=upper)
```

## 4.5 Categorical encoding

### Label encoding (for ordinal or when mapping is known)

```python
le = LabelEncoder()
df['Sex_label'] = le.fit_transform(df['Sex'])  # female->0, male->1 (order depends on unique values)
```

Caution: label encoding gives a numeric ordering; only use when order is meaningful or model can handle categorical variables differently (e.g., tree models can use label encoding without implying linear ordering as strongly as linear models).

### One-hot encoding (recommended for nominal variables)

```python
# pandas one-hot
df = pd.get_dummies(df, columns=['Embarked', 'Pclass'], drop_first=False)

# or sklearn OneHotEncoder inside ColumnTransformer for pipeline
```

### Ordinal encoding

If you have an education level feature `[HighSchool < Bachelors < Masters < PhD]`, apply OrdinalEncoder with explicit categories.

## 4.6 Discretization / Binning

Use `pd.cut()` to convert continuous to discrete bins. Example:

```python
bins = [0, 3, 17, 63, 99]
labels = ['Baby/Toddler','Child','Adult','Elderly']
df['Age_group'] = pd.cut(df['Age'].fillna(-1), bins=bins, labels=labels)
```

Explain: Binning can reduce noise and produce interpretable features but can also discard information.

## 4.7 Normalization & Standardization

* **Min-Max scaling** maps features into [0,1]. Good for neural networks.
* **Z-score (StandardScaler)** centers features to zero mean and unit variance. Good for many algorithms (logistic regression, SVM).

Example:

```python
scaler = MinMaxScaler()
df[['Fare_scaled','Age_scaled']] = scaler.fit_transform(df[['Fare','Age']].fillna(0))

std = StandardScaler()
df[['Fare_std','Age_std']] = std.fit_transform(df[['Fare','Age']].fillna(0))
```

Caution: fit scalers only on training data and apply transform to validation/test sets.

## 4.8 Final pipeline example (compact)

```python
from sklearn.pipeline import Pipeline
from sklearn.compose import ColumnTransformer
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import OneHotEncoder, StandardScaler

numeric_features = ['Age','Fare','SibSp','Parch']
numeric_transformer = Pipeline(steps=[
    ('imputer', SimpleImputer(strategy='median')),
    ('scaler', StandardScaler())
])

categorical_features = ['Sex','Embarked','Pclass']
cat_transformer = Pipeline(steps=[
    ('imputer', SimpleImputer(strategy='most_frequent')),
    ('onehot', OneHotEncoder(handle_unknown='ignore'))
])

preprocessor = ColumnTransformer(
    transformers=[
        ('num', numeric_transformer, numeric_features),
        ('cat', cat_transformer, categorical_features)
    ])

clf_pipeline = Pipeline(steps=[('preprocessor', preprocessor)])

# Then use clf_pipeline.fit(X_train) and clf_pipeline.transform(X_test)
```

---

# 5. Lab Task solutions (complete)

> **Reminder**: The lab asks you to implement these in a notebook and **show the output to the instructor**. Include screenshots or the notebook `.ipynb` file.

## Lab Task 1 — Impute null values using average of previous and next value

**Problem statement:** "Download and load a dataset. Now, write a Python program to impute null values (if any) using the average value of its previous and next value."

**Approach & notes:**

* This imputation assumes that data is ordered in a meaningful way (for example by time or index). It makes sense for sequences where neighbors are similar.
* For missing values at the beginning or end (no previous or next), we can fall back to: next/previous value (single neighbor) or to global mean/median.

**Implementation (general function):**

```python
def impute_with_neighbor_average(series: pd.Series) -> pd.Series:
    """Impute NaNs by taking the average of the previous and next non-NaN values.

    If the NaN is at the start or end, use the nearest neighbor (or global mean as last resort).
    The function returns a new Series with imputed values.
    """
    s = series.copy()
    n = len(s)
    for i in range(n):
        if pd.isnull(s.iloc[i]):
            # find previous non-null
            prev_idx = i - 1
            while prev_idx >= 0 and pd.isnull(s.iloc[prev_idx]):
                prev_idx -= 1
            # find next non-null
            next_idx = i + 1
            while next_idx < n and pd.isnull(s.iloc[next_idx]):
                next_idx += 1

            prev_val = s.iloc[prev_idx] if prev_idx >= 0 else np.nan
            next_val = s.iloc[next_idx] if next_idx < n else np.nan

            if not pd.isnull(prev_val) and not pd.isnull(next_val):
                s.iloc[i] = (prev_val + next_val) / 2.0
            elif not pd.isnull(prev_val):
                s.iloc[i] = prev_val
            elif not pd.isnull(next_val):
                s.iloc[i] = next_val
            else:
                # both neighbors missing: fallback to series mean
                s.iloc[i] = series.mean()
    return s

# Example usage on Titanic 'Age' column
# df['Age_neighbor_imputed'] = impute_with_neighbor_average(df['Age'])
```

**Explanation of behavior:**

* If a single missing cell has valid previous and next values, it's replaced by their mean.
* If there is a block of consecutive NaNs, we iterate left-to-right: each will be imputed based on nearest available neighbors which may themselves have been filled earlier if you process left-to-right. The function above checks neighbors from original (copied) series; if you want strictly original neighbors (not using previously imputed values), you can copy the original and compute using `s_original` for neighbor detection.

**Edge cases:**

* If the entire column is null, the fallback is the column mean — which would be NaN; you should detect this and perhaps set to 0 or raise an error.
* If data isn't ordered meaningfully, this method introduces bias; prefer median/machine-learning imputation.

---

## Lab Task 2 — One-hot encoding of categorical values

**Problem statement:** "Using one-hot encoding, convert categorical values into numerical values."

**Implementation (pandas)**:

```python
# Suppose df has columns: 'Sex', 'Embarked', 'Pclass' (if you want Pclass as categories)
df_ohe = pd.get_dummies(df, columns=['Sex','Embarked'], prefix=['Sex','Embarked'], drop_first=False)

# Inspect result
print(df_ohe.head())
```

**Notes:**

* `drop_first=True` drops one column per original categorical column to prevent perfect multicollinearity in linear models. Use with caution depending on the model.
* For pipelines, prefer `OneHotEncoder(handle_unknown='ignore')` inside a `ColumnTransformer` so you maintain consistent columns at train and test time.

**If you want a reusable function:**

```python
from typing import List

def one_hot_encode_dataframe(df: pd.DataFrame, cols: List[str], drop_first: bool = False) -> pd.DataFrame:
    return pd.get_dummies(df, columns=cols, drop_first=drop_first)

# usage
# df_encoded = one_hot_encode_dataframe(df, ['Sex','Embarked'])
```

---

# 6. Additional examples & utilities

### Function: drop columns with too many nulls

```python
def drop_high_null_columns(df, threshold=0.5):
    # drops columns with a fraction of nulls >= threshold
    return df.loc[:, df.isnull().mean() < threshold]
```

### Function: fill categorical unknowns

```python
def fill_categorical_unknown(df, cols):
    for c in cols:
        df[c] = df[c].fillna('Unknown')
    return df
```

### Function: clip outliers by percentile

```python
def clip_by_percentile(series, lower_q=0.01, upper_q=0.99):
    lower = series.quantile(lower_q)
    upper = series.quantile(upper_q)
    return series.clip(lower=lower, upper=upper)
```

---

# 7. Best practices, pitfalls & submission checklist

**Best practices:**

* Always **split** into train/validation/test before doing operations that learn from the dataset (e.g., scaling, imputing based on global mean) unless you are careful to compute those statistics on training only.
* Keep the preprocessing steps in a pipeline so the same exact transforms can be applied to new data.
* Use `handle_unknown='ignore'` for one-hot encoders in production.
* Document every decision (why you dropped a column, why you used median vs mean).

**Common pitfalls:**

* Leaking test information (computing mean/std on full dataset before split).
* Label encoding nominal variables for linear models — leads to false ordering assumptions.
* Blindly dropping rows/columns with missing values — might remove important signal.

**Submission checklist for lab:**

* Jupyter notebook (`.ipynb`) with code cells and markdown explanations.
* Include the dataset path and a short README cell that explains how to run the notebook.
* Screenshots of key outputs (if required), or export the notebook to HTML and attach.
* Short discussion section: what worked, what didn't, suggestions for further improvement.

---

# 8. Lab Exercise — how to prepare the notebook for submission

1. Title cell with course, name, ID and date.
2. Brief intro and objective.
3. Load dataset cell and `df.head()` + `df.info()` + `df.isnull().sum()`.
4. Step-by-step transformations with short explanations and outputs.

   * show counts before/after imputation
   * show sample rows before/after one-hot encoding
   * show histograms or `describe()` after scaling
5. Conclude with pros/cons of each imputation and encoding strategy.
6. Attach generated plots and print shapes.

---

# 9. Discussion & Conclusion

Preprocessing is crucial — it often determines the ceiling performance of downstream models. Different tasks require different preprocessing choices. The code and functions above provide a reproducible and well-documented starting point.

---

## Appendix: Full example notebook order (summary)

1. Imports
2. Load dataset
3. Inspect data
4. Drop irrelevant columns
5. Handle missing values (several methods)
6. Encode categorical variables
7. Scale numeric variables
8. Save processed dataset
9. Short modelling step (optional) to show the effect (e.g., logistic regression baseline)
