-- Create the database
CREATE DATABASE IF NOT EXISTS ecommerce_db1;

-- Use the database
USE ecommerce_db1;

-- Create the tables

-- 1. Users table
CREATE TABLE IF NOT EXISTS Users (
    UserID INT AUTO_INCREMENT PRIMARY KEY,
    Username VARCHAR(50) NOT NULL,
    Email VARCHAR(100) NOT NULL,
    Password VARCHAR(100) NOT NULL
);

-- Insert some sample data into Users table
INSERT INTO Users (Username, Email, Password) VALUES
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

-- 2. Products table
CREATE TABLE IF NOT EXISTS Products (
    ProductID INT AUTO_INCREMENT PRIMARY KEY,
    ProductName VARCHAR(100) NOT NULL,
    Description TEXT,
    Price DECIMAL(10, 2) NOT NULL
);

-- Insert some sample data into Products table
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

-- 3. Orders table
CREATE TABLE IF NOT EXISTS Orders (
    OrderID INT AUTO_INCREMENT PRIMARY KEY,
    OrderNumber VARCHAR(20) NOT NULL,
    CustomerName VARCHAR(100) NOT NULL,
    OrderDate DATE,
    TotalAmount DECIMAL(10, 2) NOT NULL
);

-- Insert some sample data into Orders table
INSERT INTO Orders (OrderNumber, CustomerName, OrderDate, TotalAmount) VALUES
('ORD001', 'Mohammad Ali', '2024-03-01', 799.99),
('ORD002', 'Fatima Khan', '2024-03-02', 699.99),
('ORD003', 'Rahim Hasan', '2024-03-03', 199.99),
('ORD004', 'Nur Jahan', '2024-03-04', 149.99),
('ORD005', 'Aminul Islam', '2024-03-05', 429.99),
('ORD006', 'Sabina Ahmed', '2024-03-06', 599.99),
('ORD007', 'Kamal Hossain', '2024-03-07', 79.99),
('ORD008', 'Mehar Tasnim', '2024-03-08', 199.99),
('ORD009', 'Rubel Islam', '2024-03-09', 349.99),
('ORD010', 'Nusrat Jahan', '2024-03-10', 129.99);

-- 4. Categories table
CREATE TABLE IF NOT EXISTS Categories (
    CategoryID INT AUTO_INCREMENT PRIMARY KEY,
    CategoryName VARCHAR(100) NOT NULL,
    Description TEXT
);

-- Insert some sample data into Categories table
INSERT INTO Categories (CategoryName, Description) VALUES
('Electronics', 'Devices that operate using electric power.'),
('Clothing', 'Articles of dress worn on the body.'),
('Accessories', 'Additional items to complement or enhance something.'),
('Home Appliances', 'Appliances used for household purposes.'),
('Beauty & Personal Care', 'Products used to enhance or maintain personal appearance.'),
('Books & Stationery', 'Books and office supplies.');

-- 5. Shipping table
CREATE TABLE IF NOT EXISTS Shipping (
    ShippingID INT AUTO_INCREMENT PRIMARY KEY,
    OrderID INT,
    ShippingDate DATE,
    ShippingAddress TEXT,
    ShippingStatus VARCHAR(20) NOT NULL
);

-- Insert some sample data into Shipping table
INSERT INTO Shipping (OrderID, ShippingDate, ShippingAddress, ShippingStatus) VALUES
(1, '2024-03-02', '123 Main St, City, Country', 'Shipped'),
(2, '2024-03-03', '456 Oak Ave, Town, Country', 'Shipped'),
(3, '2024-03-04', '789 Pine Rd, Village, Country', 'In Transit'),
(4, '2024-03-05', '101 Maple Blvd, Hamlet, Country', 'Delivered'),
(5, '2024-03-06', '321 Cedar Ln, Borough, Country', 'In Transit'),
(6, '2024-03-07', '555 Elm St, City, Country', 'Shipped'),
(7, '2024-03-08', '777 Pine St, Town, Country', 'Delivered'),
(8, '2024-03-09', '999 Oak St, Village, Country', 'In Transit'),
(9, '2024-03-10', '111 Maple St, Hamlet, Country', 'Shipped'),
(10, '2024-03-11', '222 Cedar St, Borough, Country', 'In Transit');
