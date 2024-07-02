#include <stdlib.h>
#include <string.h>

#include "splitter.h"





Node* strToNode(char* str, char* delims) {
    char* strCopy = strdup(str);
    char* token = strtok(strCopy, delims);
    Node* head = NULL;
    Node* tail = NULL;

    while (token != NULL) {
        Node* newNode = malloc(sizeof(Node));
        newNode->next = NULL;
        newNode->word = strdup(token);

        if (tail == NULL) {
            tail = newNode;
            head = tail;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

        token = strtok(NULL, delims);
    }

    free(strCopy);
    return head;
}





void freeNode(Node* head) {
    Node* follower;
    while (head) {
        follower = head;
        head = head->next;
        free(follower);
    }
}





char** nodeToArray(Node* head, int* returnSize) {
    Node* n = head;
    int length = 0;

    while (n) {
        n = n->next;
        length++;
    }

    char** result = malloc(sizeof(char*) * length);
    n = head;
    
    for (int i = 0; i < length; i++) {
        result[i] = strdup(n->word);
        n = n->next;
    }

    *returnSize = length;
    return result;
}





char** strToArray(char* str, char* delims,  int* returnSize) {
    Node* n = strToNode(str, delims);
    char** result = nodeToArray(n, returnSize);
    free(n);
    return result;
}

void freeStrArray(char** array, size_t arraySize) {
    for (int i = 0; i < arraySize; i++)
        free(array[i]);
    free(array);
}