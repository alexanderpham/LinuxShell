/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 1

File name: IORedirect.h

Instructor: Marc Schroeder

Purpose: contains the function prototypes for IO redirect


*/

#ifndef IOREDIRECT_H
#define IOREDIRECT_H

#include "const.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

/*

Function: ioIORedirect

Purpose: to check if the symbol < or > 
         is present in the argument

Details: this function will check the 
         argument and to see if there is
         < or > and returns a flag if
         the symbol is present or not

Input: takes in an array of chars to check
       if symbol is there

Output: output wether a symbol is there (1)
        or 0 if not there

*/
int isIORedirect(char symbol[]);

/*

Function: processIORedirect

Purpose: process the IO redirect to input
         or output based on the the symbol

Details: forking a child process to run the specified command. 
         If the fork operation fails, it outputs an error message. 
         In the child process, the function checks the symbol argument, which 
         represents whether the redirection should be for input or output.
         If it is output redirection, the function creates a new file with the 
         specified name, redirects the standard output to that file, and then 
         executes the command. If it's an input redirection, the function opens 
         the specified file for reading and redirects the standard input to it 
         before executing the command then the function waits for the child 
         process to finish. 

Input: takes two arguments that are both an array of pointers to chars which one
       is the argument before the < or > and the second argument is the one
       after the symbol. As well it takes in the symbol to know wether it is
       for input or output redirection

Output: returns a flag to see if the IO redirection was done or not.

*/

int processIORedirect(char *arg[], char *arg2[], char symbol[]);

#endif