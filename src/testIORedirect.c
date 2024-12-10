/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 1

File name: testIORedirect.c

Instructor: Marc Schroeder

Purpose: test isIORedirect and processIORedirect functions 

Each of the function is tested, and is working as intended. 

*/

#include <stdio.h>
#include <assert.h>
#include "IORedirect.h"

int main() {
    char *validCommand[] = {"ls", "-l", NULL};
    char *validCommand2[] = {"echo", "Hello, World!", NULL};
    char *invalidCommand[] = {"nonexistentcommand", NULL};

    printf("Testing isIORedirect function:\n");

    // Test case 1: Check if '>' returns 1
    char symbol1[] = ">";
    int result1 = isIORedirect(symbol1);
    assert(result1 == 1);

    // Test case 2: Check if '<' returns 1
    char symbol2[] = "<";
    int result2 = isIORedirect(symbol2);
    assert(result2 == 1);

    // Test case 3: Check if 'x' returns 0
    char symbol3[] = "x";
    int result3 = isIORedirect(symbol3);
    assert(result3 == 0);

    printf("\nTesting processIORedirect function:\n");

    // Test case 4: Test processIORedirect with '>' and valid file paths
    char arg4[] = "echo";
    char arg2_4[] = "output.txt";
    char symbol4[] = ">";
    int result4 = processIORedirect(arg4, arg2_4, symbol4);
    assert(result4 == 1);

    // Test case 5: Test processIORedirect with '<' and valid file paths
    char arg5[] = "cat";
    char arg2_5[] = "input.txt";
    char symbol5[] = "<";
    int result5 = processIORedirect(arg5, arg2_5, symbol5);
    assert(result5 == 1);

    // Test case 6: Test processIORedirect with an invalid command
    char arg6[] = "nonexistentcommand";
    char arg2_6[] = "output.txt";
    char symbol6[] = ">";
    int result6 = processIORedirect(arg6, arg2_6, symbol6);
    assert(result6 == -1);

    // Add more test cases as needed

    printf("All test cases passed!\n");
    return 0;
}
