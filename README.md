# Course_project_01
Attendance Management

## Abstract

This project is a simple Attendance Management System written in C using text files for storage. It allows a teacher or admin to store student details like roll number and name in a file called students.txt. For each day, the program asks the user to mark every student as P (Present) or A (Absent) and saves it in attendance.csv.

The project uses a menu-based interface, where the user can choose different options like adding a student, marking attendance, viewing attendance for a specific date, and checking the attendance percentage of a student. The system uses the computer’s current date to automatically save daily attendance.

This system is simple, portable, and easy to run on any machine with a C compiler. It does not require any database; it only uses plain text files.




## Functional requirements

#### 1) Student Information Storage

- The system must store each student’s roll number and name.

- The data must be saved permanently in students.txt.

- Each student record is stored in the form:

#### 2) Attendance Recording

- The system must allow the user to mark attendance for today’s date.

- It should automatically detect the system date (e.g., 2025-11-24).

- For each student, the user must enter either:

- P → Present

- A → Absent


#### 3) Viewing Attendance

- The system must allow viewing attendance of any date.

- The user can type today or enter a date manually (YYYY-MM-DD).

- The program must print all roll numbers and their status for that day.


#### 4) Individual Attendance Percentage

- The system must calculate:

- how many days a student was present,

- how many total attendance entries the student has,and the percentage.




#### 5) Menu-Based System

- The system must repeatedly ask the user to choose an option until they exit:

- Add student

- View students

- Mark attendance

- View attendance for a date

- Student attendance percentage

- Exit


#### 6) Error Handling

- Handle invalid input letters except P/A.

- Handle missing files (show a message instead of crashing).

- Ignore empty lines or corrupted lines inside files.


## Features


#### 1. Add New Students

- You can add a student by entering:

- Roll number

- Name

- The details are saved permanently in a file students.txt.

- Format inside the file →

#### 2. View All Students

- Displays a neat list of all registered students.

- Reads the data from students.txt and prints:

#### 3. Mark Attendance for Today

- The program automatically detects today’s date using system time.

- For each student, it asks:

Saves attendance for each student in attendance.csv in this format:

✔ Easy to record attendance

✔ Automatically stores by date, roll number, and status

#### 4. View Attendance by Date

- You can type a specific date like:

2025-11-23


- or you can simply type:

 today


- The program reads attendance.csv and prints all students' attendance for that date.

#### Example output:

Attendance for 2025-11-24

Roll         Status
----       ------
101        P

102        A

#### 5. Calculate Student Attendance Percentage

- Enter a student’s roll number.

- The program counts:

- How many days attendance is recorded

- How many days the student was present

- Then it calculates:

- Percentage = (Present / Total Days) × 100


#### Example:

Roll 101 -> Present: 18 / 20 (90.00%)


#### 6. File-Based Permanent Storage

- The program uses text files to store data permanently:

- students.txt for student details

- attendance.csv for attendance records

- Even if you close the program, your data stays saved.
#### 7. User-Friendly Menu System

- A simple 1–6 menu lets you:

- Add students

- View students

- Mark attendance

- Check attendance

- View percentage

- Exit program





## How to Run the Attendance Project (Windows / Linux)

- Save Your Code in a File

- Open Notepad, VS Code, CodeBlocks, or any editor.

- Copy the full code.

- Save it as:

attendance.c


- Make sure the file extension is .c, not .txt.

  #### Install a C Compiler (if not installed)
✔ Windows Users

Install MinGW (GCC compiler):

- 🔗 https://sourceforge.net/projects/mingw/

- During setup → Make sure gcc is checked.

- After installation, open Command Prompt (cmd) and type:

 gcc --version

 - If it shows a version, you’re ready.


✔ Linux Users

- GCC is usually installed. But if not:

- Ubuntu / Debian:

sudo apt install build-essential


- Fedora:

sudo dnf install gcc

#### Compile the Program

Open Command Prompt (Windows) or Terminal (Linux).

Go to the folder where you saved attendance.c.
   

