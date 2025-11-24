# Course_project_01
Attendance Management

## Abstract

A simple, file-based Attendance Management program in C that stores student info in students.txt and daily attendance in attendance.csv. It provides a console menu to add/view students, mark attendance for the current date, view attendance by date, and compute an individual student’s attendance percentage. The program is lightweight, requires no external libraries, and persists data between runs using plain text files.




## Functional requirements

Persist student records

Store roll number and name in students.txt (one student per line, CSV format: roll,name).

Record daily attendance

For each class/day, append per-student attendance rows to attendance.csv in the format: YYYY-MM-DD,roll,P|A.

User interactions (console menu)

Add a student.

View all students.

Mark attendance for today for every student (prompt P/A for each).

View attendance records for a specific date.

Compute attendance percentage for a specific roll across all recorded dates.

Exit the application.

Date handling

Automatically use the system date for “today” records (format YYYY-MM-DD).

Allow manual date entry (YYYY-MM-DD) when viewing attendance by date.

Validation & robustness

Basic input validation for roll numbers and attendance entries (only accept P or A).

Handle missing files gracefully (prompt to add students or show no records).



## Features (what the program provides)

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

