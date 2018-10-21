//
//  array_queue.h
//  array_queue
//
//  Created by liyoucheng on 2018/10/20.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef array_queue_h
#define array_queue_h

#include <stdio.h>

typedef struct array_queue
{
    int size;//队列大小
    int num; //数据多少
    int head;//队头
    int tail;//队尾
    int *array;//数据存储区
}ArrayQueue;

void test(void);

#endif /* array_queue_h */
