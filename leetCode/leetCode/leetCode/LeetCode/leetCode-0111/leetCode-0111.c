//
//  leetCode-0111.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0111.h"

#include "Tree.h"


int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    
    if (left == 0 || right == 0) {
        return left + right + 1;
    }
    else {
        return min(left, right) + 1;
    }
}

