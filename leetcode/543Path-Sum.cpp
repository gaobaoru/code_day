题目描述

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree andsum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//时间复杂度O(n),空间复杂度O(logn)
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
    	if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr)
            return sum==root->val;
        return hasPathSum(root->left, sum - root->val)
            || hasPathSum(root->right, sum - root->val);
    }
};
