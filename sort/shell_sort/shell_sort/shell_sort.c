//
//  shell_sort.c
//  shell_sort
//
//  Created by liyoucheng on 2018/10/24.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "shell_sort.h"

/**
 希尔排序
 
 @param a 原数组
 @param len 数组长度
 */
void shellSort(int a[], int len)
{
    int d = len / 2;
    while (d >= 1) {
        for (int i = d; i < len; i++) {
            //序列中的下一个数据
            int x = a[i];
            //序列中前一个数据的序号
            int j = i - d;
            //下一个数大于前一个数
            while (j >= 0 && a[j] > x) {
                //后一个数向前移动
                a[j + d] = a[j];
                //向前比较
                j = j - d;
            }
            //保存数据
            a[j + d] = x;
        }
        //缩小增量
        d /= 2;
    }
    
}

/**
 测试希尔排序
 */
void testShellSort()
{
    int arr[8] = { 19, 3, 10, 9, 16, 11, 28, 26 };
    int len = sizeof(arr)/ sizeof(arr[0]);
    
    printf("希尔排序前:");
    for (int i = 0; i < len; i++) {
        printf("%d ",arr[i]);
    }
    
    shellSort(arr, len);
    
    printf("\n希尔排序后:");
    for (int i = 0; i < len; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
