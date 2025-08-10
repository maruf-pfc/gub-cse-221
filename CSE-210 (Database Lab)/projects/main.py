import random
from datetime import datetime, timedelta

first_names = ["John", "Jane", "Alex", "Emily", "Chris", "Katie", "Michael", "Laura", "David", "Sarah",
               "Daniel", "Emma", "Matthew", "Olivia", "Andrew", "Sophia", "Ryan", "Isabella", "Joshua", "Ava",
               "Jacob", "Mia", "Nicholas", "Ella", "Tyler", "Charlotte", "Aaron", "Amelia", "Samuel", "Harper",
               "Justin", "Evelyn", "Jonathan", "Abigail", "Jordan", "Madison", "Brandon", "Lily", "Ethan", "Grace"]

middle_names = ["James", "Anne", "Lee", "Marie", "Jordan", "Grace", "Ryan", "Louise", "Scott", "Elizabeth",
                "Michael", "Rose", "Thomas", "Claire", "David", "Paige", "Matthew", "Brooke", "Joseph", "Faith",
                "Alexander", "Renee", "Daniel", "Jane", "Christopher", "Hope", "Anthony", "Nicole", "Robert", "Lynn"]

last_names = ["Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor",
              "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", "Garcia", "Martinez", "Robinson",
              "Clark", "Rodriguez", "Lewis", "Lee", "Walker", "Hall", "Allen", "Young", "King", "Wright",
              "Scott", "Torres", "Nguyen", "Hill", "Flores", "Green", "Adams", "Nelson", "Baker", "Perez"]

schools = ["Greenwood High", "Riverdale Academy", "Hilltop School", "Lakewood School", "Sunrise Academy",
           "Pine Valley School", "Oakwood Academy", "Maple Ridge School", "Cedar Hill School", "Willow Creek School"]

subjects = ["Math", "Science", "History", "Art", "Physical Education", "Music", "Geography", "English", "Biology", "Chemistry", "DBMS", "Operating Systems", "Computer Networks", "Data Structures", "Algorithms", "Software Engineering", "Computer Architecture", "Computer Graphics", "Artificial Intelligence", "Machine Learning", "C", "C++", "Java", "Python", "JavaScript", "HTML", "CSS", "SQL", "PHP", "Ruby", "Swift", "Kotlin", "Rust", "Go", "Scala", "Haskell", "Perl", "R", "TypeScript", "Assembly", "COBOL", "Fortran", "Lisp", "Prolog", "Ada", "Pascal", "Smalltalk", "Objective-C", "Visual Basic", "Dart", "Lua", "MATLAB", "Verilog", "VHDL", "SystemVerilog", "Assembly", "Bash", "PowerShell", "Racket", "Scheme", "Clojure", "Erlang", "F#", "OCaml", "D", "Kotlin", "Rust", "Go", "Scala", "Haskell", "Perl", "R", "TypeScript", "Assembly", "COBOL", "Fortran", "Lisp", "Prolog", "Ada", "Pascal", "Smalltalk", "Objective-C", "Visual Basic", "Dart", "Lua", "MATLAB", "Verilog", "VHDL", "SystemVerilog", "Assembly", "Bash", "PowerShell", "Racket", "Scheme", "Clojure", "Erlang", "F#", "OCaml", "D", "Kotlin", "Rust", "Go", "Scala", "Haskell", "Perl", "R", "TypeScript", "Assembly", "COBOL", "Fortran", "Lisp", "Prolog", "Ada", "Pascal", "Smalltalk", "Objective-C", "Visual Basic", "Dart", "Lua", "MATLAB", "Verilog", "VHDL", "SystemVerilog", "Assembly", "Bash", "PowerShell", "Racket", "Scheme", "Clojure", "Erlang", "F#", "OCaml", "D", "Kotlin", "Rust", "Go", "Scala", "Haskell", "Perl", "R", "TypeScript", "Assembly", "COBOL", "Fortran", "Lisp", "Prolog", "Ada", "Pascal", "Smalltalk", "Objective-C", "Visual Basic", "Dart", "Lua", "MATLAB", "Verilog"]

def random_date(start_year=1990, end_year=2010):
    """Generate a random date of birth."""
    start_date = datetime(start_year, 1, 1)
    end_date = datetime(end_year, 12, 31)
    delta = end_date - start_date
    random_days = random.randint(0, delta.days)
    return (start_date + timedelta(days=random_days)).strftime('%Y-%m-%d')

def generate_insert_queries():
    with open('insert_queries.sql', 'w') as f:
        # # Generate student inserts
        # for i in range(1, 10001):
        #     student_id = i
        #     gender = 'M' if i % 2 == 0 else 'F'
        #     first_name = random.choice(first_names)
        #     # middle_name = random.choice(middle_names)
        #     last_name = random.choice(last_names)
        #     date_of_birth = random_date()
        #     other_student_details = "N/A"

        #     query = (f"INSERT INTO Students3 (student_id, gender, first_name, last_name, date_of_birth, other_student_details) "
        #              f"VALUES ('{student_id}', '{gender}', '{first_name}', '{last_name}', TO_DATE('{date_of_birth}', 'YYYY-MM-DD'), '{other_student_details}');\n")
        #     f.write(query)

        # # # Generate address inserts
        # # for i in range(1, 10001):
        # #     address_details = i
        # #     query = f"INSERT INTO Addresses (address_id, address_details) VALUES ({i}, '{address_details}');\n"
        # #     f.write(query)

        # # # Generate school inserts
        # # for i in range(1, 10001):
        # #     address_id = random.randint(1, 10000)
        # #     school_name = random.choice(schools)
        # #     school_principal = random.choice(first_names) + " " + random.choice(last_names)
        # #     other_school_details = f"Details about {school_name}"
        # #     query = (f"INSERT INTO Schools (school_id, address_id, school_name, school_principal, other_school_details) "
        # #              f"VALUES ({i}, {address_id}, '{school_name}', '{school_principal}', '{other_school_details}');\n")
        # #     f.write(query)

        # # # Generate parent inserts
        # # for i in range(1, 10001):
        # #     gender = random.choice(['M', 'F'])
        # #     first_name = random.choice(first_names)
        # #     middle_name = random.choice(middle_names)
        # #     last_name = random.choice(last_names)
        # #     other_parent_details = f"Details about {first_name}"
        # #     query = (f"INSERT INTO Parents (parent_id, gender, first_name, middle_name, last_name, other_parent_details) "
        # #              f"VALUES ({i}, '{gender}', '{first_name}', '{middle_name}', '{last_name}', '{other_parent_details}');\n")
        # #     f.write(query)

        # Generate parent addresses inserts
        # for i in range(1, 10001):
        #     parent_id = i
        #     address_id = i
        #     date_address_from = random_date(1990, 2010)
        #     date_address_to = random_date(2010, 2020)
        #     query = (f"INSERT INTO Parent_Addresses3 (parent_id, address_id, date_address_from, date_address_to) "
        #              f"VALUES ({parent_id}, {address_id}, TO_DATE('{date_address_from}', 'YYYY-MM-DD'), TO_DATE('{date_address_to}', 'YYYY-MM-DD'));\n")
        #     f.write(query)

        # Generate student addresses inserts
        # for i in range(1, 10001):
        #     student_id = i
        #     address_id = i
        #     date_from = random_date(1990, 2010)
        #     date_to = random_date(2010, 2020)
        #     query = (f"INSERT INTO Student_Addresses3 (student_id, address_id, date_from, date_to) "
        #              f"VALUES ({student_id}, {address_id}, TO_DATE('{date_from}', 'YYYY-MM-DD'), TO_DATE('{date_to}', 'YYYY-MM-DD'));\n")
        #     f.write(query)

        # Generate teacher inserts
        # for i in range(1, 10001):
        #     school_id = i
        #     gender = random.choice(['M', 'F'])
        #     first_name = random.choice(first_names)
        #     last_name = random.choice(last_names)
        #     other_teacher_details = "N/A"
        #     query = (f"INSERT INTO Teachers3 (teacher_id, school_id, gender, first_name, last_name, other_teacher_details) "
        #              f"VALUES ({i}, {school_id}, '{gender}', '{first_name}', '{last_name}', '{other_teacher_details}');\n")
        #     f.write(query)

        # Generate subject inserts
        # for i in range(1, 10001):
        #     subject_name = random.choice(subjects)
        #     query = f"INSERT INTO Subjects3 (subject_id, subject_name) VALUES ({i}, '{subject_name}');\n"
        #     f.write(query)

        # Generate class inserts
        # for i in range(1, 10001):
        #     subject_id = i
        #     teacher_id = i
        #     class_code = f"{random.choice(subjects)}"
        #     class_code += f"{random.choice(['101', '201', '301', '102', '202', '302', '103', '203', '303'])}"
        #     class_name = random.choice(subjects)
        #     date_from = random_date()
        #     date_to = random_date()
        #     query = (f"INSERT INTO Classes3 (class_id, subject_id, teacher_id, class_code, class_name, date_from, date_to) "
        #              f"VALUES ({i}, {subject_id}, {teacher_id}, '{class_code}', '{class_name}', TO_DATE('{date_from}', 'YYYY-MM-DD'), TO_DATE('{date_to}', 'YYYY-MM-DD'));\n")
        #     f.write(query)

        # Generate student parents inserts
        # for i in range(1, 10001):
        #     student_id = i
        #     parent_id = i
        #     query = f"INSERT INTO Student_Parents3 (student_id, parent_id) VALUES ({student_id}, {parent_id});\n"
        #     f.write(query)

        # Generate family inserts
        # for i in range(1, 10001):
        #     head_of_family_parent_id = i
        #     family_name = f"Family {i}"
        #     query = (f"INSERT INTO Families3 (family_id, head_of_family_parent_id, family_name) "
        #              f"VALUES ({i}, {head_of_family_parent_id}, '{family_name}');\n")
        #     f.write(query)

        # Generate family members inserts
        # for i in range(1, 10001):
        #     family_id = i
        #     parent_or_student_member = random.choice(['P', 'S'])
        #     parent_id = i if parent_or_student_member == 'P' else 'NULL'
        #     student_id = i if parent_or_student_member == 'S' else 'NULL'
        #     query = (f"INSERT INTO Family_Members3 (family_member_id, family_id, parent_or_student_member, parent_id, student_id) "
        #              f"VALUES ({i}, {family_id}, '{parent_or_student_member}', {parent_id}, {student_id});\n")
        #     f.write(query)

        # Generate homework inserts
        # for i in range(1, 10001):
        #     student_id = i
        #     date_created = random_date()
        #     homework_content = f"Homework content {i}"
        #     grade = random.randint(1, 100)
        #     grade = 'A+' if grade >= 90 else 'A' if grade >= 80 else 'B' if grade >= 70 else 'C' if grade >= 60 else 'D' if grade >= 50 else 'F'
        #     other_homework_details = "N/A"
        #     query = (f"INSERT INTO Homework3 (homework_id, student_id, date_created, homework_content, grade, other_homework_details) "
        #              f"VALUES ({i}, {student_id}, TO_DATE('{date_created}', 'YYYY-MM-DD'), '{homework_content}', '{grade}', '{other_homework_details}');\n")
        #     f.write(query)

        # Generate report inserts
        # for i in range(1, 10001):
        #     student_id = i
        #     class_id = i
        #     date_created = random_date()
        #     report_content = f"Report content {i}"
        #     teachers_comments = f"Comments for report {i}"
        #     other_report_details = "N/A"
        #     query = (f"INSERT INTO Reports3 (report_id, student_id, class_id, date_created, report_content, teachers_comments, other_report_details) "
        #              f"VALUES ({i}, {student_id}, {class_id}, TO_DATE('{date_created}', 'YYYY-MM-DD'), '{report_content}', '{teachers_comments}', '{other_report_details}');\n")
        #     f.write(query)

        # Generate student classes inserts
        # for i in range(1, 10001):
        #     student_id = i
        #     class_id = i
        #     date_from = random_date(1990, 2010)
        #     date_to = random_date(2010, 2020)
        #     query = (f"INSERT INTO Student_Classes3 (student_id, class_id, date_from, date_to) "
        #              f"VALUES ({student_id}, {class_id}, TO_DATE('{date_from}', 'YYYY-MM-DD'), TO_DATE('{date_to}', 'YYYY-MM-DD'));\n")
        #     f.write(query)

if __name__ == "__main__":
    generate_insert_queries()
