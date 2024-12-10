/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 1

File name: shell.h

Instructor: Marc Schroeder

Purpose: function prototypes for shell and its
         basic function

*/

#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "const.h"
#include "stringLib.h"
#include "IORedirect.h"
#include "BackgroundJob.h"
#include "pipes.h"
#include "commandHistory.h"

/*
Command struture that holds the fields of two arguements of a command line
*/
typedef struct Command {

    char *arg1[MAX_ARGS];
    char *arg2[MAX_ARGS];

} Command;

/*

Function: login

Purpose: This function prompts the user to log into shell with 
         their credentials (username and password). 
         
Details: For simplicity of this testing and logging in, the 
         username and password are basic. It will prompt the user
         to enter the username and password. The function will use
         stringCompare to compare if the username and password match, 
         if they do not match, it will prompt the user to enter the 
         correct username and password until it is right. The function
         uses the system call "read" to get user input. As well as the
         "write" system call to prompt the user.

         username: testuser
         password: password


Input:  Does not take any input values

Returns: Returns if login was successful (1) or unsuccessful (-1)

*/
int login();

/*

Function: readCommand

Purpose: is to read a command line input from the user, tokenize the 
         command and to store thte token in the array of the structure

Details: Depending on what the command argument is, the function will 
         tokenize the argument in the following ways:

         1. if there is no special symbol such as IO redirect or pipe,
            the function will tokenize the input and store the argument
            in arg1 

        2. if the input is seen with the pipe (|) symbol or either IO 
           redirect (<,>), it will read the first part of the arugment 
           up until the symbol and store the argument into arg1. After
           it reads the symbol that is passed, it will read the second
           part of the arguement until a null terminator ('\n') and
           it will store the second argument in arg2. 

           The input is read into an array called buffer and it is
           tokenized into a 2D array which then arg1 or arg2 is set 
           to point at the first char in each of the string.

         3. if the input is an up-arrow(s), 

Input: takes in the Command structure of two arguments, an array
       of char which is the symbol from the argument and a 
       temp array which tokenizes the input

Returns: returns a token counter of the number of arugments that were 
         read from the command land and if the read was succesful. -2
         is returned if up-arrow(s) entered or there are no commands entered, while -1 is 
         returned if there are any read errors. 

Example of how the function works:

if input is: /bin/ls -al | /usr/bin/wc -l\

   tempArr[0][7] = /bin/ls
   arg1[0] = /bin/ls
   tempArr[1][3] = -al
   arg1[1] = -al
   tempArr[2][11] = /usr/bin/wc
   arg1[2] = /usr/bin/wc
   tempArr[3][2] = -l
   arg1[3] = -l

*/
int readCommand(Command *command, char symbol[], char tempArr[][MAX_LINE], History *history);

/*

Function: processCommand

Purpose: to create a child process and to execute the
         command that is read in 

Details: this function creates a child process and it 
         executes a command in the child process that was created 
         and waits until it is executed. It checks if the child
         process was created and if fails, it writes an error which
         the child process failed to be created. Otherwise it will
         process the command and return a flag if the command
         was successful or not. 

Input: this function takes one input and it is a array of pointers
       to chars.

Returns: returns a flag if the command was executed sucessfully (0) 
         or -1 if unsuccesful.

*/
int processCommand(char *arg[]);

/*

Function: flush

Purpose: to clear all elements in an array of pointers to NULL or
         also called to clean the input buffer for next read
        
Details: this function goes through an array and sets each element
         to NULL and resets for the next read to ensure nothing
         "garbage" is read next time a user inputs a command.

Input: array of pointers to chars that is to be cleared or flushed

*/
void flush(char *arg[]);

#endif