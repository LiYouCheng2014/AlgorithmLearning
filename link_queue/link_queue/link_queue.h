//
//  link_queue.h
//  link_queue
//
//  Created by liyoucheng on 2018/10/20.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef link_queue_h
#define link_queue_h

#include <stdio.h>

typedef struct link_queue_node
{
    int data;
    struct link_queue_node *next;
}LinkQueueNode;

typedef struct link_queue
{
    int num;
    LinkQueueNode *head;
    LinkQueueNode *tail;
}LinkQueue;

void test(void);

#endif /* link_queue_h */
