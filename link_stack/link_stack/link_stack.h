//
//  link_stack.h
//  link_stack
//
//  Created by liyoucheng on 2018/10/15.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef link_stack_h
#define link_stack_h

#include <stdio.h>

typedef struct link_stack
{
    int data;//数据域
    struct link_stack *next;//指针域
}LinkStack;

void link_stack_test(void);

#endif /* link_stack_h */
