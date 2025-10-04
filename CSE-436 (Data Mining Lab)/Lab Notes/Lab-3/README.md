# **Pandas DataFrame Operations:**

## **1. Importing pandas and Loading a Dataset**

```python
import pandas as pd
```

The `pandas` library is used to manipulate and analyze data in Python. We use `pd.read_csv()` to load CSV data into a pandas DataFrame.

```python
df = pd.read_csv("https://raw.githubusercontent.com/Ataullha/CSE-412_Machine-Learning-Lab/refs/heads/main/titanic_train.csv")
```

This loads a dataset from the given URL into the `df` variable as a pandas DataFrame.

---

## **2. Exploring the DataFrame**

### **Viewing the First and Last Few Rows**

```python
print(df.head())  # Shows first 5 rows of the DataFrame
print(df.tail())  # Shows last 5 rows of the DataFrame
```

- `df.head()` returns the first 5 rows by default, but you can specify the number like `df.head(10)` to get the first 10 rows.
- `df.tail()` works similarly, but returns the last 5 rows.

### **Counting the Number of Rows**

```python
print(len(df))  # Prints the number of rows
```

- `len(df)` returns the number of rows in the DataFrame.

### **Shape of the DataFrame**

```python
print(df.shape)
```

- `df.shape` returns a tuple representing the number of rows and columns in the DataFrame. It returns `(rows, columns)`.

---

## **3. Accessing Data in DataFrame**

### **Accessing a Column (Series)**

```python
print(df['age'])  # This is a Series
```

- `df['age']` accesses the 'age' column and returns a **Series** object (1D array-like structure).

### **Accessing a Column (DataFrame)**

```python
print(df[['age']])  # This is a DataFrame
```

- `df[['age']]` accesses the 'age' column, but in **DataFrame** format (2D structure). It’s a subset of the original DataFrame.

---

## **4. Handling Missing Data**

### **Checking for Missing Values**

```python
print(df['age'].isnull().sum())
```

- `df['age'].isnull()` returns a boolean Series indicating whether each value in the 'age' column is `NaN` (missing).
- `.sum()` counts the number of missing values (True = 1, False = 0).

### **Filling Missing Values with Mean**

```python
df['age'] = df['age'].fillna(df['age'].mean())  # Method 1
# or
df['age'].fillna(df['age'].mean(), inplace=True)  # Method 2
```

- **Method 1:** `df['age'] = df['age'].fillna(df['age'].mean())` creates a new column with the missing values filled with the mean of the column and reassigns it to `df['age']`.
- **Method 2:** `df['age'].fillna(df['age'].mean(), inplace=True)` directly modifies the original DataFrame without creating a new column.

---

## **5. Summary Statistics**

### **Descriptive Statistics**

```python
print(df.describe())
```

- `df.describe()` provides summary statistics for numerical columns, including:

  - **count**: The number of non-null values.
  - **mean**: The mean value.
  - **std**: The standard deviation.
  - **min**: The minimum value.
  - **25%**: The first quartile (25th percentile).
  - **50%**: The median (50th percentile).
  - **75%**: The third quartile (75th percentile).
  - **max**: The maximum value.

### **DataFrame Information**

```python
print(df.info())
```

- `df.info()` provides a summary of the DataFrame, including:

  - Number of entries (rows).
  - Column names.
  - Non-null counts (how many non-missing values in each column).
  - Data types of each column.

---

## **6. Column Removal**

```python
df.drop('column-name', axis=1)
```

- `axis=1` means you are dropping a column (axis=0 would drop rows).
- **Important:** The `drop()` function **does not modify the original DataFrame** unless `inplace=True` is used.

Example of removing multiple columns:

```python
df.drop(['name', 'boat', 'body', 'home.dest', 'cabin'], axis=1, inplace=True)
```

---

## **7. Normalization Techniques**

### **Min-Max Normalization (Rescaling)**

The formula for Min-Max normalization is:

[
\text{eq} = \frac{x - \text{min}(x)}{\text{max}(x) - \text{min}(x)}
]

Where `x` is the data point, `min(x)` is the minimum value, and `max(x)` is the maximum value of the column.

```python
df['age'] = (df['age'] - df['age'].min()) / (df['age'].max() - df['age'].min())
```

This rescales the values of the 'age' column to a range between 0 and 1.

#### **Example of Min-Max Normalization:**

| Original | Normalized | Formula                        |
| -------- | ---------- | ------------------------------ |
| 1        | 0          | (1 - 1) / (5 - 1) = 0          |
| 2        | 0.25       | (2 - 1) / (5 - 1) = 1/4 = 0.25 |
| 5        | 1          | (5 - 1) / (5 - 1) = 1          |

---

### **Z-Score (Standard) Normalization**

The formula for Z-Score normalization is:

[
z = \frac{x - \mu}{\sigma}
]

Where:

- `x` is the data point.
- `μ` is the mean of the column.
- `σ` is the standard deviation of the column.

This transforms data so that it has a mean of 0 and a standard deviation of 1. It is particularly useful when the data follows a Gaussian distribution.

```python
df['age'] = (df['age'] - df['age'].mean()) / df['age'].std()
```

---

## **8. Encoding Data (String → Numeric)**

### **Types of Encoding:**

1. **Label Encoding**: Assigns each unique string label a unique integer value.

   - Example:

     - `Male` → 0, `Female` → 1.

2. **Ordinal Encoding**: Assigns an ordered integer value to categories.

   - Example:

     - `First` → 0, `Second` → 1, `Third` → 2.

3. **One-Hot Encoding**: Creates separate binary columns for each category.

   - Example:

     - `Male` → `Male=1`, `Female=0`; `Female` → `Male=0`, `Female=1`.

```python
# Label Encoding
from sklearn.preprocessing import LabelEncoder
le = LabelEncoder()
df['sex'] = le.fit_transform(df['sex'])  # Encode the 'sex' column
print(df['sex'])  # Output the encoded 'sex' column

# Ordinal Encoding
from sklearn.preprocessing import OrdinalEncoder
ordinal_encoder = OrdinalEncoder()
df['sex'] = ordinal_encoder.fit_transform(df[['sex']])  # Ordinal encoding for 'sex' column
print(df['sex'])  # Output the encoded 'sex' column

# One-Hot Encoding
from sklearn.preprocessing import OneHotEncoder
onehot_encoder = OneHotEncoder(sparse=False)  # sparse=False returns a dense array instead of sparse matrix
encoded_sex = onehot_encoder.fit_transform(df[['sex']])  # One-hot encode the 'sex' column
encoded_sex_df = pd.DataFrame(encoded_sex, columns=onehot_encoder.get_feature_names_out(['sex']))  # Convert to DataFrame
print(encoded_sex_df)  # Output the one-hot encoded DataFrame for 'sex'

# Concatenate one-hot encoded columns back to the DataFrame
df = pd.concat([df, encoded_sex_df], axis=1)
```

---

## **9. Filtering Data (Important for Classification/Regression)**

### **Basic Filtering:**

```python
print(sum(df['age'] >= 1))  # Count how many rows have 'age' >= 1
```

- This checks how many rows in the 'age' column have a value greater than or equal to 1.

### **Filtering Specific Values:**

```python
print(df[df['age'] == df['age'].max()]['cabin'])
```

- This filters the 'age' column to find the row(s) where the value is the maximum (`df['age'].max()`), and then accesses the 'cabin' column of those rows.

---

## **Conclusion:**

This README covers essential operations you can perform on a pandas DataFrame:

1. **Data Exploration**: Loading, viewing, and understanding the structure of the data.
2. **Missing Data Handling**: Identifying and filling missing values with techniques like the mean or median.
3. **Data Normalization**: Scaling data using Min-Max normalization or Z-score normalization.
4. \*\*Basic Data Filtering
