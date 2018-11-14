//
//  leetCode-0169.c
//  leetCode-0169
//
//  Created by liyoucheng on 2018/11/13.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0169.h"

int majorityElement(int* nums, int numsSize) {
    int major = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            major = nums[i];
            count += 1;
        }
        else if (major == nums[i]) {
            count += 1;
        }
        else {
            count -= 1;
        }
    }
    return major;
}

void test()
{
//    int arr[7] = { 2,2,1,1,1,2,2 };
    int arr[3] = { 3,2,3 };
    int ret = majorityElement(arr, 3);
    printf("ret = %d\n", ret);
}
