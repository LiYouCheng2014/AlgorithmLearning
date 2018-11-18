//
//  leetCode-0004.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/16.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0004.h"

double find_kth(int a[], int alen, int b[], int blen, int k)
{
    if (alen > blen) {
        return find_kth(b, blen, a, alen, k);
    }
    
    if (alen == 0) {
        return b[k - 1];
    }
    
    if (k == 1) {
        return a[0] < b[0] ? a[0] : b[0];
    }
    
    int ia = k / 2 < alen ? k / 2 : alen;
    int ib = k - ia;
    if (a[ia - 1] < b[ib - 1]) {
        return find_kth(a + ia, alen - ia, b, blen, k - ia);
    }
    else if (a[ia - 1] > b[ib - 1]) {
        return find_kth(a, alen, b + ib, blen - ib, k - ib);
    }
    else {
        return a[ia - 1];
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    int half = (nums1Size + nums2Size) / 2;
    if ((nums1Size + nums2Size) & 0x1) {
        return find_kth(nums1, nums1Size, nums2, nums2Size, half + 1);
    }
    else {
        return (find_kth(nums1, nums1Size, nums2, nums2Size, half) + find_kth(nums1, nums1Size, nums2, nums2Size, half + 1)) / 2;
    }
}

void test_0004() {
    int nums1[2] = { 1, 2 };
    int nums2[2] = { 3, 4 };
    double m = findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(nums1[0]), nums2, sizeof(nums2) / sizeof(nums2[0]));
    printf("%f\n",m);
}

