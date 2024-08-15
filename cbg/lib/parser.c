#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "parser.h"
#include "split.h"

#define SECTION_DELIMS ":"
#define STATEMENT_DELIMS "\n\t;"

/*
    typedef struct {
        char* title;
        char** statements;
		int statementsLength;
    } Section;
*/

Section* toSection(char** strArray, int strArrayLength) {
	if (!strArray || !strArrayLength) return NULL;
	
	Section* newSection = malloc(sizeof(Section));
	newSection->title = strdup(*strArray);
	newSection->statementsLength = strArrayLength - 1;
	
	if (strArrayLength == 1) {
		newSection->statements = NULL;
		return newSection;
	}
	
	newSection->statements = malloc(sizeof(char*) * newSection->statementsLength);
	for(int i = 1; i < strArrayLength; i++)
		newSection->statements[i - 1] = strdup(strArray[i]);

	return newSection;
}







Section** getSections(char* str, int* returnSize) {
	 
	int sectionCount;
	char** initialArray;
	initialArray = splitStr(str, SECTION_DELIMS, &sectionCount);
	


	int* statementSplitSizes;
	char*** statementArray; // SHUTTER IN FEAR!!! 3D array!

	statementSplitSizes = malloc(sizeof(int) * sectionCount);
	statementArray = malloc(sizeof(char**) * sectionCount);

	for (int i = 0; i < sectionCount; i++)
		statementArray[i] = splitStr(initialArray[i], STATEMENT_DELIMS, statementSplitSizes + i);



	Section** result;
	result = malloc(sizeof(Section*) * sectionCount);
	for (int i = 0; i < sectionCount; i++)
		result[i] = toSection(statementArray[i], statementSplitSizes[i]);



	freeStrArray(initialArray, sectionCount);
	for (int i = 0; i < sectionCount; i++)
		freeStrArray(statementArray[i] , statementSplitSizes[i]);
	free(statementSplitSizes);
	free(statementArray);



	*returnSize = sectionCount;
	return result;
}






void freeSection(Section* ptr) {
	if (!ptr) return;
	free(ptr->title);
	if (ptr->statements) freeStrArray(ptr->statements, ptr->statementsLength);
	free(ptr);
}
