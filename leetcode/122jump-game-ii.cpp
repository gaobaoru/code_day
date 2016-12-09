题目描述


Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A =[2,3,1,1,4]

The minimum number of jumps to reach the last index is2. 
(Jump1step from index 0 to 1, then3steps to the last index.) 

class Solution {
public:
    //时间复杂度O(n),空间复杂度O(1)
    int jump(int A[], int n) {
        int steps = 0;
        int last = 0;
        int cur = 0;
        for(int i = 0; i < n; i++){
            if(i > last){
                last = cur;
                steps++;
            }
            cur = max(cur, i+A[i]);
        }
        return steps;
    }
};
