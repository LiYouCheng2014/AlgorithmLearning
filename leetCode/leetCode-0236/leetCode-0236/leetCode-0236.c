//
//  leetCode-0236.c
//  leetCode-0236
//
//  Created by liyoucheng on 2018/11/10.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0236.h"

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

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) {
        return NULL;
    }
    
    if (!root || p == root || q == root) {
        return root;
    }
    
    struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *right = lowestCommonAncestor(root->right, p , q);
    
    if (left && right) {
        return root;
    }
    
    return left ? left : right;
}

void test()
{
//    //    356##27##4##10##8##
//    struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//    p->val = 5;
//
//    struct TreeNode *q = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//    q->val = 1;
//
//    struct TreeNode *tree = createTree();
    struct TreeNode root, node1, node2, node11, node12, node21, node22, node121, node122;
    root.val = 3;
    node1.val = 5;
    node2.val = 1;
    node11.val = 0;
    node12.val = 4;
    node21.val = 7;
    node22.val = 9;
    node121.val = 3;
    node122.val = 5;
    root.left = &node1;
    root.right = &node2;
    node1.left = &node11;
    node1.right = &node12;
    node2.left = &node21;
    node2.right = &node22;
    node11.left = NULL;
    node11.right = NULL;
    node12.left = &node121;
    node12.right = &node122;
    node21.left = NULL;
    node21.right = NULL;
    node22.left = NULL;
    node22.right = NULL;
    node121.left = NULL;
    node121.right = NULL;
    node122.left = NULL;
    node122.right = NULL;
    
    struct TreeNode *ancestor = lowestCommonAncestor(&root, &node11, &node22);
    printf("公共祖先 %d\n",ancestor->val);
}
