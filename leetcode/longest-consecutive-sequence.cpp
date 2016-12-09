题目描述

Given an unsorted array of integers, find the length of the longest consecutive elements sequence. 

For example,
 Given[100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is[1, 2, 3, 4]. Return its length:4. 
Your algorithm should run in O(n) complexity. 

时间复杂度O（n）,空间复杂度O（n）
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> hashtable;
        for(auto i : num) hashtable[i] = false;
        int longest = 0;
        int length;
        for(auto i : num){
            if(hashtable[i]) continue;
            length = 1;
            for(int j=i+1; hashtable.find(j)!=hashtable.end(); j++){
                hashtable[j] = true;
                length++;
            }
            
            for(int j=i-1; hashtable.find(j)!= hashtable.end(); j--){
                hashtable[j] = true;
                length++;
            }
            longest = longest>length?longest:length;
        }
        return longest;
    }
};
