# 📝 Summary Notes – Python Programming (Loops, Functions, Classes, Objects)

**Course:** Data Mining Lab (CSE 424) – Green University of Bangladesh

---

## 1. 🔹 Python Basics

* **Python** = High-level, interpreted, general-purpose language.
* **Key Features:**

  * Easy syntax, indentation-based.
  * Supports **procedural + object-oriented programming (OOP)**.
  * Great for small and large projects.

---

## 2. 🔹 Loops in Python

Loops help **repeat tasks without rewriting code**.

### ✅ For Loop

* Iterates over **sequences**: list, tuple, dict, set, string.
* `range()` is commonly used.

**Examples:**

```python
for i in range(5):   # 0 to 4
    print(i)

for i in range(2, 20, 3):   # step = 3
    print(i)

for i in "orange":   # loop through string
    print(i)

fruits = ["orange", "apple", "cherry"]
for f in fruits:
    print(f)
    if f == "apple": break
```

---

### ✅ While Loop

* Runs **as long as condition is true**.

**Examples:**

```python
i = 1
while i < 5:
    print(i)
    i += 1
```

* `break` → exit loop.
* `continue` → skip to next iteration.
* `else` with loop → executes when loop ends naturally.

---

### 🔹 Lab Tasks (Loop Section)

1. Sum of odd/even numbers.
2. Smallest number from a set.
3. Sum of numbers between 50–100 (divisible by 3, not by 5).
4. Find **second highest number**.
5. Factorial of a number.
6. Fibonacci series generation.

---

## 3. 🔹 Functions in Python

* A **function** groups reusable code.
* Defined using `def`.

**Examples:**

```python
def my_function():
    print("Hello World")

def add(a, b):
    return a + b

def my_function(*args):   # arbitrary arguments
    print(args[2])

def my_function(**kwargs):   # keyword arguments
    print("His last name is", kwargs["lname"])
```

* Functions can:

  * Take arguments (`*args`, `**kwargs`).
  * Return values (`return`).
  * Use recursion.

---

### 🔹 Lab Tasks (Functions Section)

1. Largest number between two numbers.
2. Sum of numbers passed as parameters.

---

## 4. 🔹 Classes and Objects in Python

Python supports **OOP** → Classes define blueprints, objects are instances.

### ✅ Create Class & Object

```python
class MyClass:
    a = 5

obj = MyClass()
print(obj.a)
```

---

### ✅ The `__init__()` Constructor

* Runs when object is created.

```python
class Employee:
    def __init__(self, name, age):
        self.name = name
        self.age = age
e1 = Employee("John", 26)
```

---

### ✅ Object Methods

```python
class Employee:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def greet(self):
        print("Hello my name is", self.name)

e1 = Employee("John", 26)
e1.greet()
```

* `self` refers to the current instance.

---

### ✅ Modify & Delete Properties

```python
e1.age = 30   # modify
del e1.age    # delete
```

---

### 🔹 Lab Tasks (Class Section)

1. Function `student()` → show argument names using attributes.
2. Function `studentId()` → print student details.

---

## 5. 🔹 Lab Exercises (Report Submission)

1. Create empty classes `Student` and `Marks`. Check instances & subclasses.
2. Class `Student` with `studentName`, `marks`. Modify and display.
3. Class `Student` with `studentId`, `studentName`. Add `studentClass`, then remove `studentName`.
4. Class `Student` with `studentId`, `studentName`, `studentClass` → create method to display all attributes.

---

## 6. 🔹 Policy

* ❌ No copying (internet/classmates/seniors).
* If plagiarism is detected → **0 marks**.

---

## ✅ Final Conclusion

* Loops → help with repetition (for, while).
* Functions → enable reusability and modular programming.
* Classes & Objects → allow structured, object-oriented approach.
* Lab tasks → practice problems to strengthen concepts.
