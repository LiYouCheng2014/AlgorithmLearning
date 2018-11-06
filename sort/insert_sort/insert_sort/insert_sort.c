//
//  insert_sort.c
//  insert_sort
//
//  Created by liyoucheng on 2018/10/24.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "insert_sort.h"


/**
 插入排序
 
 @param a 原数组
 @param len 数组长度
 */
void insertSort(int a[], int len)
{
    for (int i = 1; i < len; i++) {
        int t = a[i];
        int j = 0;
        for (j = i - 1; j >= 0; j--) {
            if (t < a[j]) {
                a[j + 1] = a[j];
            }
            else {
                break;
            }
        }
        a[j + 1] = t;
    }
}

/**
 测试插入排序
 */
void testInsertSort()
{
    int arr[8] = { 19, 3, 10, 9, 16, 11, 28, 26 };
    int len = sizeof(arr)/ sizeof(arr[0]);
    
    printf("插入排序前:");
    for (int i = 0; i < len; i++) {
        printf("%d ",arr[i]);
    }
    
    insertSort(arr, len);
    
    printf("\n插入排序后:");
    for (int i = 0; i < len; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

