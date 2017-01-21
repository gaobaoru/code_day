题目描述

Given a binary tree, determine if it is height-balanced. 

For this problem, a height-balanced binary tree is defined as a binary tree in which 
the depth of the two subtrees of every node never differ by more than 1. 

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
    bool isBalanced(TreeNode *root) {
        return balancedHeight(root)>=0;
    }
    
    int balancedHeight(TreeNode *root){
        if(root == nullptr) return 0;
        
        int left = balancedHeight(root->left);
        int right = balancedHeight(root->right);
        
        if(left < 0 || right < 0 || abs(left-right) > 1) return -1;
        
        return max(left, right)+1;
    }
};
