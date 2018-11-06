//
//  leetCode-0215.c
//  leetCode-0215
//
//  Created by liyoucheng on 2018/11/4.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0215.h"

#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int left, int right)
{
    int i = left;
    int j = left;
    for (j = left; j < right; j++) {
        if (a[j] > a[right]) {
            if (i != j) {
                swap(a + i, a + j);
            }
            i++;
        }
    }
    
    swap(a + i, a + right);
    return i;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int left = 0;
    int right = numsSize - 1;
    while (true) {
        int pos = partition(nums, left, right);
        if (pos == k - 1) {
            return nums[pos];
        }
        else if (pos > k - 1) {
            right = pos - 1;
        }
        else {
            left = pos + 1;
        }
    }
}

/**
 测试
 */
void test()
{
    int arr1[6] = { 3, 2, 1, 5, 6, 4};
    int k1 = 2;
    int max1 = findKthLargest(arr1, 6, k1);
    printf("第%d大元素是%d\n",k1,max1);
    
    int arr[9] = { 3,2,3,1,2,4,5,5,6 };
    int k = 4;
    
    int max = findKthLargest(arr, 9, k);
    printf("第%d大元素是%d\n",k,max);
}
