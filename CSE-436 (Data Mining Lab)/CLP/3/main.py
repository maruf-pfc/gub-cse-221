import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.cluster import DBSCAN
import matplotlib.pyplot as plt

df = pd.read_csv("./income.csv")

df.head()

X = df[['Age', 'Income($)']]

sc = StandardScaler()
X_sc = sc.fit_transform(X)

dbscan = DBSCAN(eps=0.7, min_samples=4)
df['Cluster'] = dbscan.fit_predict(X_sc)

df[['Name', 'Age', 'Income($)', 'Cluster']]

plt.figure(figsize=(8, 6))

plt.scatter(
    df['Age'],
    df['Income($)'],
    c=df['Cluster'],
    cmap='tab10',
    s=60
)

outliers = df[df['Cluster'] == -1]
plt.scatter(
    outliers['Age'],
    outliers['Income($)'],
    color='red',
    label='Outliers',
    edgecolors='black',
    s=100
)

plt.xlabel('Age')
plt.ylabel('Income ($)')
plt.title('DBSCAN Clustering (Age vs Income)')
plt.legend()
plt.show()
