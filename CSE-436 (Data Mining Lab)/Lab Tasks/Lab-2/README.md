# 🖥️ Lab Task Solutions – Python Programming

## 🔹 1. Loop Section Tasks

### ✅ Task 1: Find the sum of odd and even numbers from a set of numbers

```python
# Sum of odd and even numbers
numbers = [10, 15, 20, 25, 30, 35]

even_sum = 0
odd_sum = 0

for n in numbers:
    if n % 2 == 0:
        even_sum += n
    else:
        odd_sum += n

print("Sum of even numbers:", even_sum)
print("Sum of odd numbers:", odd_sum)
```

🔎 *Explanation*: We loop through numbers → check even/odd using `% 2` → accumulate sums separately.

---

### ✅ Task 2: Find the smallest number

```python
numbers = [12, 45, 3, 67, 1, 99]

smallest = numbers[0]   # assume first element is smallest

for n in numbers:
    if n < smallest:
        smallest = n

print("Smallest number is:", smallest)
```

🔎 *Explanation*: Start with first element, compare with others → update smallest.

---

### ✅ Task 3: Sum of numbers between 50 and 100 divisible by 3 but not by 5

```python
total = 0
for i in range(50, 101):
    if i % 3 == 0 and i % 5 != 0:
        total += i
print("Sum =", total)
```

🔎 *Explanation*: Condition → divisible by 3 (`% 3 == 0`) but not divisible by 5 (`% 5 != 0`).

---

### ✅ Task 4: Find the second highest number

```python
numbers = [23, 56, 78, 12, 99, 45]

first = second = float('-inf')

for n in numbers:
    if n > first:
        second = first
        first = n
    elif n > second and n != first:
        second = n

print("Second highest number is:", second)
```

🔎 *Explanation*: Keep track of **first highest** and **second highest** while looping.

---

### ✅ Task 5: Factorial using for loop

```python
num = 5
fact = 1

for i in range(1, num + 1):
    fact *= i

print("Factorial of", num, "is", fact)
```

🔎 *Explanation*: Multiply numbers from `1 → n`.

---

### ✅ Task 6: Generate Fibonacci series

```python
n = 10
a, b = 0, 1

print("Fibonacci series:")
for i in range(n):
    print(a, end=" ")
    a, b = b, a + b
```

🔎 *Explanation*: Each term = sum of previous two (`a+b`).

---

## 🔹 2. Function Section Tasks

### ✅ Task 1: Largest number between two numbers

```python
def largest(a, b):
    if a > b:
        return a
    else:
        return b

print("Largest:", largest(10, 20))
```

🔎 *Explanation*: Function compares two numbers → returns larger.

---

### ✅ Task 2: Sum of numbers passed as parameters

```python
def sum_numbers(*nums):
    return sum(nums)

print("Sum =", sum_numbers(10, 20, 30, 40))
```

🔎 *Explanation*: `*nums` lets us pass multiple arguments → use `sum()`.

---

## 🔹 3. Class Section Tasks

### ✅ Task 1: Function `student()` – display names of arguments

```python
def student(name, age, dept):
    print("Function arguments are:", student.__code__.co_varnames[:student.__code__.co_argcount])

student("John", 22, "CSE")
```

🔎 *Explanation*: Function attributes (`__code__`) give parameter names.

---

### ✅ Task 2: Function `studentId()` – print student details

```python
def studentId(studentId=None, name=None, studentClass=None):
    if studentId and name and studentClass:
        print(f"ID: {studentId}, Name: {name}, Class: {studentClass}")
    elif studentId:
        print(f"Student ID: {studentId}")
    else:
        print("No details provided")

studentId(101)
studentId(102, "Alice", "CSE-2")
```

🔎 *Explanation*: Function checks what arguments were passed and prints accordingly.

---

## 🔹 4. Lab Exercises (Report Submission)

### ✅ Exercise 1: Empty classes and instance checking

```python
class Student:
    pass

class Marks:
    pass

s = Student()
m = Marks()

print(isinstance(s, Student))   # True
print(isinstance(m, Marks))     # True
print(issubclass(Student, object))  # True
print(issubclass(Marks, object))    # True
```

---

### ✅ Exercise 2: Class with attributes, modify values

```python
class Student:
    def __init__(self, name, marks):
        self.studentName = name
        self.marks = marks

s1 = Student("John", 85)
print("Original:", s1.studentName, s1.marks)

# Modify values
s1.studentName = "Alice"
s1.marks = 90
print("Modified:", s1.studentName, s1.marks)
```

---

### ✅ Exercise 3: Add and remove attributes

```python
class Student:
    def __init__(self, studentId, studentName):
        self.studentId = studentId
        self.studentName = studentName

s1 = Student(101, "John")
s1.studentClass = "CSE-2"   # add attribute

print("All attributes:", s1.__dict__)

del s1.studentName   # remove attribute
print("After deletion:", s1.__dict__)
```

---

### ✅ Exercise 4: Display all attributes via method

```python
class Student:
    def __init__(self, studentId, studentName, studentClass):
        self.studentId = studentId
        self.studentName = studentName
        self.studentClass = studentClass

    def display(self):
        for key, value in self.__dict__.items():
            print(key, "=", value)

s1 = Student(101, "Alice", "CSE-3")
s1.display()
```

🔎 *Explanation*: `__dict__` stores all object attributes in dictionary form.

---

# ✅ Conclusion

Now you have:

* **Loop tasks** → sum, factorial, Fibonacci, highest/lowest.
* **Function tasks** → largest number, sum with arguments.
* **Class tasks** → constructor, attributes, methods, object manipulation.
* **Lab exercises** → full class practice with `__dict__`, `isinstance`, `issubclass`.
