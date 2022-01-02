#ifndef EX4_GRAPHALGO_H
#define EX4_GRAPHALGO_H


#ifndef GRAPH
#define GRAPH

typedef struct Node *pNode;

typedef struct edge {
    int weight;
    pNode dest;
    struct edge* next;
} edge, *pEdge;


typedef struct Node {
    int nodeId;
    int weight;
    pEdge edges;
    struct Node* next;
    struct Node* parent;
    int visited;
} node;


#endif

void createNodes(int);
void printGraph_cmd();
pNode GetNode(int data);
void addEdges(pNode node);
void addNode();
void createGraph();
void deleteNode(int num);
void deleteGraph_cmd();
void relax(pNode src, pNode dest, pEdge e);
void dijkstra(int src, int dest);
int contains(int nodeId);
pNode createNode(int id, pNode next, pEdge edge);
pNode getLast();
void freeEdgesOfNode(pNode p);
int shortestPath(int src, int dest);
int TSP(int num);
void swap(int *x, int *y);
void permutation(int a[], int size, int n);

#endif 
