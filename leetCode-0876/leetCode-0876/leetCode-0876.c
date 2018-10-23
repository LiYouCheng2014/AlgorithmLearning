//
//  leetCode-0876.c
//  leetCode-0876
//
//  Created by liyoucheng on 2018/10/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0876.h"

#include "link_list.h"

/**
 链表的中间结点
 
 @param head 不带头结点
 @return 链表中间结点之后的链表
 */
struct ListNode *middleNode(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

/**
 链表的中间结点测试
 */
void middleNode_test()
{
    SingleLinkListNode *head = single_link_list_create();
    single_link_list_insert_tail(head, 1);
    single_link_list_insert_tail(head, 2);
    single_link_list_insert_tail(head, 3);
    single_link_list_insert_tail(head, 4);
    single_link_list_insert_tail(head, 5);
    //    single_link_list_insert_tail(head, 6);
    
    printf("========链表的中间结点========\n");
    single_link_list_dump_head(head);
    SingleLinkListNode *new = middleNode(head->next);
    single_link_list_dump(new);
}

