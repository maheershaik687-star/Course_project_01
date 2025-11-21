/* attendance.c
   Simple Attendance Management System (file-based)
   Compile: gcc attendance.c -o attendance
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STUD_FILE "students.txt"
#define ATT_FILE  "attendance.csv"
#define NAME_LEN  100
#define LINE_LEN  256

/* Helper: get today's date as YYYY-MM-DD */
void get_today(char *buf, size_t n) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    snprintf(buf, n, "%04d-%02d-%02d", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday);
}

/* Trim newline from fgets */
void trim_newline(char *s) {
    size_t l = strlen(s);
    if (l > 0 && (s[l-1] == '\n' || s[l-1] == '\r')) s[l-1] = '\0';
}

/* Add a student (append to students.txt) */
void add_student() {
    int roll;
    char name[NAME_LEN];

    printf("Enter roll number: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid roll.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n'); // clear newline

    printf("Enter name: ");
    if (!fgets(name, sizeof(name), stdin)) return;
    trim_newline(name);

    FILE *f = fopen(STUD_FILE, "a");
    if (!f) { perror("Unable to open students file"); return; }
    fprintf(f, "%d,%s\n", roll, name);
    fclose(f);
    printf("Student added: %d, %s\n", roll, name);
}

/* View all students */
void view_students() {
    FILE *f = fopen(STUD_FILE, "r");
    if (!f) { printf("No students found (file missing).\n"); return; }
    char line[LINE_LEN];
    printf("\nRoll\tName\n----\t----\n");
    while (fgets(line, sizeof(line), f)) {
        trim_newline(line);
        if (strlen(line) == 0) continue;
        char *comma = strchr(line, ',');
        if (!comma) continue;
        *comma = '\0';
        printf("%s\t%s\n", line, comma + 1);
    }
    fclose(f);
}

/* Mark attendance for today for all students */
void mark_attendance() {
    // read students into memory
    FILE *f = fopen(STUD_FILE, "r");
    if (!f) { printf("No students file found. Add students first.\n"); return; }

    typedef struct { int roll; char name[NAME_LEN]; } Stu;
    Stu arr[1000];
    int n = 0;
    char line[LINE_LEN];
    while (fgets(line, sizeof(line), f)) {
        trim_newline(line);
        if (strlen(line) == 0) continue;
        int r;
        char nm[NAME_LEN];
        if (sscanf(line, "%d,%99[^\n]", &r, nm) == 2) {
            arr[n].roll = r;
            strncpy(arr[n].name, nm, NAME_LEN);
            n++;
            if (n >= 1000) break;
        }
    }
    fclose(f);
    if (n == 0) { printf("No students to mark.\n"); return; }

    char date[32];
    get_today(date, sizeof(date));
    printf("Marking attendance for date: %s\n", date);
    printf("Enter P for present, A for absent. (case-insensitive)\n");

    FILE *fa = fopen(ATT_FILE, "a");
    if (!fa) { perror("Unable to open attendance file"); return; }

    for (int i = 0; i < n; ++i) {
        char status[4];
        while (1) {
            printf("%d - %s: ", arr[i].roll, arr[i].name);
            if (!fgets(status, sizeof(status), stdin)) { strcpy(status, "A\n"); }
            trim_newline(status);
            if (strlen(status) == 0) continue;
            char ch = status[0];
            if (ch == 'P' || ch == 'p') {
                fprintf(fa, "%s,%d,P\n", date, arr[i].roll);
                break;
            } else if (ch == 'A' || ch == 'a') {
                fprintf(fa, "%s,%d,A\n", date, arr[i].roll);
                break;
            } else {
                printf("Please enter P or A.\n");
            }
        }
    }
    fclose(fa);
    printf("Attendance saved to %s\n", ATT_FILE);
}

/* View attendance for a specific date */
void view_attendance_by_date() {
    char date[32];
    printf("Enter date (YYYY-MM-DD) or 'today': ");
    if (!fgets(date, sizeof(date), stdin)) return;
    trim_newline(date);
    if (strcmp(date, "today") == 0 || strlen(date) == 0) get_today(date, sizeof(date));

    FILE *f = fopen(ATT_FILE, "r");
    if (!f) { printf("No attendance records found.\n"); return; }
    char line[LINE_LEN];
    printf("\nAttendance for %s\n", date);
    printf("Roll\tStatus\n----\t------\n");
    int found = 0;
    while (fgets(line, sizeof(line), f)) {
        trim_newline(line);
        int r;
        char d[32], s[4];
        if (sscanf(line, "%31[^,],%d,%3s", d, &r, s) == 3) {
            if (strcmp(d, date) == 0) {
                printf("%d\t%s\n", r, s);
                found = 1;
            }
        }
    }
    if (!found) printf("No records for this date.\n");
    fclose(f);
}

/* Compute attendance percentage for a roll across all dates */
void student_percentage() {
    int roll;
    printf("Enter student's roll number: ");
    if (scanf("%d", &roll) != 1) { printf("Invalid roll.\n"); while (getchar() != '\n'); return; }
    while (getchar() != '\n');

    FILE *f = fopen(ATT_FILE, "r");
    if (!f) { printf("No attendance records found.\n"); return; }

    char line[LINE_LEN];
    int total = 0, present = 0;
    while (fgets(line, sizeof(line), f)) {
        trim_newline(line);
        int r;
        char d[32], s[4];
        if (sscanf(line, "%31[^,],%d,%3s", d, &r, s) == 3) {
            if (r == roll) {
                total++;
                if (s[0] == 'P' || s[0] == 'p') present++;
            }
        }
    }
    fclose(f);
    if (total == 0) {
        printf("No attendance records found for roll %d.\n", roll);
        return;
    }
    double percent = (100.0 * present) / total;
    printf("Roll %d -> Present: %d / %d  (%.2f%%)\n", roll, present, total, percent);
}

/* Main menu */
int main() {
    int choice;
    char temp[8];

    while (1) {
        printf("\n=== Attendance Management (C) ===\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Mark Attendance (today)\n");
        printf("4. View Attendance by Date\n");
        printf("5. Student Attendance Percentage\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        if (!fgets(temp, sizeof(temp), stdin)) continue;
        choice = atoi(temp);

        switch (choice) {
            case 1: add_student(); break;
            case 2: view_students(); break;
            case 3: mark_attendance(); break;
            case 4: view_attendance_by_date(); break;
            case 5: student_percentage(); break;
            case 6: printf("Exiting. Bye!\n"); exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}