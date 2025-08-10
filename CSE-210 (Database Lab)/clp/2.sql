Create database clpQuestion2;
use clpQuestion2;
-- https://www.red-gate.com/website/sql-formatter
CREATE TABLE branch
(
    branch_name VARCHAR(50) PRIMARY KEY,
    branch_city VARCHAR(50),
    assets INT
);

INSERT INTO branch
(
    branch_name,
    branch_city,
    assets
)
VALUES
('Brighton', 'Brooklyn', 7100000),
('Downtown', 'Brooklyn', 9000000),
('Mianus', 'Horseneck', 400000),
('North Town', 'Rye', 3700000),
('Perryridge', 'Horseneck', 4000000),
('Pownal', 'Bennington', 300000),
('Redwood', 'Palo Alto', 3000000),
('Round Hill', 'Horseneck', 8000000);

CREATE TABLE loan
(
    loan_number VARCHAR(50) PRIMARY KEY,
    branch_name VARCHAR(50),
    amount INT,
    FOREIGN KEY (branch_name) REFERENCES branch (branch_name)
);

INSERT INTO loan
(
    loan_number,
    branch_name,
    amount
)
VALUES
('L-11', 'Round Hill', 900),
('L-14', 'Downtown', 1500),
('L-15', 'Perryridge', 1500),
('L-16', 'Downtown', 1300),
('L-17', 'Perryridge', 1000),
('L-23', 'Redwood', 2000),
('L-93', 'Mianus', 500);

CREATE TABLE depositor
(
    customer_name VARCHAR(50),
    account_number VARCHAR(50)
);

INSERT INTO depositor
(
    customer_name,
    account_number
)
VALUES
('Hayes', 'A-102'),
('Johnson', 'A-101'),
('Johnson', 'A-201'),
('Jones', 'A-217'),
('Lindsay', 'A-222'),
('Smith', 'A-215'),
('Turner', 'A-305');

CREATE TABLE account
(
    account_number VARCHAR(50) PRIMARY KEY,
    branch_name VARCHAR(50),
    balance INT,
    FOREIGN KEY (branch_name) REFERENCES branch (branch_name)
);

INSERT INTO account
(
    account_number,
    branch_name,
    balance
)
VALUES
('A-101', 'Downtown', 500),
('A-102', 'Brighton', 400),
('A-201', 'Perryridge', 900),
('A-215', 'Mianus', 700),
('A-217', 'Brighton', 750),
('A-222', 'Redwood', 700),
('A-305', 'Round Hill', 350);

SELECT customer_name
FROM depositor
    JOIN account
        ON depositor.account_number = account.account_number
    JOIN branch
        ON account.branch_name = branch.branch_name
WHERE branch.branch_city IN ( 'Brooklyn', 'Horseneck' )
GROUP BY customer_name
HAVING COUNT(branch.branch_name) =
(
    SELECT COUNT(branch_name)
    FROM branch
    WHERE branch.branch_city IN ( 'Brooklyn', 'Horseneck' )
);
