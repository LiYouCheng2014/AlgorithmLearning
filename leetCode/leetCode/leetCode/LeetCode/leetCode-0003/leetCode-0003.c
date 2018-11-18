//
//  leetCode-0003.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/16.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0003.h"

#include <string.h>

#define max(a,b) (a > b ? a : b)

int lengthOfLongestSubstring(char* s) {
    int m[128];
    memset(m, 0xff, sizeof(m));
    
    int len = 0;
    int index = 0;
    int maxLen = 0;
    while (*s != '\0') {
        if (m[*s] == -1) {
            len++;
        }
        else {
            if (index - m[*s] > len) {
                len++;
            }
            else {
                len = index - m[*s];
            }
        }
        
        if (len > maxLen) {
            maxLen = len;
        }
        m[*s++] = index++;
    }
    
    return maxLen;
}

void test_0003() {
    char *s = "abcabcbb";
    int len = lengthOfLongestSubstring(s);
    printf("%d\n",len);
}
