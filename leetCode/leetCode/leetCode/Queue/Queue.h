//
//  Queue.h
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include "comman.h"

typedef int QElemType;

//顺序存储
typedef struct
{
    QElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

//链式存储
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
    
    int count;
}LinkQueue;

#endif /* Queue_h */
