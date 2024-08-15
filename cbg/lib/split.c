#include <stdlib.h>
#include <string.h>

#include "split.h"




void freeNode(Node* head) {
    Node* follower;
    while (head) {
        follower = head;
        head = head->next;
		if (follower->word) free(follower->word);
        free(follower);
    }
}



void freeStrArray(char** array, size_t arraySize) {
	if (!array) return;
	for (int i = 0; i < arraySize; i++)
        free(array[i]);
    free(array);
}



char** splitStr(char* str, char* delims, int* returnSize) {

	if (!str || !delims) return NULL;
	else if (!strlen(str) || !strlen(delims)) return NULL;


	// convert to sLL
	char* strCopy = strdup(str);
    char* token = strtok(strCopy, delims);
    Node* head = NULL, *tail = NULL;

    while (token) {
        Node* newNode = malloc(sizeof(Node));
        newNode->next = NULL;
        newNode->word = strdup(token);

        if (tail) {
            tail->next = newNode;
            tail = newNode;
        }
        else {
            tail = newNode;
            head = tail;
        }

        token = strtok(NULL, delims);
    }


	// convert to array of strings
	int length = 0;
	Node* iterator = head;

    while (iterator) {
        iterator = iterator->next;
        length++;
    }

    char** result = malloc(sizeof(char*) * length);
    iterator = head;
    for (int i = 0; i < length; i++) {
        result[i] = strdup(iterator->word);
        iterator = iterator->next;
    }
    *returnSize = length;

	free(strCopy);
	freeNode(head);

    return result;
}
