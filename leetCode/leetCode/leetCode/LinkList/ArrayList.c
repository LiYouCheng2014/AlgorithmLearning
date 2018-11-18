//
//  ArrayList.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "ArrayList.h"

#include "List.h"

Status al_GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length) {
        return ERROR;
    }
    
    *e = L.data[i - 1];
    return OK;
}

Status al_ListInsert(SqList *L, int i, ElemType e)
{
    if (L->length == MAXSIZE) {
        return ERROR;
    }
    
    if (i < 1 || i > L->length + 1) {
        return ERROR;
    }
    
    if (i <= L->length) {
        for (int k = L->length - 1; k >= i - 1; k--) {
            L->data[k + 1] = L->data[k];
        }
    }
    
    L->data[i - 1] = e;
    L->length++;
    
    return OK;
}

Status al_ListDelete(SqList *L, int i, ElemType *e)
{
    if (L->length == 0) {
        return ERROR;
    }
    
    if (i < 1 || i > L->length) {
        return ERROR;
    }
    
    *e = L->data[i - 1];
    if (i < L->length) {
        for (int k = i; k < L->length; k++) {
            L->data[k - 1] = L->data[k];
        }
    }
    L->length--;
    return OK;
}
