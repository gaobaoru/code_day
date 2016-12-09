题目描述

Given a binary tree 
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set toNULL. 

Initially, all next pointers are set toNULL. 

Note: 
You may only use constant extra space. 
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children). 

For example,
 Given the following perfect binary tree, 
         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like: 
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 时间复杂度O（n）,空间复杂度O（1）
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr) return;
        TreeLinkNode dummy(-1);
        
        for(TreeLinkNode *cur = root, *prev = &dummy; cur; cur = cur->next){
            if(cur->left != nullptr){
                prev->next = cur->left;
                prev = prev->next;
            }
            if(cur->right != nullptr){
                prev->next = cur->right;
                prev = prev->next;
            }
        }
        connect(dummy.next);
    }
};
