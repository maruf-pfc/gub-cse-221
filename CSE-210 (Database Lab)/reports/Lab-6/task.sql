CREATE DATABASE employee_db;

USE employee_db;

CREATE TABLE employee (
    EmpID INT PRIMARY KEY,
    EmpName VARCHAR(100),
    BasicSalary DOUBLE,
    StartDate DATE,
    NoofPub INT
);

INSERT INTO
    employee (EmpID, EmpName, BasicSalary, StartDate, NoofPub)
VALUES
    (1, 'John Adams', 51000, '2021-02-14', 6),
    (2, 'Jane Austen', 56000, '2020-05-19', 4),
    (3, 'Alice Walker', 61000, '2023-04-11', 7),
    (4, 'Bob Marley', 53000, '2019-10-06', 3),
    (5, 'Charlie Chaplin', 49000, '2018-08-24', 5),
    (6, 'Diana Ross', 54000, '2021-09-29', 7),
    (7, 'Evan Peters', 58000, '2020-11-12', 8),
    (8, 'Fiona Apple', 63000, '2022-03-21', 10),
    (9, 'George Clooney', 50000, '2019-02-17', 2),
    (10, 'Hannah Montana', 55000, '2018-06-28', 6);

SELECT
    *
FROM
    employee;

DELIMITER CREATE TRIGGER update_basic_salary
AFTER
UPDATE
    ON employee FOR EACH ROW BEGIN IF NEW.NoofPub <> OLD.NoofPub THEN
SET
    NEW.BasicSalary = OLD.BasicSalary * 1.10;

END IF;

END;

DELIMITER;

INSERT INTO
    employee (EmpID, EmpName, BasicSalary, StartDate, NoofPub)
VALUES
    (11, 'Sam Smith', 52000, '2023-05-16', 5),
    (12, 'Aria Stark', 57000, '2020-04-22', 9),
    (13, 'Chris Hemsworth', 71000, '2022-05-23', 2),
    (14, 'Tom Holland', 66000, '2019-04-11', 6);

SELECT
    *
FROM
    employee;