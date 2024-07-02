#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "splitter.h"


/*
    typedef struct {
        char* title;
        char** statements;
    } Section;
*/


Section* getSections(char* code, int* returnSize) {
    int sectionsCount;
    char** sections = strToArray(code, ".", &sectionsCount);
    
    
    freeStrArray(sections, sectionsCount);
    return NULL;
}