//
//  leetCode-0025.c
//  leetCode-0025
//
//  Created by liyoucheng on 2018/10/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0025.h"

#include "link_list.h"

/**
 反转链表 1->2-3->4
 
 @param head 不带头结点
 @return 反转后的链表 4->3->2->1
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *cur = head;
    struct ListNode *prev = NULL;
    while(cur) {
        struct ListNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

/**
 k个一组翻转链表 1->2->3->4->5
 
 @param head 不带头结点
 @param k 几个节点 2
 @return 翻转后的链表 2->1->4->3->5
 */
struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    struct ListNode *root = NULL;
    struct ListNode *p = NULL;
    
    while (head != NULL) {
        struct  ListNode *tempHead = head;
        struct ListNode *tempP = NULL;
        
        int count = 0;
        bool isReverse = true;
        
        while (count < k) {
            if (head == NULL) {
                isReverse = false;
                break;
            }
            
            tempP = head;
            head = head->next;
            count++;
        }
        tempP->next = NULL;
        
        if (isReverse) {
            if (root == NULL) {
                root = reverseList(tempHead);
                p = tempHead;
            }
            else {
                p->next = reverseList(tempHead);
                p = tempHead;
            }
        }
        else {
            if (root == NULL) {
                root = tempHead;
            }
            else {
                p->next = tempHead;
            }
        }
    }
    
    return root;
}

/**
 k个一组翻转链表测试
 */
void reverseKGroup_test()
{
    SingleLinkListNode *head = single_link_list_create();
    single_link_list_insert_tail(head, 1);
    single_link_list_insert_tail(head, 2);
    single_link_list_insert_tail(head, 3);
    single_link_list_insert_tail(head, 4);
    single_link_list_insert_tail(head, 5);
    
    printf("========k个一组翻转链表测试========\n");
    single_link_list_dump_head(head);
    SingleLinkListNode *new = reverseKGroup(head->next, 2);
    single_link_list_dump(new);
}
