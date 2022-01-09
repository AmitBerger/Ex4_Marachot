#include <stdio.h>
#include <stdlib.h>
#include "GraphAlgo.h"
#include "PQ.h"
#define INF 21474836


static pNode graphNodes;
static int minPath = INF;
pNode GetNode(int data);
void deleteGraph_cmd();


pNode createNode(int id, pNode next, pEdge edge){
    pNode tmp = (pNode)malloc(sizeof(node));
    tmp->nodeId = id;
    tmp->next = next;
    tmp->edges = edge;
    tmp->weight = INF;
    tmp->parent = NULL;
    return tmp;
}

void createNodes(int size){

    if(graphNodes != NULL){
        deleteGraph_cmd();
    }
    pNode tmp = createNode(size - 1, NULL, NULL);
    for (int i = size - 2; i >= 0; i--)
    {
        pNode newNode = createNode(i, tmp, NULL);
        tmp = newNode;
    }
    graphNodes = tmp;
}


void addEdges(pNode node){

    int givenNum;
    int givenNum2;
    char ch;
    scanf("%c", &ch);
    if(ch == '\n'){
        return;
    }
    pEdge e = (pEdge)malloc(sizeof(edge));
    if (scanf("%d", &givenNum) == 1){

        if (scanf("%d", &givenNum2) == 1){
            e->weight = givenNum2;
            node->edges = e;
            e->dest = GetNode(givenNum);
            e->next = NULL;
        }
    }else{
        return;
    }

    scanf("%c", &ch);
    if(ch == '\n'){
        return;
    }
    while (scanf("%d", &givenNum) == 1){

        if (scanf("%d", &givenNum2) == 1){
            pEdge tmp = (pEdge)malloc(sizeof(edge));
            tmp->next = NULL;
            e->next = tmp;
            tmp->weight = givenNum2;
            tmp->dest = GetNode(givenNum);
            e = tmp;
        }
        scanf("%c", &ch);
        if(ch == '\n'){
            return;
        }
    }

}

void createGraph(){
    int srcId;
    scanf("%d", &srcId);
    pNode node = GetNode(srcId);
    addEdges(node);
}


int contains(int nodeId){
    pNode tmp = graphNodes;
    while (tmp){
        if (tmp->nodeId == nodeId){
            return 1; 
        }
        tmp = tmp->next;
    }
    return 0;
}

pNode getLast(){
    pNode tmp = graphNodes;
    while (tmp->next){
        tmp = tmp->next;
    }
    return tmp;
}

void freeEdgesOfNode(pNode p) {
    pEdge del_e = p->edges;
    if (del_e != NULL) {
        pEdge tmp = del_e->next;
        if (tmp == NULL) {
            free(del_e);
        } else {
            while (del_e->next != NULL) {
                pEdge ptmp = tmp;
                del_e->next = tmp->next;
                free(ptmp);
            }
            free(del_e);
        }
    }
}

void addNode()
{
    int srcId;
    scanf("%d", &srcId);
    if (contains(srcId) == 0) {

        pNode last = getLast();
        pNode tmp = createNode(srcId, NULL, NULL);
        last->next = tmp;
        addEdges(tmp);
    } else{
        pNode curr = GetNode(srcId);
        freeEdgesOfNode(curr);
        curr->edges = NULL;
        addEdges(curr);
    
    }
    
}

pNode GetNode(int data){
    pNode p = graphNodes;
    while (p->nodeId != data){
        p = p->next;
    }
    return p;
}



void deleteNode(int num) {
    pNode nodeToDel = GetNode(num);
    pNode p = graphNodes;
    while (p) {
        pEdge e = p->edges;
        while (e) {

            if (e->dest == nodeToDel) {
                p->edges = e->next;
                pEdge pe = e;
                free(pe);
                e = NULL;
            } else {
                pEdge tmp = e->next;
                if (tmp != NULL && tmp->dest == nodeToDel) {
                    e->next = tmp->next;
                    free(tmp);
                } else {
                    e = tmp;
                }
            }
        }
        p = p->next;
    }
    pNode h = graphNodes;
    if (h != nodeToDel) {
        while (h->next != nodeToDel) {
            h = h->next;
        }
        h->next = nodeToDel->next;
    }
    freeEdgesOfNode(nodeToDel);
    free(nodeToDel);

}

void deleteGraph_cmd(){
    pNode tmp = graphNodes;
    int nodeId;
    while (tmp){
        nodeId = tmp->nodeId;
        deleteNode(nodeId);
        tmp = tmp->next;
    }
    graphNodes = NULL;
    free(graphNodes);
}

void setGraph(){
    pNode tmp = graphNodes;
    while (tmp){
        tmp->weight = INF;
        tmp->parent = NULL;
        tmp->visited = 0;
        tmp = tmp->next;
    }
}
void relax(pNode src, pNode dest, pEdge e){
    int wEdge = e->weight;
    int wSrc = src->weight;
    int wDest = dest->weight;
    if (wDest > wSrc + wEdge){
        dest->weight = wSrc + wEdge;
        dest->parent = src;
    }
}

void dijkstra(int src, int dest){
    setGraph();
    pNode srcNode = GetNode(src);
    srcNode->weight = 0;
    pqNode* pq = newNode(srcNode, srcNode->weight);
    pqNode** head = &pq;
    while (isEmpty(head) == 0){
        pqNode* curr = pop(head);
        if(curr->data->visited == 0){
            if(curr->data->nodeId == dest){
                return;
            }
            curr->data->visited = 1;
            pEdge e = curr->data->edges;
            while (e){
                relax(curr->data, e->dest, e);
                if(pq == NULL){
                    pq = newNode(e->dest, e->dest->weight);
                } else{
                    push(head, e->dest, e->dest->weight);
                }
                e = e->next;
            }
        }

    }
    free(head);
}

int shortestPath(int src, int dest){
    dijkstra(src,dest);
    pNode d =GetNode(dest);
    return d->weight;
}
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


void permutation(int a[], int size, int n) {
    if (size == 1) {
        int sum = 0;
        for (int j = 0; j < n-1; ++j) {
            sum += shortestPath(a[j], a[j + 1]);
        }
        if (sum < minPath) {
            minPath = sum;
            return;
        }
    }

    for (int i = 0; i < size; i++) {
        permutation(a, size - 1, n);
        if (size % 2 == 1)
            swap(&a[0], &a[size - 1]);

        else
            swap(&a[i], &a[size - 1]);
    }

}

int TSP(int num) {
    minPath = INF;
    int cities[num];
    int n;
    for (int i = 0; i < num; i++) {
        scanf("%d", &n);
        cities[i] = n;
    }
    permutation(cities, num, num);
    if(minPath == INF){
        minPath = -1;
    }
    return minPath;
}
