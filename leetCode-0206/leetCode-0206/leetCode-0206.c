//
//  leetCode-0206.c
//  leetCode-0206
//
//  Created by liyoucheng on 2018/10/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0206.h"

#include "link_list.h"

/**
 反转链表 1->2-3->4
 
 @param head 不带头结点
 @return 反转后的链表 4->3->2->1
 */
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *cur = head;
    struct ListNode *prev = NULL;
    while (cur) {
        struct ListNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

/**
 反转链表测试
 */
void reverseList_test()
{
    SingleLinkListNode *head = single_link_list_create();
    single_link_list_insert_tail(head, 1);
    single_link_list_insert_tail(head, 2);
    single_link_list_insert_tail(head, 3);
    single_link_list_insert_tail(head, 4);
    
    printf("========反转链表测试========\n");
    single_link_list_dump_head(head);
    SingleLinkListNode *new = reverseList(head->next);
    single_link_list_dump(new);
}
