#include "commandHistory.h"
#include <stdio.h>

void initializeHistory(History *history) {
    history->currLine = -1;
    for (int i = 0; i < MAX_HISTORY; i++) {
        history->historyArr[i][0] = '\0';
    }
}

void pushInputHistory(History *history, char const *input) {

    int currChar = 0;

    if(history->currLine < MAX_HISTORY - 1) {
        history->currLine++;
    } else {
        history->currLine = 0;
    }

    while(input[currChar] != '\0' && currChar < MAX_LINE) {
        history->historyArr[history->currLine][currChar] = input[currChar];
        currChar++;
    }
    history->historyArr[history->currLine][currChar] = '\0';

    return;
}

void printInputHistory(History *history, int position) {

    char inputHistory[MAX_LINE];
    if (history->currLine == -1 || position > MAX_HISTORY - 1) {
        inputHistory[0] = '\0';
    } else {

        int positionIndex = (history->currLine - position);
        if (positionIndex < 0) {
            positionIndex += MAX_HISTORY;
        }

        int i = 0;
        while(i < MAX_LINE && history->historyArr[positionIndex][i] != '\0') {
            inputHistory[i] = history->historyArr[positionIndex][i];
            i++;
        }
        inputHistory[i] = '\0';
        write(1, &inputHistory, i);
        write(1, "\n", 1);
    }
    return;
}

int isUpArrow(char* const input) {
    int inputIndex = 0;
    int sequenceIndex = 0;
    int numArrows = -1;
    char sequence[4];
    sequence[3] = '\0';
    
    while (input[inputIndex] != '\0') {
        
        if (sequenceIndex > 2) {

            if(sequence[0] == ESCAPE && stringCompare(&sequence[1], UP_ARROW) == 0) {
                numArrows++;
            } else {
                break;
            }
            sequenceIndex = 0;
        }

        sequence[sequenceIndex] = input[inputIndex];
        sequenceIndex++;
        inputIndex++;
    }

    return numArrows;
}