//
//  ALGraph.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "ALGraph.h"

#include <stdlib.h>
#include <stdbool.h>

#include "Graph.h"

#include "LinkQueue.h"

//邻接表
Boolean al_visited[MAXSIZE];

void al_CreateGraph(GraphAdjList *G)
{
    printf("输入顶点数和边数:\n");
    scanf("%d,%d",&G->numVertexes,&G->numEdges);
    for (int i = 0; i < G->numVertexes; i++) {
        scanf("%c",&G->adjList[i].data);
        G->adjList[i].firstedge = NULL;
    }
    
    int i,j;
    for (int k = 0; k < G->numEdges; k++) {
        printf("输入边(vi,vj)上的下标i,下标j:\n");
        scanf("%d,%d",&i,&j);
        
        EdgeNode *e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;
        
        EdgeNode *e1 = (EdgeNode *)malloc(sizeof(EdgeNode));
        e1->adjvex = j;
        e1->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}//O(n+e)


//DFS

void al_DFS(GraphAdjList G, int i)
{
    al_visited[i] = TRUE;
    
    printf("%c ", G.adjList[i].data);
    EdgeNode *p = G.adjList[i].firstedge;
    
    while (p) {
        if (!al_visited[p->adjvex]) {
            al_DFS(G, p->adjvex);
        }
        p = p->next;
    }
}

void al_DFSTraverse(GraphAdjList G)
{
    for (int i = 0; i < G.numVertexes; i++) {
        al_visited[i] = FALSE;
    }
    
    for (int i = 0; i < G.numVertexes; i++) {
        if (!al_visited[i]) {
            al_DFS(G, i);
        }
    }
}//O(n+e)


void BFSTraverse(GraphAdjList G)
{
    for (int i = 0; i < G.numVertexes; i++) {
        al_visited[i] = FALSE;
    }
    
    EdgeNode *p;
    
    LinkQueue *Q = lq_InitQueue();
    int i = 0;
    for (i = 0; i < G.numVertexes; i++) {
        if (!al_visited[i]) {
            al_visited[i] = TRUE;
            printf("%c ", G.adjList[i].data);
            
            lq_EnQueue(Q, i);
            while (!lq_QueueIsEmpty(Q)) {
                lq_DeQueue(Q, &i);
                
                p = G.adjList[i].firstedge;
                while (p) {
                    if (!al_visited[p->adjvex]) {
                        al_visited[p->adjvex] = TRUE;
                        printf("%c ", G.adjList[p->adjvex].data);
                        lq_EnQueue(Q, p->adjvex);
                    }
                    p = p->next;
                }
            }
        }
    }
}

