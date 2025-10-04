import pandas as pd

# Loading the dataset from the provided URL
df = pd.read_csv("https://raw.githubusercontent.com/Ataullha/CSE-412_Machine-Learning-Lab/refs/heads/main/titanic_train.csv")

# Display the first 5 rows of the dataframe to get a quick look at the data
print(df.head())

# Display the last 5 rows of the dataframe to understand the end of the dataset
print(df.tail())

# Print the total number of rows in the dataframe
print(len(df))  # This will output the number of rows in the dataset

# Print the shape of the dataframe: (number of rows, number of columns)
print(df.shape)

# Access the 'age' column as a Series (a 1-dimensional array)
print(df['age'])  # This outputs the 'age' column as a Series

# Access the 'age' column as a DataFrame (2-dimensional structure)
print(df[['age']])  # This outputs the 'age' column as a DataFrame

# Count the number of missing (NaN) values in the 'age' column
print(df['age'].isnull().sum())

# **Filling missing values**: 
# 1. Fill missing values with the mean of the 'age' column
# 2. Alternatively, fill missing values in-place

# Fill missing values with the mean of 'age'
df['age'] = df['age'].fillna(df['age'].mean())

# Alternatively, you can use inplace=True to modify the dataframe without reassignment
# df['age'].fillna(df['age'].mean(), inplace=True)

# Re-check the number of missing values in the 'age' column after filling
print(df['age'].isnull().sum())

# Explanation of the two methods to fill missing values:
'''
- If you want to retain the original dataframe and create a modified version, use df['age'] = ...
- If you want to modify the dataframe in-place without needing to reassign, use inplace=True.
'''

# Get a 5-point summary (min, max, mean, std, etc.) of the numerical columns in the dataframe
print(df.describe())

# Get information about the dataframe including data types and non-null counts
print(df.info())

# **Normalization**: Min-Max normalization scales features to a [0, 1] range
# Formula: (x - x_min) / (x_max - x_min)
# Example:
# | Value | Normalized Value |
# |-------|------------------|
# | 1     | (1 - 1) / (5 - 1) = 0   |
# | 2     | (2 - 1) / (5 - 1) = 1/4 |
# | 5     | (5 - 1) / (5 - 1) = 1   |

# Perform Min-Max normalization on the 'age' column
df['age'] = (df['age'] - df['age'].min()) / (df['age'].max() - df['age'].min())

# **Filtering**: Important for filtering rows based on conditions
# Example: Count how many rows have 'age' greater than or equal to 1
print(sum(df['age'] >= 1))

# Filtering rows where 'age' is equal to the maximum value and getting the corresponding 'cabin' values
# This returns the 'cabin' value(s) for the rows where 'age' is equal to its maximum value
print(df[df['age'] == df['age'].max()]['cabin'])

# **Z-Score (Standard Normalization)**: Another way to normalize data (not implemented here)
# Z-score normalization formula: (x - mean) / standard deviation

# ===========================
# Encoding (String -> Numeric)
# Encoding has 3 types:
# 1) Label Encoding
# 2) Ordinal Encoding
# 3) One-hot Encoding
# ===========================

# 1. Label Encoding: Assigns each category a unique integer value.

# Example: 
# Hair Color -> Red = 0, Blue = 1
# 'Red' will be encoded as 0, 'Blue' as 1, and so on.

le = LabelEncoder()
df['sex'] = le.fit_transform(df['sex'])  # Encode the 'sex' column
print(df['sex'])  # Output the encoded 'sex' column

# 2. Ordinal Encoding: Assigns an ordered integer value to categories.

# Example:
# First = 0, Second = 1, Third = 2 (or any custom order)

ordinal_encoder = OrdinalEncoder()
df['sex'] = ordinal_encoder.fit_transform(df[['sex']])  # Ordinal encoding for 'sex' column
print(df['sex'])  # Output the encoded 'sex' column

# 3. One-Hot Encoding: Creates separate columns for each category (binary representation).

# Example:
# Gender: Male | Female
# One-hot encoding will create two new columns: 'Male' and 'Female', where:
# - Male = 1, Female = 0 for Male entries.
# - Male = 0, Female = 1 for Female entries.

onehot_encoder = OneHotEncoder(sparse=False)  # sparse=False returns a dense array instead of sparse matrix
encoded_sex = onehot_encoder.fit_transform(df[['sex']])  # One-hot encode the 'sex' column
encoded_sex_df = pd.DataFrame(encoded_sex, columns=onehot_encoder.get_feature_names_out(['sex']))  # Convert to DataFrame
print(encoded_sex_df)  # Output the one-hot encoded DataFrame for 'sex'

# Optional: You can concatenate this one-hot encoded DataFrame back to your original DataFrame if needed
df = pd.concat([df, encoded_sex_df], axis=1)

# drop multicolumn
df.drop(['name', 'boat', 'body', 'home.dest', 'cabin'], axis=1, inplace=True)

# one hot encoding
pd.get_dummies(df)