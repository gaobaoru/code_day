题目描述

Given a binary tree, return the postorder traversal of its nodes' values. 

For example:
 Given binary tree{1,#,2,3}, 
   1
    \
     2
    /
   3
   
return[3,2,1]. 

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<const TreeNode *> s;
        const TreeNode *p = root, *q = nullptr;
        do{
            while(p != nullptr){
                s.push(p);
                p = p->left;
            }
            
            q = nullptr;
            while(!s.empty()){
                p = s.top();
                s.pop();
                if(p->right == q){
                    result.push_back(p->val);
                    q = p;
                }else{
                    s.push(p);
                    p = p->right;
                    break;
                }
            }
        }while(!s.empty());
        return result;
    }
};

