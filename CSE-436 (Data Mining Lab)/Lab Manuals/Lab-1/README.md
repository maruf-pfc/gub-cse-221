# 📘 Python Basics – Full Summary (CSE 424, Data Mining Lab)

## 🔹 1. Introduction

* **Python** = high-level, interpreted, general-purpose language.
* Prioritizes **readability** (indentation instead of `{}`).
* Supports **OOP and multi-paradigm** programming.
* Code is concise, close to **pseudo-code**.

---

## 🔹 2. Variables & Strings

* **Variables** = containers for values.
* **Strings** = sequence of characters inside quotes.

### Example

```python
print("Hello world!")

msg = "Hello world!"
print(msg)

first_name = "albert"
last_name = "einstein"
full_name = first_name + " " + last_name
print(full_name)
```

**Output**

```
Hello world!
Hello world!
albert einstein
```

---

## 🔹 3. Casting (Type Conversion)

* Convert between types with `str()`, `int()`, `float()`.
* Use `type()` to check data type.

### Example

```python
x = str(5)   # "5"
y = int(5)   # 5
z = float(5) # 5.0
print(type(x), type(y), type(z))
```

**Output**

```
<class 'str'> <class 'int'> <class 'float'>
```

---

## 🔹 4. User Input

* `input()` (Python 3) → always returns **string**.
* Convert with `int()` or `float()`.

### Example

```python
name = input("Enter name: ")
print("Name is:", name)

age = int(input("Enter your age: "))
print("Age is:", age)
```

**Output**

```
Enter name: Mike
Name is: Mike
Enter your age: 25
Age is: 25
```

---

## 🔹 5. Operators

### (a) Arithmetic Operators

```python
x, y = 10, 5
print(x + y)   # Addition
print(x - y)   # Subtraction
print(x * y)   # Multiplication
print(x / y)   # Division
print(x % y)   # Modulus
print(x ** y)  # Exponentiation
print(x // y)  # Floor division
```

### (b) Comparison Operators

```python
x, y = 10, 5
print(x == y, x != y, x > y, x < y, x >= y, x <= y)
```

### (c) Logical Operators

```python
x = 10
print(x < 5 and x < 10)   # AND
print(x < 5 or x < 4)     # OR
print(not(x < 5 and x < 10))  # NOT
```

---

## 🔹 6. Lists

* Ordered, indexed, **mutable**, allow duplicates.

### Creating & Duplicates

```python
thislist = ["apple", "banana", "cherry"]
print(thislist)

thislist = ["apple", "banana", "cherry", "apple"]
print(thislist)
```

### List Length

```python
print(len(thislist))
```

### Access Items

```python
print(thislist[0])   # first item
print(thislist[-1])  # last item
```

### Slicing

```python
thislist = ["apple", "banana", "cherry", "orange", "kiwi"]
print(thislist[1:3])   # ['banana', 'cherry']
print(thislist[:3])    # ['apple','banana','cherry']
print(thislist[2:])    # from index 2 to end
```

### Change Items

```python
thislist[1] = "blackcurrant"
thislist[1:2] = ["blackcurrant", "watermelon"]
```

### Add Items

```python
thislist.append("mango")
thislist.insert(1, "orange")
thislist.extend(["pineapple", "papaya"])
```

### Remove Items

```python
thislist.remove("banana")  # by value
thislist.pop(1)            # by index
thislist.pop()             # last item
del thislist[0]            # delete first item
thislist.clear()           # empty list
```

---

## 🔹 7. Conditional Statements

### If

```python
a, b = 10, 20
if b > a:
    print("b is greater than a")
```

### If-Elif-Else

```python
a, b = 20, 10
if b > a:
    print("b > a")
elif a == b:
    print("equal")
else:
    print("a > b")
```

### Nested If

```python
x = 15
if x > 5:
    print("Above 5")
    if x > 10:
        print("Above 10")
    else:
        print("Not above 10")
```

### Short-hand If

```python
a, b = 20, 5
if a > b: print("a > b")
```

### Short-hand If-Else

```python
a, b = 2, 3
print("A") if a > b else print("B")
```

---

## 🔹 8. Lab Tasks (To Implement)

1. Accept first & last name → print full name.
2. Accept integer `n` → compute `n + nn + nnn`.
3. Accept radius → compute area of circle.
4. Accept number → check even/odd.
5. Accept comma-separated numbers → make list.
6. Display **first & last** color from `["Red","Green","White","Black"]`.
7. Find largest among 3 numbers.
8. Display student grades.
9. Sum of 3 numbers → if equal → return **3× sum**.
10. Find sum of odd and even numbers.
11. Check if a triangle is valid.

---

## 🔹 9. Conclusion

* Gained knowledge of **Python basics** (variables, casting, input/output, operators, lists, conditions).
* Lab tasks strengthen **problem-solving skills**.

---

## 🔹 10. Policy

* ❌ Copying from internet/classmates not allowed.
* Plagiarism = **0 marks**.
