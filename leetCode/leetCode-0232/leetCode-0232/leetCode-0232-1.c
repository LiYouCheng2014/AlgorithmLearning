//
//  leetCode-0232-1.c
//  leetCode-0232
//
//  Created by liyoucheng on 2018/10/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0232-1.h"

#include "link_stack.h"
#include <stdlib.h>
#include <stdbool.h>

//typedef struct {
//    LinkStack *s1;
//} MyQueue;
//
///** Initialize your data structure here. */
//MyQueue* myQueueCreate(int maxSize) {
//    MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
//    queue->s1 = link_stack_create();
//    
//    return queue;
//}
//
///** Push element x to the back of queue. */
//void myQueuePush(MyQueue* obj, int x) {
//    LinkStack *tmp = link_stack_create();
//    while (!link_stack_is_empty(obj->s1)) {
//        int data = 0;
//        link_stack_top(obj->s1, &data);
//        link_stack_push(tmp, data);
//        link_stack_pop(obj->s1, &data);
//    }
//    
//    link_stack_push(obj->s1, x);
//    while (!link_stack_is_empty(tmp)) {
//        int data = 0;
//        link_stack_top(tmp, &data);
//        link_stack_push(obj->s1, data);
//        link_stack_pop(tmp, &data);
//    }
//    
//    free(tmp);
//}
//
///** Removes the element from in front of queue and returns that element. */
//int myQueuePop(MyQueue* obj) {
//    int data = 0;
//    link_stack_pop(obj->s1, &data);
//    return data;
//}
//
///** Get the front element. */
//int myQueuePeek(MyQueue* obj) {
//    int data = 0;
//    link_stack_top(obj->s1, &data);
//    return data;
//}
//
///** Returns whether the queue is empty. */
//bool myQueueEmpty(MyQueue* obj) {
//    return link_stack_is_empty(obj->s1);
//}
//
//void myQueueFree(MyQueue* obj) {
//    link_stack_destory(obj->s1);
//    free(obj);
//}
//
//void testQueue()
//{
//    MyQueue *queue = myQueueCreate(5);
//    myQueuePush(queue, 1);
//    myQueuePush(queue, 2);
//    myQueuePush(queue, 3);
//    myQueuePush(queue, 4);
//    
//    while (!myQueueEmpty(queue)) {
//        int data = myQueuePop(queue);
//        printf("%d\n",data);
//    }
//    
//}
