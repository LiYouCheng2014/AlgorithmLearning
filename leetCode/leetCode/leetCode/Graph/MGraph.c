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

void m_CreateGraph(MGraph *G)
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

void m_DFS(MGraph G, int i)
{
    m_visited[i] = TRUE;
    printf("%c ", G.vexs[i]);
    
    for (int j = 0; j < G.numVertexes; j++) {
        if (G.arc[i][j] == 1 && !m_visited[j]) {
            m_DFS(G, j);
        }
    }
}

void m_DFSTraverse(MGraph G)
{
    for (int i = 0; i < G.numVertexes; i++) {
        m_visited[i] = FALSE;
    }
    
    for (int i = 0; i < G.numVertexes; i++) {
        if (!m_visited[i]) {
            m_DFS(G, i);
        }
    }
}//O(n^2)

void m_BFSTraverse(MGraph G)
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

/*
 普利姆Prim算法
 假设 N = (P,{E})是连通网，TE是N上最小生成树中边的集合。算法从U={u0}(u0∈V),TE={}开始。重复执行下述操作：在所有u∈U,v∈V-U的边（u,v)∈E中找一条代价最小的边（u0,v0)并入集合TE，同时v0并入U，直到U=V为止。此时TE中必有n-1条边，则T=（V，{TE})为N的最小生成树
 */
void MiniSpanTree_Prim(MGraph G)
{
    int adjvex[MAXSIZE];//保存相关顶点下标
    int lowcost[MAXSIZE];//保存相关顶点间边的权值
    //lowcost的值为0，在这里就是此下标的顶点已经加入生成树
    lowcost[0] = 0;//初始化第一个权值为0，即v0加入生成树
    adjvex[0] = 0;//初始化第一个顶点下标为0
    
    //循环除下标0外的全部顶点
    for (int i = 1; i < G.numVertexes; i++) {
        lowcost[i] = G.arc[0][i];//将v0顶点与之有边的权值存入数组
        adjvex[i] = 0;//初始化都为v0的下标
    }
    
    //初始化最小权值为无穷， 通常设置为不可能的大数字如32767，65535
    int min = INFINITY;
    int j = 1;
    int k = 0;
    for (int i = 1; i < G.numVertexes; i++) {
        min = INFINITY;
        j = 1;
        k = 0;
        while (j < G.numVertexes) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                //如果权值不为0且权值小于min
                min = lowcost[j];//则让当前权值成为最小值
                k = j;//将当前最小值的下标存入k
            }
            j++;
        }
        
        printf("(%d,%d)",adjvex[k],k);//打印当前顶点边中权值最小边
        lowcost[k] = 0;//将当前顶点的权值设置为0，表示此顶点已经完成任务
        
        for (int j = 1; j < G.numVertexes; j++) {
            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {
                //若下标为k顶点各边权值小于此前这些顶点未被加入生成树权值
                lowcost[j] = G.arc[k][j];//将较小权值存入lowcost
                adjvex[j] = k;//将下标为k的顶点存入adjvex
            }
        }
    }
}//O(n^2)


/*
 Kruskal算法
 假设 N = (V,{E})是连通网，则令最小生成树的初始状态为只有n个顶点而无边的非连通图T={V,{}},图中每个顶点自成一个连通分量。在E中选择代价最小的边，若该边依附的顶点落在T中不同的连通分量上，则将此边加入到T中，否则舍去此边而选择下一条代价最小的边。依次类推，直至T中所有顶点都在同一连通分量上为止。
 */
//查找连线顶点的尾部下标
int Find(int *parent, int f)
{
    while (parent[f] > 0) {
        f = parent[f];
    }
    return f;
}

void MiniSpanTree_Kruskal(MGraph G)
{
    Edge edges[MAXSIZE];//定义边集数组
    int parent[MAXSIZE];//定义一数组用来判断边与边是否形成环路
    //此处省略将邻接矩阵G转化为边集数组edges并按权由小到大排序的代码
    for (int i = 0; i < G.numVertexes; i++) {
        parent[i] = 0;
    }
    
    //循环每一条边
    int n = 0;
    int m = 0;
    for (int i = 0; i < G.numEdges; i++) {
        n = Find(parent, edges[i].begin);
        m = Find(parent, edges[i].end);
        //假如n与m不等，说明此条边没有与现有生成树形成环路
        if (n != m) {
            //将此条边的结尾顶点放入下标为起点的parent中
            //表示此顶点已经在生成树集合中
            parent[n] = m;
            printf("(%d,%d) %d ",edges[i].begin,edges[i].end,edges[i].weight);
        }
    }
}//O(eloge)

//克鲁斯卡尔算法主要针对边来开展，边少时效率非常高
//普利姆算法主要针对稠密图，边多时效率好




















