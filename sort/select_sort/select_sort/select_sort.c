//
//  select_sort.c
//  select_sort
//
//  Created by liyoucheng on 2018/10/24.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "select_sort.h"

/**
 选择排序
 
 @param a 原数组
 @param len 数组长度
 */
void selectSort(int a[], int len)
{
    for (int i = 0; i < len - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

/**
 测试选择排序
 */
void testSelectSort()
{
    int arr[8] = { 19, 3, 10, 9, 16, 11, 28, 26 };
    int len = sizeof(arr)/ sizeof(arr[0]);
    
    printf("选择排序前:");
    for (int i = 0; i < len; i++) {
        printf("%d ",arr[i]);
    }
    
    selectSort(arr, len);
    
    printf("\n选择排序后:");
    for (int i = 0; i < len; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
