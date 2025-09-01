#ifndef STUDENT_H
#define  STUDENT_H

// STudent Structure
typedef struct{

    int id;
    char name[50];
    int age;
    char grade[10];
    char fatherName[50];
    char motherName[50];
    char address[100];
    char course[50];
    char email[50];
    char phone[30];
    char dob[15];
    char gender[10];
    char state[50];
} Student;

// Function declaration
void addStudent();
void viewStudents();
void searchStudent(int id);
void updateStudent(int id);
void deleteStudent(int id);
void exportToCSV();
void showStatistics();
void sortStudents();

#endif
