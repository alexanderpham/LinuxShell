/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 1

File name: testPipes.c

Instructor: Marc Schroeder

Purpose: test isPipe and processPipe functions 

Each of the function is tested, and is working as intended. 

*/

#include "pipes.h" 
#include <stdio.h>
#include <string.h>

int main() {
    // Test cases for the isPipe function
    printf("Testing isPipe function:\n");
    
    char pipeSymbol1[] = "|";
    char pipeSymbol2[] = "a";
    
    printf("isPipe(\"|\") = %d (Expected: 1)\n", isPipe(pipeSymbol1));
    printf("isPipe(\"a\") = %d (Expected: 0)\n", isPipe(pipeSymbol2));
    
    // Test cases for the processPipe function
    printf("\nTesting processPipe function:\n");
    
    // You need to define valid arguments and environment variables
    char* arg1[] = {"/bin/echo", "Hello", "World", NULL};
    char* arg2[] = {"/bin/grep", "World", NULL};
    
    // Define invalid arguments to simulate an error
    char* invalidArg1[] = {"/invalid/path/to/executable", "Hello", "World", NULL};
    char* invalidArg2[] = {"/bin/echo", "Hello", "World", "InvalidArgument", NULL};
    
    // Test a valid execution
    printf("Valid execution (expecting 'Hello World'):\n");
    processPipe(arg1, arg2);
    
    // Test an invalid execution with invalid arguments
    printf("\nInvalid execution with invalid arguments (expecting 'error'):\n");
    processPipe(invalidArg1, arg2);
    
    // Test an invalid execution with invalid arguments in the second process
    printf("\nInvalid execution with invalid arguments in the second process (expecting 'error'):\n");
    processPipe(arg1, invalidArg2);
    
    return 0;
}
