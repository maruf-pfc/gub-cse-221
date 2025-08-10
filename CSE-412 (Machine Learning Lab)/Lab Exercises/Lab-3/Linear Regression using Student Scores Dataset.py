import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn import metrics

dataset = pd.read_csv('student_scores.csv')
print(dataset.head())
'''
   Hours  Scores
0    2.5      21
1    5.1      47
2    3.2      27
3    8.5      75
4    3.5      30
'''

dataset.plot(x='Hours', y='Scores', style='o')
plt.title("Hours vs Percentage")
plt.xlabel("Hours Studied")
plt.ylabel("Percentage Score")
plt.show()

X = dataset.iloc[:, :-1].values
y = dataset.iloc[:, 1].values
'''
X = dataset.iloc[:, :-1].values

This line creates your features matrix (usually denoted as X).

dataset.iloc: This tells pandas you want to select rows and columns by their integer position (e.g., row 0, column 1).

: (before the comma): The colon by itself means "select all rows."

:-1 (after the comma): This means "select all columns from the beginning up to, but not including, the last one."

.values: This converts the resulting pandas DataFrame into a NumPy array, which is the standard format for machine learning libraries.
'''

# print(X, y)

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)
regressor = LinearRegression()
regressor.fit(X_train, y_train)

y_pred = regressor.predict(X_test)
df = pd.DataFrame({'Actual': y_test, 'Predicted': y_pred})
print(df.head())
'''
   Actual  Predicted
0      20  16.884145
1      27  33.732261
2      69  75.357018
3      30  26.794801
4      62  60.491033
'''

mse = metrics.mean_squared_error(y_test, y_pred)
print(f"MSE = {mse}")
