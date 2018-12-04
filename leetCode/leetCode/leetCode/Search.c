//
//  Search.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/25.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "Search.h"

int Sequential_Search(int *a, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return 0;
}

int Sequential_Search2(int *a, int n, int key) {
    a[0] = key;
    int i = n;
    while (a[i] != key) {
        i--;
    }

    return i;
}
