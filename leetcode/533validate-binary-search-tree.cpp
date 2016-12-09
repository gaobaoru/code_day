题目描述


Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.


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
class Solution {
public:
    //时间复杂度Ｏ(n),空间复杂度Ｏ(logn)
    bool isValidBST(TreeNode *root) {
        return isValid(root, INT_MIN, INT_MAX);
    }
    
    bool isValid(TreeNode* root, int lower, int upper){
        if(root == nullptr) return true;
        return root->val > lower && root->val < upper
            && isValid(root->left, lower, root->val)
            && isValid(root->right, root->val, upper);
    }
};
