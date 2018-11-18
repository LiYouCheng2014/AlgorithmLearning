//
//  Stack.h
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include "comman.h"

typedef int SElemType;

//顺序
typedef struct
{
    SElemType data[MAXSIZE];
    int top;
}SqStack;

//两栈共享
typedef struct
{
    SElemType data[MAXSIZE];
    int top1;
    int top2;
}SqDoubleStack;

//链式
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;

#endif /* Stack_h */
