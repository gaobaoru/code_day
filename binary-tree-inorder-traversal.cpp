题目描述

Given a binary tree, return the inorder traversal of its nodes' values. 

For example:
 Given binary tree{1,#,2,3}, 
   1
    \
     2
    /
   3

return[1,3,2]. 

Note: Recursive solution is trivial, could you do it iteratively? 

confused what"{1,#,2,3}"means? > read more on how binary tree is serialized on OJ. 


OJ's Binary Tree Serialization: 
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below. 

Here's an example: 
   1
  / \
 2   3
    /
   4
    \
     5

The above binary tree is serialized as"{1,2,3,#,#,4,#,#,5}". 

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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while(!s.empty() || p != nullptr){
            if(p != nullptr){
                s.push(p);
                p = p->left;
            }else{
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result;
    }
};
