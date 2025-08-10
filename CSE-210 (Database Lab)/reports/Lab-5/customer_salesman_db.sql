CREATE DATABASE customer_salesman_db;

USE customer_salesman_db;

CREATE TABLE orders (
    ord_no INT,
    purch_amt DECIMAL(10, 2),
    ord_date DATE,
    customer_id INT,
    salesman_id INT
);

CREATE TABLE customer (
    customer_id INT,
    cust_name VARCHAR(50),
    city VARCHAR(50),
    grade INT,
    salesman_id INT
);

CREATE TABLE salesman (
    salesman_id INT,
    name VARCHAR(50),
    city VARCHAR(50),
    commission DECIMAL(4, 2)
);

-- Insert data into orders table
INSERT INTO
    orders (
        ord_no,
        purch_amt,
        ord_date,
        customer_id,
        salesman_id
    )
VALUES
    (70001, 150.50, '2012-10-05', 3002, 5002),
    (70009, 270.65, '2012-09-10', 3001, 5005),
    (70002, 65.26, '2012-10-05', 3002, 5001),
    (70004, 110.50, '2012-08-17', 3009, 5003),
    (70007, 948.50, '2012-09-10', 3005, 5002),
    (70005, 2400.60, '2012-07-27', 3007, 5001),
    (70008, 5760.00, '2012-09-10', 3002, 5001),
    (70010, 1983.43, '2012-10-10', 3004, 5006),
    (70003, 2480.40, '2012-10-10', 3009, 5003),
    (70012, 250.45, '2012-06-27', 3008, 5002),
    (70011, 75.29, '2012-08-17', 3003, 5007),
    (70013, 3045.60, '2012-04-25', 3002, 5001);

-- Insert data into customer table
INSERT INTO
    customer (customer_id, cust_name, city, grade, salesman_id)
VALUES
    (3002, 'Nick Rimando', 'New York', 100, 5001),
    (3005, 'Graham Zusi', 'California', 200, 5002),
    (3001, 'Fabian Johnson', 'Paris', 300, 5006),
    (3007, 'Brad Davis', 'New York', 200, 5001),
    (3009, 'Geoff Cameron', 'Berlin', 100, 5003),
    (3008, 'Julian Green', 'London', 300, 5002),
    (3004, 'Brad Guzan', 'London', 500, 5005),
    (3003, 'Jozy Altidore', 'Moscow', 200, 5007);

-- Insert data into salesman table
INSERT INTO
    salesman (salesman_id, name, city, commission)
VALUES
    (5001, 'James Hoog', 'New York', 0.15),
    (5002, 'Nail Knite', 'Paris', 0.13),
    (5005, 'Pit Alex', 'London', 0.11),
    (5003, 'Mc Lyon', 'Paris', 0.14),
    (5006, 'Paul Adam', 'Rome', 0.13),
    (5007, 'Lusson Hens', 'San Jose', 0.12);

SELECT
    o.ord_no,
    o.ord_date,
    o.purch_amt,
    c.cust_name AS customer_name,
    s.name AS salesman_name,
    s.commission
FROM
    orders o
    JOIN customer c ON o.customer_id = c.customer_id
    JOIN salesman s ON o.salesman_id = s.salesman_id;

SELECT
    c.cust_name,
    c.city,
    c.grade,
    s.name AS salesman_name
FROM
    customer c
    LEFT JOIN salesman s ON c.salesman_id = s.salesman_id
ORDER BY
    c.cust_name ASC;