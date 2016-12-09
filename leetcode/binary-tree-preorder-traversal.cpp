题目描述

Given a binary tree, return the preorder traversal of its nodes' values. 

For example:
 Given binary tree{1,#,2,3}, 
   1
    \
     2
    /
   3

return[1,2,3]. 

Note: Recursive solution is trivial, could you do it iteratively? 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 时间复杂度O（n）,空间复杂度O（n）
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<const TreeNode *> s;
        if(root != nullptr) s.push(root);
        
        while(!s.empty()){
            const TreeNode *p = s.top();
            s.pop();
            result.push_back(p->val);
            
            if(p->right != nullptr) s.push(p->right);
            if(p->left != nullptr) s.push(p->left);
            
        }
        return result;
    }
};
