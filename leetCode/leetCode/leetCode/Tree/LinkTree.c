//
//  LinkTree.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "LinkTree.h"

#include "Tree.h"

#include <stdlib.h>

//struct TreeNode *createBitTree(int *arr)
//{
//    TElemType ch;
//    scanf("%c",&ch);
//    if (ch == '#') {
//        *T = NULL;
//    }
//    else {
//        *T = (BiTree)malloc(sizeof(BiTNode));
//        if (!*T) {
//            exit(OVERFLOW);
//        }
//        (*T)->data = ch;
//        CreateBiTree(&(*T)->lchild);
//        CreateBiTree(&(*T)->rchild);
//    }
//
//}

//void PreOrderTraverse(BiTree T)
//{
//    if (T == NULL) {
//        return;
//    }
//    printf("%c", T->data);
//    PreOrderTraverse(T->lchild);
//    PreOrderTraverse(T->rchild);
//}
//
//void InOrderTraverse(BiTree T)
//{
//    if (T == NULL) {
//        return;
//    }
//    PreOrderTraverse(T->lchild);
//    printf("%c", T->data);
//    PreOrderTraverse(T->rchild);
//}
//
//void PostOrderTraverse(BiTree T)
//{
//    if (T == NULL) {
//        return;
//    }
//    PreOrderTraverse(T->lchild);
//    PreOrderTraverse(T->rchild);
//    printf("%c", T->data);
//}
//
//void CreateBiTree(BiTree *T)
//{
//    TElemType ch;
//    scanf("%c",&ch);
//    if (ch == '#') {
//        *T = NULL;
//    }
//    else {
//        *T = (BiTree)malloc(sizeof(BiTNode));
//        if (!*T) {
//            exit(OVERFLOW);
//        }
//        (*T)->data = ch;
//        CreateBiTree(&(*T)->lchild);
//        CreateBiTree(&(*T)->rchild);
//    }
//}
//
//
//BiThrTree pre;
//void InThreading(BiThrTree p)
//{
//    if (p) {
//        InThreading(p->lchild);
//        if (!p->lchild) {
//            p->LTag = Thread;
//            p->lchild = pre;
//        }
//
//        if (!pre->rchild) {
//            pre->Rtag = Thread;
//            pre->rchild = p;
//        }
//
//        pre = p;
//        InThreading(p->rchild);
//    }
//}
//
//Status InOrderTraverse_Thr(BiThrTree T)
//{
//    BiThrTree p = T->lchild;
//    while (p != T) {
//        while (p->LTag == Link) {
//            p = p->lchild;
//        }
//        printf("%c",p->data);
//        while (p->Rtag == Thread && p->rchild != T) {
//            p = p->rchild;
//            printf("%c",p->data);
//        }
//        p = p->rchild;
//    }
//    return OK;
//}


