题目描述

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between). 

For example:
 Given binary tree{3,9,20,#,#,15,7}, 
    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as: 
[
  [3],
  [20,9],
  [15,7]
]
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
时间复杂度O（n）,空间复杂度O（n）
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        traversal(root, 1, result, true);
        return result;
    }
    
	void traversal(TreeNode *root, size_t level, vector<vector<int> > &result, bool left_to_right){
        if(!root) return;
        
        if(level > result.size()){
            result.push_back(vector<int>());
        }
        if(left_to_right){
            result[level-1].push_back(root->val);
        }else{
            result[level-1].insert(result[level-1].begin(), root->val);
        }
        traversal(root->left, level+1, result, !left_to_right);
        traversal(root->right, level+1, result, !left_to_right);
    }   
};
