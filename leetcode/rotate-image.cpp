题目描述

You are given an n x n 2D matrix representing an image. 

Rotate the image by 90 degrees (clockwise). 

Follow up:
 Could you do this in-place? 

先沿副对角线翻转一次，再沿水平中线旋转一次即可
时间复杂度O（n^2）,空间复杂度O（1）
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        const int n = matrix.size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - i; j++){
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
            }
        }
        
        for(int i = 0; i < n / 2; i++){
            for(int j = 0; j < n; j++){
                swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }
    }
};
