#include "const.h"
#include "stringLib.h"
#include <unistd.h>

typedef struct History {
    int currLine;
    char historyArr[MAX_HISTORY][MAX_LINE];
} History;

void initializeHistory(History *history);
void pushInputHistory(History *history, char const *input);
void printInputHistory(History *history, int position);
int isUpArrow(char* const input);