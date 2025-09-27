print("Hello World!")
n = 100
print(f"Number = {n}")

a = 10
b = 20
c = 30
print(a,b,c)
print(a+b+c)

print("He said, 'I eat rice'")

# string concatination
fn = "DM"
ln = "Lab"
fnln = fn + " " + ln
print(fnln)

# string multiplication
prod = fnln * 2
print(prod)

# typecast
pi = 3.1416
print(type(pi))

# user input
# num = int(input("Enter a number: "))

# taking multiple input
# p, q = map(int, input().split())
# print(p,q)

# print = (n+m)^2 == n^2+2*n*m+m^2
# m = int(input("Enter the value of m: "))
# n = int(input("Enter the value of n: "))
# left = ((n + m) ** 2)
# right = ((n ** 2) + (2 * n * m) + (m ** 2))
# print(left == right)

# list
mylist = ["a", "b", "c", "a"]

print(mylist)
print(len(mylist))
print(mylist[-1])
print(mylist[len(mylist) - 1])

# set
myset = set(mylist)
print(myset)

# slicing
sub = "DataMining"
print(sub[1:4])

# 0 1 2 3 4 5
# -5 -4 -3 -2 -1 0

print(sub[-4:-2])
print(sub[-2:-4])
# reason: always low to high -4 to -2

# reverse a string
print(sub[::-1])

# palindrome check
print(sub == sub[::-1])

'''
In python string is immutable means we can't edit a string. But list is mutable means we can edit a list
'''

# list operation
mylist.append(10)
print(mylist)
mylist.insert(2, 420)
print(mylist)
mylist.remove("b")
print(mylist)
mylist.pop(1) # default = -1 means removes the last value
print(mylist)

# fun with list
l1 = [1,2,3]
l2 = [4,5,6]
listConcatinate = l1 + l2
print(f"List Concatinate {listConcatinate}")
listDuplicate = listConcatinate * 2
print(f"List Duplicate {listDuplicate}")

# conditional statements
print('A') if 'A' == 'A' else print('B')

# variable swap
x = 2
y = 3
print(f"Before swapping {x, y}")
x = x + y
y = x - y
x = x - y
print(f"After swapping {x, y}")

# sorting
ls = [2, 3, 1]
ls.sort() # changes the original list
print(ls)
ls = [2, 3, 1]
ls = sorted(ls) # best practice
print(ls)

# Sorting and reversing a list
ls = [2, 3, 1]

# Sorting in ascending order and reversing it
ls.sort(reverse=True)
print("Sorted in reverse order (original list modified):", ls)

# Re-sorting and using sorted() to reverse it
ls = [2, 3, 1]
sorted_list = sorted(ls, reverse=True)
print("Sorted in reverse order (new list):", sorted_list)

