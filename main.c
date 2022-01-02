#include <stdio.h>
#include <string.h>
#include "GraphAlgo.h"
#include "graph.h"

int main(){

    char givenChar;
    int givenNum;
    int givenNum2;
    int ans = 0;
    while (1){

        scanf("%c", &givenChar);
        if (givenChar == 'A') {
            scanf("%d", &givenNum);
            createNodes(givenNum);
        }
        if(givenChar == 'n') {
            createGraph();
        }
        if(givenChar == 'B') {
            addNode();
        }
        if(givenChar == 'D') {
            scanf("%d", &givenNum);
            deleteNode(givenNum);
        }
        if(givenChar == 'S') {
            scanf("%d", &givenNum);
            scanf("%d", &givenNum2);
            ans = shortestPath(givenNum, givenNum2);
            printf("Dijsktra shortest path: %d \n", ans);
        }
        if(givenChar == 'T') {
            scanf("%d", &givenNum);
           int ansT = TSP(givenNum);
           printf("TSP shortest path: %d \n", ansT);
        }
        if(givenChar == '\n') {
            deleteGraph_cmd();
            break;
        }

    }

    return 0;
}
