/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 1

File name: stringLib.h

Instructor: Marc Schroeder

Purpose: functions prototypes for string library functions

*/
#ifndef STRINGLIB_H
#define STRINGLIB_H

/*

Function: stringCompare

Purpose: to compare two strings to see if they're equal or not

Details: this function compares two strings that are null terminated 
         to see if they're the same or not. It will loop through both 
         string and compare to each other until a null char is 
         encountered.

Input: takes two strings which are a pointer to a character named
       string1 and string2

Output: a flag to indicate if a string is equal (0) or a 1 
        if the two string are not equal

*/
int stringCompare(char const *string1, char const *string2);

/*

Function: stringLength

Purpose: to get the length of a string

Details: this function will loop through the string 
         and check the length of the string and return
         the length

Input: takes in a pointer to a constant char (the string
       that needs its length)

Output: returns the length of the string.

*/
int stringLength(char const *string);

#endif