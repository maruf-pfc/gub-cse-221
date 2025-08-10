-- Done
CREATE TABLE Addresses3 (
    address_id NUMBER PRIMARY KEY,
    address_details VARCHAR2(255)
);
-- Done
CREATE TABLE Schools3 (
    school_id NUMBER PRIMARY KEY,
    address_id NUMBER,
    school_name VARCHAR2(255),
    school_principal VARCHAR2(255),
    other_school_details VARCHAR2(255),
    FOREIGN KEY (address_id) REFERENCES Addresses3(address_id)
);
-- Done
CREATE TABLE Parents3 (
    parent_id NUMBER PRIMARY KEY,
    gender CHAR(1),
    first_name VARCHAR2(255),
    middle_name VARCHAR2(255),
    last_name VARCHAR2(255),
    other_parent_details VARCHAR2(255)
);
-- Done
CREATE TABLE Parent_Addresses3 (
    parent_id NUMBER,
    address_id NUMBER,
    date_address_from DATE,
    date_address_to DATE,
    PRIMARY KEY (parent_id, address_id),
    FOREIGN KEY (parent_id) REFERENCES Parents3(parent_id),
    FOREIGN KEY (address_id) REFERENCES Addresses3(address_id)
);
-- Done
CREATE TABLE Students3 (
    student_id NUMBER PRIMARY KEY,
    gender CHAR(1),
    first_name VARCHAR2(255),
    middle_name VARCHAR2(255),
    last_name VARCHAR2(255),
    date_of_birth DATE,
    other_student_details VARCHAR2(255)
);
-- Done
CREATE TABLE Student_Addresses3 (
    student_id NUMBER,
    address_id NUMBER,
    date_from DATE,
    date_to DATE,
    PRIMARY KEY (student_id, address_id),
    FOREIGN KEY (student_id) REFERENCES Students3(student_id),
    FOREIGN KEY (address_id) REFERENCES Addresses3(address_id)
);
-- Done
CREATE TABLE Teachers3 (
    teacher_id NUMBER PRIMARY KEY,
    school_id NUMBER,
    gender CHAR(1),
    first_name VARCHAR2(255),
    middle_name VARCHAR2(255),
    last_name VARCHAR2(255),
    other_teacher_details VARCHAR2(255),
    FOREIGN KEY (school_id) REFERENCES Schools3 (school_id)
);
-- Done
CREATE TABLE Subjects3 (
    subject_id NUMBER PRIMARY KEY,
    subject_name VARCHAR2(255)
);
-- Done
CREATE TABLE Classes3 (
    class_id NUMBER PRIMARY KEY,
    subject_id NUMBER,
    teacher_id NUMBER,
    class_code VARCHAR2(255),
    class_name VARCHAR2(255),
    date_from DATE,
    date_to DATE,
    FOREIGN KEY (subject_id) REFERENCES Subjects3(subject_id),
    FOREIGN KEY (teacher_id) REFERENCES Teachers3(teacher_id)
);
-- Done
CREATE TABLE Student_Parents3 (
    student_id NUMBER,
    parent_id NUMBER,
    PRIMARY KEY (student_id, parent_id),
    FOREIGN KEY (student_id) REFERENCES Students3(student_id),
    FOREIGN KEY (parent_id) REFERENCES Parents3(parent_id)
);
-- Done
CREATE TABLE Families3 (
    family_id NUMBER PRIMARY KEY,
    head_of_family_parent_id NUMBER,
    family_name VARCHAR2(255),
    FOREIGN KEY (head_of_family_parent_id) REFERENCES Parents3(parent_id)
);
-- Done
CREATE TABLE Family_Members3 (
    family_member_id NUMBER PRIMARY KEY,
    family_id NUMBER,
    parent_or_student_member CHAR(1),
    parent_id NUMBER,
    student_id NUMBER,
    FOREIGN KEY (family_id) REFERENCES Families3(family_id),
    FOREIGN KEY (parent_id) REFERENCES Parents3(parent_id),
    FOREIGN KEY (student_id) REFERENCES Students3(student_id)
);
-- Done
CREATE TABLE Student_Classes3 (
    student_id NUMBER,
    class_id NUMBER,
    date_from DATE,
    date_to DATE,
    PRIMARY KEY (student_id, class_id),
    FOREIGN KEY (student_id) REFERENCES Students3(student_id),
    FOREIGN KEY (class_id) REFERENCES Classes3(class_id)
);
-- Done
CREATE TABLE Homework3 (
    homework_id NUMBER PRIMARY KEY,
    student_id NUMBER,
    class_id NUMBER,
    date_created DATE,
    homework_content CLOB,
    grade VARCHAR2(5),
    other_homework_details VARCHAR2(255),
    FOREIGN KEY (student_id) REFERENCES Students3(student_id),
    FOREIGN KEY (class_id) REFERENCES Classes3(class_id)
);
-- Done
CREATE TABLE Reports3 (
    report_id NUMBER PRIMARY KEY,
    student_id NUMBER,
    class_id NUMBER,
    date_created DATE,
    report_content CLOB,
    teachers_comments CLOB,
    other_report_details VARCHAR2(255),
    FOREIGN KEY (student_id) REFERENCES Students3(student_id),
    FOREIGN KEY (class_id) REFERENCES Classes3(class_id)
);
