/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 1

File name: pipes.c

Instructor: Marc Schroeder

Purpose: contains the code to check if it is an pipeline 
         and if so, process the command pipeline

Each of the function is tested, and is working as intended. 

*/

#include "pipes.h"

int isPipe(char symbol[]) {
    
    char pipe = '|';

    if(symbol[0] == pipe) {

      return 1;

    } else{

      return 0;

    }


}

int processPipe(char *arg[], char *arg2[]) {

  char * const envp[] = { NULL };
  const char *errorMssg = "error\n";

  int childStatus, pid1, pid2;
  int flag = 1;
  int pipefd[2];

  pipe(pipefd);

  pid1 = fork();
    
  if(pid1 == -1) {

      write(1, errorMssg,6);

      return -1;

    }

  else if (pid1 == 0) {

      close(pipefd[FD_READ]);
      dup2(pipefd[FD_WRITE], 1);
      flag = execve(arg[0], arg, envp);

      if(flag = -1) {

          write(1, errorMssg,6);
          return flag;

        }

    }

  close(pipefd[FD_WRITE]);

  pid2 = fork();

    if(pid2 == -1) {

      write(1, errorMssg,6);
      return -1;

    } else if (pid2 == 0) {

      dup2(pipefd[FD_READ], 0);
      flag = execve(arg2[0], arg2, envp);
      
      if(flag = -1) {

          write(1, errorMssg,6);
          return flag;

        }

    }

  close(pipefd[FD_READ]);

  waitpid(pid1, &childStatus, 0);
  waitpid(pid2, &childStatus, 0);

}