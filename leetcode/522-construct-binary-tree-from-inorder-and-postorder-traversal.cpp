题目描述

Given inorder and postorder traversal of a tree, construct the binary tree. 

Note:
 You may assume that duplicates do not exist in the tree. 

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(begin(inorder), end(inorder), begin(postorder), end(postorder));
    }
    template<typename InputIterator>
    TreeNode *buildTree(InputIterator in_first, InputIterator in_last,
                       InputIterator post_first, InputIterator post_last){
        if(in_first == in_last) return nullptr;
        if(post_first == post_last) return nullptr;
        
        const auto val = *prev(post_last);//注意
        auto root = new TreeNode(val);
        auto inRootPos = find(in_first, in_last, val);
        auto leftSize = distance(in_first, inRootPos);
        
        root->left = buildTree(in_first, inRootPos,post_first,next(post_first,leftSize));
        root->right = buildTree(next(inRootPos),in_last, next(post_first,leftSize),prev(post_last));
        
        return root;
    }
};
