//
//  leetCode-0098.c
//  leetCode-0098
//
//  Created by liyoucheng on 2018/11/8.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0098.h"

#include "TreeNode.h"
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>


//创建树
struct TreeNode *createTree()
{
    struct TreeNode *tree;
    char str = getchar();
    if (str == '#') {
        tree = NULL;
    }
    else {
        tree = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        tree->val = str;
        tree->left = createTree();
        tree->right = createTree();
    }
    return tree;
}

struct TreeNode *pre;
void inOrder(struct TreeNode *root, int *res)
{
    if (!root) {
        return;
    }
    
    inOrder(root->left, res);
    if (!pre) {
        pre = root;
    }
    else {
        if (root->val <= pre->val) {
            *res = 0;
        }
        pre = root;
    }
    inOrder(root->right, res);
}

bool isValidBST(struct TreeNode* root) {
    int res = 1;
    pre = NULL;
    inOrder(root, &res);
    if (res == 1) {
        return true;
    }
    return false;
}

//bool isValid_BST(struct TreeNode *root, long min, long max)
//{
//    if (!root) {
//        return true;
//    }
//
//    if (root->val <= min || root->val >= max) {
//        return false;
//    }
//
//    return isValid_BST(root->left, min, root->val) && isValid_BST(root->right, root->val, max);
//}
//
//bool isValidBST(struct TreeNode* root) {
//    return isValid_BST(root, LONG_MIN, LONG_MAX);
//}


void test()
{
    //    51##43##6##
//    21##3##
    struct TreeNode *tree = createTree();
    bool isBST = isValidBST(tree);
    printf("是否排序二叉树 %d\n",isBST);
}
