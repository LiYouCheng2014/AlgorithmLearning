//
//  array_stack.c
//  array_stack
//
//  Created by liyoucheng on 2018/10/15.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "array_stack.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


/**
 获取栈长度

 @param stack 栈
 @return 栈长度
 */
int array_stack_length(ArrayStack *stack)
{
    return stack->size;
}

/**
 获取栈是否空

 @param stack 栈
 @return 是否空
 */
bool array_stack_is_empty(ArrayStack *stack)
{
    return stack->pos == -1;
}

/**
 获取栈是否满

 @param stack 栈
 @return 是否满
 */
bool array_stack_is_full(ArrayStack *stack)
{
    return stack->pos == (stack->size - 1);
}

/**
 初始化栈

 @param size 栈大小
 @return 栈
 */
ArrayStack *array_stack_create(int size)
{
    ArrayStack *stack = (ArrayStack *)malloc(sizeof(ArrayStack));
    if (stack == NULL) {
        return NULL;
    }
    
    stack->size = size;
    stack->pos = -1;
    stack->array = (int *)malloc(sizeof(int) * size);
    
    if (stack->array == NULL) {
        free(stack);
        return NULL;
    }
    
    return stack;
}

/**
 销毁栈

 @param stack 栈
 */
void array_stack_destory(ArrayStack *stack)
{
    if (stack == NULL) {
        return;
    }
    
    if (stack->array != NULL) {
        free(stack->array);
    }
    free(stack);
    return;
}

/**
 出栈

 @param stack 栈
 @return 栈顶元素
 */
int array_stack_pop(ArrayStack *stack)
{
    int data = 0;
    if (array_stack_is_empty(stack)) {
        return -1;
    }
    
    data = stack->array[stack->pos];
    stack->pos--;
    
    return data;
}

/**
 入栈

 @param stack 栈
 @param data 入栈元素
 @return 是否入栈成功
 */
int array_stack_push(ArrayStack *stack, int data)
{
    if (array_stack_is_full(stack)) {
        return -1;
    }
    
    stack->pos++;
    stack->array[stack->pos] = data;
    
    return 0;
}

/**
 入栈 不足申请新空间

 @param stack 栈
 @param data 入栈元素
 @return 是否入栈成功
 */
int array_stack_push_new(ArrayStack *stack, int data)
{
    if (!array_stack_is_full(stack)) {
        return array_stack_push(stack, data);
    }
    
    int *temp = (int *)malloc(2 * stack->size * sizeof(int));
    if (temp == NULL) {
        return -1;
    }
    
    memcpy(temp, stack->array, stack->size * sizeof(int));
    free(stack->array);
    
    stack->array = temp;
    stack->size = 2 * stack->size;
    stack->pos++;
    stack->array[stack->pos] = data;
    
    return 0;
}

/**
 遍历栈

 @param stack 栈
 */
void array_stack_dump(ArrayStack *stack)
{
    if (array_stack_is_empty(stack)) {
        printf("栈空\n");
        return ;
    }
    
    printf("打印栈size=%d,pos=%d\n",stack->size,stack->pos);
    for (int i = 0; i <= stack->pos; i++) {
        printf("array[%d] = %d\n",i,stack->array[i]);
    }
}

/**
 测试栈
 */
void array_stack_test()
{
    ArrayStack *stack = array_stack_create(4);
    if (stack == NULL) {
        printf("创建失败\n");
    }
    
    for (int i = 0; i < 5; i++) {
        int ret = array_stack_push(stack, i);
        if (ret != 0) {
            printf("入栈失败 %d\n",i);
        }
    }
    
    array_stack_dump(stack);
    
    int ret = array_stack_push_new(stack, 4);
    if (ret != 0) {
        printf("入栈失败\n");
    }
    array_stack_dump(stack);
    
    array_stack_destory(stack);
}
