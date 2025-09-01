#include<stdio.h>
#include<string.h>
#include "auth.h"
#include "util.h" //to use clearscreen() and pauseprogram()

#define USER_FILE "users.txt"

typedef struct {
    char username[20];
    char password[20];
} User;

//Register new users
void registerUser(){

    FILE *file = fopen(USER_FILE, "ab");
    if(!file){
        printf("Error: Cannot open users file\n");
        pauseprogram();
        return;
    }

    User u;
    printf("=====Register New User====\n");

    printf("Enter new username: ");
    scanf("%19s",u.username);

    while(1){
        printf("Enter password: ");
        scanf("%19s",u.password);

        if(isStrongPassword(u.password)){
            break;
        }
        else{
            printf("Password must be at least 8 characters,"
                   "with uppercase, lowercase, digit and special character.\n");
        }
    }

    fwrite(&u, sizeof(User), 1, file);
    fclose(file);

    printf("User Registered Successfully!\n");
    
}

//Login existing users
int login(){
    FILE *file = fopen(USER_FILE, "rb");
    if(!file){
        printf("Error: cannot open users file\n");
        pauseprogram();
        return 0;
    }

    char username[30], password[30];

    printf("=========Student Database Login=========\n");

    printf("Enter username: ");
    scanf("%29s",username);

    printf("Enter password: ");
    scanf("%29s",password);

    
    User u;
    //check each user in file
    while (fread(&u, sizeof(User), 1, file)){
        //printf("[DEBUG] File user: %s %s\n", u.username, u.password);
        if(strcmp(username, u.username) == 0 && strcmp(password, u.password) == 0){
            fclose(file);
            printf("\n Login Successul!\n");
            pauseprogram();
            return 1;
        }
    }
    
    fclose(file);
    printf("\nInvalid Username or Password\n");
    pauseprogram();
    return 0;   
}

