//
//  leetCode-0020.c
//  leetCode-0020
//
//  Created by liyoucheng on 2018/10/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0020.h"

#include <stdbool.h>

bool isValid(char* s) {
    //栈
    char a[10000];
    int top = -1;
    int i = 0;
    
    while(*s != '\0') {
        if (*s == '[' || *s == '{' || *s == '(') {
            a[i] = *s;
            i++;
            top++;
        }
        else if (*s == ']') {
            if (i != 0 && a[--i] == '[') {
                top--;
            }
            else {
                return false;
            }
        }
        else if (*s == '}') {
            if (i != 0 && a[--i] == '{') {
                top--;
            }
            else {
                return false;
            }
        }
        else if (*s == ')') {
            if (i != 0 && a[--i] == '(') {
                top--;
            }
            else {
                return false;
            }
        }
        s++;
    }
    return top == -1;
}

void test(void)
{
    int flag = isValid("{[]}");
    printf("flag = %d\n",flag);
}
