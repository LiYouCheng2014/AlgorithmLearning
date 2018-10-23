//
//  leetCode-0142.c
//  leetCode-0142
//
//  Created by liyoucheng on 2018/10/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0142.h"

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
 环形链表II
 
 @param head 不带头结点
 @return 入环的第一个节点
 */
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    
    while (fast != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        
        if (fast == slow) {
            fast = head;
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }
    return NULL;
}


/**
 环形链表II 测试
 */
void detectCycle_test()
{
    printf("========环形链表II测试========\n");
    
    SingleLinkListNode *cycleHead = create_cycle_list();
    SingleLinkListNode *firstNode = detectCycle(cycleHead);
    printf("入环的第一个节点值：%d\n",firstNode->val);
}
