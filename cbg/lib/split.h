#ifndef _SPLITTER_H
#define _SPLITTER_H


struct Node {
    char* word;
    struct Node* next;
};

typedef struct Node Node;

char** splitStr(char* str, char* delims, int* returnSize);
void freeNode(Node* head);
void freeStrArray(char** array, size_t arraySize);
#endif