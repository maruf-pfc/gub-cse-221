CREATE DATABASE clpQuestion1;
-- https://www.red-gate.com/website/sql-formatter
USE clpQuestion1;


CREATE TABLE customer
(
    customer_id INT PRIMARY KEY,
    cust_name VARCHAR(50) NOT NULL,
    city VARCHAR(50) NOT NULL,
    grade INT NOT NULL,
    salesman_id INT NOT NULL
);


CREATE TABLE orders
(
    ord_no INT PRIMARY KEY,
    purch_amt DECIMAL(10, 2) NOT NULL,
    ord_date DATE NOT NULL,
    customer_id INT NOT NULL,
    salesman_id INT NOT NULL
);


INSERT INTO customer
(
    customer_id,
    cust_name,
    city,
    grade,
    salesman_id
)
VALUES
(3002, 'Nick Rimando', 'New York', 100, 5001),
(3007, 'Brad Davis', 'New York', 200, 5001),
(3005, 'Graham Zusi', 'California', 200, 5002),
(3008, 'Julian Green', 'London', 300, 5002),
(3004, 'Fabian Johnson', 'Paris', 300, 5006),
(3009, 'Geoff Cameron', 'Berlin', 100, 5003),
(3003, 'Jozy Altidor', 'Moscow', 200, 5007),
(3001, 'Brad Guzan', 'London', 200, 5005);


INSERT INTO orders
(
    ord_no,
    purch_amt,
    ord_date,
    customer_id,
    salesman_id
)
VALUES
(70001, 150.5, '2012-10-05', 3005, 5002),
(70009, 270.65, '2012-09-10', 3001, 5005),
(70002, 65.26, '2012-10-05', 3002, 5001),
(70004, 110.5, '2012-08-17', 3009, 5003),
(70007, 948.5, '2012-09-10', 3005, 5002),
(70005, 2400.6, '2012-07-27', 3007, 5001),
(70008, 5760.0, '2012-09-10', 3002, 5001),
(70010, 1983.43, '2012-10-10', 3004, 5006);


SELECT cust_name,
       city,
       ord_no,
       ord_date,
       purch_amt
FROM customer
    INNER JOIN orders
        ON customer.customer_id = orders.customer_id;


SELECT cust_name,
       SUM(purch_amt) AS total_purchase,
       (
           SELECT AVG(purch_amt) FROM orders
       ) AS avg_purchase
FROM customer
    JOIN orders
        ON customer.customer_id = orders.customer_id
GROUP BY customer.cust_name
HAVING SUM(orders.purch_amt) <
(
    SELECT AVG(purch_amt) FROM orders
);