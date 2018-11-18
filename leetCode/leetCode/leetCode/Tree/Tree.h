//
//  Tree.h
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include "comman.h"

//双亲表示法

typedef char TElemType;
typedef struct PTNode
{
    TElemType data;
    int parent;//双亲位置
}PTNode;

typedef struct
{
    PTNode nodes[MAXSIZE];
    int r;//根位置
    int n;//结点树
}PTree;

//孩子表示法
typedef struct CTNode
{
    int child;
    struct CTNode *next;
}*ChildPtr;

typedef struct
{
    TElemType data;
    ChildPtr firstchild;
}CTBox;

typedef struct
{
    CTBox nodes[MAXSIZE];
    int r;//根位置
    int n;//结点树
}CTree;

//孩子兄弟表示法
typedef struct CSNode
{
    TElemType data;
    struct CSNode *firstchild;
    struct CSNode *rightsib;
}CSNode, *CSTree;


//二叉树
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;


//线索二叉树
typedef enum
{
    Link = 0,//0表示左右孩子，1表示线索
    Thread
}PointerTag;

typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild;
    struct BiThrNode *rchild;
    PointerTag LTag;
    PointerTag Rtag;
}BiThrNode, *BiThrTree;




#endif /* Tree_h */
