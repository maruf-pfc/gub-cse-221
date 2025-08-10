CREATE DATABASE lab6Exercise;

USE lab6Exercise;

CREATE TABLE StudentInfo (
    StudentID INT PRIMARY KEY,
    StudentName VARCHAR(100),
    Address VARCHAR(255),
    Email VARCHAR(100)
);

CREATE TABLE WaiverInfo (
    StudentID INT PRIMARY KEY,
    StudentName VARCHAR(100),
    CGPA DOUBLE,
    WaiverPercentage INT,
    FOREIGN KEY (StudentID) REFERENCES StudentInfo(StudentID)
);

INSERT INTO
    StudentInfo (StudentID, StudentName, Address, Email)
VALUES
    (
        1,
        'Michael Scott',
        '1725 Slough Ave',
        'michael.scott@dundermifflin.com'
    ),
    (
        2,
        'Jim Halpert',
        '247 Dunder Ave',
        'jim.halpert@dundermifflin.com'
    ),
    (
        3,
        'Pam Beesly',
        '350 Paper St',
        'pam.beesly@dundermifflin.com'
    ),
    (
        4,
        'Dwight Schrute',
        '400 Beet Farm Rd',
        'dwight.schrute@dundermifflin.com'
    ),
    (
        5,
        'Stanley Hudson',
        '100 Scranton St',
        'stanley.hudson@dundermifflin.com'
    );

INSERT INTO
    WaiverInfo (StudentID, StudentName, CGPA, WaiverPercentage)
VALUES
    (1, 'Michael Scott', 3.90, 10),
    (2, 'Jim Halpert', 3.85, 5),
    (3, 'Pam Beesly', 3.70, 0),
    (4, 'Dwight Schrute', 3.65, 0),
    (5, 'Stanley Hudson', 3.75, 5);

SELECT
    *
FROM
    WaiverInfo;

SELECT
    *
FROM
    StudentInfo;

DELIMITER CREATE TRIGGER update_waiver_percentage
AFTER
INSERT
    OR
UPDATE
    ON WaiverInfo FOR EACH ROW BEGIN DECLARE new_waiver INT;

IF NEW.CGPA >= 3.90 THEN
SET
    new_waiver = OLD.WaiverPercentage + 10;

ELSEIF NEW.CGPA >= 3.80 THEN
SET
    new_waiver = OLD.WaiverPercentage + 5;

ELSE
SET
    new_waiver = OLD.WaiverPercentage;

END IF;

UPDATE
    WaiverInfo
SET
    WaiverPercentage = new_waiver
WHERE
    StudentID = NEW.StudentID;

END;

DELIMITER;

INSERT INTO
    StudentInfo (StudentID, StudentName, Address, Email)
VALUES
    (
        6,
        'Ryan Howard',
        '505 Temp St',
        'ryan.howard@dundermifflin.com'
    ),
    (
        7,
        'Kelly Kapoor',
        '606 Gossip Ln',
        'kelly.kapoor@dundermifflin.com'
    );

INSERT INTO
    WaiverInfo (StudentID, StudentName, CGPA, WaiverPercentage)
VALUES
    (6, 'Ryan Howard', 3.80, 5),
    (7, 'Kelly Kapoor', 3.95, 10);

SELECT
    *
FROM
    WaiverInfo;

SELECT
    *
FROM
    StudentInfo;