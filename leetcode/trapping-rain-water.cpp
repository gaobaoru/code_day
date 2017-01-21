题目描述

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. 

For example, 
 Given[0,1,0,2,1,0,1,3,2,1,2,1], return6. 

 http://uploadfiles.nowcoder.com/images/20150314/0_1426326865262_rainwatertrap.png

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image! 

描一遍，找到最高的，分成两半，分别处理左边一半和右边一半。
时间复杂度O（n）,空间复杂度O（1）
class Solution {
public:
    int trap(int A[], int n) {
        int max = 0;
        for(int i=0; i<n; i++){
            if(A[i] > A[max]) max = i;
        }
        
        int water = 0;
        for(int i=0, left_peak=0; i<max; i++){
            if(A[i] > left_peak) left_peak = A[i];
            else water += left_peak - A[i];
        }
        for(int i=n-1, right_peak=0; i>max; i--){
            if(A[i] > right_peak) right_peak = A[i];
            else water += right_peak - A[i];
        }
        return water;
    }
};
