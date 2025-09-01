#ifndef UTIL_H
#define UTIL_H

//Function declaration Prototypes

//Clear the screen (cross-platform)
void clearScreen();

//Pause the program until Enter is pressed
void pauseprogram();

//Validates that string contains only alphabets
int isAlphabetic(const char *str);

//Validates that string contains only numbers
int isNumeric(const char *str);

//Validate string password
int isStrongPassword(const char *password);

#endif