//
//  buble_sort.c
//  buble_sort
//
//  Created by liyoucheng on 2018/10/24.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "buble_sort.h"

#include <stdbool.h>

/**
 冒泡排序
 
 @param a 原数组
 @param len 数组长度
 */
void bubbleSort(int a[], int len)
{
    for (int i = 0; i < len; i++) {
        for (int j = len - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

/**
 冒泡排序优化
 
 @param a 原数组
 @param len 数组长度
 */
void bubbleOptimizationSort(int a[], int len)
{
    int flag = 1;
    for (int i = 0; i < len && flag == 1; i++) {
        flag = 0;
        for (int j = len - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                
                flag = 1;
            }
        }
    }
}

/**
 测试冒泡排序
 */
void testBubbleSort()
{
    int arr[8] = { 19, 3, 10, 9, 16, 11, 28, 26 };
    int len = sizeof(arr)/ sizeof(arr[0]);
    
    printf("冒泡排序前:");
    for (int i = 0; i < len; i++) {
        printf("%d ",arr[i]);
    }
    
    //    bubbleSort(arr, len);
    
    //优化的冒泡排序
    bubbleOptimizationSort(arr, len);
    
    printf("\n冒泡排序后:");
    for (int i = 0; i < len; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
