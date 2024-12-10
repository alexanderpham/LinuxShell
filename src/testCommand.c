#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_ARGS 10

/* THIS FILE IS USED TO TEST IF TOKENIZING WORKS */

int processCommand(char *arg[]);
void flush(char *arg[]);

int main() {

    char *command1[] = {"ls", "-l", NULL};
    char *command2[] = {"echo", "Hello, World!", NULL};
    char *command3[] = {"nonexistentcommand", NULL};

    /* Test a valid command (ls -l) */
    printf("Testing a valid command (ls -l):\n");

    int result1 = processCommand(command1);

    if (result1 == 1) {
        printf("Command executed successfully.\n");
    } else {
        printf("Command execution failed.\n");
    }

    /* Test another valid command (echo "Hello, World!") */
    printf("\nTesting another valid command (echo \"Hello, World!\"):\n");

    int result2 = processCommand(command2);

    if (result2 == 1) {
        printf("Command executed successfully.\n");
    } else {
        printf("Command execution failed.\n");
    }

    /* Test an invalid command (nonexistentcommand) */
    printf("\nTesting an invalid command (nonexistentcommand):\n");
    int result3 = processCommand(command3);
    
    if (result3 == -1) {
        printf("Command execution failed as expected.\n");
    } else {
        printf("Unexpected result for an invalid command.\n");
    }

    return 0;
}

int processCommand(char *arg[]) {
    int flag = 1;
    int pid, childStatus;
    char *const envp[] = {NULL};
    const char *errorMsg = "error\n";

    pid = fork();

    if (pid == -1) {
        write(1, errorMsg, 6);
        flag = -1;
    }

    if (pid == 0) {
        flag = execve(arg[0], arg, envp);
        _exit(0);
    }

    waitpid(pid, &childStatus, 0);

    return flag;
}

void flush(char *arg[]) {
    int i;
    for (i = 0; i < MAX_ARGS; i++) {
        arg[i] = NULL;
    }
}
