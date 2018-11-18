//
//  StaticList.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "StaticList.h"

Status sl_InitList(StaticLinkList space)
{
    for (int i = 0; i < MAXSIZE - 1; i++) {
        space[i].cur = i + 1;
    }
    space[MAXSIZE - 1].cur = 0;
    return OK;
}

int sl_Malloc_SLL(StaticLinkList space)
{
    int i = space[0].cur;
    if (space[0].cur) {
        space[0].cur = space[i].cur;
    }
    return i;
}

int sl_ListLength(StaticLinkList L)
{
    int i = L[MAXSIZE - 1].cur;
    int j = 0;
    while (i) {
        i = L[i].cur;
        j++;
    }
    return j;
}

Status sl_ListInsert(StaticLinkList L, int i, ElemType e)
{
    int k = MAXSIZE - 1;
    if (i < 1 || i > sl_ListLength(L) + 1 ) {
        return ERROR;
    }
    
    int j = sl_Malloc_SLL(L);
    if (j) {
        L[j].data = e;
        for (int l = 1; l <= i - 1; l++) {
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    
    return ERROR;
}

void sl_Free_SSL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

Status sl_ListDelete(StaticLinkList L, int i)
{
    if (i < 1 || i > sl_ListLength(L)) {
        return ERROR;
    }
    
    int k = MAXSIZE - 1;
    int j = 0;
    for (int j = 1; j <= i - 1; j++) {
        k = L[k].cur;
    }
    j = L[k].cur;
    L[k].cur = L[j].cur;
    sl_Free_SSL(L, j);
    
    return ERROR;
}
