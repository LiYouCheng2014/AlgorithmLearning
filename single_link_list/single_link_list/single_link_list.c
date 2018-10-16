//
//  single_link_list.c
//  single_link_list
//
//  Created by liyoucheng on 2018/10/16.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "single_link_list.h"

#include <stdlib.h>
#include <stdbool.h>

//带头结点，便于插入和删除统一操作

#pragma mark - 链表操作

/**
 创建头结点

 @return 链表
 */
SingleLinkListNode *single_link_list_create()
{
    SingleLinkListNode *head = (SingleLinkListNode *)malloc(sizeof(SingleLinkListNode));
    if (head == NULL) {
        printf("头结点创建失败\n");
        return NULL;
    }
    head->next = NULL;
    
    return head;
}

/**
 链表是否空

 @param head 链表
 @return 链表是否空
 */
bool single_link_list_is_empty(SingleLinkListNode *head)
{
    return head->next == NULL;
}

/**
 链表遍历

 @param head 链表
 */
void single_link_list_dump_head(SingleLinkListNode *head)
{
    SingleLinkListNode *p = head->next;

    printf("带头结点链表:");
    while (p != NULL) {
        printf("%d", p->val);
        if (p->next != NULL) {
            printf("->");
        }
        else {
            printf("\n");
        }
        p = p->next;
    }
}

/**
 链表遍历 不带头结点
 
 @param head 链表
 */
void single_link_list_dump(SingleLinkListNode *head)
{
    SingleLinkListNode *p = head;
    
    printf("不带头结点链表:");
    while (p != NULL) {
        printf("%d", p->val);
        if (p->next != NULL) {
            printf("->");
        }
        else {
            printf("\n");
        }
        p = p->next;
    }
}

/**
 头部插入

 @param head 链表
 @param data 插入数据
 */
void single_link_list_insert_head(SingleLinkListNode *head, int data)
{
    SingleLinkListNode *p = head;

    SingleLinkListNode *temp = (SingleLinkListNode *)malloc(sizeof(SingleLinkListNode));
    temp->val = data;
    temp->next = p->next;
    p->next = temp;
}

/**
 尾部插入

 @param head 链表
 @param data 插入数据
 */
void single_link_list_insert_tail(SingleLinkListNode *head, int data)
{
    SingleLinkListNode *p = head;
    
    while (p->next != NULL) {
        p = p->next;
    }
    
    SingleLinkListNode *temp = (SingleLinkListNode *)malloc(sizeof(SingleLinkListNode));
    temp->val = data;
    temp->next = NULL;
    
    p->next = temp;
}

/**
 删除头部节点

 @param head 链表
 @return 删除的节点
 */
SingleLinkListNode *single_link_list_delete_head(SingleLinkListNode *head)
{
    SingleLinkListNode *p = head;

    
    if (!p->next) {
        return NULL;
    }

    SingleLinkListNode *temp = p->next;
    p->next = temp->next;
    temp->next = NULL;
    return temp;
}

/**
 删除尾部节点

 @param head 链表
 @return 删除的节点
 */
SingleLinkListNode *single_link_list_delete_tail(SingleLinkListNode *head)
{
    SingleLinkListNode *p = head;

    if (!p->next) {
        return NULL;
    }
    
    while (p->next->next != NULL) {
        p = p->next;
    }
    
    
    SingleLinkListNode *temp = p->next;
    p->next = temp->next;
    temp->next = NULL;
    return temp;
}

#pragma mark - 反转链表

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

#pragma mark - 两两交换链表中的节点

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

#pragma mark - 环

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

#pragma mark - 环形链表II


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

#pragma mark - k个一组翻转链表

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

#pragma mark - 合并两个有序链表


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

/**
 链表测试
 */
void single_link_list_test()
{
    reverseList_test();
    swapPairs_test();
    hasCycle_test();
    detectCycle_test();
    reverseKGroup_test();
    mergeTwoLists_test();
}



