//
//  MGraph.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "MGraph.h"

#include <stdlib.h>
#include <stdbool.h>

#include "Graph.h"

#include "LinkQueue.h"

//邻接矩阵
Boolean m_visited[MAXSIZE];

void CreateMGraph(MGraph *G)
{
    printf("输入顶点数和边数:\n");
    scanf("%d,%d",&G->numVertexes,&G->numEdges);
    for (int i = 0; i < G->numVertexes; i++) {
        scanf("%c",&G->vexs[i]);
    }
    
    for (int i = 0; i < G->numVertexes; i++) {
        for (int j = 0; j < G->numVertexes; j++) {
            G->arc[i][j] = INFINITY;
        }
    }
    
    int i,j,w;
    for (int k = 0; k < G->numEdges; k++) {
        printf("输入边(vi,vj)上的下标i,下标jd和权w:\n");
        scanf("%d,%d,%d",&i,&j,&w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}//O(n+n^2+e)

//DFS

void M_DFS(MGraph G, int i)
{
    m_visited[i] = TRUE;
    printf("%c ", G.vexs[i]);
    
    for (int j = 0; j < G.numVertexes; j++) {
        if (G.arc[i][j] == 1 && !m_visited[j]) {
            M_DFS(G, j);
        }
    }
}

void M_DFSTraverse(MGraph G)
{
    for (int i = 0; i < G.numVertexes; i++) {
        m_visited[i] = FALSE;
    }
    
    for (int i = 0; i < G.numVertexes; i++) {
        if (!m_visited[i]) {
            M_DFS(G, i);
        }
    }
}//O(n^2)

void BFSTraverse(MGraph G)
{
    for (int i = 0; i < G.numVertexes; i++) {
        m_visited[i] = FALSE;
    }
    
    LinkQueue *Q = lq_InitQueue();
    int i = 0;
    for (i = 0; i < G.numVertexes; i++) {
        if (!m_visited[i]) {
            m_visited[i] = TRUE;
            printf("%c ", G.vexs[i]);
            
            lq_EnQueue(Q, i);
            while (!lq_QueueIsEmpty(Q)) {
                lq_DeQueue(Q, &i);
                
                for (int j = 0; j < G.numVertexes; j++) {
                    if (G.arc[i][j] == 1 && !m_visited[j]) {
                        m_visited[j] = TRUE;
                        printf("%c ",G.vexs[j]);
                        lq_EnQueue(Q, j);
                    }
                }
                
            }
        }
    }
}
