income = int(input("Enter your salary: ")) 

# <= 10000 -> 5%
# 10001 - 50000 -> 10%
# 50001 - 100000 -> 20%
# >= 100000 -> 30%

tax = 0

if income <= 0:
    print("Wrong Salary Input")
elif income <= 10000:
    amount = min(income, 10000)
    tax += amount * 0.05
elif income >= 10001 and income <= 50000:
    amount = min(income, 50000) - 10000
    tax += amount * 0.10
elif income >= 50001 and income <= 100000:
    amount = min(income, 100000) - 50000
    tax += amount * 0.20
else:
    amount = income - 100000
    tax += amount * 0.30

print(f"Tax = {tax}")