//
//  leetCode-0102.c
//  leetCode-0102
//
//  Created by liyoucheng on 2018/11/15.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0102.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "TreeNode.h"

typedef struct link_queue_node
{
    struct TreeNode *data;
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
bool link_queue_is_empty(LinkQueue *queue)
{
    return queue->num == 0;
}

/**
 队长度
 
 @param queue 队
 @return 长度
 */
int link_queue_length(LinkQueue *queue)
{
    return queue->num;
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
 入队
 
 @param queue 队
 @param data 入队数据
 @return 是否出入成功
 */
int link_queue_enqueue(LinkQueue *queue, struct TreeNode *data)
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
 出队
 
 @param queue 队
 @param data 出队数据
 @return 是否出队成功
 */
struct TreeNode *link_queue_dequeue(LinkQueue *queue)
{
    if ((queue == NULL) || link_queue_is_empty(queue)) {
        return NULL;
    }
    
    struct TreeNode *data = queue->head->data;
    LinkQueueNode *temp = queue->head;
    queue->head = queue->head->next;
    queue->num--;
    
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    
    free(temp);
    
    return data;
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    *returnSize = 0;
    int **results = malloc(1000 * sizeof(int *));
    *columnSizes = malloc(1000 * sizeof(int));
    memset(*columnSizes, 0, 1000 * sizeof(int));
    
    LinkQueue *queue = link_queue_create();
    link_queue_enqueue(queue, root);
    
    int *nums = malloc(1000 * sizeof(int));
    
    while (!link_queue_is_empty(queue)) {
        int len = link_queue_length(queue);
        int *temp = malloc(len * sizeof(int));
        for (int i = 0; i < len; i++) {
            struct TreeNode *node = link_queue_dequeue(queue);
            temp[i] = node->val;
            
            if (node->left) {
                link_queue_enqueue(queue, node->left);
            }
            
            if (node->right) {
                link_queue_enqueue(queue, node->right);
            }
        }
        nums[*returnSize] = len;
        results[*returnSize] = temp;
        *returnSize += 1;
    }
    
    *columnSizes = nums;
    
    return results;
}

void test()
{
    struct TreeNode root;
    root.val = 3;
    
    struct TreeNode node1[2];
    node1[0].val = 9;
    node1[1].val = 20;
    
    struct TreeNode node2[4];
    node2[2].val = 15;
    node2[3].val = 7;
    
    root.left = &node1[0];
    root.right = &node1[1];
    
    node1[0].left = NULL;
    node1[0].right = NULL;
    node1[1].left = &node2[2];
    node1[1].right = &node2[3];
    
    node2[0].left = NULL;
    node2[0].right = NULL;
    node2[1].left = NULL;
    node2[1].right = NULL;
    node2[2].left = NULL;
    node2[2].right = NULL;
    node2[3].left = NULL;
    node2[3].right = NULL;
    
    int *column = NULL;
    int size = 0;
    int **ret = levelOrder(&root, &column, &size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < column[i]; j++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
}

///**
// 队遍历
//
// @param queue 队
// */
//void link_queue_dump(LinkQueue *queue)
//{
//    if ((queue == NULL) || link_queue_is_empty(queue)) {
//        return;
//    }
//
//    LinkQueueNode *temp = queue->head;
//    printf("num = %d\n", queue->num);
//
//    int i = 0;
//    while (temp != NULL) {
//        printf("node[%d] = %d\n",i, temp->data);
//        i++;
//        temp = temp->next;
//    }
//}
