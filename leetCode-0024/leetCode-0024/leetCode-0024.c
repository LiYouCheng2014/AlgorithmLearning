//
//  leetCode-0024.c
//  leetCode-0024
//
//  Created by liyoucheng on 2018/10/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0024.h"

#include "link_list.h"

/**
 两两交换链表中的节点 1->2->3->4
 
 @param head 不带头结点
 @return 交换之后的链表 2->1->4->3
 */
struct ListNode *swapPairs(struct ListNode *head)
{
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *prev = dummy;
    prev->next = head;
    
    while (prev->next != NULL && prev->next->next != NULL) {
        
        struct ListNode *a = prev->next;
        struct ListNode *b = prev->next->next;
        
        struct ListNode *temp = b->next;
        prev->next = b;
        b->next = a;
        a->next = temp;
        prev = a;
    }
    
    return dummy->next;
}

/**
 两两交换链表中的节点测试
 */
void swapPairs_test()
{
    SingleLinkListNode *head = single_link_list_create();
    single_link_list_insert_tail(head, 1);
    single_link_list_insert_tail(head, 2);
    single_link_list_insert_tail(head, 3);
    single_link_list_insert_tail(head, 4);
    
    printf("========两两交换链表中的节点测试========\n");
    single_link_list_dump_head(head);
    SingleLinkListNode *new = swapPairs(head->next);
    single_link_list_dump(new);
}
