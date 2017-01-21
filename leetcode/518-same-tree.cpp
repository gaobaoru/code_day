题目描述

Given two binary trees, write a function to check if they are equal or not. 

Two binary trees are considered equal if they are structurally identical and the nodes have the same value. 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 时间复杂度O（n）,空间复杂度O（logn）
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        return (p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
