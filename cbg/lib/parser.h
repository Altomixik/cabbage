#ifndef _PARSER_H
#define _PARSER_H

struct Section {
    char* title;
    char** statements;
};

typedef struct Section Section;

Section* getSections(char* code, int* returnSize);

#endif