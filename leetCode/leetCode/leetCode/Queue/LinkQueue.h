//
//  LinkQueue.h
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef LinkQueue_h
#define LinkQueue_h

#include <stdio.h>

#include "Queue.h"

Status lq_QueueIsEmpty(LinkQueue *Q);

int lq_QueueLength(LinkQueue *Q);

LinkQueue *lq_InitQueue(void);

Status lq_EnQueue(LinkQueue *Q, QElemType e);

Status lq_DeQueue(LinkQueue *Q, QElemType *e);


/**
 测试
 */
void test(void);

#endif /* LinkQueue_h */
