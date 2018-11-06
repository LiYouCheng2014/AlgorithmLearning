//
//  merge_sort.c
//  merge_sort
//
//  Created by liyoucheng on 2018/10/25.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "merge_sort.h"

#include <stdlib.h>

/**
 合并两个有序数组
 
 @param a 原数组
 @param low 起始位
 @param mid 中间位
 @param high 终点位
 */
void merge(int a[], int low, int mid, int high)
{
    //申请临时合并区域
    int *temp = (int *)malloc(sizeof(int) * (high - low + 1));
    int i = low;
    int j = mid + 1;
    int k = 0;
    
    //合并左右区间
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
        }
    }
    
    //合并剩余左区间
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    
    //合并剩余右区间
    while (j <= high) {
        temp[k++] = a[j++];
    }
    
    //临时区域数组整合到原数组
    for (int i = 0; i < k; i++) {
        a[low + i] = temp[i];
    }
    
    free(temp);
}

/**
 数组合并
 
 @param a 原数组
 @param len 数组长度
 @param subLen 子数组长度
 */
void mergeGroups(int a[], int len, int subLen)
{
    int i = 0;
    //每两个相邻的子数组进行合并排序
    for (i = 0; i + 2 * subLen - 1 < len; i += (2 * subLen)) {
        merge(a, i, i + subLen - 1, i + 2 * subLen - 1);
    }
    
    //若i + subLen - 1 < len - 1，则剩余一个子数组未配对
    if (i + subLen - 1 < len - 1) {
        merge(a, i, i + subLen - 1, len - 1);
    }
}


/**
 归并排序 从下到上
 
 @param a 原数组
 @param len 数组长度
 */
void mergeSortDownToUp(int a[], int len)
{
    if (a == NULL || len <= 0) {
        return;
    }
    
    for (int i = 1; i < len; i *= 2) {
        mergeGroups(a, len, i);
    }
}

/**
 测试归并排序
 */
void testMergeSort()
{
    int arr[8] = { 19, 3, 10, 9, 16, 11, 28, 26 };
    int len = sizeof(arr)/ sizeof(arr[0]);
    
    printf("归并排序前:");
    for (int i = 0; i < len; i++) {
        printf("%d ",arr[i]);
    }
    
    //从上到下
    //    mergeSortUpToDown(arr, 0, len - 1);
    //从下到上
    mergeSortDownToUp(arr, len);
    
    printf("\n归并排序后:");
    for (int i = 0; i < len; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
