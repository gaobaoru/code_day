题目描述

Given an array of integers, find two numbers such that they add up to a specific target number. 

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based. 

You may assume that each input would have exactly one solution. 

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 

时间复杂度O（n）,空间复杂度O（n）
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> hashtable;
        vector<int> result;
        for(int i=0; i<numbers.size(); i++){
            hashtable[numbers[i]] = i;
        }
        for(int i=0; i<numbers.size(); i++){
            const int diff = target - numbers[i];
            if(hashtable.find(diff) != hashtable.end() && hashtable[diff] > i){
                result.push_back(i+1);
                result.push_back(hashtable[diff]+1);
                break;
            }
        }
        return result;
    }
};
