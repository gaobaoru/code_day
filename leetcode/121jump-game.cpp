题目描述


Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A =[2,3,1,1,4], return true.

A =[3,2,1,0,4], return false. 

class Solution {
public:
    //时间复杂度O(n),空间复杂度O(1)
    bool canJump(int A[], int n) {
        if(n < 1) return true;
        int left_most = n - 1;
        for(int i = n-2; i >= 0; i--){
            if(i + A[i] >= left_most)
                left_most = i;
        }
        return left_most == 0;
    }
};
