题目描述

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution. 

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

时间复杂度O（n^2）,空间复杂度O（1）
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int result = 0;
        int min_gap = INT_MAX;
        sort(num.begin(),num.end());
        for(auto i = num.begin(); i != prev(num.end(),2); i++){
            auto j = next(i);
            auto k = prev(num.end());
            while(j<k){
                const int sum = *i + *j + *k;
                const int gap = abs(sum - target);
                
                if(gap < min_gap){
                    result = sum;
                    min_gap = gap;
                }
                if(sum < target) j++;
                else k--;
            }
        }
        return result;
    }
};
