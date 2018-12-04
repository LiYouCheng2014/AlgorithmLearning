//
//  Graph.h
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include "comman.h"

//深度优先更适合目标比较明确以找到目标为主要目的的情况
//广度优先更适合在不断扩大遍历时找到相对最优解的情况

typedef struct
{
    VertexType vexs[MAXSIZE];
    EdgeType arc[MAXSIZE][MAXSIZE];
    int numVertexes;
    int numEdges;
}MGraph;

//边表结点
typedef struct EdgeNode
{
    int adjvex;//邻接点域，存储该顶点对应的下标
    EdgeType weight;//用于存储权值，对于非网图可以不需要
    struct EdgeNode *next;//指向下一个邻接点
}EdgeNode;


//顶点表结点
typedef struct VertexNode
{
    VertexType in;//顶点入度
    VertexType data;//顶点域，存储顶点信息
    EdgeNode *firstedge;//边表头指针
}VertexNode, AdjList[MAXSIZE];

typedef struct
{
    AdjList adjList;
    int numVertexes;//当前顶点数和边树
    int numEdges;
}graphAdjList, *GraphAdjList;

//对边集数组Edge结构的定义
typedef struct
{
    int begin;
    int end;
    int weight;
}Edge;


#endif /* Graph_h */
