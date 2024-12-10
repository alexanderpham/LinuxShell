/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 1

File name: testStringLib.c

Instructor: Marc Schroeder

Purpose: test stringCompare and stringLength functions 

Each of the function is tested, and is working as intended. 

*/

#include <stdio.h>
#include "stringLib.h"
#include <assert.h>

/* FOR TESTING STRING LIB */

void testStringCompare() {

    /* Test case 1: Equal strings */
    assert(stringCompare("hello", "hello") == 0);

    /* Test case 2: Different strings */
    assert(stringCompare("hello", "world") == 1);

    /* Test case 3: Strings with different lengths */
    assert(stringCompare("short string", "this is a longer string, testing") == 1);

    /* Test case 4: Empty strings */
    assert(stringCompare(" ", " ") == 0);

    /* Test case 5: Strings with a common prefix */
    assert(stringCompare("apple", "appetizer") == 1);

    /* Test case 5: Strings with special chars */
    assert(stringCompare("!@#$%^&*()", "!@#$%^&*()") == 0);

}

void testStringLength() {

    /* short string */
    const char *testString1 = "Hello, World!";
    /* longer string */
    const char *testString2 = "this is a longer a string, testing with a longer string";
    /* empty string */
    const char *testString3 = "";

    assert(stringLength(testString1) == 13);
    assert(stringLength(testString2) == 55);
    assert(stringLength(testString3) == 0);

}

int main() {

    testStringCompare();
    testStringLength();
    /* 
    WILL ONLY PRINT THIS OUT IF ALL TESTS PASS OTHERWISE, 
    IT WILL SAY AN ERROR IF ANY TESTS DO NOT PASS
    */
    printf("All tests passed!\n");

    return 0;

}
