import pandas as pd
from mlxtend.preprocessing import TransactionEncoder
from mlxtend.frequent_patterns import apriori, fpgrowth, association_rules

# 1. Load Dataset
dataset = pd.read_csv("Market_Basket_Optimisation.csv", header=None)
print("Dataset Loaded Successfully")
print(dataset.head())

# 2. Data Preprocessing
transactions = []
for i in range(len(dataset)):
    transactions.append(
        [
            str(dataset.values[i, j])
            for j in range(len(dataset.columns))
            if str(dataset.values[i, j]) != 'nan'
        ]
    )

print("\nSample Transaction:")
print(transactions[0])

# 3. One-Hot Encoding
te = TransactionEncoder()
array = te.fit(transactions).transform(transactions)
df = pd.DataFrame(array, columns=te.columns_)

print("\nOne-hot encoded data:")
print(df.head())

# 4. Apriori Algorithm
frequent_itemsets_apriori = apriori(
    df,
    min_support=0.003,
    use_colnames=True
)

print("\nFrequent Itemsets (Apriori):")
print(frequent_itemsets_apriori.head())

rules_apriori = association_rules(
    frequent_itemsets_apriori,
    metric="lift",
    min_threshold=1
)

print("\nAssociation Rules (Apriori):")
print(rules_apriori[['antecedents', 'consequents', 'support', 'confidence', 'lift']].head())

# 5. FP-Growth Algorithm
frequent_itemsets_fp = fpgrowth(
    df,
    min_support=0.003,
    use_colnames=True
)

print("\nFrequent Itemsets (FP-Growth):")
print(frequent_itemsets_fp.head())

rules_fp = association_rules(
    frequent_itemsets_fp,
    metric="lift",
    min_threshold=1
)

print("\nAssociation Rules (FP-Growth):")
print(rules_fp[['antecedents', 'consequents', 'support', 'confidence', 'lift']].head())
