题目描述


Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node. 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//时间复杂度为O(n),空间复杂度为(logn)
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == nullptr) return 0;
        return max(maxDepth(root->left) , maxDepth(root->right)) + 1;
    }
};
