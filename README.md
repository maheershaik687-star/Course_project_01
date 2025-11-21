# Course_project_01
Attendance Management

Abstract

A simple, file-based Attendance Management program in C that stores student info in students.txt and daily attendance in attendance.csv. It provides a console menu to add/view students, mark attendance for the current date, view attendance by date, and compute an individual student’s attendance percentage. The program is lightweight, requires no external libraries, and persists data between runs using plain text files.




Functional requirements

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
