//
//  leetCode-0225-2.c
//  leetCode-0225
//
//  Created by liyoucheng on 2018/10/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0225-2.h"

#include <stdlib.h>
#include "link_queue.h"

/*
 每次把新加入的数插到前头，这样队列保存的顺序和栈的顺序是相反的，它们的取出方式也是反的，那么反反得正，就是我们需要的顺序了。我们需要一个辅助队列tmp，把s的元素也逆着顺序存入tmp中，此时加入新元素x，再把tmp中的元素存回来，这样就是我们要的顺序了，其他三个操作也就直接调用队列的操作即可
 */

typedef struct
{
    LinkQueue *q1;
}MyStack;

MyStack *myStackCreate(int maxSize)
{
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->q1 = link_queue_create();
    
    return stack;
}

void myStackPush(MyStack *obj, int x)
{
    LinkQueue *tmp = link_queue_create();
    while (!link_queue_is_empty(obj->q1)) {
        link_queue_enqueue(tmp, obj->q1->head->data);
        int data = 0;
        link_queue_dequeue(obj->q1, &data);
    }
    
    link_queue_enqueue(obj->q1, x);
    while (!link_queue_is_empty(tmp)) {
        link_queue_enqueue(obj->q1, tmp->head->data);
        int data = 0;
        link_queue_dequeue(tmp, &data);
    }
    
    free(tmp);
}

int myStackTop(MyStack *obj)
{
    return obj->q1->head->data;
}

int myStackPop(MyStack *obj)
{
    int data;
    link_queue_dequeue(obj->q1, &data);
    
    return data;
}

bool myStackEmpty(MyStack *obj)
{
    return link_queue_is_empty(obj->q1);
}

void myStackFree(MyStack *obj)
{
    link_queue_destroy(obj->q1);
    free(obj);
}

void testStack()
{
    MyStack *stack = myStackCreate(5);
    myStackPush(stack, 1);
    myStackPush(stack, 2);
    myStackPush(stack, 3);
    myStackPush(stack, 4);
    
    while (!myStackEmpty(stack)) {
        int data = myStackPop(stack);
        printf("%d\n", data);
    }
}
