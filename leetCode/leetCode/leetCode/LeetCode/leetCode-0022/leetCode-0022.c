//
//  leetCode-0022.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0022.h"

#include <stdlib.h>
#include <string.h>

void _gen(char *subStr, int subLen, char ***result, int *returnSize, int n, int left, int right) {
    if (left == 0 && right == 0) {
        //添加结果
        subStr[subLen] = '\0';
        subLen = 0;
        
        (*returnSize) += 1;
        (*result) = (char **)realloc((*result), sizeof(char *) * (*returnSize + 1));
        (*result)[*returnSize - 1] = (char *)malloc(sizeof(char) * (2 * n + 1));
        strcpy((*result)[*returnSize - 1], subStr);
        
        return;
    }
    
    if (left > 0) {
        //添加左括号
        subStr[subLen] = '(';
        _gen(subStr, subLen + 1, result, returnSize, n, left - 1, right);
    }
    
    if (right > left) {
        //添加右括号
        subStr[subLen] = ')';
        _gen(subStr, subLen + 1, result, returnSize, n, left, right - 1);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    char **result = (char **)malloc(sizeof(char *));
    *returnSize = 0;
    char *subStr = (char *)malloc((2 * n + 1) * sizeof(char));
    
    _gen(subStr, 0, &result, returnSize, n, n, n);
    
    return result;
}

void test()
{
    int count = 0;
    char **a = generateParenthesis(3, &count);
    for (int i = 0; i < count; i++) {
        char *s = a[i];
        for (int j = 0; j < strlen(s); j++) {
            printf("%c",s[j]);
        }
        printf("\n");
    }
}
