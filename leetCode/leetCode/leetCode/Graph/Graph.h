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
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next;
}EdgeNode;


//顶点表结点
typedef struct VertexNode
{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode, AdjList[MAXSIZE];

typedef struct
{
    AdjList adjList;
    int numVertexes;
    int numEdges;
}GraphAdjList;

#endif /* Graph_h */
