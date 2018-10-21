//
//  single_link_list.c
//  single_link_list
//
//  Created by liyoucheng on 2018/10/16.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "single_link_list.h"



//带头结点，便于插入和删除统一操作

#pragma mark - 链表操作

/**
 创建头结点

 @return 链表
 */
SingleLinkListNode *single_link_list_create()
{
    SingleLinkListNode *head = (SingleLinkListNode *)malloc(sizeof(SingleLinkListNode));
    if (head == NULL) {
        printf("头结点创建失败\n");
        return NULL;
    }
    head->next = NULL;
    
    return head;
}

/**
 链表是否空

 @param head 链表
 @return 链表是否空
 */
bool single_link_list_is_empty(SingleLinkListNode *head)
{
    return head->next == NULL;
}

/**
 链表遍历

 @param head 链表
 */
void single_link_list_dump_head(SingleLinkListNode *head)
{
    SingleLinkListNode *p = head->next;

    printf("带头结点链表:");
    while (p != NULL) {
        printf("%d", p->val);
        if (p->next != NULL) {
            printf("->");
        }
        else {
            printf("\n");
        }
        p = p->next;
    }
}

/**
 链表遍历 不带头结点
 
 @param head 链表
 */
void single_link_list_dump(SingleLinkListNode *head)
{
    SingleLinkListNode *p = head;
    
    printf("不带头结点链表:");
    while (p != NULL) {
        printf("%d", p->val);
        if (p->next != NULL) {
            printf("->");
        }
        else {
            printf("\n");
        }
        p = p->next;
    }
}

/**
 头部插入

 @param head 链表
 @param data 插入数据
 */
void single_link_list_insert_head(SingleLinkListNode *head, int data)
{
    SingleLinkListNode *p = head;

    SingleLinkListNode *temp = (SingleLinkListNode *)malloc(sizeof(SingleLinkListNode));
    temp->val = data;
    temp->next = p->next;
    p->next = temp;
}

/**
 尾部插入

 @param head 链表
 @param data 插入数据
 */
void single_link_list_insert_tail(SingleLinkListNode *head, int data)
{
    SingleLinkListNode *p = head;
    
    while (p->next != NULL) {
        p = p->next;
    }
    
    SingleLinkListNode *temp = (SingleLinkListNode *)malloc(sizeof(SingleLinkListNode));
    temp->val = data;
    temp->next = NULL;
    
    p->next = temp;
}

/**
 删除头部节点

 @param head 链表
 @return 删除的节点
 */
SingleLinkListNode *single_link_list_delete_head(SingleLinkListNode *head)
{
    SingleLinkListNode *p = head;

    
    if (!p->next) {
        return NULL;
    }

    SingleLinkListNode *temp = p->next;
    p->next = temp->next;
    temp->next = NULL;
    return temp;
}

/**
 删除尾部节点

 @param head 链表
 @return 删除的节点
 */
SingleLinkListNode *single_link_list_delete_tail(SingleLinkListNode *head)
{
    SingleLinkListNode *p = head;

    if (!p->next) {
        return NULL;
    }
    
    while (p->next->next != NULL) {
        p = p->next;
    }
    
    
    SingleLinkListNode *temp = p->next;
    p->next = temp->next;
    temp->next = NULL;
    return temp;
}
