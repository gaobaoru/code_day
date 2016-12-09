题目描述

 Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as1and0respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is2.

Note: m and n will be at most 100. 

class Solution {
public:
    //时间复杂度Ｏ(n^2),空间复杂度Ｏ(n)
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        
        vector<int> f(n,0);
        f[0] = obstacleGrid[0][0] ? 0 : 1;
        for(int i = 0; i < m; i++){
            f[0] = f[0]==0 ? 0 : (obstacleGrid[i][0] ? 0 : 1);
            for(int j = 1; j < n; j++){
                f[j] = obstacleGrid[i][j] ? 0 : (f[j] + f[j-1]);
            }
        }
        return f[n-1];
    }
};
