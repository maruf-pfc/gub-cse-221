from sklearn.datasets import load_iris
iris = load_iris()

print(iris)
'''
data: numpy array -> 150 rows, 4 columns
target: numpy array -> label / species [0: setosa, 1: versicolor, 2: virginica]
feature_names:  list of strings -> 4 columns ['sepal length (cm)', 'sepal width (cm)', 'petal length (cm)', 'petal width (cm)']
target_names: list of strings -> ['setosa', 'versicolor', 'virginica']
DESCR
filename
'''

# To see the first 5 rows of numerical data
print("Data (first 5 samples):")
print(iris.data[:5])
# Output:
# [[5.1 3.5 1.4 0.2]
#  [4.9 3.  1.4 0.2]
#  [4.7 3.2 1.3 0.2]
#  [4.6 3.1 1.5 0.2]
#  [5.  3.6 1.4 0.2]]


# To see the feature names
print("\nFeature Names:")
print(iris.feature_names)
# Output:
# ['sepal length (cm)', 'sepal width (cm)', 'petal length (cm)', 'petal width (cm)']


# To see the target names (the species)
print("\nTarget Names:")
print(iris.target_names)
# Output:
# ['setosa' 'versicolor' 'virginica']

# print("\nDESCR:")
# print(iris.DESCR)
