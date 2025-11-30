import pandas as pd
import numpy as np
from sklearn.preprocessing import MinMaxScaler

# -----------------------------------------------------------
# STEP 0: Create the dataset
# -----------------------------------------------------------
data = {
    "Student_ID": [101, 102, 103, 104, 105],
    "CGPA": [3.8, 3.2, np.nan, 3.9, 2.7],           # Missing value
    "Major": ["CSE", "EEE", "Business", "CSE", "Economics"],
    "Internships": [2, 1, 0, 3, np.nan],             # Missing value
    "Placed": ["Yes", "No", "No", "Yes", "No"]
}

df = pd.DataFrame(data)
print("Original Dataset:\n", df)

# -----------------------------------------------------------
# STEP 1: Handle Missing Values
# -----------------------------------------------------------

# Fill missing CGPA with mean
df["CGPA"] = df["CGPA"].fillna(df["CGPA"].mean())

# Fill missing Internships with median
df["Internships"] = df["Internships"].fillna(df["Internships"].median())

print("\nAfter Handling Missing Values:\n", df)

# -----------------------------------------------------------
# STEP 2: Normalize Numeric Columns
# -----------------------------------------------------------

scaler = MinMaxScaler()
df[["CGPA", "Internships"]] = scaler.fit_transform(df[["CGPA", "Internships"]])

print("\nAfter Normalizing Numeric Columns:\n", df)

# -----------------------------------------------------------
# STEP 3: Encode Categorical Columns
# -----------------------------------------------------------

df_encoded = pd.get_dummies(df, columns=["Major", "Placed"], drop_first=True)

print("\nAfter Encoding Categorical Columns:\n", df_encoded)

# -----------------------------------------------------------
# STEP 4: Find Student With Highest CGPA in CSE Department
# -----------------------------------------------------------

# First, extract students from CSE department
cse_students = df[df["Major"] == "CSE"]

# Then find the row with max CGPA
highest_cgpa_cse = cse_students.loc[cse_students["CGPA"].idxmax()]

print("\nStudent With Highest CGPA in CSE Department:\n")
print(highest_cgpa_cse)
