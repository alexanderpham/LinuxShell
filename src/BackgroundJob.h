/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 1

File name: BackgroundJob.h

Instructor: Marc Schroeder

Purpose: contains the function prototypes of background
         job functions

Each of the function is tested, and is working as intended. 

*/

#ifndef BACKGROUNDJOB_H
#define BACKGROUNDJOB_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stringLib.h"
#include "const.h"

/*

Function: isABackgroundJob

Purpose: check if the command arugment has an & at the 
         end of it

Details: This function will check to see if the user 
         entered command has a & on the end. If there is,
         it will only execute by creating a process to run
         in the background. But this function only checks
         to see if & is in the argument.

Input: takes an array of pointer to chars (the arugment) 
       and the number of arugments that is read

Output: returns a flag whether it is a background job or not 

*/
int isABackgroundJob(char *arg[], int numberOfArgs);

/*

Function: doBackgroundJob

Purpose: to process a backgroundjob given the arugment 
         from the user

Details: the function will create a child process of the
         arugment and if failed, will write an error 
         and otherwise, it will create the child and will
         wait until the child process is complated and 
         returns a flag if the job was completed or not.

Input: takes an array of pointers to chars (the argument)
       and the number of arguments that is read

Output: returns a flag if the background job was sucessful
        or not

*/
int doBackgroundJob(char *arg[], int numOfArgs);

#endif