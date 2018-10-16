//
//  double_link_list.c
//  double_link_list
//
//  Created by liyoucheng on 2018/10/15.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "double_link_list.h"

#include <stdlib.h>
#include <string.h>


/**
 创建双向链表

 @param list 双向链表
 */
void double_link_list_create(DoubleLinkListHead *list)
{
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

/**
 销毁双向链表

 @param list 双向链表
 */
void double_link_list_destory(DoubleLinkListHead *list)
{
    DoubleLinkListNode *temp = NULL;
    while (list->size > 0) {
        temp = list->head;
        list->head = temp->next;
        free(temp);
        list->size--;
    }
    
    memset(list, 0, sizeof(DoubleLinkListHead));
}


/**
 头部插入

 @param list 双向链表
 @param node 需插入的节点
 @param data 需插入的数据
 @return 是否插入成功
 */
int double_link_list_insert_head(DoubleLinkListHead *list, DoubleLinkListNode *node, int data)
{
    if (node == NULL) {
        node = (DoubleLinkListNode *)malloc(sizeof(DoubleLinkListNode));
        if (node == NULL) {
            return -1;
        }
    }
    
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    
    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    }
    else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    
    list->size++;
    
    return 0;
}

/**
 移除尾部节点

 @param list 双向链表
 @return 移除的尾部节点
 */
DoubleLinkListNode *double_link_list_remove_tail(DoubleLinkListHead *list)
{
    DoubleLinkListNode *node = NULL;
    if (list->size == 0) {
        return NULL;
    }
    
    node = list->tail;
    if (list->size > 1) {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    else {
        list->head = NULL;
        list->tail = NULL;
    }
    list->size--;
    
    return node;
}

/**
 移除节点

 @param list 双向链表
 @param node 移除的节点
 */
void double_link_list_remove_node(DoubleLinkListHead *list, DoubleLinkListNode *node)
{
    if ((list == NULL) || (node == NULL)) {
        return;
    }
    
    if (list->head == node) {
        list->head = list->head->next;
    }
    else if (list->tail == node) {
        list->tail = node->prev;
        list->tail->next = NULL;
    }
    else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    list->size--;
    node->prev = NULL;
    node->next = NULL;
    
    if (list->size == 0) {
        memset(list, 0, sizeof(DoubleLinkListHead));
    }
}

/**
 查找节点

 @param list 双向链表
 @param data 查找的数据
 @return 查找到的节点
 */
DoubleLinkListNode *double_link_list_search(DoubleLinkListHead *list, int data)
{
    DoubleLinkListNode *node = list->head;
    while (node != NULL) {
        if (node->data == data) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

/**
 遍历双向链表

 @param list 双向链表
 */
void double_link_list_dump(DoubleLinkListHead *list)
{
    int count = 0;
    printf("打印链表\n");
    DoubleLinkListNode *node = list->head;
    while (node != NULL) {
        printf("[%d] = %d\n",count++, node->data);
        node = node->next;
    }
}

/**
 LRU缓存淘汰算法

 @param list 双向链表
 @param data 数据
 */
void LRU_list(DoubleLinkListHead *list, int data)
{
    DoubleLinkListNode *node = double_link_list_search(list, data);
    if (node != NULL) {
        double_link_list_remove_node(list, node);
    }
    else if (list->size >= 4) {
        node = double_link_list_remove_tail(list);
    }
    
    double_link_list_insert_head(list, node, data);
}

/**
 LRU缓存淘汰算法测试
 */
void LRU_list_test()
{
    DoubleLinkListHead list = {0};
    DoubleLinkListNode *node = NULL;
    
    double_link_list_create(&list);
    
    printf("插入 1 2 3\n");
    double_link_list_insert_head(&list, NULL, 1);
    double_link_list_insert_head(&list, NULL, 2);
    double_link_list_insert_head(&list, NULL, 3);
    
    double_link_list_dump(&list);
    
    node = double_link_list_remove_tail(&list);
    if (node != NULL) {
        printf("删除 %d\n",node->data);
    }
    double_link_list_insert_head(&list, node, 4);
    
    double_link_list_dump(&list);
    
    LRU_list(&list, 5);
    double_link_list_dump(&list);
    
    LRU_list(&list, 6);
    double_link_list_dump(&list);
    
    LRU_list(&list, 7);
    double_link_list_dump(&list);
    
    LRU_list(&list, 5);
    double_link_list_dump(&list);
    
    while (list.size > 0) {
        node = double_link_list_remove_tail(&list);
        if (node != NULL) {
            printf("删除 %d\n", node->data);
            free(node);
        }
    }
}
