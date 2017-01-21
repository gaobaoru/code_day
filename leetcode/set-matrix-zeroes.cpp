题目描述

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place. 

click to show follow up. 

Follow up: 
Did you use extra space?
 A straight forward solution using O(mn) space is probably a bad idea.
 A simple improvement uses O(m + n) space, but still not the best solution.
 Could you devise a constant space solution? 

时间复杂度O（m*n）,空间复杂度O（m+n）
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        
        vector<int> row(m, false);
        vector<int> column(n, false);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j]==0)
                    row[i] = column[j] = true;
            }
        }
        
        for(int i = 0; i < m; i++){
            if(row[i]){
                for(int j = 0; j < n; j++)
                    matrix[i][j] = 0;
            }
        }
        
        for(int j = 0; j < n; j++){
            if(column[j]){
                for(int i = 0; i < m; i++)
                    matrix[i][j] = 0;
            }
        }
    }
};
