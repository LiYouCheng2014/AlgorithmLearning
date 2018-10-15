//
//  link_stack.c
//  link_stack
//
//  Created by liyoucheng on 2018/10/15.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "link_stack.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


/**
 获取栈是否空

 @param stack 栈
 @return 是否空
 */
bool link_stack_is_empty(LinkStack *stack)
{
    return stack->next == NULL;
}

/**
 初始化栈

 @return 栈
 */
LinkStack *link_stack_create()
{
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));
    if (stack == NULL) {
        return NULL;
    }
    stack->next = NULL;
    
    return stack;
}

/**
 销毁栈

 @param stack 栈
 */
void link_stack_destory(LinkStack *stack)
{
    LinkStack *temp = NULL;
    while (!link_stack_is_empty(stack)) {
        temp = stack->next;
        stack->next = temp->next;
        free(temp);
    }
    free(stack);
}

/**
 出栈

 @param stack 栈
 @param data 栈顶元素
 @return 是否出栈成功
 */
int link_stack_pop(LinkStack *stack, int *data)
{
    if (data == NULL) {
        return -1;
    }
    
    if (link_stack_is_empty(stack)) {
        return -1;
    }
    
    *data = stack->next->data;
    LinkStack *temp = stack->next;
    stack->next = temp->next;
    
    free(temp);
    
    return 0;
}

/**
 入栈
 
 @param stack 栈
 @param data 入栈元素
 @return 是否入栈成功
 */
int link_stack_push(LinkStack *stack, int data)
{
    LinkStack *temp = (LinkStack *)malloc(sizeof(LinkStack));
    if (temp == NULL) {
        return -1;
    }
    
    temp->data = data;
    temp->next = stack->next;
    stack->next = temp;
    
    return 0;
}

/**
 遍历栈

 @param stack 栈
 */
void link_stack_dump(LinkStack *stack)
{
    printf("打印栈\n");
    LinkStack *temp = stack->next;
    while (temp != NULL) {
        printf("data = %d\n",temp->data);
        temp = temp->next;
    }
}

/**
 测试栈
 */
void link_stack_test()
{
    LinkStack *stack = link_stack_create();
    if (stack == NULL) {
        printf("创建失败\n");
    }
    
    for (int i = 0; i < 4; i++) {
        int ret = link_stack_push(stack, i);
        if (ret != 0) {
            printf("入栈失败%d\n",i);
        }
    }
    
    link_stack_dump(stack);
    
    printf("出栈\n");
    int data = 0;
    for (int i = 0; i < 5; i++) {
        int ret = link_stack_pop(stack, &data);
        if (ret != 0) {
            printf("出栈失败%d\n",i);
        }
        else {
            printf("data = %d\n",data);
        }
    }
    link_stack_destory(stack);
}
