//
//  leetCode-0104.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0104.h"

#include "Tree.h"

int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    return max(maxDepth(root->left),maxDepth(root->right)) + 1;
}
