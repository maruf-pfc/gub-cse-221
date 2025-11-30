# ------------------------------------------------------------
# APRIORI ALGORITHM IMPLEMENTATION FOR QUESTION 2
# Minimum Support Count = 3
# Student ID last digit = ODD → Use Apriori
# ------------------------------------------------------------

from itertools import combinations

# ---------------------------
# Input Transaction Dataset
# ---------------------------

transactions = {
    "T101": {"P", "Q", "R", "S", "T", "U"},
    "T102": {"V", "P", "Q", "S", "T", "U"},
    "T103": {"W", "P", "Q", "R"},
    "T104": {"X", "Q", "R", "Y", "U"},
    "T105": {"X", "P", "Z", "Q", "T"}  # Note: T repeated, but sets remove duplicates
}

min_support = 3


# ---------------------------------------------
# Function to count support for any itemset
# ---------------------------------------------
def get_support(itemset):
    count = 0
    for t in transactions.values():
        if itemset.issubset(t):
            count += 1
    return count


# ---------------------------------------------
# Step 1: Generate frequent 1-itemsets
# ---------------------------------------------
print("\n=== Frequent 1-itemsets ===")

item_counts = {}
for t in transactions.values():
    for item in t:
        item_counts[item] = item_counts.get(item, 0) + 1

L1 = []
for item, count in sorted(item_counts.items()):
    if count >= min_support:
        L1.append({item})
        print(f"{item}: support = {count}")

# Convert to list of sets for next steps
current_L = L1
all_frequent_itemsets = L1.copy()


# --------------------------------------------------------
# Step 2: Generate k-itemsets using the Apriori principle
# --------------------------------------------------------
k = 2
while True:
    print(f"\n=== Frequent {k}-itemsets ===")
    
    # Generate candidate itemsets of size k
    candidates = []
    items_flat = sorted(list({item for s in current_L for item in s}))

    for combo in combinations(items_flat, k):
        candidates.append(set(combo))
    
    # Count support of candidates
    Lk = []
    for itemset in candidates:
        support = get_support(itemset)
        if support >= min_support:
            Lk.append(itemset)
            print(f"{set(itemset)}: support = {support}")

    if not Lk:  # Stop if no frequent k-itemsets found
        break

    all_frequent_itemsets.extend(Lk)
    current_L = Lk
    k += 1


# ---------------------------------------------
# Final Output
# ---------------------------------------------
print("\n======================================")
print(" ALL FREQUENT ITEMSETS (support ≥ 3)")
print("======================================")
for s in all_frequent_itemsets:
    print(s)
