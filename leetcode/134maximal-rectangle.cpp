题目描述


Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area. 

class Solution {
public:
    //时间复杂度Ｏ(n^2),空间复杂度Ｏ(n)
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<int> H(n, 0);
        vector<int> L(n, 0);
        vector<int> R(n, n);
        
        int ret = 0;
        for(int i = 0; i < m; i++){
            int left = 0, right = n;
            //from left to right
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    ++H[j];
                    L[j] = max(L[j], left);
                }else{
                    left = j + 1;
                    H[j] = 0;
                    L[j] = 0;
                    R[j] = n;
                }
            }
            //from right to left
            for(int j = n - 1; j >= 0; j--){
                if(matrix[i][j] == '1'){
                    R[j] = min(R[j], right);
                    ret = max(ret, H[j] * (R[j] - L[j]));
                }else{
                    right = j;
                }
            }
        }
        return ret;
    }
};
