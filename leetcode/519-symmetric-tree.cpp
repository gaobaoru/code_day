题目描述

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center). 

For example, this binary tree is symmetric: 
    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not: 
    1
   / \
  2   2
   \   \
   3    3

Note:
 Bonus points if you could solve it both recursively and iteratively. 

confused what"{1,#,2,3}"means? > read more on how binary tree is serialized on OJ. 

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
    bool isSymmetric(TreeNode *root) {
        if(root == nullptr) return true;
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode *p, TreeNode *q){
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        return (p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left));
    }
};
