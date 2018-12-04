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


////最短路径 迪杰斯特拉 Dijkstra
//typedef int Pathmatirx[MAXSIZE];//存储最短路径下标的数组
//typedef int ShortPathTable[MAXSIZE];//存储到各点最短路径的权值
//
////求有向网G的v0顶点到其余顶点v最短路径P[v]及带权长度D[v]
////P[v]的值为前驱顶点下标，D[v]表示v0到v的最短路径长度
//void ShortestPath_Dijkstra(MGraph G, int v0, Pathmatirx *P, ShortPathTable *D) {
//    int final[MAXSIZE];//求得顶点v0至vw的最短路径
//    for (int v = 0; v < G.numVertexes; v++) {
//        //全部顶点初始化为未知最短路径状态
//        final[v] = 0;
//        //将与v0点有连线的顶点加上权值
//        (*D)[v] = G.arc[v0][v];
//        //初始化路径数组P为0
//        (*P)[v] = 0;
//    }
//    //v0值v0的路径为0
//    (*D)[v0] = 0;
//    //v0至v0不需要求路径
//    final[v0] = 1;
//    int k = 0;
//    int min = 0;
//
//    //开始主循环，每次求得v0到某个v顶点的最短路径
//    for (int v = 1; v < G.numVertexes; v++) {
//        //当前所知离v0顶点的最近距离
//        min = INFINITY;
//        for (int w = 0; w < G.numVertexes; w++) {
//            if (!final[w] && (*D)[w] < min) {
//                k = w;
//                //w顶点离v0顶点更近
//                min = (*D)[w];
//            }
//        }
//    }
//    //将目前找到的最近的顶点位置为1
//    final[k] = 1;
//    //修正当前最短路径及距离
//    for (int w = 0; w < G.numVertexes; w++) {
//        //如果经过v顶点的路径比现在这条路径的长度短的话
//        if (!final[w] && (min + G.arc[k][w] < (*D)[w])) {
//            //说明找到了更短的路径，修改D[w]和P[w]
//            (*D)[w] = min + G.arc[k][w];//修改当前路径长度
//            (*P)[w] = k;
//        }
//    }
//}

//弗洛伊德 Floyd
//最短路径 迪杰斯特拉 Dijkstra
typedef int Pathmatirx[MAXSIZE][MAXSIZE];
typedef int ShortPathTable[MAXSIZE][MAXSIZE];

//求有向网G中各顶点v到其余顶点w最短路径P[v][w]及带权长度D[v][w]
void ShortestPath_Floyd(MGraph G, Pathmatirx *P, ShortPathTable *D) {
    for (int v = 0; v < G.numVertexes; v++) {
        for (int w = 0; w < G.numVertexes; w++) {
            //D[v][w]值即为对应点间的权值
            (*D)[v][w] = G.arc[v][w];
            (*P)[v][w] = w;
        }
    }
    
    for (int k = 0; k < G.numVertexes; k++) {
        for (int v = 0; v < G.numVertexes; v++) {
            for (int w = 0; w < G.numVertexes; w++) {
                if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w]) {
                    //如果经过下标为k顶点路径比原两点间路径更短
                    //将当前两点间权值设置为更小的一个
                    (*D)[v][w] = (*D)[v][k] + (*D)[k][w];
                    //路径设置经过下标为k的顶点
                    (*P)[v][w] = (*P)[v][k];
                }
            }
        }
    }
}

//void printShortestPath_Floyd(MGraph G, Pathmatirx *P, ShortPathTable *D)
//{
//    for (int v = 0; v < G.numVertexes; v++) {
//        for (int w = v + 1; w < G.numVertexes; w++) {
//            printf("v%d-v%d weight: %d",v,w,D[v][w]);
//            int k = P[v][w];
//            printf("path: %d",v);
//            while (k != w) {
//                printf(" -> %d",k);
//                k = P[k][w];
//            }
//            printf(" -> %d\n",w);
//        }
//        printf("\n");
//    }
//}











