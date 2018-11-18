//
//  LinkStack.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "LinkStack.h"

#include "Stack.h"

#include <stdlib.h>

Status ls_Push(LinkStack *S, SElemType e)
{
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    
    return OK;
}

int ls_StackEmpty(LinkStack  *S)
{
    return S->count == 0;
}

Status ls_Pop(LinkStack *S, SElemType *e)
{
   
    if (ls_StackEmpty(S)) {
        return ERROR;
    }
    
    *e = S->top->data;
    LinkStackPtr p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    
    return OK;
}
