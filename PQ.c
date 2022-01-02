#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"

pqNode *newNode(pNode d, int p){
    pqNode *temp = (pqNode *)malloc(sizeof(pqNode));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

pNode peek(pqNode **head){
    return (*head)->data;
}

pqNode *pop(pqNode **head){
    pqNode *temp = *head;
    *head = (*head)->next;
    return temp;
    free(temp);
}

void push(pqNode **head, pNode d, int p){
    pqNode *start = (*head);

    pqNode *temp = newNode(d, p);

    if ((*head)->priority > p){
        temp->next = *head;
        (*head) = temp;
    }
    else {

        while (start->next != NULL && start->next->priority < p){
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

int isEmpty(pqNode **head){
    return (*head) == NULL;
}
