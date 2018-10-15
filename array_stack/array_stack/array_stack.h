//
//  array_stack.h
//  array_stack
//
//  Created by liyoucheng on 2018/10/15.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef array_stack_h
#define array_stack_h

#include <stdio.h>

typedef struct array_stack
{
    int size;//栈大小
    int pos;//栈顶元素
    int *array;//数据存储区
}ArrayStack;

void array_stack_test(void);

#endif /* array_stack_h */
