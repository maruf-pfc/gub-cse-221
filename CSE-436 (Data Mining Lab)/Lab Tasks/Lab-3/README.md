# Data Preprocessing Lab — Completed Jupyter Notebook

**Course:** Data Mining LAB (CSE 424)

**Title:** Data Preprocessing Techniques — Full Lab Report

**Dataset chosen:** *House Prices - Advanced Regression Techniques* (Kaggle) — `train.csv` from the competition. This dataset contains many NULL values and varied garbage/inconsistent entries (good for demonstrating preprocessing techniques). If you prefer a different dataset (e.g., Titanic), you can swap the file and run the same notebook with minor changes.

---

## Notebook Overview / Table of Contents

1. Objective
2. Environment & How to run in Colab
3. Load dataset & initial inspection
4. Data cleaning

   * Identify missing data and garbage
   * Visualize missingness
5. Handling missing values

   * Simple imputation (mean/median/mode)
   * Group-wise imputation (median by neighborhood)
   * Imputation using previous & next values (neighbor-average function)
   * Deleting columns/rows (with justification)
6. Handling noisy data & outliers

   * Binning
   * Clipping & winsorization
7. Categorical encoding

   * Label encoding
   * Ordinal encoding (with mapping)
   * One-hot encoding
8. Feature engineering & transformations

   * Create new features
   * Discretization (pd.cut)
9. Normalization & Standardization

   * Min-Max scaling
   * StandardScaler
10. Preprocessing pipelines (sklearn ColumnTransformer)
11. Visual comparison: before vs after preprocessing
12. Quick baseline model to show effect (optional)
13. Conclusion & Submission notes

---

## 1 — Objective

Complete the lab exercise by implementing, demonstrating, explaining, and documenting common data preprocessing techniques on a real dataset containing NULL and garbage values. Provide runnable code, clear markdown explanations, and results that show how the dataset changes after each step.

---

## 2 — Environment & How to run in Colab

1. Open Google Colab.
2. Upload `train.csv` from the Kaggle House Prices dataset (or mount your Google Drive and place the file there).
3. Run cells sequentially. The notebook uses only standard libraries + scikit-learn.

**Required packages:** `pandas`, `numpy`, `matplotlib`, `seaborn`, `sklearn` (all available in Colab by default).

Example Colab cell to mount Drive:

```python
from google.colab import drive
drive.mount('/content/drive')
# then set your path, e.g. PATH = '/content/drive/MyDrive/datasets/house-prices/'
```

---

## 3 — Load dataset & initial inspection

```python
# Imports
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

from sklearn.model_selection import train_test_split
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import OneHotEncoder, OrdinalEncoder, LabelEncoder, StandardScaler, MinMaxScaler
from sklearn.pipeline import Pipeline
from sklearn.compose import ColumnTransformer
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

# Load dataset
df = pd.read_csv('train.csv')  # change path if needed

# Quick inspection
print('Shape:', df.shape)
print(df.head().T.iloc[:25])  # transpose to see columns
print('
Info:')
df.info()

print('
Missing values per column:')
print(df.isnull().sum().sort_values(ascending=False).head(30))

# A few descriptive stats
print('
Describe numeric:')
print(df.describe().T)
```

**Explanation:** We inspect shape, head, `.info()` to identify data types and missing values. The House Prices dataset typically has many missing values in `LotFrontage`, `Alley`, `MasVnrType/Area`, `Garage*`, `Bsmt*` columns.

---

## 4 — Data cleaning: Identify missing data and garbage values

```python
# Percentage of missing values per column
missing_pct = df.isnull().mean().sort_values(ascending=False)
missing_pct[missing_pct>0].head(50)

# Visualize missingness with a heatmap (sample of rows to avoid clutter)
sns.heatmap(df.isnull().sample(200), cbar=False)
plt.title('Missing values heatmap (sample=200 rows)')
plt.show()

# Check for obvious garbage values (like strings in numeric columns or negative values)
for col in df.select_dtypes(include=['int64','float64']).columns:
    if (df[col] < 0).any():
        print('Negative values in', col)

# Check categorical columns unique sample
for col in df.select_dtypes(include=['object']).columns[:10]:
    print(col, '->', df[col].unique()[:10])
```

**Explanation:** Visual and programmatic checks reveal where missing values are concentrated and whether there are formatting issues in categorical columns.

---

## 5 — Handling missing values

We will apply several strategies and explain trade-offs.

### 5.1 Strategy 1: Simple imputation — mean/median for numeric, mode for categorical

```python
# Copy original for comparison
df_simple = df.copy()

# Numeric columns imputed by median (robust to outliers)
num_cols = df_simple.select_dtypes(include=['int64','float64']).columns.tolist()
num_imputer = SimpleImputer(strategy='median')

df_simple[num_cols] = pd.DataFrame(num_imputer.fit_transform(df_simple[num_cols]), columns=num_cols)

# Categorical imputation: fill with 'Missing' for clarity
cat_cols = df_simple.select_dtypes(include=['object']).columns.tolist()
df_simple[cat_cols] = df_simple[cat_cols].fillna('Missing')

print('Missing after simple imputation:', df_simple.isnull().sum().sum())
```

**Explanation:** Median is used for numeric to reduce the effect of outliers. Categorical columns get a `'Missing'` label, preserving frequency counts and allowing models to treat missing as a category.

### 5.2 Strategy 2: Group-wise imputation (median by neighborhood or similar)

Rationale: Some features vary strongly by groups — e.g., `LotFrontage` might depend on `Neighborhood`. Use group medians to impute.

```python
# Example: impute LotFrontage by median LotFrontage within each Neighborhood
df_group = df.copy()

df_group['LotFrontage'] = df_group.groupby('Neighborhood')['LotFrontage'].apply(lambda x: x.fillna(x.median()))

# If some neighborhoods have all nulls, fallback to overall median
df_group['LotFrontage'] = df_group['LotFrontage'].fillna(df_group['LotFrontage'].median())

print('Nulls in LotFrontage after group impute:', df_group['LotFrontage'].isnull().sum())
```

**Explanation:** This preserves local structure and often yields better downstream model performance than global mean/median.

### 5.3 Strategy 3: Impute missing values using average of previous & next values (neighbor-average)

**Important:** This method assumes a meaningful row ordering (e.g., time series or sorted by a relevant key). For tabular datasets like House Prices, neighbor-average is less common; but we implement it for the lab requirement and demonstrate on a chosen numeric column.

```python
# General function for neighbor average imputation
import math

def impute_with_neighbor_average(series: pd.Series) -> pd.Series:
    s = series.copy()
    n = len(s)
    # We'll use numpy arrays for faster assignment
    arr = s.values
    for i in range(n):
        if pd.isnull(arr[i]):
            # find prev
            prev_idx = i - 1
            while prev_idx >= 0 and pd.isnull(arr[prev_idx]):
                prev_idx -= 1
            # find next
            next_idx = i + 1
            while next_idx < n and pd.isnull(arr[next_idx]):
                next_idx += 1

            prev_val = arr[prev_idx] if prev_idx >= 0 else np.nan
            next_val = arr[next_idx] if next_idx < n else np.nan

            if not pd.isnull(prev_val) and not pd.isnull(next_val):
                arr[i] = (prev_val + next_val) / 2.0
            elif not pd.isnull(prev_val):
                arr[i] = prev_val
            elif not pd.isnull(next_val):
                arr[i] = next_val
            else:
                arr[i] = np.nan  # leave as nan, fallback handled later
    return pd.Series(arr, index=series.index)

# Demonstrate on LotFrontage after sorting by Neighborhood then Id (just to create grouping)
df_neighbor = df.copy().sort_values(['Neighborhood','Id']).reset_index(drop=True)
df_neighbor['LotFrontage_imputed_neighbor'] = impute_with_neighbor_average(df_neighbor['LotFrontage'])

# Fill remaining with median
df_neighbor['LotFrontage_imputed_neighbor'] = df_neighbor['LotFrontage_imputed_neighbor'].fillna(df_neighbor['LotFrontage'].median())

print('Remaining nulls:', df_neighbor['LotFrontage_imputed_neighbor'].isnull().sum())
```

**Explanation & caveat:** The neighbor-average method works best when rows are ordered such that adjacent rows are similar (time-series, sensor data). For cross-sectional tabular data, neighbor averaging can introduce noise unless you sort by a meaningful key; use this only with justification.

### 5.4 Strategy 4: Dropping columns or rows

We drop columns if they are mostly missing and not easily recoverable or not useful. Eg., if a column has >80% missing values and can't be meaningfully imputed, consider dropping it.

```python
# Example: drop columns with more than 80% missing
threshold = 0.8
cols_to_drop = missing_pct[missing_pct > threshold].index.tolist()
df_drop = df.copy().drop(columns=cols_to_drop)
print('Dropped columns:', cols_to_drop)
print('Shape after dropping:', df_drop.shape)
```

**Explanation:** Document the dropped columns and why. If those columns are potentially important, document alternative imputation methods and why they were rejected.

---

## 6 — Handling noisy data & outliers

### 6.1 Binning (discretization) — example on `GrLivArea`

```python
# Create bins for GrLivArea
series = df['GrLivArea'].fillna(df['GrLivArea'].median())
labels = ['VerySmall','Small','Medium','Large','VeryLarge']
bins = pd.qcut(series, q=5, labels=labels)
print(bins.value_counts())

# Attach to df
df_binned = df.copy()
df_binned['GrLivArea_bin'] = bins
```

**Explanation:** qcut creates quantile-based bins so each bin has roughly equal counts. This can reduce influence of extreme values.

### 6.2 Clipping & winsorization

```python
# Clip SalePrice to 99th percentile
upper = df['SalePrice'].quantile(0.99)
lower = df['SalePrice'].quantile(0.01)
df_clip = df.copy()
df_clip['SalePrice_clipped'] = df_clip['SalePrice'].clip(lower=lower, upper=upper)

print('Original max:', df['SalePrice'].max())
print('Clipped max:', df_clip['SalePrice_clipped'].max())
```

**Explanation:** Clipping caps extreme values to reduce their influence on models sensitive to scale and outliers.

---

## 7 — Categorical encoding

### 7.1 Label encoding for binary variable (Sex-like) — example: `Street` has 'Grvl' or 'Pave'

```python
# Example: label encode Street (if desired)
df_enc = df.copy()
if 'Street' in df_enc.columns:
    df_enc['Street_label'] = df_enc['Street'].map({'Grvl':0,'Pave':1})
    print('Street mapping applied')
```

**Explanation:** For binary categorical variables, mapping to 0/1 is straightforward.

### 7.2 Ordinal encoding for ordered categories

If a column has an inherent order — e.g., `ExterQual` = ['Po','Fa','TA','Gd','Ex'] — map explicitly.

```python
exter_map = {'Po':1, 'Fa':2, 'TA':3, 'Gd':4, 'Ex':5}
if 'ExterQual' in df.columns:
    df_ord = df.copy()
    df_ord['ExterQual_ord'] = df_ord['ExterQual'].map(exter_map)
    print(df_ord[['ExterQual','ExterQual_ord']].head())
```

**Explanation:** Ordinal encoding must reflect the correct order. Always document your mapping.

### 7.3 One-hot encoding (pandas or sklearn)

Use `pd.get_dummies()` for quick encoding; use `OneHotEncoder` in pipelines for production.

```python
# Quick OHE with pandas on top categorical columns (limit to top N unique values to avoid high-dim)
cat_cols = df.select_dtypes(include=['object']).columns.tolist()
# choose a subset to avoid explosion, e.g., top 5 nominal columns by unique values
sel_cols = [c for c in cat_cols if df[c].nunique() < 20][:6]

df_ohe = pd.get_dummies(df.fillna('Missing'), columns=sel_cols, drop_first=False)
print('OHE new shape:', df_ohe.shape)
```

**Explanation:** Drop columns with many unique categories before naive one-hot or use target encoding / hashing for high-cardinality variables.

---

## 8 — Feature engineering & discretization

```python
# Example new features
df_feat = df.copy()
# Total bathrooms
df_feat['TotalBath'] = df_feat['FullBath'].fillna(0) + 0.5*df_feat['HalfBath'].fillna(0) + df_feat['BsmtFullBath'].fillna(0) + 0.5*df_feat['BsmtHalfBath'].fillna(0)

# Age of house (assuming YearBuilt exists)
df_feat['HouseAge'] = df_feat['YrSold'] - df_feat['YearBuilt']

# Discretize HouseAge
df_feat['HouseAge_bin'] = pd.cut(df_feat['HouseAge'].fillna(df_feat['HouseAge'].median()), bins=[-1,10,30,60,200], labels=['New','Mid','Old','VeryOld'])

print(df_feat[['TotalBath','HouseAge','HouseAge_bin']].head())
```

**Explanation:** Feature engineering can improve model signal — total bathrooms and house age are common and intuitive.

---

## 9 — Normalization & Standardization

```python
# Choose numeric features for scaling
numeric_cols = df.select_dtypes(include=['int64','float64']).columns.tolist()
# exclude Id and target
numeric_cols = [c for c in numeric_cols if c not in ['Id','SalePrice']]

scaler = MinMaxScaler()
df_scale = df.copy()
df_scale[numeric_cols] = scaler.fit_transform(df_scale[numeric_cols].fillna(0))

# Alternatively standardize
std = StandardScaler()
df_std = df.copy()
df_std[numeric_cols] = std.fit_transform(df_std[numeric_cols].fillna(0))

print('Scaled sample:')
print(df_scale[numeric_cols].iloc[:3])
```

**Explanation:** Scaling ensures features are comparable and helps algorithms converge faster.

---

## 10 — Preprocessing pipelines (sklearn ColumnTransformer)

Package all transformations into a reproducible pipeline.

```python
# Example pipeline: numeric median impute + standard scale, categorical one-hot (limited set)
numeric_features = ['LotFrontage','LotArea','OverallQual','OverallCond','YearBuilt','GrLivArea']
# pick features that exist in dataset
numeric_features = [f for f in numeric_features if f in df.columns]

categorical_features = sel_cols  # from earlier selection

numeric_transformer = Pipeline(steps=[
    ('imputer', SimpleImputer(strategy='median')),
    ('scaler', StandardScaler())
])

categorical_transformer = Pipeline(steps=[
    ('imputer', SimpleImputer(strategy='constant', fill_value='Missing')),
    ('onehot', OneHotEncoder(handle_unknown='ignore', sparse=False))
])

preprocessor = ColumnTransformer(
    transformers=[
        ('num', numeric_transformer, numeric_features),
        ('cat', categorical_transformer, categorical_features)
    ], remainder='drop')

# Combine with a simple model to illustrate
model_pipeline = Pipeline(steps=[('preprocessor', preprocessor), ('regressor', LinearRegression())])

# Train/test split (for demonstration; not for final evaluation)
train, test = train_test_split(df[df['SalePrice'].notnull()], test_size=0.2, random_state=42)
X_train = train[numeric_features + categorical_features]
y_train = train['SalePrice']
X_test = test[numeric_features + categorical_features]
y_test = test['SalePrice']

# Fit model — note: many NaNs and missing categories exist so this is only illustrative
model_pipeline.fit(X_train, y_train)
preds = model_pipeline.predict(X_test)
print('RMSE:', np.sqrt(mean_squared_error(y_test, preds)))
```

**Explanation:** ColumnTransformer lets you apply different preprocessing to numeric and categorical features and keep everything reproducible.

---

## 11 — Visual comparison: before vs after preprocessing

Show a few histograms/boxplots demonstrating the effect of scaling and clipping.

```python
# Before scaling
plt.figure(figsize=(12,4))
plt.subplot(1,2,1)
sns.histplot(df['SalePrice'].dropna(), kde=True)
plt.title('SalePrice (original)')

# After clipping
plt.subplot(1,2,2)
sns.histplot(df_clip['SalePrice_clipped'].dropna(), kde=True)
plt.title('SalePrice (clipped 1-99 percentile)')
plt.show()

# Show numeric boxplot before and after scaling for GrLivArea
plt.figure(figsize=(10,4))
plt.subplot(1,2,1)
sns.boxplot(x=df['GrLivArea'].dropna())
plt.title('GrLivArea original')

plt.subplot(1,2,2)
sns.boxplot(x=df_scale['GrLivArea'].dropna())
plt.title('GrLivArea min-max scaled')
plt.show()
```

**Explanation:** Visuals help the reader understand how distributions and outliers change with preprocessing.

---

## 12 — Quick baseline model to show effect (optional)

We already trained a quick linear regression to illustrate RMSE. To show the effect of preprocessing, train the model with two different preprocessing strategies (simple global median impute + standardize vs advanced group-wise impute + engineered features) and compare RMSE reports.

```python
# Example: compare simple vs group-wise approaches
# (left as an exercise to run and record exact RMSE values for your submission)
```

**Explanation:** Include a short table in your final report comparing RMSE/MAE for each preprocessing strategy.

---

## 13 — Conclusion & Submission notes

* Include the `.ipynb` file and a short PDF report that summarizes the dataset, the techniques used, and results (use screenshots where helpful).
* In the notebook, for each transformation, include a markdown cell: "What I did", "Why I did it", "Effect on data".
* Document any columns dropped and the exact reasoning.

**Academic policy reminder:** Do not copy someone else's work. Clearly state any external references you used.

---

## Appendix — Useful helper functions (copy into a cell)

```python
# Reusable functions

def show_missing_table(df):
    miss = df.isnull().sum()
    miss_pct = (miss / len(df)).sort_values(ascending=False)
    return pd.DataFrame({'missing_count': miss, 'missing_pct': miss_pct})


def drop_high_null_columns(df, threshold=0.8):
    cols = df.columns[df.isnull().mean() > threshold].tolist()
    return df.drop(columns=cols), cols


def one_hot_limited(df, cols, max_unique=20):
    eligible = [c for c in cols if df[c].nunique() <= max_unique]
    return pd.get_dummies(df, columns=eligible, drop_first=False)
```
