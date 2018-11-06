//
//  leetCode-0069.c
//  leetCode-0069
//
//  Created by liyoucheng on 2018/10/28.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0069.h"
#include <math.h>

int mySqrt(int x)
{
    int low = 0;
    int high = x;
    int ret = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid * mid <= x) {
            ret = mid;
            low = mid + 1;
        }
        else if (mid * mid > x) {
            high = mid - 1;
        }
    }
    return ret;
}

void test()
{
    int n = 1;
    int r = mySqrt(n);
    printf("%d\n",r);
}
