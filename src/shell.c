/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 1

File name: shell.c

Instructor: Marc Schroeder

Purpose: main function of the shell along with the basic shell
         functionailty

Each of the function is tested, and is working as intended.

*/

#include "shell.h"

int main()
{

  Command command;
  History history;
  char symbol[1];
  symbol[0] = '\0';
  char tempArr[MAX_LINE][MAX_LINE];
  int running = 1;
  char shellMsg[] = "myShell$ ";
  char exitMsg[] = "exit";
  int loginSuccessful = 0;

  while (!loginSuccessful)
  {

    loginSuccessful = login();
  }

  initializeHistory(&history);

  while (running)
  {
    write(1, shellMsg, 10);
    int numOfArgs = readCommand(&command, symbol, tempArr, &history);

    if (numOfArgs != -2)
    {
      if (stringCompare(*command.arg1, exitMsg) == 0)
      {

        running = 0;
      }
      else if (isIORedirect(symbol))
      {

        processIORedirect(command.arg1, command.arg2, symbol);
      }
      else if (isABackgroundJob(command.arg1, numOfArgs))
      {

        doBackgroundJob(command.arg1, numOfArgs);
      }
      else if (isPipe(symbol))
      {

        processPipe(command.arg1, command.arg2);
      }
      else
      {
        processCommand(command.arg1);
      }
    }

    flush(command.arg1);
    flush(command.arg2);
    symbol[0] = '\0';
  }

  return 0;
}

int login()
{

  char usernameBuffer[MAX_LINE];
  char passwordBuffer[MAX_LINE];
  char username[] = "testuser\n";
  char password[] = "password\n";

  int temp, bytesRead;
  int error = 0;
  int readSucess;

  const char *usernameMsg = "Enter username: \n";
  const char *userPasswordMsg = "Enter password: \n";

  error = write(1, usernameMsg, 17);

  if (error == -1)
  {

    readSucess = -1;
  }

  bytesRead = read(0, usernameBuffer, MAX_LINE);

  if (bytesRead > 1)
  {

    temp = stringCompare(usernameBuffer, username);

    if (temp == 0)
    {
      /* if user name is right */
      write(1, userPasswordMsg, 17);
      bytesRead = read(0, passwordBuffer, MAX_LINE);

      if (bytesRead > 1)
      {
        /* if password is correct too */
        temp = stringCompare(passwordBuffer, password);

        if (temp == 0)
        {

          readSucess = 1;
        }
      }
    }
  }

  return readSucess;
}

int readCommand(Command *command, char symbol[], char tempArr[][MAX_LINE], History *history)
{

  char buffer[MAX_LINE]; /* the buffer of user input */
  char tempChar;         /* holds the character that is to be read */
  char in = '<';
  char out = '>';
  char pipe = '|';
  int flag = 0;
  int counter = 0;
  int charCounter;
  int tokenCounter = 0;
  int arg2Counter = 0;

  int bytesRead = read(0, buffer, MAX_LINE);

  const char *enterMsg = "myShell$ \n";
  const char *errorMsg = "error\n";

  if (bytesRead == 1)
  {
    /* readCommand will be called again if it is -2*/
    tokenCounter = -2;
  }
  else if (bytesRead == -1)
  {

    write(1, errorMsg, 6);
    tokenCounter = -1; /* terminate the shell*/
  }
  else
  {
    buffer[bytesRead] = '\0'; // overwrites the /n with /0

    if (isUpArrow(buffer) >= 0)
    {
      tokenCounter = -2;
      printInputHistory(history, isUpArrow(buffer));
    }
    else
    {
      pushInputHistory(history, buffer);

      /* returns constructed array from arguments*/
      while (counter < bytesRead)
      {

        tempChar = buffer[counter];

        if (tempChar == pipe || tempChar == in || tempChar == out)
        {

          symbol[0] = tempChar;
          flag = 1;
          counter++;
          tempChar = buffer[counter];

          if (tempChar == ' ')
          {

            counter++;
            tempChar = buffer[counter];
          }
        }

        charCounter = 0;

        /* only takes the valid characters and ignores white space*/
        while (tempChar != ' ' && tempChar != '\n')
        {

          tempArr[tokenCounter][charCounter] = tempChar;
          charCounter++;
          counter++;
          tempChar = buffer[counter];
        }

        if (flag == 0)
        {

          tempArr[tokenCounter][charCounter] = '\0';
          command->arg1[tokenCounter] = &tempArr[tokenCounter][0];
        }
        else
        {

          tempArr[tokenCounter][charCounter] = '\0';
          command->arg2[arg2Counter] = &tempArr[tokenCounter][0];
          arg2Counter++;
        }

        tokenCounter++;
        counter++;
      }
    }
    command->arg1[tokenCounter + 1] = '\0';
    command->arg2[arg2Counter + 1] = '\0';
  }
  return tokenCounter;
}

int processCommand(char *arg[])
{
  int flag = 1;
  int pid, childStatus;
  char *const envp[] = {NULL};
  const char *errorMsg = "error\n";

  pid = fork();

  if (pid == -1)
  {

    write(1, errorMsg, 6);
    flag = -1;
  }

  if (pid == 0)
  {

    flag = execve(arg[0], arg, envp);
    _exit(0);
  }

  waitpid(pid, &childStatus, 0);

  return flag;
}

void flush(char *arg[])
{

  int i;

  for (i = 0; i < MAX_ARGS; i++)
  {

    arg[i] = NULL;
  }
}