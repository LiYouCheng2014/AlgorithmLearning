//
//  ArrayQueue.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "ArrayQueue.h"

#include "comman.h"
#include "Queue.h"

int sq_QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status sq_EnQueue(SqQueue *Q, QElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front) {
        return ERROR;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    
    return OK;
}

Status sq_DeQueue(SqQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear) {
        return ERROR;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    
    return OK;
}


