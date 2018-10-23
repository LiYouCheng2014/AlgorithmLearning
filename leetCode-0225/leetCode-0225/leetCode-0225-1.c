//
//  leetCode-0225.c
//  leetCode-0225
//
//  Created by liyoucheng on 2018/10/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0225-1.h"

//#include <stdlib.h>
//#include "link_queue.h"
//
///*
// 需要另外一个队列来辅助操作，我们总共需要两个队列，其中一个队列用来放最后加进来的数，模拟栈顶元素。剩下所有的数都按顺序放入另一个队列中。
// 当push操作时，将新数字先加入模拟栈顶元素的队列中，如果此时队列中有数字，则将原本有的数字放入另一个队中，让新数字在这队中，用来模拟栈顶元素。
// 当top操作时，如果模拟栈顶的队中有数字则直接返回，如果没有则到另一个队列中通过平移数字取出最后一个数字加入模拟栈顶的队列中。
// 当pop操作时，先执行下top()操作，保证模拟栈顶的队列中有数字，然后再将该数字移除即可。
// 当empty操作时，当两个队列都为空时，栈为空
// */
//
//typedef struct
//{
//    LinkQueue *q1;
//    LinkQueue *q2;//模拟栈顶元素
//}MyStack;
//
//MyStack *myStackCreate(int maxSize)
//{
//    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
//    stack->q1 = link_queue_create();
//    stack->q2 = link_queue_create();
//    
//    return stack;
//}
//
//void myStackPush(MyStack *obj, int x)
//{
//    link_queue_enqueue(obj->q2, x);
//    while (link_queue_length(obj->q2) > 1) {
//        link_queue_enqueue(obj->q1, obj->q2->head->data);
//        
//        int data = 0;
//        link_queue_dequeue(obj->q2, &data);
//    }
//}
//
//int myStackTop(MyStack *obj)
//{
//    if (link_queue_is_empty(obj->q2)) {
//        for (int i = 0; i < link_queue_length(obj->q1) - 1; i++) {
//            link_queue_enqueue(obj->q1, obj->q1->head->data);
//            int data = 0;
//            link_queue_dequeue(obj->q1, &data);
//        }
//        link_queue_enqueue(obj->q2, obj->q1->head->data);
//        int data = 0;
//        link_queue_dequeue(obj->q1, &data);
//    }
//    return obj->q2->head->data;
//}
//
//int myStackPop(MyStack *obj)
//{
//    myStackTop(obj);
//    int data;
//    link_queue_dequeue(obj->q2, &data);
//    
//    return data;
//}
//
//bool myStackEmpty(MyStack *obj)
//{
//    return link_queue_is_empty(obj->q1) && link_queue_is_empty(obj->q2);
//}
//
//void myStackFree(MyStack *obj)
//{
//    link_queue_destroy(obj->q1);
//    link_queue_destroy(obj->q2);
//    free(obj);
//}
//
//void testStack()
//{
//    MyStack *stack = myStackCreate(5);
//    myStackPush(stack, 1);
//    myStackPush(stack, 2);
//    myStackPush(stack, 3);
//    myStackPush(stack, 4);
//    
//    while (!myStackEmpty(stack)) {
//        int data = myStackPop(stack);
//        printf("%d\n", data);
//    }
//}
