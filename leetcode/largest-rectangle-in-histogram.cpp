题目描述

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram. 

Above is a histogram where width of each bar is 1, given height =[2,1,5,6,2,3]. 

The largest rectangle is shown in the shaded area, which has area =10unit. 

For example,
 Given height =[2,1,5,6,2,3],
 return10. 

时间复杂度O（n）,空间复杂度O（n）
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        height.push_back(0);
        int result = 0;
        for(int i=0; i < height.size();){
            if(s.empty() || height[i] > height[s.top()]){
                s.push(i++);
            }else{
                int tmp = s.top();
                s.pop();
                result = max(result, height[tmp]*(s.empty()?i:i-s.top()-1));
            }
        }
        return result;
    }
};
