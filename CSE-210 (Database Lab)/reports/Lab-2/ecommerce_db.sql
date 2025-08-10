CREATE DATABASE IF NOT EXISTS ecommerce_db2;
USE ecommerce_db2;

-- Create Customers table
CREATE TABLE IF NOT EXISTS Customers (
    CustomerID INT AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(100) NOT NULL,
    Email VARCHAR(100) NOT NULL UNIQUE,
    Password VARCHAR(100) NOT NULL
);

-- Insert data into Customers table
INSERT INTO Customers (Name, Email, Password) VALUES
('Mohammad Ali', 'ali@example.com', 'password123'),
('Fatima Khan', 'fatima@example.com', 'letmein'),
('Rahim Hasan', 'rahim@example.com', 'securepass'),
('Nur Jahan', 'nur@example.com', 'qwerty'),
('Aminul Islam', 'aminul@example.com', 'password123'),
('Sabina Ahmed', 'sabina@example.com', 'pass123'),
('Kamal Hossain', 'kamal@example.com', 'password1'),
('Mehar Tasnim', 'mehar@example.com', 'abc123'),
('Rubel Islam', 'rubel@example.com', '123456'),
('Nusrat Jahan', 'nusrat@example.com', 'iloveyou');

-- Create Products table
CREATE TABLE IF NOT EXISTS Products (
    ProductID INT AUTO_INCREMENT PRIMARY KEY,
    ProductName VARCHAR(100) NOT NULL,
    Description TEXT,
    Price DECIMAL(10, 2) NOT NULL
);

-- Insert data into Products table
INSERT INTO Products (ProductName, Description, Price) VALUES
('Laptop', '15.6" Full HD, Intel Core i5, 8GB RAM, 256GB SSD', 799.99),
('Smartphone', '6.5" AMOLED, Snapdragon 865, 128GB Storage', 699.99),
('Headphones', 'Wireless Noise Cancelling Headphones', 199.99),
('Smartwatch', 'Fitness Tracker with Heart Rate Monitor', 149.99),
('Tablet', '10.2" Retina Display, A12 Bionic Chip, 128GB Storage', 429.99),
('Camera', '24MP DSLR Camera with 18-55mm Lens', 599.99),
('Speaker', 'Bluetooth Speaker with 20W Output', 79.99),
('Printer', 'All-in-One Inkjet Printer with Wireless Connectivity', 199.99),
('Monitor', '27" QHD Monitor with IPS Panel', 349.99),
('Keyboard', 'Mechanical Gaming Keyboard with RGB Lighting', 129.99);

-- Create Orders table
CREATE TABLE IF NOT EXISTS Orders (
    OrderID INT AUTO_INCREMENT PRIMARY KEY,
    OrderNumber VARCHAR(20) NOT NULL UNIQUE,
    CustomerID INT,
    OrderDate DATE,
    TotalAmount DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID)
);

-- Insert data into Orders table
INSERT INTO Orders (OrderNumber, CustomerID, OrderDate, TotalAmount) VALUES
('ORD001', 1, '2024-03-01', 799.99),
('ORD002', 2, '2024-03-02', 699.99),
('ORD003', 3, '2024-03-03', 199.99),
('ORD004', 4, '2024-03-04', 149.99),
('ORD005', 5, '2024-03-05', 429.99),
('ORD006', 6, '2024-03-06', 599.99),
('ORD007', 7, '2024-03-07', 79.99),
('ORD008', 8, '2024-03-08', 199.99),
('ORD009', 9, '2024-03-09', 349.99),
('ORD010', 10, '2024-03-10', 129.99);

-- Browse data for Customers table
SELECT * FROM Customers;

-- Browse data for Products table
SELECT * FROM Products;

-- Browse data for Orders table
SELECT * FROM Orders;
