题目描述

Given a binary tree containing digits from0-9only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path1->2->3which represents the number123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3


The root-to-leaf path1->2represents the number12.
The root-to-leaf path1->3represents the number13.

Return the sum = 12 + 13 =25.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//时间复杂度为O(n),空间复杂度为O(logn)
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return dfs(root, 0);
    }
private:
    int dfs(TreeNode* root, int sum){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr){
            return sum*10 + root->val;
        }
        return dfs(root->left, sum*10+root->val) + 
            dfs(root->right, sum*10+root->val);
    }
};
