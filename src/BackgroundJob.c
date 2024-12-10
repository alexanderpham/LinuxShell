/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 1

File name: BackgroundJob.c

Instructor: Marc Schroeder

Purpose: the functions to check if a background job and
         processing a background job

Each of the function is tested, and is working as intended. 

*/

#include "BackgroundJob.h"

/*

Purpose: The purpose of this function is to check the command is a background job


*/

int isABackgroundJob(char *arg[], int numberOfArgs)
{
    int isBackgroundJob = 0;
    char ampersand[] = "&";
    int iterator = 0;

    while(arg[iterator] != NULL && isBackgroundJob == 0 && iterator < numberOfArgs)
    {
        if(stringCompare(arg[iterator],ampersand) == 0)
        {
            isBackgroundJob = 1;
            break;
        }
        iterator++;

    }

    return isBackgroundJob;

}

int doBackgroundJob(char *arg[], int numOfArgs)
{
    char * const envp [] = {NULL};
    const char *errorMessageFork = "Fork Failed!\n";
    const char *errorMessageExecve = "Execve Failed!\n";
    int statusOfChild = 0;
    int pid = 0;
    int contentChanged = 1; /* checks if the child process's content has been changed*/

    pid = fork();

    arg[numOfArgs - 1] = NULL;

    if(pid == -1) /* Fork failed*/
    {

        write(FD_WRITE, errorMessageFork, stringLength(errorMessageFork));
        return pid; 

    } else if( pid == 0)
    {

        setpgid(0,0);
        contentChanged = execve(arg[0],arg,envp);

        if(contentChanged ==-1) /* Content was not changed in the child process*/
        {

            write(FD_WRITE, errorMessageExecve, stringLength(errorMessageExecve));
            return contentChanged;

        }
    }

    waitpid(pid, &statusOfChild, WNOHANG);

    return contentChanged;

}