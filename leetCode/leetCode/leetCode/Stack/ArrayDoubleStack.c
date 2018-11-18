//
//  ArrayDoubleStack.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "ArrayDoubleStack.h"

#include "Stack.h"

Status ads_Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
    if (S->top1 + 1 == S->top2) {
        return ERROR;
    }
    
    if (stackNumber == 1) {
        S->data[++S->top1] = e;
    }
    else if (stackNumber == 2) {
        S->data[--S->top2] = e;
    }
    
    return OK;
}

Status ads_Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
    if (stackNumber == 1) {
        if (S->top1 == -1) {
            return ERROR;
        }
        *e = S->data[S->top1--];
    }
    else if (stackNumber == 2) {
        if (S->top2 == MAXSIZE) {
            return ERROR;
        }
        *e = S->data[S->top2++];
    }
    
    return OK;
}
