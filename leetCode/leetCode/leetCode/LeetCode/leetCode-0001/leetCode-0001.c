//
//  leetCode-0001.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/16.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0001.h"

#include <stdlib.h>
#include <string.h>

struct object {
    int key;
    int value;
};

int compare(const void *a, const void *b) {
    return ((struct object*)a)->value - ((struct object*)b)->value;
}

int* twoSum(int* nums, int numsSize, int target) {
    struct object *objs = (struct object*)malloc(sizeof(*objs) * numsSize);
    for(int i = 0; i < numsSize; i++) {
        objs[i].key = i;
        objs[i].value = nums[i];
    }
    
    qsort(objs, numsSize, sizeof(*objs), compare);
    
    int i = 0;
    int j = numsSize - 1;
    while (i < j) {
        int diff = target - objs[i].value;
        if (diff < objs[j].value) {
            while (--j > i && objs[j].value == objs[j + 1].value) {
                
            }
        }
        else if (diff > objs[j].value) {
            while (++i < j && objs[i].value == objs[i - 1].value) {
                
            }
        }
        else {
            int *ret = (int *)malloc(sizeof(int) * 2);
            ret[0] = objs[i].key;
            ret[1] = objs[j].key;
            return ret;
        }
    }
    
    return NULL;
}

void test_0001() {
    int nums[5] = { 2, 7, 11, 15 };
    int target = 9;
    int *ret = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target);
    printf("%d->%d\n",ret[0],ret[1]);
}

