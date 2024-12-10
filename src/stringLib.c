/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 1

File name: stringLib.c

Instructor: Marc Schroeder

Purpose: string library that are used such as comparing string
         checking the length of a string

Each of the function is tested, and is working as intended. 

*/

#include "stringLib.h"
#include <stdio.h>

int stringCompare(char const *string1, char const *string2) {

    int i = 0;
    int flag = 0;

    while (string1[i] != '\0' && string2[i] != '\0') {

        if (string1[i] != string2[i]) {

            flag = 1;
            break;

        }

        i++;

    }

    if (string1[i] == '\0' && string2[i] == '\0') {
        flag = 0;  // Strings are equal
    } else {
        flag = 1;  // Strings have different lengths
    }

    return flag;

}

int stringLength(char const *string) {

    int length = 0;

    while (string[length] != '\0') {

        length++;

    }

    return length;

}
