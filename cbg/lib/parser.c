#include <stdlib.h>
#include <string.h>

#include "parser.h"

Node* strToNode(char* str, char* delims) {
    char* token = strtok(str, delims);
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