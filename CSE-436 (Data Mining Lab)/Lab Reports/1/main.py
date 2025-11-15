import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

data = pd.read_csv("income.csv")

print(data.head())

# Heatmap (Correlation Matrix)
plt.figure(figsize=(6,4))
corr = data[["Age", "Income($)"]].corr()

sns.heatmap(corr, annot=True, cmap="Blues", linewidths=0.5)
plt.title("Correlation Heatmap: Age vs Income")

plt.savefig("heatmap.pdf")
plt.show()

# Boxplot (Income Distribution)
plt.figure(figsize=(6,4))
sns.boxplot(y=data["Income($)"], color="skyblue")

plt.title("Boxplot of Income")
plt.ylabel("Income ($)")

plt.savefig("boxplot.pdf")
plt.show()


# Violin Plot (Age and Income Distributions)
plt.figure(figsize=(7,5))
sns.violinplot(data=data[['Age', 'Income($)']])

plt.title("Violin Plot: Age and Income Distributions")
plt.xlabel("Variables")

plt.savefig("violin.pdf")
plt.show()


# Barplot (Income by Person)
plt.figure(figsize=(12,5))
sns.barplot(x="Name", y="Income($)", data=data, palette="viridis")

plt.xticks(rotation=90)
plt.title("Barplot of Income by Person")
plt.ylabel("Income ($)")
plt.xlabel("Name")

plt.savefig("barplot.pdf")
plt.show()


# Histogram (Distribution of Income)
plt.figure(figsize=(7,4))
sns.histplot(data["Income($)"], bins=10, kde=True, color="steelblue")

plt.title("Histogram of Income")
plt.xlabel("Income ($)")
plt.ylabel("Frequency")

plt.savefig("histogram.pdf")
plt.show()
