//
//  leetCode-0232-2.c
//  leetCode-0232
//
//  Created by liyoucheng on 2018/10/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0232-2.h"

#include "link_stack.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    LinkStack *s1;//新
    LinkStack *s2;//旧
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
    queue->s1 = link_stack_create();
    queue->s2 = link_stack_create();
    
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    
    link_stack_push(obj->s1, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (link_stack_is_empty(obj->s2)) {
        while (!link_stack_is_empty(obj->s1)) {
            int data = 0;
            link_stack_top(obj->s1, &data);
            link_stack_push(obj->s2, data);
            link_stack_pop(obj->s1, &data);
        }
    }
    
    if (!link_stack_is_empty(obj->s2)) {
        int data = 0;
        link_stack_pop(obj->s2, &data);
        return data;
    }
    return 0;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (link_stack_is_empty(obj->s2)) {
        while (!link_stack_is_empty(obj->s1)) {
            int data = 0;
            link_stack_top(obj->s1, &data);
            link_stack_push(obj->s2, data);
            link_stack_pop(obj->s1, &data);
        }
    }
    
    if (!link_stack_is_empty(obj->s2)) {
        int data = 0;
        link_stack_top(obj->s2, &data);
        return data;
    }
    return 0;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return link_stack_is_empty(obj->s1) && link_stack_is_empty(obj->s2);
}

void myQueueFree(MyQueue* obj) {
    link_stack_destory(obj->s1);
    link_stack_destory(obj->s2);
    free(obj);
}

void testQueue()
{
    MyQueue *queue = myQueueCreate(5);
    myQueuePush(queue, 1);
    myQueuePush(queue, 2);
    myQueuePush(queue, 3);
    myQueuePush(queue, 4);
    
    while (!myQueueEmpty(queue)) {
        int data = myQueuePop(queue);
        printf("%d\n",data);
    }
    
}
