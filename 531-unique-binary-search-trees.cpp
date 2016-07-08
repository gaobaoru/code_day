题目描述

Given n, how many structurally unique BST's (binary search trees) that store values 1...n? 

For example,
 Given n = 3, there are a total of 5 unique BST's. 
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

时间复杂度O（n^2）,空间复杂度O（n）
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n+1, 0);
        f[0] = 1;
        f[1] = 1;
        for(int i=2;i<=n;++i){
            for(int k=1;k<=i;++k){
                f[i] += f[k-1]*f[i-k];
            }
        }
        return f[n];
    }
};
