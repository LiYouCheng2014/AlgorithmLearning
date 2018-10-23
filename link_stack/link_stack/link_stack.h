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
#include <stdbool.h>
typedef struct link_stack
{
    int data;//数据域
    struct link_stack *next;//指针域
}LinkStack;

/**
 获取栈是否空
 
 @param stack 栈
 @return 是否空
 */
bool link_stack_is_empty(LinkStack *stack);

/**
 初始化栈
 
 @return 栈
 */
LinkStack *link_stack_create(void);

/**
 销毁栈
 
 @param stack 栈
 */
void link_stack_destory(LinkStack *stack);

/**
 出栈
 
 @param stack 栈
 @param data 栈顶元素
 @return 是否出栈成功
 */
int link_stack_pop(LinkStack *stack, int *data);

/**
 栈顶元素
 
 @param stack 栈
 @param data 栈顶元素
 @return 是否获取栈顶成功
 */
int link_stack_top(LinkStack *stack, int *data);

/**
 入栈
 
 @param stack 栈
 @param data 入栈元素
 @return 是否入栈成功
 */
int link_stack_push(LinkStack *stack, int data);

/**
 遍历栈
 
 @param stack 栈
 */
void link_stack_dump(LinkStack *stack);

/**
 测试栈
 */
void link_stack_test(void);

#endif /* link_stack_h */
