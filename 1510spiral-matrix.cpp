题目描述


Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return[1,2,3,6,9,8,7,4,5]. 

class Solution {
public:
    //时间复杂度Ｏ(n^2), 空间复杂度Ｏ(1)
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if(matrix.empty()) return result;
        int beginX = 0, endX = matrix.size()-1;
        int beginY = 0, endY = matrix[0].size()-1;
        while(1){
            //from left to right
            for(int i = beginY; i <= endY; ++i)
                result.push_back(matrix[beginX][i]);
            if(++beginX > endX) break;
            //from top to down
            for(int j = beginX; j <= endX; ++j)
                result.push_back(matrix[j][endY]);
            if(--endY < beginY) break;
            //from right to left
            for(int i = endY; i >= beginY; --i)
                result.push_back(matrix[endX][i]);
            if(--endX < beginX) break;
            //from down to top
            for(int j = endX; j>= beginX; --j)
                result.push_back(matrix[j][beginY]);
            if(++beginY > endY) break;
        }
        return result;
    }
};
