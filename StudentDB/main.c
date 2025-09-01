#include<stdio.h>
#include "student.h"
#include "util.h"
#include "auth.h"

int main(){
    /*if(!login()){
        printf("Exiting Program....\n");
        return 0;
    }*/

    int option;

     while (1) {
        clearScreen();
        printf("===== Welcome =====\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &option);

        if (option == 1) {
            registerUser();   // adds new user to file
            pauseprogram();
        }
        else if (option == 2) {
            if (login()) {   // only go to student DB if login succeeds
                break;       // exit pre-menu loop
            } else {
                printf("Try again...\n");
                pauseprogram();
            }
        }
        else if (option == 0) {
            return 0;
        }
        else {
            printf("Invalid choice!\n");
            pauseprogram();
        }
    }


    int choice;
    while (1){
        clearScreen();
        printf("=========Student Database Management=========\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Export to CSV\n");
        printf("7. Show Statistics\n");
        printf("8. Sort Students by Name\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice){
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: {
                        int id;
                        printf("Enter id: ");
                        scanf("%d",&id);
                        searchStudent(id);
                        break;
                    }
            case 4: {
                        int id;
                        printf("Enter id to update: ");
                        scanf("%d",&id);
                        updateStudent(id);
                        break;
                    }
            case 5: {
                        int id;
                        printf("Enter Id to Delete: ");
                        scanf("%d",&id);
                        deleteStudent(id);
                        break;
                    }
            case 6: exportToCSV(); break;
            case 7: showStatistics(); break;
            case 8: sortStudents(); break;
            case 0: return 0;
            default: printf("Invalid choice!!\n");
        }
        pauseprogram();
    }
    
}

