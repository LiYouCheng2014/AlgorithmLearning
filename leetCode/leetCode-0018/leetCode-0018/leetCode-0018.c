//
//  leetCode-0018.c
//  leetCode-0018
//
//  Created by liyoucheng on 2018/11/6.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0018.h"

#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

void k_sum(int *nums, int low, int high, int target, int total, int k, int *stack, int len, int **results, int *count) {
    if (k == 2) {
        while(low < high) {
            int diff = target - nums[low];
            if(diff > nums[high]) {
                while (++low < high && nums[low] == nums[low - 1]) {}
            } else if (diff < nums[high]) {
                while (--high > low && nums[high] == nums[high + 1]) {}
            } else {
                stack[len++] = nums[low];
                stack[len++] = nums[high];
                results[*count] = malloc(total * sizeof(int));
                memcpy(results[*count],stack,total * sizeof(int));
                (*count)++;
                len -= 2;
                //过滤重复
                while (++low < high && nums[low] == nums[low - 1]) {}
                while (--high > low && nums[high] == nums[high + 1]) {}
            }
        }
    }
    else {
        for (int i = low; i <= high - k + 1; i++) {
            if (i > low && nums[i] == nums[i - 1]) {
                continue;
            }
            stack[len++] = nums[i];
            k_sum(nums, i + 1, high, target - nums[i],total, k - 1, stack, len, results, count);
            len--;
        }
    }
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize){
    int len = 4;
    if (numsSize < len) {
        return NULL;
    }
    
    qsort(nums,numsSize,sizeof(*nums),compare);
    
    *returnSize = 0;
    int **results = malloc(sizeof(int *) * (((numsSize * (numsSize - 1) * (numsSize - 2))) / (3 * 2 * 1)));
    //临时存储
    int *stack = malloc(len * sizeof(int));
    k_sum(nums, 0, numsSize - 1, target, len, len, stack, 0, results, returnSize);
    
    return results;
}

void test()
{
    int arr[6] = { 1, 0, -1, 0, -2, 2 };
    int count = 0;
    int **ret = fourSum(arr, 6, 0, &count);
    
    if (ret) {
        for (int i = 0; i < count; i++) {
            int *temp = ret[i];
            printf("%d->%d->%d->%d\n",temp[0], temp[1], temp[2], temp[3]);
        }
        
    }
}
