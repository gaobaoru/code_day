

对于两棵彼此独立的二叉树A和B，请编写一个高效算法，检查A中是否存在一棵子树与B树的拓扑结构完全相同。

给定两棵二叉树的头结点A和B，请返回一个bool值，代表A中是否存在一棵同构于B的子树。
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
 
class IdenticalTree {
public:
    bool chkIdentical(TreeNode* A, TreeNode* B) {
        // write code here
        string strA, strB;
        tree_to_str(A, strA);
        tree_to_str(B, strB);
        if(strB.size() == 0){
            return true;
        }else{
            if(string::npos != strA.find(strB)){
                return true;
            }else{
                return false;
            }
        }
    }
     
    void tree_to_str(TreeNode* root, string &str){
        if(root == NULL || root->val == 0){
            str.push_back('#');
            str.push_back(' ');
            return;
        }
        else{
            str.push_back(root->val + '0');
            str.push_back(' ');
            tree_to_str(root->left, str);
            tree_to_str(root->right, str);
        }
    }
};
