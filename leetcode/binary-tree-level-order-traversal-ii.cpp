题目描述





Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root). 

For example:
 Given binary tree{3,9,20,#,#,15,7}, 
    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as: 
[
  [15,7]
  [9,20],
  [3],
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        traversal(root, 1, result);
        std::reverse(result.begin(), result.end());
        return result;
    }
    
    void traversal(TreeNode *root, size_t level,vector<vector<int> > &result){
        if(!root) return;
        
        if(level > result.size()){
            result.push_back(vector<int>());
        }
        
        result[level-1].push_back(root->val);
        traversal(root->left, level+1, result);
        traversal(root->right, level+1, result);
    }
};
