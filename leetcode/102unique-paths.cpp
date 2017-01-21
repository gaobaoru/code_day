题目描述


A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100. 

class Solution {
public:
    //时间复杂度Ｏ(n^2),空间复杂度Ｏ(n)
    int uniquePaths(int m, int n) {
        vector<int> f(n,0);
        f[0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                f[j] = f[j] + f[j-1];
            }
        }
        return f[n-1];
    }
};
