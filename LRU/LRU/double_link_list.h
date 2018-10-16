//
//  double_link_list.h
//  double_link_list
//
//  Created by liyoucheng on 2018/10/15.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef double_link_list_h
#define double_link_list_h

#include <stdio.h>

typedef struct double_link_list_node
{
    struct double_link_list_node *prev;
    struct double_link_list_node *next;
    int data;
}DoubleLinkListNode;

typedef struct double_link_list_head
{
    int size;
    DoubleLinkListNode *head;//头指针
    DoubleLinkListNode *tail;//尾指针
}DoubleLinkListHead;

void LRU_list_test(void);

#endif /* double_link_list_h */
