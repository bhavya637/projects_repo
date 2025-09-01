#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "student.h"

//Clear the screen
void clearScreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//Pause the program until user presses enter
void pauseprogram(){
    int c;
    printf("\nPress Enter to continue...\n");
    while((c= getchar())!='\n' && c !=EOF){ }
    getchar(); //wait for input
}

//Check if Registered password is strong or not
int isStrongPassword(const char *password){
    int hasUpper=0, hasLower=0, hasDigit=0, hasSpecialCharac=0;

    if(strlen(password)<8){
        printf("Password too short\n");
        return 0;
    }

    for(int i=0; password[i]; i++){
        if(isupper(password[i])){
            hasUpper=1;
        }
        if(islower(password[i])){
            hasLower=1;
        }
        if(isdigit(password[i])){
            hasDigit=1;
        }
        if(!isalnum(password[i])){
            hasSpecialCharac=1;
        }
    }
    return hasUpper&&hasLower&&hasDigit&&hasSpecialCharac;
}

//Check if string has alphabets for name validation
int isAlphabetic(const char *str){
    for(int i=0; str[i]!='\0'; i++){
        if(!isalpha(str[i]) && str[i]!=' '){
            return 0;//invalid
        }
    }
    return 1;//valid
}

//Check if string is a valid number for ID verification
int isNumeric(const char *str){
    for(int i=0; str[i]!='\0'; i++){
        if(!isdigit(str[i])){
            return 0;
        }
    }
    return 1;
}