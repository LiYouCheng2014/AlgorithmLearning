//
//  single_link_list.h
//  single_link_list
//
//  Created by liyoucheng on 2018/10/16.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef single_link_list_h
#define single_link_list_h

#include <stdio.h>

typedef struct ListNode {
    struct ListNode *next;
    int val;
}SingleLinkListNode;


void single_link_list_test(void);

#endif /* single_link_list_h */
