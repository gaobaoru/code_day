题目描述


Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:


    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.


For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target =3, returntrue. 

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty()) return false;
        const size_t m = matrix.size();
        const size_t n = matrix.front().size();
        
        int first = 0;
        int last = m*n - 1;
        while(first <= last){
            int mid = (first + last) / 2;
            int value = matrix[mid/n][mid%n];
            if(value == target) return true;
            else if(value < target) first = mid + 1;
            else last = mid - 1;
        }
        return false;
    }
};
