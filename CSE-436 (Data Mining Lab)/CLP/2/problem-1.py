import matplotlib.pyplot as plt

# Monthly sales data for Department A (in $000)
sales = [18,20,22,25,28,30,35]

plt.figure(figsize=(5,6))
plt.boxplot(sales)
plt.title("Boxplot of Monthly Sales - Department A")
plt.ylabel("Sales ($000)")
plt.show()
