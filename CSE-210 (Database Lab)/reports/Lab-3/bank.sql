CREATE DATABASE IF NOT EXISTS bank_database;

USE bank_database;
CREATE TABLE branch (
    branch_name VARCHAR(50),
    branch_city VARCHAR(50),
    assets INTEGER
);

CREATE TABLE customer (
    customer_id INTEGER PRIMARY KEY,
    customer_name VARCHAR(50),
    customer_city VARCHAR(50)
);

CREATE TABLE account (
    account_number INTEGER PRIMARY KEY,
    branch_name VARCHAR(50),
    balance INTEGER
);

CREATE TABLE loan (
    loan_number INTEGER PRIMARY KEY,
    branch_name VARCHAR(50),
    amount INTEGER
);

CREATE TABLE depositor (
    customer_name VARCHAR(50),
    account_number INTEGER,
    FOREIGN KEY (account_number) REFERENCES account(account_number)
);

CREATE TABLE borrower (
    customer_name VARCHAR(50),
    loan_number INTEGER,
    FOREIGN KEY (loan_number) REFERENCES loan(loan_number)
);

INSERT INTO branch (branch_name, branch_city, assets)
VALUES ('Branch 1', 'Dhaka', 1000000),
       ('Branch 2', 'Rajshahi', 500000),
       ('Branch 3', 'Chittagong', 800000),
       ('Branch 4', 'Sylhet', 600000),
       ('Branch 5', 'Mymensingh', 900000);

INSERT INTO customer (customer_id, customer_name, customer_city)
VALUES (1, 'Sumaya', 'Dhaka'),
       (2, 'Ariful', 'Rajshahi'),
       (3, 'Lima', 'Chittagong'),
       (4, 'Monira', 'Sylhet'),
       (5, 'Abdul', 'Mymensingh');

INSERT INTO account (account_number, branch_name, balance)
VALUES (1001, 'Branch 1', 5000),
       (1002, 'Branch 2', 7000),
       (1003, 'Branch 3', 3000),
       (1004, 'Branch 4', 9000),
       (1005, 'Branch 5', 8000);

INSERT INTO loan (loan_number, branch_name, amount)
VALUES (1011, 'Branch 1', 10000),
       (1012, 'Branch 2', 15000),
       (1013, 'Branch 3', 5000),
       (1014, 'Branch 4', 12000),
       (1015, 'Branch 5', 11000);

INSERT INTO depositor (customer_name, account_number)
VALUES ('Sumaya', 1001),
       ('Ariful', 1002),
       ('Lima', 1003),
       ('Monira', 1004),
       ('Abdul', 1005);

INSERT INTO borrower (customer_name, loan_number)
VALUES ('Sumaya', 1011),
       ('Ariful', 1012),
       ('Lima', 1013),
       ('Monira', 1014),
       ('Abdul', 1015);


ALTER TABLE customer ADD COLUMN Email VARCHAR(50);

UPDATE customer SET Email = 'sumaya@example.com' WHERE customer_id = 1;
UPDATE customer SET Email = 'ariful@example.com' WHERE customer_id = 2;
UPDATE customer SET Email = 'lima@example.com' WHERE customer_id = 3;
UPDATE customer SET Email = 'monira@example.com' WHERE customer_id = 4;
UPDATE customer SET Email = 'abdul@example.com' WHERE customer_id = 5;

ALTER TABLE customer RENAME COLUMN customer_city TO city;
ALTER TABLE branch RENAME COLUMN assets TO total_assets;

SELECT * FROM branch;
SELECT * FROM customer;
SELECT * FROM account;
SELECT * FROM loan;
SELECT * FROM depositor;
SELECT * FROM borrower;
