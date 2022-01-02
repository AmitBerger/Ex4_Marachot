#include "GraphAlgo.h"
#ifndef EX4_PRIORITYQUEUE_H
#define EX4_PRIORITYQUEUE_H

typedef struct PQNode {
    pNode data;

    int priority;

    struct PQNode *next;

} pqNode;

pqNode* newNode(pNode d, int p);
pNode peek(pqNode** head);
pqNode* pop(pqNode** head);
void push(pqNode** head, pNode d, int p);
int isEmpty(pqNode** head);

#endif 
