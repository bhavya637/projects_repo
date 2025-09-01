#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "student.h"
#include "util.h"

#define FILENAME "students.dat"

//Function to add a student
void addStudent(){
    FILE *fp = fopen(FILENAME, "ab"); // open file in append binary mode
    if(fp == NULL){
        printf("Error file does not exist!!!\n");
        return;
    }

    Student s; // Add students
    char buffer[100];

    // --------- Numeric inputs (ID and Age) ----------
    while(1){
        printf("Enter Id: ");
        fgets(buffer,sizeof(buffer),stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(isNumeric(buffer) && buffer[0] != '\0'){
            s.id = atoi(buffer);
            break;
        }
        else{
            printf(" Invalid ID. Digits only!\n");
            continue;
        }
    }

    while(1){
        printf("Enter Age: ");
        fgets(buffer,sizeof(buffer),stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(isNumeric(buffer) && buffer[0] != '\0'){
            s.age = atoi(buffer);
            break;// Both ID and Age valid-> exit numeric loop
        }
        else{
            printf("Invalid Age Digits only!\n");
            continue;
        }
    }

    while(1){
        printf("Enter Phone Number (with country code, e.g. +91XXXXXXXXXX): ");
        fgets(s.phone, sizeof(s.phone), stdin);
        s.phone[strcspn(s.phone, "\n")] = '\0';

        // Check: starts with '+' OR digit, and length >= 10
        if ((s.phone[0] == '+' || isdigit(s.phone[0])) && isNumeric(s.phone + (s.phone[0] == '+' ? 1 : 0)) && strlen(s.phone) >= 10) {
            break;
        } else {
            printf("Invalid Phone Number. Must be digits (and optional +country code).\n");
        }
    }

    // --------- Alphabetic inputs (Name) ----------
    while(1){
        printf("Enter Name: ");
        fgets(s.name, sizeof(s.name), stdin);
        s.name[strcspn(s.name, "\n")] = '\0';

        if(isAlphabetic(s.name) && s.name[0]!='\0'){
            break; //valid name exit loop
        }
        else{
            printf("Invalid Name. Letters only!\n");
        }
    }

    while(1){

        printf("Enter Father's Name: ");
        fgets(s.fatherName, sizeof(s.fatherName), stdin);
        s.fatherName[strcspn(s.fatherName, "\n")] = '\0';

        if (isAlphabetic(s.fatherName) && s.fatherName[0] != '\0') {
            break; // valid → exit loop
        } else {
            printf("Invalid Father's Name. Letters only!\n");
        }
    }

    while(1){

        printf("Enter Mother's Name: ");
        fgets(s.motherName, sizeof(s.motherName), stdin);
        s.motherName[strcspn(s.motherName, "\n")] = '\0';

        if (isAlphabetic(s.motherName) && s.motherName[0] != '\0') {
            break;
        } else {
            printf("Invalid Mother's Name. Letters only!\n");
        }
    }

    while(1){

        printf("Enter Course: ");
        fgets(s.course, sizeof(s.course), stdin);
        s.course[strcspn(s.course, "\n")] = '\0';

        if (isAlphabetic(s.course) && s.course[0] != '\0') {
            break;
        } else {
            printf("Invalid Course. Letters only!\n");
        }
    }

    while(1){

         printf("Enter Email ID: ");
        fgets(s.email, sizeof(s.email), stdin);
        s.email[strcspn(s.email, "\n")] = '\0';

        if (strchr(s.email, '@') && strchr(s.email, '.')) {
            break;
        } else {
            printf("Invalid Email ID. Must contain '@' and a domain like '.com'\n");
        }
    }

    while(1){
        printf("Enter Gender (Male/Female/Other): ");
        fgets(s.gender, sizeof(s.gender), stdin);
        s.gender[strcspn(s.gender, "\n")] = '\0';

        if (isAlphabetic(s.gender) && s.gender[0] != '\0') {
            break;
        } else {
            printf("Invalid Gender. Letters only!\n");
        }
    }

    while(1){
        printf("Enter State: ");
        fgets(s.state, sizeof(s.state), stdin);
        s.state[strcspn(s.state, "\n")] = '\0';

        if (isAlphabetic(s.state) && s.state[0] != '\0') {
            break;
        } else {
            printf("Invalid State. Letters only!\n");
        }
        
    }

    while(1){
        printf("Enter Grade: ");
        fgets(s.grade, sizeof(s.grade), stdin);
        s.grade[strcspn(s.grade, "\n")] = '\0';

        if(isAlphabetic(s.grade) && s.grade[0]!='\0'){
            break; //valid name exit loop
        }
        else{
            printf("Invalid Grade Letters only!\n");
        }
    }

    printf("Enter Address: ");
    fgets(s.address, sizeof(s.address), stdin);
    s.address[strcspn(s.address, "\n")] = '\0';

    while (1) {
    printf("Enter Date of Birth (DD/MM/YYYY): ");
    fgets(s.dob, sizeof(s.dob), stdin);
    s.dob[strcspn(s.dob, "\n")] = '\0';

    int d, m, y;
    if (sscanf(s.dob, "%2d/%2d/%4d", &d, &m, &y) == 3) {
        // Basic validation
        if (d >= 1 && d <= 31 && m >= 1 && m <= 12 && y >= 1900 && y <= 2100) {
            break;  // ✅ valid DOB
        }
    }
    printf("Invalid Date! Format must be DD/MM/YYYY and valid values.\n");
}
// ✅ Write student record to file
if (fwrite(&s, sizeof(Student), 1, fp) == 1) {
    printf("Student entered successfully!\n");
} else {
    printf("❌ Error writing student!\n");
}
    
    fclose(fp);

}

//Function to view students
void viewStudents(){
    FILE *fp = fopen(FILENAME, "rb"); //read-binary
    if(fp == NULL){
        printf("No record\n");
        return;
    }

    Student s;
    //int count=0;
     printf("\n=========================================================================================================================\n");
    printf("| %-2s | %-8s | %-2s | %-3s | %-8s | %-8s | %-10s | %-6s | %-12s | %-18s | %-8s | %-11s | %-6s |\n",
           "ID", "Name", "Age", "Grade", "Father", "Mother", "DOB", "Gender", "Phone", "Email", "Address", "Course", "State");
    printf("=========================================================================================================================\n");

    while (fread(&s, sizeof(Student), 1, fp)) {
        printf("| %-2d | %-8s | %-2d | %-2s | %-8s | %-8s | %-10s | %-6s | %-12s | %-18s | %-8s | %-8s | %-6s |\n",
               s.id, s.name, s.age, s.grade, s.fatherName, s.motherName,
               s.dob, s.gender, s.phone, s.email, s.address, s.course, s.state);
        break;
    }

    printf("=========================================================================================================================\n");

    fclose(fp);   
}

//Functin to search student
void searchStudent(int id){
    FILE *fp = fopen(FILENAME, "rb"); //read-binary
    
    if(fp == NULL){
        printf("No record\n");
        return;
    }
    Student s;
    int found = 0;
    while(fread(&s, sizeof(Student), 1, fp)){
        if(s.id == id){
            printf("\nStudent found:\n");
            printf("ID: %d, Name: %s, Age: %d, Grade: %s",s.id,s.name,s.age,s.grade);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }

}

//Function to update student
void updateStudent(int id){
    FILE *fp = fopen(FILENAME, "rb+"); //read+write
    Student s;
    int found = 0;
    if(fp == NULL){
        printf("No record\n");
        return;
    }

    while(fread(&s, sizeof(Student), 1, fp)){
        if(s.id == id){
            printf("Updating Student with id %d..\n",s.id);

            printf("Enter New Name: ");
            getchar();
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = '\0';

            printf("Enter New Age: ");
            scanf("%d",&s.age);

            printf("Enter New Grade: ");
            scanf("%s", s.grade);

            fseek(fp, -(long)sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if(found){
        printf("Student updated successfully\n");
    }
    else
        printf("Student with ID %d does not found\n",id);
}

// Function to delete student
void deleteStudent(int id){
    FILE *fp = fopen(FILENAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if(fp == NULL){
        printf("No Record found!!\n");
        return;
    }

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp))
    {
        if(s.id == id){
            found = 1; // We have to delete this record so we will not write it in temporary file
        }
        else{
            fwrite(&s, sizeof(Student), 1, temp);
        }
    }
    fclose(fp);
    fclose(temp);

    remove (FILENAME); //delete old file as we have to delete that record
    rename("temp.dat", FILENAME); //Replace with filtered file

    if(found)
        printf("Student deleted successfully\n");
    else
        printf("Student with ID %d not found\n",id);
}

//Function to Export CSV
void exportToCSV(){
    FILE *fp = fopen(FILENAME, "rb");
    FILE *csv = fopen("students.csv", "w");

    if(!fp || !csv){
        printf("No record found!!\n");
    }

    fprintf(csv, "ID | Name | Age | Grade\n");

    Student s;
    while(fread(&s, sizeof(Student), 1, fp)){
        fprintf(csv, "%d | %s | %d | %s\n",s.id, s.name, s.age, s.grade);
    }
    fclose(fp);
    fclose(csv);

    printf("Exported to students.csv successfully\n");
}

//Function to show statistics
void showStatistics(){
    FILE *file = fopen("students.dat","rb");
    if(!file){
        printf("No record available!!\n");
        return;
    }

    int total=0, sumAge=0;
    int gradeA=0, gradeB=0, gradeC=0, gradeD=0;

    Student s;
    while (fread(&s, sizeof(Student), 1, file)){
        total++;
        sumAge += s.age;

        if (strcmp(s.grade, "A") == 0) {
            gradeA++;
        }
        else if (strcmp(s.grade, "B") == 0) {
            gradeB++;
        }
        else if (strcmp(s.grade, "C") == 0) {
            gradeC++;
        }
        else {
            gradeD++;
        }
    }

    fclose(file);

    printf("\n ==========Statistics==========\n");
    printf("Total students: %d\n",total);
    if(total>0){
        printf("Average age: %.2f\n",(float)sumAge/total);
    }
    printf("Grade A: %d | Grade B: %d | Grade C: %d | Grade D: %d\n",gradeA,gradeB,gradeC,gradeD);
    
}
//Function to sort students
int copareByName(const void *a, const void *b){
    const Student *s1 = (const Student *)a;
    const Student *s2 = (const Student *)b;
    return _stricmp(s1->name, s2->name);
}
void sortStudents(){
    FILE *fp = fopen("students.dat","rb");
    if(!fp){
        printf("No record available\n");
        return;
    }

    Student arr[100];
    int count = 0;

    while(fread(&arr[count], sizeof(Student), 1,fp)){
        count++;
    }
    fclose(fp);

    qsort(arr, count,sizeof(Student),copareByName);

    printf("\n============Students Sorted By Name============\n");
    for(int i=0; i<count; i++){
        printf("%d %s %d %s\n",arr[i].id,arr[i].name, arr[i].age, arr[i].grade);
    }

}

