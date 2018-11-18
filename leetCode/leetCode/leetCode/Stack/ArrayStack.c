//
//  ArrayStack.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "ArrayStack.h"

#include "Stack.h"

Status as_Push(SqStack *S, SElemType e)
{
    if (S->top == MAXSIZE - 1) {
        return ERROR;
    }
    
    S->top++;
    S->data[S->top] = e;
    return OK;
}

Status as_Pop(SqStack *S, SElemType *e)
{
    if (S->top == -1) {
        return ERROR;
    }
    
    *e = S->data[S->top];
    S->top--;
    return OK;
}
