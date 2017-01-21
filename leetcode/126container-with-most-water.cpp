题目描述


Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, 
such that the container contains the most water.

Note: You may not slant the container. 

class Solution {
public:
    //时间复杂度Ｏ(n),空间复杂度Ｏ(1)
    int maxArea(vector<int> &height) {
        int start = 0;
        int end = height.size() - 1;
        int result = INT_MIN;
        while(start < end){
            int area = min(height[start], height[end]) * (end - start);
            result = max(result, area);
            if(height[start] < height[end]){
                start++;
            }else{
                end--;
            }
        }
        return result;
    }
};
