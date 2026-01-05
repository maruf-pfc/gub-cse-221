import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler
from sklearn.cluster import DBSCAN

url = "./income.csv"
df = pd.read_csv(url)

X = df[['Age', 'Income($)']]

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

dbscan = DBSCAN(eps=1.4, min_samples=4)
labels = dbscan.fit_predict(X_scaled)
df['Cluster'] = labels
plt.figure(figsize=(8, 6))
unique_labels = set(labels)
for label in unique_labels:
    if label == -1:
        plt.scatter(
            X_scaled[labels == label, 0],
            X_scaled[labels == label, 1],
            c='red',
            marker='x',
            label='Outliers'
        )
    else:
        plt.scatter(
            X_scaled[labels == label, 0],
            X_scaled[labels == label, 1],
            label=f'Cluster {label}'
        )
plt.xlabel("Age (scaled)")
plt.ylabel("Income (scaled)")
plt.title("DBSCAN Clustering (Age vs Income)")
plt.legend()
plt.show()

print(df)
