
题目描述


Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array[−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray[4,−1,2,1]has the largest sum =6.

click to show more practice.
More practice:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


class Solution {
public:
    //时间复杂度Ｏ(n),空间复杂度Ｏ(1)
    int maxSubArray(int A[], int n) {
        int result = INT_MIN, f = 0;
        for(int i = 0; i < n; i++){
            f = max(f + A[i], A[i]);
            result = max(f, result);
        }
        return result;
    }
};
