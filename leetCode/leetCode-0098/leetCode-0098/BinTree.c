//
//  BinTree.c
//  leetCode-0098
//
//  Created by liyoucheng on 2018/11/8.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "BinTree.h"

#include "TreeNode.h"

#include <stdlib.h>

////创建树
//struct TreeNode *createTree()
//{
//    struct TreeNode *tree;
//    char str = getchar();
//    if (str == '#') {
//        tree = NULL;
//    }
//    else {
//        tree = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//        tree->val = str;
//        tree->left = createTree();
//        tree->right = createTree();
//    }
//    return tree;
//}
//
////先序 根左右
//void preOrderTraversal(struct TreeNode * bt)
//{
//    if (bt) {
//        printf("%c ",bt->val);
//        preOrderTraversal(bt->left);
//        preOrderTraversal(bt->right);
//    }
//}
//
////中序 左根右
//void inOrderTraversal(struct TreeNode * bt)
//{
//    if (bt) {
//        inOrderTraversal(bt->left);
//        printf("%c ",bt->val);
//        inOrderTraversal(bt->right);
//    }
//}
//
////后序 左右根
//void postOrderTraversal(struct TreeNode * bt)
//{
//    if (bt) {
//        postOrderTraversal(bt->left);
//        postOrderTraversal(bt->right);
//        printf("%c ",bt->val);
//    }
//}
//
//void test()
//{
////    ABD#G###CE##FH###
////    51##43##6##
//    struct TreeNode *tree = createTree();
//    printf("先序递归遍历:");
//    preOrderTraversal(tree);
//    printf("\n");
//    
//    printf("中序递归遍历:");
//    inOrderTraversal(tree);
//    printf("\n");
//    
//    printf("后序递归遍历:");
//    postOrderTraversal(tree);
//    printf("\n");
//}
