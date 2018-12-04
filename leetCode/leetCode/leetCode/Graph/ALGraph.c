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

void al_CreateGraph(GraphAdjList G)
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
    
    printf("%c ", G->adjList[i].data);
    EdgeNode *p = G->adjList[i].firstedge;
    
    while (p) {
        if (!al_visited[p->adjvex]) {
            al_DFS(G, p->adjvex);
        }
        p = p->next;
    }
}

void al_DFSTraverse(GraphAdjList G)
{
    for (int i = 0; i < G->numVertexes; i++) {
        al_visited[i] = FALSE;
    }
    
    for (int i = 0; i < G->numVertexes; i++) {
        if (!al_visited[i]) {
            al_DFS(G, i);
        }
    }
}//O(n+e)


void BFSTraverse(GraphAdjList G)
{
    for (int i = 0; i < G->numVertexes; i++) {
        al_visited[i] = FALSE;
    }
    
    EdgeNode *p;
    
    LinkQueue *Q = lq_InitQueue();
    int i = 0;
    for (i = 0; i < G->numVertexes; i++) {
        if (!al_visited[i]) {
            al_visited[i] = TRUE;
            printf("%c ", G->adjList[i].data);
            
            lq_EnQueue(Q, i);
            while (!lq_QueueIsEmpty(Q)) {
                lq_DeQueue(Q, &i);
                
                p = G->adjList[i].firstedge;
                while (p) {
                    if (!al_visited[p->adjvex]) {
                        al_visited[p->adjvex] = TRUE;
                        printf("%c ", G->adjList[p->adjvex].data);
                        lq_EnQueue(Q, p->adjvex);
                    }
                    p = p->next;
                }
            }
        }
    }
}

////拓扑排序 GL无回路，则输出拓扑排序序列并返回OK，若有回路返回ERROR
//Status TopologicalSort(GraphAdjList GL)
//{
//    int top = 0;//用于栈指针下标
//    int count = 0;//用于统计输出顶点的个数
//    int *stack; //建栈存储入度为0的顶点
//    stack = (int *)malloc(GL->numVertexes * sizeof(int));
//    for (int i = 0; i < GL->numVertexes; i++) {
//        if (GL->adjList[i].in == 0) {
//            //将入度为0的顶点入栈
//            stack[++top] = i;
//        }
//    }
//
//    int gettop;
//    while (top != 0) {
//        gettop = stack[top--];//出栈
//        printf("%d -> ", GL->adjList[gettop].data);
//        count++;
//        for (EdgeNode *e = GL->adjList[gettop].firstedge; e; e = e->next) {
//            //对此顶点弧表遍历
//            int k = e->adjvex;
//            //将k号顶点邻接点的入度减1
//            if (!(--GL->adjList[k].in)) {
//                //若为0则入栈，以便于下次循环输出
//                stack[++top] = k;
//            }
//        }
//    }
//
//    //如果count小于顶点数，说明存在环
//    if (count < GL->numVertexes) {
//        return ERROR;
//    }
//    else {
//        return OK;
//    }
//}

int *etv;//事件最早发生时间和最迟发生时间数组
int *ltv;
int *stack2;//用于存储拓扑排序列的栈
int top2;//用于stack2的指针

//拓扑排序 GL无回路，则输出拓扑排序序列并返回OK，若有回路返回ERROR
Status TopologicalSort(GraphAdjList GL)
{
    int top = 0;//用于栈指针下标
    int count = 0;//用于统计输出顶点的个数
    int *stack; //建栈存储入度为0的顶点
    stack = (int *)malloc(GL->numVertexes * sizeof(int));
    for (int i = 0; i < GL->numVertexes; i++) {
        if (GL->adjList[i].in == 0) {
            //将入度为0的顶点入栈
            stack[++top] = i;
        }
    }
    
    top2 = 0;
    etv = (int *)malloc(GL->numVertexes * sizeof(int));//事件最早发生时间
    for (int i = 0; i < GL->numVertexes; i++) {
        etv[i] = 0;
    }
    stack2 = (int *)malloc(GL->numVertexes * sizeof(int));
    
    int gettop;
    while (top != 0) {
        gettop = stack[top--];//出栈
        count++;
        stack2[++top2] = gettop;//将弹出的顶点序号压入拓扑序列的栈
        
        for (EdgeNode *e = GL->adjList[gettop].firstedge; e; e = e->next) {
            //对此顶点弧表遍历
            int k = e->adjvex;
            //将k号顶点邻接点的入度减1
            if (!(--GL->adjList[k].in)) {
                //若为0则入栈，以便于下次循环输出
                stack[++top] = k;
            }
            
            if ((etv[gettop]+e->weight) > etv[k]) {
                //求各顶点事件最早发生时间值
                etv[k] = etv[gettop] + e->weight;
            }
        }
    }
    
    //如果count小于顶点数，说明存在环
    if (count < GL->numVertexes) {
        return ERROR;
    }
    else {
        return OK;
    }
}


//求关键路径，GL为有向网，输出GL的各项关键活动
void CriticalPath(GraphAdjList GL)
{
    int ete;//最早发生时间
    int lte;//最迟发生时间
    TopologicalSort(GL);
    ltv = (int *)malloc(GL->numVertexes * sizeof(int));
    for (int i = 0; i < GL->numVertexes; i++) {
        ltv[i] = etv[GL->numVertexes - 1];
    }
    
    int gettop;
    while (top2 != 0) {
        gettop = stack2[top2--];//将拓扑序列出栈，后进先出
        for (EdgeNode *e = GL->adjList[gettop].firstedge; e; e = e->next) {
            //求各顶点事件的最迟发生时间ltv值
            int k = e->adjvex;
            //求各顶点事件最晚发生时间
            if (ltv[k] - e->weight < ltv[gettop]) {
                ltv[gettop] = ltv[k] - e->weight;
            }
        }
    }

    for (int j = 0; j < GL->numVertexes; j++) {
        for (EdgeNode *e = GL->adjList[gettop].firstedge; e; e = e->next) {
            int k = e->adjvex;
            ete = etv[j];//活动最早发生时间
            lte = ltv[k] - e->weight;//活动最迟发生时间
            
            if (ete == lte) {
                printf("<v%d,v%d> length: %d", GL->adjList[j].data, GL->adjList[k].data, e->weight);
            }
        }
    }
}





















