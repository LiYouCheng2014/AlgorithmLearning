//
//  leetCode-0021.c
//  leetCode-0021
//
//  Created by liyoucheng on 2018/10/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0021.h"

#include "link_list.h"

/**
 合并两个有序链表测试
 
 @param l1 有序链表1
 @param l2 有序链表2
 @return 合并的有序链表
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (l1 == NULL) {
        return l2;
    }
    
    if (l2 == NULL) {
        return l1;
    }
    
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    
    struct ListNode *p = dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        }
        else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    
    if (l1) {
        p->next = l1;
    }
    else {
        p->next = l2;
    }
    
    return dummy->next;
}


/**
 合并两个有序链表测试
 */
void mergeTwoLists_test()
{
    SingleLinkListNode *head1 = single_link_list_create();
    single_link_list_insert_tail(head1, 1);
    single_link_list_insert_tail(head1, 2);
    single_link_list_insert_tail(head1, 4);
    
    SingleLinkListNode *head2 = single_link_list_create();
    single_link_list_insert_tail(head2, 1);
    single_link_list_insert_tail(head2, 3);
    single_link_list_insert_tail(head2, 4);
    
    printf("========合并两个有序链表测试========\n");
    single_link_list_dump_head(head1);
    single_link_list_dump_head(head2);
    SingleLinkListNode *new = mergeTwoLists(head1->next, head2->next);
    single_link_list_dump(new);
}
