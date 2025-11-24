# Course_project_01
Attendance Management

## Abstract

This project is a simple Attendance Management System written in C using text files for storage. It allows a teacher or admin to store student details like roll number and name in a file called students.txt. For each day, the program asks the user to mark every student as P (Present) or A (Absent) and saves it in attendance.csv.

The project uses a menu-based interface, where the user can choose different options like adding a student, marking attendance, viewing attendance for a specific date, and checking the attendance percentage of a student. The system uses the computer’s current date to automatically save daily attendance.

This system is simple, portable, and easy to run on any machine with a C compiler. It does not require any database; it only uses plain text files.




## Functional requirements

### 2.1 Student Information Storage

The system must store each student’s roll number and name.

The data must be saved permanently in students.txt.

Each student record is stored in the form:


.



 ## Features

Simple persistent storage using plain text files:

students.txt — list of students (CSV: roll,name).

attendance.csv — attendance log (CSV: date,roll,status).

Menu-driven CLI (clear options, loop until exit).

Mark attendance interactively (one student at a time).

View attendance for any date (enter today or a specific YYYY-MM-DD).

Compute per-student attendance percentage (Present / Total records for that roll).

Text-based, portable — can be compiled on Linux/macOS/Windows (with a C compiler).




File formats / examples

students.txt (each line: roll,name)

1,Anita Sharma
2,Raj Patel
3,Sneha Kumar


attendance.csv (each line: YYYY-MM-DD,roll,P or YYYY-MM-DD,roll,A)

2025-11-21,1,P
2025-11-21,2,A
2025-11-21,3,P
2025-11-22,1,P

How to compile & run (Linux / macOS)

Save your source as attendance.c.

Open a terminal in the directory with attendance.c.

Compile:

gcc attendance.c -o attendance


Run:

./attendance

How to compile & run (Windows using MinGW)

Save attendance.c.

Open Command Prompt in that folder (or use MSYS2/MinGW shell).

Compile:

gcc attendance.c -o attendance.exe


Run:

attendance.exe

<img width="384" height="221" alt="image" src="https://github.com/user-attachments/assets/d6ac136e-5b7c-4ccf-927f-b4da8ae1b5a7" />

<img width="406" height="409" alt="Screenshot 2025-11-21 154836" src="https://github.com/user-attachments/assets/4feaac4d-1e8c-42a2-93ac-a8f6eadc86c6" />

