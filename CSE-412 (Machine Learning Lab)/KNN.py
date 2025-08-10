# Importing the Tools
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn import metrics

# Loading and Preparing the Data
iris = load_iris()

X = iris.data[:, :]
y = iris.target

# print(X, y)

# Split Data into Training and Testing
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.30)

# Feature Scaling (Standardization)
scaler = StandardScaler()

scaler.fit(X_train)
# The scaler learns the mean and standard deviation from the training data only. This is a crucial rule to prevent "data leakage," where information from the test set unfairly influences the training process.

X_train = scaler.transform(X_train)
X_test = scaler.transform(X_test)

# print(X_train, X_test)
print(X_train.shape, X_test.shape) # (105, 4) (45, 4)
print(y_train.shape, y_test.shape) # (105,) (45,)

# run for k = 1 to 15
scores_list = []

for k in range(1, 16):
    classifier = KNeighborsClassifier(n_neighbors=k)
    classifier.fit(X_train, y_train)
    y_pred = classifier.predict(X_test)
    scores_list.append(metrics.accuracy_score(y_test, y_pred))

result = metrics.confusion_matrix(y_test, y_pred)

print("Confusion Matrix:")
print(result)

report = metrics.classification_report(y_test, y_pred)
print(report)

'''
    The rows represent the actual true labels of the flowers.

    The columns represent the labels predicted by your model.

Here’s a breakdown of the numbers:

    Class 0 (e.g., setosa): The model correctly predicted all 14 actual Class 0 flowers as Class 0. Perfect performance.

    Class 1 (e.g., versicolor): There were 13 actual Class 1 flowers. The model correctly predicted 12 of them but mistakenly predicted 1 as Class 2.

    Class 2 (e.g., virginica): There were 18 actual Class 2 flowers. The model correctly predicted 17 of them but mistakenly predicted 1 as Class 1.

The values on the main diagonal (14, 12, 17) are correct predictions. The off-diagonal values (the two 1s) are the errors.
'''