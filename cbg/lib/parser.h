#ifndef _PARSER_H
#define _PARSER_H

struct Section {
    char* title;
    char** statements;
	int statementsLength;
};

typedef struct Section Section;

Section* toSection(char** strArray, int strArrayLength);
Section** getSections(char* str, int* returnSize);
void freeSection(Section* ptr);

#endif	