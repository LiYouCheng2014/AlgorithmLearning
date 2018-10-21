//
//  link_queue.c
//  link_queue
//
//  Created by liyoucheng on 2018/10/20.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "link_queue.h"

#include <stdbool.h>
#include <stdlib.h>

/**
 队是否空

 @param queue 队
 @return 是否空
 */
bool link_queue_is_empty(LinkQueue *queue)
{
    return queue->num == 0;
}

/**
 创建队

 @return 队
 */
LinkQueue *link_queue_create()
{
    LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
    if (queue == NULL) {
        return NULL;
    }
    
    queue->num = 0;
    queue->head = NULL;
    queue->tail = NULL;
    
    return queue;
}

/**
 出队

 @param queue 队
 @param data 出队数据
 @return 是否出队成功
 */
int link_queue_enqueue(LinkQueue *queue, int data)
{
    if (queue == NULL) {
        return -1;
    }
    
    LinkQueueNode *temp = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (temp == NULL) {
        return -1;
    }
    
    temp->data = data;
    temp->next = NULL;
    if (queue->head == NULL) {
        queue->head = temp;
    }
    else {
        queue->tail->next = temp;
    }
    queue->tail = temp;
    queue->num++;
    
    return 0;
}

/**
 入队

 @param queue 队
 @param data 入队数据
 @return 是否入队成功
 */
int link_queue_dequeue(LinkQueue *queue, int *data)
{
    if ((queue == NULL) || (data == NULL) || link_queue_is_empty(queue)) {
        return -1;
    }
    
    *data = queue->head->data;
    LinkQueueNode *temp = queue->head;
    queue->head = queue->head->next;
    queue->num--;
    
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    
    free(temp);
    
    return 0;
}

/**
 销毁队

 @param queue 队
 */
void link_queue_destroy(LinkQueue *queue)
{
    if ((queue == NULL) || link_queue_is_empty(queue)) {
        return;
    }
    
    int data = 0;
    while (!link_queue_is_empty(queue)) {
        link_queue_dequeue(queue, &data);
    }
    free(queue);
}

/**
 队遍历

 @param queue 队
 */
void link_queue_dump(LinkQueue *queue)
{
    if ((queue == NULL) || link_queue_is_empty(queue)) {
        return;
    }
    
    LinkQueueNode *temp = queue->head;
    printf("num = %d\n", queue->num);
    
    int i = 0;
    while (temp != NULL) {
        printf("node[%d] = %d\n",i, temp->data);
        i++;
        temp = temp->next;
    }
}

/**
 测试
 */
void test()
{
    LinkQueue *queue = link_queue_create();
    if (queue == NULL) {
        printf("创建失败\n");
        return;
    }
    
    for (int i = 0; i < 5; i++) {
        link_queue_enqueue(queue, i);
    }
    link_queue_dump(queue);
    
    int data = 0;
    int ret = link_queue_dequeue(queue, &data);
    if (ret != 0) {
        printf("出栈失败 %d", data);
    }
    printf("data = %d\n", data);
    link_queue_dump(queue);
    
    ret = link_queue_dequeue(queue, &data);
    if (ret != 0) {
        printf("出栈失败 %d", data);
    }
    printf("data = %d\n", data);
    link_queue_dump(queue);
    
    link_queue_enqueue(queue, data);
    link_queue_dump(queue);
}


