题目描述

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:

Given the below binary tree andsum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]

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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> cur;
        PathSum(root, sum, cur, result);
        return result;
    }
private:
    void PathSum(TreeNode* root, int gap, vector<int>& cur,vector<vector<int> >& result){
        if(root == nullptr) return;
        cur.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(gap == root->val)
                result.push_back(cur);
        }
        PathSum(root->left, gap - root->val, cur, result);
        PathSum(root->right, gap - root->val, cur, result);
        cur.pop_back();
    }
};
