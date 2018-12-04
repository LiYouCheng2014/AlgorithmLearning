//
//  leetCode-0019.c
//  leetCode-0019
//
//  Created by liyoucheng on 2018/10/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0019.h"

#include "link_list.h"

/**
 删除链表的倒数第N个节点
 
 @param head 不带头结点
 @param n 倒数第N个节点
 @return 删除后的链表
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    if (!head->next) {
        return NULL;
    }
    
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    
    if (!fast) {
        return head->next;
    }
    
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    
    struct ListNode *temp = slow->next;
    slow->next = temp->next;
    
    free(temp);
    
    return head;
}


/**
 删除链表的倒数第N个节点测试
 */
void removeNthFromEnd_test()
{
    SingleLinkListNode *head = single_link_list_create();
    single_link_list_insert_tail(head, 1);
    single_link_list_insert_tail(head, 2);
    single_link_list_insert_tail(head, 3);
    single_link_list_insert_tail(head, 4);
    single_link_list_insert_tail(head, 5);
    
    
    printf("========删除链表的倒数第N个节点测试========\n");
    single_link_list_dump_head(head);
    SingleLinkListNode *new = removeNthFromEnd(head->next, 2);
    single_link_list_dump(new);
}

