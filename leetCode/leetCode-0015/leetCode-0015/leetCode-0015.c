//
//  leetCode-0015.c
//  leetCode-0015
//
//  Created by liyoucheng on 2018/11/6.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0015.h"

#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

//计算两数之和在i和j之内等于target
void two_sum(int *nums, int i, int j, int target, int **results, int *count) {
    while (i < j) {
        int diff = target - nums[i];
        if (diff < nums[j]) {
            while (--j > i && nums[j] == nums[j + 1]) {}
        } else if (diff > nums[j]) {
            while (++i < j && nums[i] == nums[i - 1]) {}
        } else {
            results[*count] = malloc(3 * sizeof(int));
            results[*count][0] = -target;
            results[*count][1] = nums[i];
            results[*count][2] = nums[j];
            (*count)++;
            
            while (++i < j && nums[i] == nums[i - 1]) {}
            while (--j > i && nums[j] == nums[j + 1]) {}
        }
    }
}

//计算三数之和
int** threeSum(int* nums, int numsSize, int* returnSize) {
    if (numsSize < 3) {
        return NULL;
    }
    
    qsort(nums, numsSize, sizeof(*nums), compare);
    
    *returnSize = 0;
    int **results = malloc(sizeof(int *) * (((numsSize * (numsSize - 1) * (numsSize - 2))) / (3 * 2 * 1)));
    for (int i = 0; i < numsSize; i++) {
        if (i == 0 || i > 0 && nums[i] != nums[i - 1]) {
            //加上大于0判断，优化
            two_sum(nums, i + 1, numsSize - 1, -nums[i], results, returnSize);
        }
    }
    
    return results;
}
void test()
{
//    int arr[6] = { -1, 0, 1, 2, -1, -4 };
    int arr[4] = { 1, 2, -2, -1 };
    int count = 0;
    int **ret = threeSum(arr, 4, &count);
    
    if (ret) {
        for (int i = 0; i < count; i++) {
            int *temp = ret[i];
            printf("%d->%d->%d\n",temp[0],temp[1],temp[2]);
        }
        
    }
}
