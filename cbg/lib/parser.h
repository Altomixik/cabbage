#ifndef PARSER_H
#define PARSER_H


struct Node {
    char* word;
    struct Node* next;
};

typedef struct Node Node;

Node* strToNode(char* str, char* delims);
void freeNode(Node* head);


#endif