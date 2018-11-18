//
//  leetCode-0002.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/16.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0002.h"

#include <stdlib.h>

#include "LinkList.h"

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *root = (struct ListNode *)malloc(sizeof(struct ListNode));
    root->next = NULL;
    
    struct ListNode *p = root;
    
    int carry = 0;
    while (l1 || l2) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->next = NULL;
        temp->val = sum % 10;
        
        p->next = temp;

        if (l1 != NULL) {
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            l2 = l2->next;
        }
        
        p = p->next;
    }
    
    if (carry == 1) {
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->next = NULL;
        temp->val = carry;

        p->next = temp;
        p = p->next;
    }
    
    return root->next;
}

void test_0002() {
    //342
    int arrA[3] = { 2,4,3 };
    //465
    int arrB[3] = { 5,6,4 };
    
    struct ListNode *pa = createNode(arrA, sizeof(arrA)/sizeof(arrA[0]));
    struct ListNode *pb = createNode(arrB, sizeof(arrB)/sizeof(arrB[0]));
    
    printNode(pa);
    printNode(pb);
    
    struct ListNode *p = addTwoNumbers(pa, pb);
    printNode(p);
}
