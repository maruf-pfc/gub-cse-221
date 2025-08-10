-- https://paste.ubuntu.com/p/WqT5H3hzp7/

-- Step 1: Create the "University" database
CREATE DATABASE IF NOT EXISTS University;

-- Select Database
USE University;

-- Step 2: Create the "Teacher" table
CREATE TABLE IF NOT EXISTS Teacher (
    TeacherID INT AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(255) NOT NULL,
    Designation VARCHAR(100),
    Address VARCHAR(255),
    Email VARCHAR(100)
);

-- Step 3: Create the "Student" table
CREATE TABLE IF NOT EXISTS Student (
    StudentID INT AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(255) NOT NULL,
    Address VARCHAR(255),
    Phone VARCHAR(20)
);

-- Step 4: Create the "Staff" table
CREATE TABLE IF NOT EXISTS Staff (
    StaffID INT AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(255) NOT NULL,
    Position VARCHAR(100),
    Address VARCHAR(255),
    Phone VARCHAR(20)
);

-- Insert demo data into the Teacher table
INSERT INTO Teacher (Name, Designation, Address, Email) VALUES
('John Doe', 'Professor', '123 Main St, City', 'john.doe@example.com'),
('Jane Smith', 'Assistant Professor', '456 Elm St, Town', 'jane.smith@example.com'),
('Michael Johnson', 'Associate Professor', '789 Oak St, Village', 'michael.johnson@example.com');

-- Insert demo data into the Student table
INSERT INTO Student (Name, Address, Phone) VALUES
('Alice Johnson', '321 Maple Ave, City', '555-1234'),
('Bob Williams', '654 Pine St, Town', '555-5678'),
('Emily Brown', '987 Cedar St, Village', '555-9012');

-- Insert demo data into the Staff table
INSERT INTO Staff (Name, Position, Address, Phone) VALUES
('Sarah Wilson', 'Administrative Assistant', '111 Walnut St, City', '555-1111'),
('David Lee', 'Custodian', '222 Birch St, Town', '555-2222'),
('Karen Garcia', 'IT Technician', '333 Spruce St, Village', '555-3333');
