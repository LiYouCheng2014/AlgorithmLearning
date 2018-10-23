//
//  link_list.h
//  link_list
//
//  Created by liyoucheng on 2018/10/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef link_list_h
#define link_list_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    struct ListNode *next;
    int val;
}SingleLinkListNode;


//带头结点，便于插入和删除统一操作

#pragma mark - 链表操作

/**
 创建头结点
 
 @return 链表
 */
SingleLinkListNode *single_link_list_create(void);

/**
 链表是否空
 
 @param head 链表
 @return 链表是否空
 */
bool single_link_list_is_empty(SingleLinkListNode *head);

/**
 链表遍历
 
 @param head 链表
 */
void single_link_list_dump_head(SingleLinkListNode *head);

/**
 链表遍历 不带头结点
 
 @param head 链表
 */
void single_link_list_dump(SingleLinkListNode *head);

/**
 头部插入
 
 @param head 链表
 @param data 插入数据
 */
void single_link_list_insert_head(SingleLinkListNode *head, int data);

/**
 尾部插入
 
 @param head 链表
 @param data 插入数据
 */
void single_link_list_insert_tail(SingleLinkListNode *head, int data);

/**
 删除头部节点
 
 @param head 链表
 @return 删除的节点
 */
SingleLinkListNode *single_link_list_delete_head(SingleLinkListNode *head);

/**
 删除尾部节点
 
 @param head 链表
 @return 删除的节点
 */
SingleLinkListNode *single_link_list_delete_tail(SingleLinkListNode *head);

#endif /* link_list_h */
