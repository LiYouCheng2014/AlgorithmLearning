//
//  array_queue.c
//  array_queue
//
//  Created by liyoucheng on 2018/10/20.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "array_queue.h"

#include <stdbool.h>
#include <stdlib.h>

/**
 队是否空

 @param queue 队
 @return 是否空
 */
bool array_queue_is_empty(ArrayQueue *queue)
{
    return queue->num == 0;
}

/**
 队是否满

 @param queue 队
 @return 是否满
 */
bool array_queue_is_full(ArrayQueue *queue)
{
    return queue->num == queue->size;
}

/**
创建队
 
 @param size 队大小
 @return 队
 */
ArrayQueue *array_queue_create(int size)
{
    ArrayQueue *queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
    if (queue == NULL) {
        return NULL;
    }
    
    queue->array = (int *)malloc(sizeof(int) * size);
    if (queue->array == NULL) {
        free(queue);
        return NULL;
    }
    
    queue->size = size;
    queue->num = 0;
    queue->head = 0;
    queue->tail = 0;
    
    return queue;
}

/**
 销毁队

 @param queue 队
 */
void array_queue_destory(ArrayQueue *queue)
{
    if (queue == NULL) {
        return;
    }
    
    if (queue->array != NULL) {
        free(queue->array);
    }
    
    free(queue);
}

/**
 入队

 @param queue dui
 @param data 入队数据
 @return 是否入队成功
 */
int array_queue_enqueue(ArrayQueue *queue, int data)
{
    if ((queue == NULL) || array_queue_is_full(queue)) {
        return -1;
    }
    
    queue->num++;
    queue->array[queue->tail] = data;
    queue->tail = (queue->tail + 1) % queue->size;
    
    return 0;
}

/**
 出队

 @param queue 队
 @param data 出队数据
 @return 是否出队成功
 */
int array_queue_dequeue(ArrayQueue *queue, int *data)
{
    if ((queue == NULL) || (data == NULL) || array_queue_is_empty(queue)) {
        return -1;
    }
    
    *data = queue->array[queue->head];
    queue->num--;
    queue->head = (queue->head + 1) % queue->size;
    
    return 0;
}

/**
 队遍历

 @param queue 队
 */
void array_queue_dump(ArrayQueue *queue)
{
    if ((queue == NULL) || (array_queue_is_empty(queue))) {
        return;
    }
    
    printf("size:%d,num:%d,head:%d,tail:%d\n",queue->size, queue->num, queue->head, queue->tail);
    for (int i = 0; i < queue->num; i++) {
        int pos = (queue->head + i) % queue->size;
        printf("array[%d] = %d\n", pos, queue->array[pos]);
    }
}

/**
 测试
 */
void test()
{
    ArrayQueue *queue = array_queue_create(4);
    if (queue == NULL) {
        return;
    }
    
    int data = 0;
    int ret = array_queue_dequeue(queue, &data);
    if (ret != 0) {
        printf("出栈失败 %d\n",ret);
    }
    
    for (int i = 0; i < 5; i++) {
        int ret = array_queue_enqueue(queue, i);
        if (ret != 0) {
            printf("入栈失败 %d\n", ret);
        }
    }
    
    array_queue_dump(queue);
    
    data = 0;
    ret = array_queue_dequeue(queue, &data);
    if (ret != 0) {
        printf("出栈失败 %d\n",ret);
    }
    
    printf("data = %d\n",data);
    
    array_queue_dump(queue);
    
    data = 5;
    ret = array_queue_enqueue(queue, data);
    if (ret != 0) {
        printf("入栈失败 %d\n", data);
    }
    array_queue_dump(queue);
    
    array_queue_destory(queue);
}
