//
//  LinkList.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/16.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "LinkList.h"

#include <stdlib.h>

Status ll_GetElem(LinkList L, int i, ElemType *e)
{
    LinkList p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    
    if (!p || j > i) {
        return ERROR;
    }
    
    *e = p->data;
    return OK;
}

Status ll_ListInsert(LinkList *L, int i, ElemType e)
{
    LinkList p = *L;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    
    if (!p || j > i) {
        return ERROR;
    }
    
    LinkList s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    
    return OK;
}

Status ll_ListDelete(LinkList *L, int i, ElemType *e)
{
    LinkList p = *L;
    int j = 1;
    while (p->next && j < i) {
        p = p->next;
        ++j;
    }
    
    if (!(p->next) || j > i) {
        return ERROR;
    }
    LinkList q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    
    return OK;
}

void ll_CreateListHead(LinkList *L, int n)
{
    LinkList p;
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    
    for (int i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void ll_CreateListTail(LinkList *L, int n)
{
    LinkList p;
    *L = (LinkList)malloc(sizeof(Node));
    LinkList r = *L;
    
    for (int i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

Status ll_ClearList(LinkList *L)
{
    LinkList p = (*L)->next;
    LinkList q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}


struct ListNode *createNode(int *arr, int count) {
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    
    for (int i = 0; i < count; i++) {
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = arr[i];
        temp->next = NULL;
        
        //头插法
        temp->next = head->next;
        head->next = temp;
    }
    
    return head->next;
}

void printNode(struct ListNode *p)
{
    struct ListNode *temp = p;
    while (temp) {
        printf("%d",temp->val);
        temp = temp->next;
        if (temp) {
            printf("->");
        }
    }
    printf("\n");
}
