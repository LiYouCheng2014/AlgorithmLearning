//
//  leetCode-0141.c
//  leetCode-0141
//
//  Created by liyoucheng on 2018/10/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0141.h"

#include "link_list.h"

/**
 创建环
 
 @return 环
 */
struct ListNode *create_cycle_list()
{
    SingleLinkListNode *node1 = (SingleLinkListNode *)malloc(sizeof(SingleLinkListNode));
    node1->val = 1;
    
    SingleLinkListNode *node2 = (SingleLinkListNode *)malloc(sizeof(SingleLinkListNode));
    node2->val = 2;
    
    SingleLinkListNode *node3 = (SingleLinkListNode *)malloc(sizeof(SingleLinkListNode));
    node3->val = 3;
    
    SingleLinkListNode *node4 = (SingleLinkListNode *)malloc(sizeof(SingleLinkListNode));
    node4->val = 4;
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;
    
    return node1;
}


/**
 环形链表
 
 @param head 不带头结点
 @return 是否存在环
 */
bool hasCycle(struct ListNode *head)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

/**
 环形链表测试
 */
void hasCycle_test()
{
    SingleLinkListNode *head = single_link_list_create();
    single_link_list_insert_tail(head, 1);
    single_link_list_insert_tail(head, 2);
    single_link_list_insert_tail(head, 3);
    single_link_list_insert_tail(head, 4);
    
    printf("========环形链表测试========\n");
    bool isCycle = hasCycle(head->next);
    printf("是否存在环:1是，0不是=>%d\n",isCycle);
    
    SingleLinkListNode *cycleHead = create_cycle_list();
    bool isCycle1 = hasCycle(cycleHead);
    printf("是否存在环:1是，0不是=>%d\n",isCycle1);
}
