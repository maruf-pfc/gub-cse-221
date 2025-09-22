# 📝 Lab Task Solutions (Python Basics – CSE 424)

## 🔹 Task 1: Accept first & last name → print full name

```python
first = input("Enter first name: ")
last = input("Enter last name: ")
print("Full name:", first + " " + last)
```

**Output**

```
Enter first name: Albert
Enter last name: Einstein
Full name: Albert Einstein
```

---

## 🔹 Task 2: Accept integer `n` → compute `n + nn + nnn`

```python
n = int(input("Enter a number: "))
result = n + int(str(n)*2) + int(str(n)*3)
print("Result:", result)
```

**Output**

```
Enter a number: 5
Result: 615   # 5 + 55 + 555
```

---

## 🔹 Task 3: Compute area of a circle

```python
import math
r = float(input("Enter radius: "))
area = math.pi * r * r
print("Area of circle:", area)
```

**Output**

```
Enter radius: 3
Area of circle: 28.274333882308138
```

---

## 🔹 Task 4: Check even or odd

```python
num = int(input("Enter a number: "))
if num % 2 == 0:
    print("Even number")
else:
    print("Odd number")
```

**Output**

```
Enter a number: 7
Odd number
```

---

## 🔹 Task 5: Accept comma-separated numbers → create list

```python
data = input("Enter numbers separated by commas: ")
num_list = data.split(",")
print("List:", num_list)
```

**Output**

```
Enter numbers separated by commas: 1,2,3,4
List: ['1', '2', '3', '4']
```

---

## 🔹 Task 6: Display first & last colors

```python
colorList = ["Red","Green","White","Black"]
print("First color:", colorList[0])
print("Last color:", colorList[-1])
```

**Output**

```
First color: Red
Last color: Black
```

---

## 🔹 Task 7: Find largest among 3 numbers

```python
a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
c = int(input("Enter third number: "))

largest = a
if b > largest:
    largest = b
if c > largest:
    largest = c

print("Largest number is:", largest)
```

**Output**

```
Enter first number: 10
Enter second number: 25
Enter third number: 15
Largest number is: 25
```

---

## 🔹 Task 8: Display student grades

```python
marks = int(input("Enter marks: "))

if marks >= 80:
    grade = "A+"
elif marks >= 70:
    grade = "A"
elif marks >= 60:
    grade = "B"
elif marks >= 50:
    grade = "C"
elif marks >= 40:
    grade = "D"
else:
    grade = "F"

print("Grade:", grade)
```

**Output**

```
Enter marks: 73
Grade: A
```

---

## 🔹 Task 9: Sum of 3 numbers → if equal → 3× sum

```python
a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
c = int(input("Enter third number: "))

total = a + b + c
if a == b == c:
    total *= 3

print("Result:", total)
```

**Output**

```
Enter first number: 5
Enter second number: 5
Enter third number: 5
Result: 45
```

---

## 🔹 Task 10: Sum of odd and even numbers

```python
numbers = list(map(int, input("Enter numbers separated by space: ").split()))
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

**Output**

```
Enter numbers separated by space: 1 2 3 4 5
Sum of even numbers: 6
Sum of odd numbers: 9
```

---

## 🔹 Task 11: Check if a triangle is valid

* A triangle is valid if the **sum of any two sides > third side**.

```python
a = int(input("Enter first side: "))
b = int(input("Enter second side: "))
c = int(input("Enter third side: "))

if (a+b > c) and (a+c > b) and (b+c > a):
    print("Triangle is valid")
else:
    print("Triangle is NOT valid")
```

**Output**

```
Enter first side: 3
Enter second side: 4
Enter third side: 5
Triangle is valid
```
