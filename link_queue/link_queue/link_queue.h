//
//  link_queue.h
//  leetCode-0225
//
//  Created by liyoucheng on 2018/10/22.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef link_queue_h
#define link_queue_h

#include <stdio.h>
#include <stdbool.h>
/*
 不带头结点
 */

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

/**
 队是否空
 
 @param queue 队
 @return 是否空
 */
bool link_queue_is_empty(LinkQueue *queue);

/**
 队长度
 
 @param queue 队
 @return 长度
 */
int link_queue_length(LinkQueue *queue);

/**
 创建队
 
 @return 队
 */
LinkQueue *link_queue_create(void);

/**
 入队
 
 @param queue 队
 @param data 入队数据
 @return 是否出入成功
 */
int link_queue_enqueue(LinkQueue *queue, int data);

/**
 出队
 
 @param queue 队
 @param data 出队数据
 @return 是否出队成功
 */
int link_queue_dequeue(LinkQueue *queue, int *data);

/**
 销毁队
 
 @param queue 队
 */
void link_queue_destroy(LinkQueue *queue);

/**
 队遍历
 
 @param queue 队
 */
void link_queue_dump(LinkQueue *queue);

void test(void);

#endif /* link_queue_h */
