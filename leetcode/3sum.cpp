题目描述

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero. 

Note: 
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c) 
The solution set must not contain duplicate triplets. 

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

时间复杂度O（n^2）,空间复杂度O（1）
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() < 3) return result;
        sort(num.begin(),num.end());
        const int target = 0;
        auto last = num.end();
        
        for(auto i=num.begin(); i<last-2; i++){
            auto j = i + 1;
            if(i > num.begin() && *i == *(i-1)) continue;
            auto k = last - 1;
            while(j < k){
                if(*i + *j + *k < target){
                    j++;
                    while(*j ==*(j-1) && j < k) j++;
                }else if(*i + *j + *k > target){
                    k--;
                    while(*k == *(k+1) && j < k) k--;
                }else{
                    result.push_back({*i , *j, *k});
                    j++;
                    k--;
                    while(*j == *(j-1) && *k == *(k+1) && j<k) j++;
                }
            }
        }
        return result;
    }
};
