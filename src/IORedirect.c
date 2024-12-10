/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 1

File name: IORedirect.c

Instructor: Marc Schroeder

Purpose: contains the code to check if it is an IO redirect 
         and if so, process the IO redirect

Each of the function is tested, and is working as intended. 

*/

#include "IORedirect.h"

int isIORedirect(char symbol[]) {

    char in = '<';
    char out = '>';
    int flag = 0;

    if ((symbol[0] == out) || (symbol[0] == in)) {

        flag = 1;

    }

    return flag;

}

int processIORedirect(char *arg[], char *arg2[], char symbol[]) {

    const char *errorMsg = "error\n";
    char *const envp[] = { NULL };
    int fd, pid, childStatus, flag;
    char in = '<';
    char out = '>';

    pid = fork();

    if (pid == -1) {

        write(1, errorMsg, 6);

    } else if (pid == 0) {

        if (symbol[0] == in) {

            fd = open(arg2[0], O_RDONLY, 0);
            dup2(fd, STDIN_FILENO);
            close(fd);

        } else {

            fd = creat(arg2[0], FILE_PERMISSIONS);
            dup2(fd, STDOUT_FILENO);
            close(fd);

        }

        execve(arg[0], arg, envp);

    } else {

        waitpid(pid, 0, 0);

    }

}
