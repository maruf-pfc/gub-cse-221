str = input()
res = {}

for char in str:
    if char in res:
        res[char] += 1
    else:
        res[char] = 1

# print(res)

print("Input String: " + str)

print("Character Frequency:")
for char, count in res.items():
    print(f"'{char}' : {count}")