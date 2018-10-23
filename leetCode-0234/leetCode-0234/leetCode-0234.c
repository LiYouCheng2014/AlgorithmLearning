//
//  leetCode-0234.c
//  leetCode-0234
//
//  Created by liyoucheng on 2018/10/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0234.h"

#include "link_list.h"

/**
 回文链表
 
 @param head 不带头结点
 @return 是否回文链表
 */
bool isPalindrome(struct ListNode *head)
{
    if (head == NULL || head->next == NULL) {
        return true;
    }
    
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *prev = NULL;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        
        //逆转前部分
        struct ListNode *temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    
    if (fast != NULL) {
        slow = slow->next;
    }
    
    while (slow != NULL) {
        if (prev->val != slow->val) {
            return false;
        }
        slow = slow->next;
        prev = prev->next;
    }
    
    return true;
}


/**
 回文链表
 */
void isPalindrome_test()
{
    SingleLinkListNode *head = single_link_list_create();
    single_link_list_insert_tail(head, 1);
    single_link_list_insert_tail(head, 2);
    single_link_list_insert_tail(head, 2);
    single_link_list_insert_tail(head, 1);
    
    printf("========回文链表========\n");
    single_link_list_dump_head(head);
    bool flag = isPalindrome(head->next);
    printf("是否回文:1回文，0非回文 => %d\n",flag);
}
