//
//  leetCode-0235.c
//  leetCode-0235
//
//  Created by liyoucheng on 2018/11/10.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0235.h"

#include "TreeNode.h"
#include <stdbool.h>

bool max(int a, int b) {
    return a > b ? a : b;
}

bool min(int a, int b) {
    return a < b ? a : b;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root->val == p->val || root->val == q->val) {
        return root;
    }
    else if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    else if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    else {
        return root;
    }
}

void test()
{
    struct TreeNode root, node1, node2, node11, node12, node21, node22, node121, node122;
    root.val = 6;
    node1.val =2;
    node2.val = 8;
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
    printf("二叉搜索公共祖先 %d\n",ancestor->val);
}


//struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
//    if (!root) {
//        return NULL;
//    }
//
//    if (root->val > max(p->val, q->val)) {
//        return lowestCommonAncestor(root->left, p, q);
//    }
//    else if (root->val < min(p->val, q->val)) {
//        return lowestCommonAncestor(root->right, p, q);
//    }
//    else {
//        return root;
//    }
//}


//return root;
