//
//  LinkQueue.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "LinkQueue.h"

#include <stdlib.h>

Status lq_QueueIsEmpty(LinkQueue *Q)
{
    return Q->count == 0;
}

int lq_QueueLength(LinkQueue *Q)
{
    return Q->count;
}

LinkQueue *lq_InitQueue(void)
{
    LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
    if (queue == NULL) {
        return NULL;
    }
    
    queue->count = 0;
    queue->front = NULL;
    queue->rear = NULL;
    
    return queue;
}

Status lq_EnQueue(LinkQueue *Q, QElemType e)
{
    if (Q == NULL) {
        return ERROR;
    }
    
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if (s == NULL) {
        return ERROR;
    }
    
    s->data = e;
    s->next = NULL;
    
    if (Q->front == NULL) {
        Q->front = s;
    }
    else {
        Q->rear->next = s;
    }
    
    Q->rear = s;
    Q->count += 1;

    return OK;
}

Status lq_DeQueue(LinkQueue *Q, QElemType *e)
{
    if (Q == NULL) {
        return ERROR;
    }
    
    if (e == NULL) {
        return ERROR;
    }
    
    if (lq_QueueIsEmpty(Q)) {
        return ERROR;
    }
    
    QueuePtr p = Q->front;
    *e = p->data;
    Q->front = p->next;
    Q->count -= 1;
    
    
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    
    free(p);
    
    return OK;
}

void lq_destroyQueue(LinkQueue *Q)
{
    if ((Q == NULL) || lq_QueueIsEmpty(Q)) {
        return;
    }
    
    QElemType data;
    while (!lq_QueueIsEmpty(Q)) {
        lq_DeQueue(Q, &data);
    }
    free(Q);
}

//void lq_QueueDump(LinkQueue *Q)
//{
//    if ((Q == NULL) || lq_QueueIsEmpty(Q)) {
//        return;
//    }
//    
//    QueuePtr temp = Q->front;
//    printf("================================\n");
//    printf("count = %d\n", Q->count);
//    
//    int i = 0;
//    while (temp != NULL) {
//        printf("node[%d] = %d\n",i, temp->data);
//        i++;
//        temp = temp->next;
//    }
//}
//
///**
// 测试
// */
//void test()
//{
//    LinkQueue *queue = lq_InitQueue();
//    if (queue == NULL) {
//        printf("创建失败\n");
//        return;
//    }
//    
//    for (int i = 0; i < 5; i++) {
//        lq_EnQueue(queue, 100 + i);
//    }
//    lq_QueueDump(queue);
//    
//    QElemType data = 0;
//    int ret = lq_DeQueue(queue, &data);
//    if (ret == 0) {
//        printf("出栈失败 %d", data);
//    }
//    printf("data = %c\n", data);
//    lq_QueueDump(queue);
//    
//    ret = lq_DeQueue(queue, &data);
//    if (ret == 0) {
//        printf("出栈失败 %d", data);
//    }
//    printf("data = %c\n", data);
//    lq_QueueDump(queue);
//    
//    lq_EnQueue(queue, data);
//    lq_QueueDump(queue);
//}
