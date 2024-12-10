/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 1

File name: pipes.h

Instructor: Marc Schroeder

Purpose: function prototype for command pipelines

*/

#ifndef PIPES_H
#define PIPES_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "const.h"

/*

Function: isPipe

Purpose: check is there is a pipe (|) symbol in the argument
         
Details: check the command line argument that is entered by
         the user and check if it is a pipeline and if it is,
         return a 1 otherwise it returns a 0

Input:  an array of char that checks if it is the pipe symbol

Returns: if a pipe is present in the command line argument 

*/
int isPipe(char symbol[]);

/*

Function: processPipe

Purpose: create a pipeline between two child processes that allow the two
         child processes to communicate
         
Details:  two commands can be run in sequence. It creates a communication pipe 
          between them so that the output of the first command becomes the input 
          for the second. The function takes two sets of command arguments, one 
          for each process. If everything goes smoothly, it returns the exit 
          status of the last command executed. If there are any problems creating
          the child processes, it returns -1 and displays an "error" message. 

Input:  both are a pointer of array to chars which are the left arugment
        and the right arugment of the pipe

Returns: return if the pipeline created was successful (1) or 0 if not

*/
int processPipe(char *arg[], char *arg2[]);

#endif