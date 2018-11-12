//
//  leetCode-0050.c
//  leetCode-0050
//
//  Created by liyoucheng on 2018/11/12.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0050.h"

double myPow(double x, int n)
{
    double res = 1.0;
    int index = n;
    while (index != 0) {
        if (index % 2 != 0) {
            res *= x;
        }
        x *= x;
        index /= 2;
    }
    
    return n < 0 ? 1 / res : res;
}

//double myPow(double x, int n)
//{
//    if (n == 0) {
//        return 1;
//    }
//
//    double half = myPow(x, n / 2);
//    if (n % 2 == 0) {
//         return half * half;
//    }
//    else if (n > 0) {
//        return half * half * x;
//    }
//    else {
//        return half * half / x;
//    }
//}

void test()
{
    double ret = myPow(2.0, 10);
    printf("%.6f\n",ret);
}
